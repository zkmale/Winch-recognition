#include "algorithm.h"

/*
zk_algorithm::zk_algorithm(int xx) {
	al_result = xx;
}
*/

//template<class T>
zk_algorithm::zk_algorithm()
{
	rr::para_super para;
	rr::RrConfig config;
	para = config.ReadCfig();
	length = para.length;
	norm_max = para.norm_max;
	fist_width = para.fist_width;
	rope_min = para.rope_min;
	rope_max = para.rope_max;
	width_min = para.width_min;
	width_max = para.width_max;
	dist_1 = para.dist_1;
	dist_2 = para.dist_2;
	dist_3 = para.dist_3;
	dist_4 = para.dist_4;
	dist_5 = para.dist_5;
	continue_normal_ts = para.continue_normal_ts;
	reg_score_ts = para.reg_score_ts;
	blur_degree_ts = para.blur_degree_ts;
	test_or_predect = para.test_or_predect;
	path = para.path;
	video_path = para.video_path;
	test_y = para.test_y;

}


//template<class T>
zk_algorithm::~zk_algorithm()
{
}

//template<class T>
int zk_algorithm::max_x(int* x) {
	//int length = _msize(x) / sizeof(*x);
	int maxs = x[0];
	for (int i = 1; i < length; i++) {
		if (maxs < x[i])
			maxs = x[i];
	}
	return maxs;
}

//template<class T>
int zk_algorithm::min_x(int* x) {
	//int length = _msize(x) / sizeof(*x);

	int mins = x[0];
	for (int i = 1; i < length; i++) {
		if (mins > x[i])
			mins = x[i];
	}
	return mins;
}

//template<class T>
double zk_algorithm::min_x_double(double x[]) {
	//int length = sizeof(x) / sizeof(x[0]);
	//int length = _msize(x) / sizeof(*x);
	int length_list = 4;
	double mins_double = x[0];
	for (int i = 1; i < length_list; i++) {
		if (mins_double > x[i])
			mins_double = x[i];
	}
	return mins_double;
}

//template<class T>
int zk_algorithm::round_x(double x) {
	return (int)(x + 0.5);
}

//template<class T>
std::vector<int> zk_algorithm::norm(int* x) {
	//int length = _msize(x) / sizeof(*x);
	int minq = min_x(x);
	int maxq = max_x(x);
	std::vector<int> norm_set(length, 0);
	for (int i = 0; i < length; i++) {
		norm_set[i] = (int)round_x(((double)x[i] - minq) / (maxq - minq) * norm_max);
	}
	return norm_set;
}

//template<class T>
double zk_algorithm::cout_var(int *x) {
	//const int length = sizeof(x) / sizeof(x[0]);
	//const int length = _msize(x) / sizeof(*x);
	const int length = 45;
	double var_x = 0;
	int sum_x = 0;

	int x1[length];
	double avrrage_x;
	std::memcpy(x1, x, sizeof(x1));
	std::sort(x1, x1 + length);
	for (int i = 3; i < length - 3; i++) {
		sum_x += x1[i];
	}
	avrrage_x = sum_x / double(length - 6);
	for (int i = 3; i < length - 3; i++) {
		var_x += pow(x1[i] - avrrage_x, 2);
	}
	return sqrt(var_x);
}

//template<class T>
int zk_algorithm::count_vague(int* x) {
	//int length = sizeof(x) / sizeof(x[0]);
		//int length = _msize(x) / sizeof(*x);

	int x1[45], x2[45], x3[45], x4[45];
	for (int i = 0; i < 45; i++) x1[i] = x[10 + i];
	for (int i = 0; i < 45; i++) x2[i] = x[75 + i];
	for (int i = 0; i < 45; i++) x3[i] = x[140 + i];
	for (int i = 0; i < 45; i++) x4[i] = x[205 + i];

	double x1_var = cout_var(x1);
	double x2_var = cout_var(x2);
	//std::cout << "x2_var = " << x2_var << std::endl;
	double x3_var = cout_var(x3);
	double x4_var = cout_var(x4);

	double list_var[] = { x1_var,x2_var,x3_var,x4_var };
	double min_xx = min_x_double(list_var);
	int vague = int(min_x_double(list_var) < 15);
	return vague;
}


struct count_Trough_struct {
	std::vector<int> bogu;
	std::vector<int> index;
};


//template<class T>
count_Trough_struct zk_algorithm::count_Trough(std::vector<int> x) {
	//const int length = sizeof(x) / sizeof(x[0]);
		//const int length = _msize(x) / sizeof(*x);
		//const int length = x.size();
	int x1[277];

	//std::memcpy(x1, x, sizeof(x));

	for (int i = 0; i < length; i++) {
		x1[i] = x[i];
	}

	std::sort(x1, x1 + length);
	int threshold = x1[62];
	struct count_Trough_struct trough;

	for (int i = 2; i < length - 2; i++) {
		if (x[i] <= x[i - 1] && x[i] <= x[i - 2] && x[i] <= x[i + 1] && x[i] <= x[i + 2] && x[i] < threshold) {
			trough.bogu.push_back(x[i]);
			trough.index.push_back(i);
		}
	}
	return trough;
}

