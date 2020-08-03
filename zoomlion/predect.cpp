#include "algorithm.h"
//#include "algorithm.cpp"
//template<class T>
int zk_algorithm::my_algorithm_pos_predict(cv::Mat img, int continue_normal, int reg_score, int blur_degree) {
	//int zk_algorithm<T>::my_algorithm_pos_predict(T& img, int continue_normal, int reg_score, int blur_degree) {

		//cv::Mat img = cv::imread(imgs_path);
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




		reg += score;

		//std::cout << "score = " << score << "reg = " << reg << std::endl;

		if (score == 0) {
			n += 1;
			if (n >= continue_normal)
				return 0;
		}
		else
		{
			n = 0;
			continue;
		}
	}
	std::cout << "reg = " << reg << std::endl;
	if (reg <= reg_score)
		return 0;
	for (int i = 0; i < img_rows / 4; i++) {
		vague_value += count_vague(imgs_lines);
		if (vague_value > blur_degree)
			return 0;
	}
	return 1;
}

//template<class T>
void zk_algorithm::read_video_algorithm(cv::String video_path) {
	//void zk_algorithm<T>::read_video_algorithm(T& video_path) {
	cv::Mat frame;
	cv::VideoCapture cap(video_path);

	//cap.set(0, 2 * 1000);

	int tmp_result;
	if (!cap.isOpened()) {
		std::cout << "can't open video" << std::endl;
	}
	while (1) {
		cap >> frame;
		cv::imshow("video", frame);
		tmp_result = my_algorithm_pos_predict(frame);
		std::cout << "tmp_result = " << tmp_result << std::endl;
		if (cv::waitKey(100) >= 0) break;
	}
}


