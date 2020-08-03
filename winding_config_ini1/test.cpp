#include "algorithm.h"

//template<class T>
int zk_algorithm::my_algorithm_pos_test(std::string imgs_path_t, int continue_normal_t, int reg_score_t, int blur_degree_t) {
	cv::Mat img = cv::imread(imgs_path_t);
	cv::Mat imgs_gray;
	cv::cvtColor(img, imgs_gray, cv::COLOR_BGR2GRAY);

	//cv::Rect rect(285, 465, 260, 277);
	cv::Rect rect(465, 285, 277, 260);

	cv::Mat imgs_crop = imgs_gray(rect);

	int img_rows = imgs_crop.rows;
	int img_cols = imgs_crop.cols;
	//int imgs_lines[img_cols];
	int* imgs_lines = new int[img_cols];

	int n = 0;
	double score, sc, reg = 0.0;
	int vague_value = 0;
	for (int i = 0; i < img_rows / 4; i++) {

		//std::cout << "counts = " << i << std::endl;

		for (int j = 0; j < img_cols; j++) {
			imgs_lines[j] = imgs_crop.at<uchar>(4 * i, j);
		}

		score = Rcognition_roller(imgs_lines);

		//std::cout << "score = " << score << std::endl;

		reg += score;

		//std::cout << "score = " << score << "reg = " << reg << std::endl;

		if (score == 0) {
			n += 1;
			if (n >= continue_normal_t)
				return 0;
		}
		else
		{
			n = 0;
			continue;
		}
	}
	
	//std::cout << "reg = " << reg << std::endl;

	if (reg <= reg_score_t)
		return 0;
	for (int i = 0; i < img_rows / 4; i++) {
		vague_value += count_vague(imgs_lines);
		//std::cout << "vague_value = " << vague_value << std::endl;
		if (vague_value > blur_degree_t)
			return 0;
	}
	return 1;
}

//template<class T>
double zk_algorithm::test_hoist(cv::String imgs_path, cv::String test_y, int continue_normal_t, 
	int reg_score_t, int blur_degree_t, bool is_write_line_data) {
	std::fstream y_stream;
	std::vector<cv::String> imgs_file;
	std::vector<int> imgs_y;
	std::vector<int> FPmat;
	std::vector<int> FNmat;
	std::string y_string;

	y_stream.open(test_y);
	cv::glob(imgs_path, imgs_file);
	int i = 0;
	if (is_write_line_data == true) {
		cv::String file_txt = "./train_index_data.txt";
		cv::String label_txt = "./train_label_txt.txt";
		while (y_stream >> y_string) {
			std::stringstream tmp;
			int y_data;
			tmp << y_string;
			tmp >> y_data;
			cv::Mat imgss = cv::imread(imgs_file[i]);
			if (y_data == 1) {
				write_txt_pos(file_txt, label_txt, imgss, y_data);
			}
			else if (i % 2 == 0) {
				write_txt(file_txt, label_txt, imgss, y_data);
				//imgout << std::endl;
			}
			i++;
		}
		return 0.0;
	}
	else
	{
		double F1;
		int TP = 0, FP = 0, FN = 0, TN = 0;
		double FPS;
		while (y_stream >> y_string) {

			//DWORD start_time = GetTickCount();

			std::stringstream tmp;
			int y_data;
			tmp << y_string;
			tmp >> y_data;
			cv::Mat imgss = cv::imread(imgs_file[i]);
			//std::cout << "heigh = " << imgss.rows << std::endl

			int result = my_algorithm_pos_test(imgs_file[i], continue_normal_t, reg_score_t, blur_degree_t);
			if (result == y_data && y_data == 1) {
				TP += 1;
			}
			else if (result == 1 && y_data == 0) {
				FP += 1;
				FPmat.push_back(i);
				std::cout << "error test1 = " << i << std::endl;
			}
			else if (result == 0 && y_data == 1) {
				FN += 1;
				FNmat.push_back(i);
				std::cout << "error test2 = " << i << std::endl;
			}
			else {
				TN += 1;
			}
			if (i % 100 == 0) {
				double recall = TP / (TP + FN + 1e-7);
				double precision = TP / (TP + FP + 1e-7);
				double acc = (TP + TN) / (TP + TN + FP + FN + 1e-7);
				F1 = 2 * precision*recall / (precision + recall + 1e-7);

				std::cout << "acc = " << acc << "    precision = " << precision << std::endl;
				std::cout << "i = " << i << "    F1 = " << F1 << std::endl;
			}
			i++;
			//DWORD end_time = GetTickCount();
			//FPS = end_time - start_time;
			//std::cout << "FPS = " << FPS << std::endl;
		}
		std::cout << "FP =  " << FP << std::endl;
		std::cout << "FN =  " << FN << std::endl;
		std::cout << "count error number =  " << (FP + FN) << std::endl;
		return F1;
	}
}