//template<class T>
int zk_algorithm::distance_Trough(std::vector<int> x) {
	int dist = 0;
	//int length = sizeof(x) / sizeof(x[0]);
	int length1 = x.size();
	//int length = _msize(x) / sizeof(*x);
	//int length = _msize(x) / sizeof(*x);

	for (int i = 1; i < length1; i++) {

		bool f = x[i] - x[i - 1] <= fist_width || (rope_min <= x[i] - x[i - 1] && x[i] - x[i - 1] <= rope_max) ||
			((rope_min + width_min) <= x[i] - x[i - 1] && x[i] - x[i - 1] <= (rope_max + width_max)) || ((rope_min + width_min * 2) <= x[i] - x[i - 1] && x[i] - x[i - 1] <= (rope_max + width_max * 2))||
			((rope_min + width_min * 3) <= x[i] - x[i - 1] && x[i] - x[i - 1] <= (rope_max + width_max * 3)) || ((rope_min + width_min * 4) <= x[i] - x[i - 1] && x[i] - x[i - 1] <= (rope_max + width_max * 4));

		if (f) {
			//std::cout << "f = " << f << std::endl;
			continue;
		}
		else
		{
			dist += 1;
		}
	}
	return dist;
}

//template<class T>
double zk_algorithm::Rcognition_roller(int* line_pixel) {
	std::vector<int> line_pixels = norm(line_pixel);
	//line_pixels = norm(line_pixel);


	count_Trough_struct trough = count_Trough(line_pixels);  //向量长度不对
	std::vector<int> indexs1 = trough.index;

	int sizes = indexs1.size();

	int dists = distance_Trough(trough.index);

	if (dists == 2)
		return dist_2;
	else if (dists == 3)
		return dist_3;
	else if (dists == 4)
		return dist_4;
	else if (dists >= 5)
		return dist_5;
	else
		return dist_1;
}



//template<class T>
void zk_algorithm::write_txt(cv::String data_path, cv::String label_path, cv::Mat imgss, int y) {
	std::ofstream imgout(data_path, std::ios::app);
	std::ofstream labelout(label_path, std::ios::app);
	cv::Mat imgs_gray;
	//cv::Mat imgs_crop;
	cv::cvtColor(imgss, imgs_gray, cv::COLOR_BGR2GRAY);
	//cv::Rect rect(285, 465, 260, 277);
	cv::Rect rect(465, 285, 277, 260);
	cv::Mat imgs_crop = imgs_gray(rect);


	int imgs_col = imgs_crop.cols;
	int* imgs_line = new int[imgs_col];
	for (int i = 30; i < imgs_crop.rows - 30; i += 30) {
		for (int j = 0; j < imgs_col; j++) {
			imgs_line[j] = imgs_crop.at<uchar>(i, j);
		}
		std::vector<int> line_pixel_txt = norm(imgs_line);
		count_Trough_struct trough_txt = count_Trough(line_pixel_txt);
		std::vector<int> indexs_txt = trough_txt.index;
		int length = indexs_txt.size();
		for (int k = 0; k < length; k++) {
			imgout << indexs_txt[k] << " ";
		}
		labelout << y << std::endl;
		imgout << std::endl;
	}


	/*
	for (int ii = 30; ii < imgs_crop.rows - 30; ii += 30) {
		for (int jj = 0; jj < imgs_crop.cols; jj++) {
			//std::cout << "(int)imgss.at<uchar>(ii, jj) = " << (int)imgss.at<uchar>(ii, jj) << "   y_data = " << y_data << std::endl;
			imgout << (int)imgs_crop.at<uchar>(ii, jj) << " ";
		}
		labelout << y << std::endl;
		imgout << std::endl;
	}
	*/
	labelout.close();
	imgout.close();
	//imgout << std::endl;
}

//template<class T>
void zk_algorithm::write_txt_pos(cv::String data_path, cv::String label_path, cv::Mat imgss, int y) {
	std::ofstream imgout(data_path, std::ios::app);
	std::ofstream labelout(label_path, std::ios::app);
	cv::Mat imgs_gray;
	//cv::Mat imgs_crop;
	cv::cvtColor(imgss, imgs_gray, cv::COLOR_BGR2GRAY);
	//cv::Rect rect(285, 465, 260, 277);
	cv::Rect rect(465, 285, 277, 260);
	cv::Mat imgs_crop = imgs_gray(rect);


	//写入图像每一行数据波谷的下标数据到txt文本中
	int imgs_col = imgs_crop.cols;
	int* imgs_line = new int[imgs_col];
	for (int i = 30; i < imgs_crop.rows - 30; i += 30) {
		for (int j = 0; j < imgs_col; j++) {
			imgs_line[j] = imgs_crop.at<uchar>(i, j);
		}
		std::vector<int> line_pixel_txt = norm(imgs_line);
		count_Trough_struct trough_txt = count_Trough(line_pixel_txt);
		std::vector<int> indexs_txt = trough_txt.index;
		int length = indexs_txt.size();
		for (int k = 0; k < length; k++) {
			imgout << indexs_txt[k] << " ";
		}
		labelout << y << std::endl;
		imgout << std::endl;
	}


	/*
	//写入图像的每一行数据到txt文本中
	for (int ii = 30; ii < imgs_crop.rows - 30; ii += 3) {
		for (int jj = 0; jj < imgs_crop.cols; jj++) {
			//std::cout << "(int)imgss.at<uchar>(ii, jj) = " << (int)imgss.at<uchar>(ii, jj) << "   y_data = " << y_data << std::endl;
			imgout << (int)imgs_crop.at<uchar>(ii, jj) << " ";
		}
		labelout << y << std::endl;
		imgout << std::endl;
	}
	*/

	labelout.close();
	imgout.close();
	//imgout << std::endl;
}






