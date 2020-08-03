#include "algorithm.h"

/*
zk_algorithm::zk_algorithm(int xx) {
	al_result = xx;
}
*/

//template<class T>
zk_algorithm::zk_algorithm()
{
	length = 277;
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
		norm_set[i] = (int)round_x(((double)x[i] - minq) / (maxq - minq) * 200);
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
	for (int i = 0; i < 45; i++) x2[i] = x[65 + i];
	for (int i = 0; i < 45; i++) x3[i] = x[130 + i];
	for (int i = 0; i < 45; i++) x4[i] = x[210 + i];

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


		bool f = x[i] - x[i - 1] <= 10 || (16 <= x[i] - x[i - 1] && x[i] - x[i - 1] <= 18) ||
			(24 <= x[i] - x[i - 1] && x[i] - x[i - 1] <= 27) || (32 <= x[i] - x[i - 1] && x[i] - x[i - 1] <= 36) ||
			(40 <= x[i] - x[i - 1] && x[i] - x[i - 1] <= 45) || (48 <= x[i] - x[i - 1] && x[i] - x[i - 1] <= 54);

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
		return 0.3;
	else if (dists == 3)
		return 1;
	else if (dists == 4)
		return 1.3;
	else if (dists >= 5)
		return 1.6;
	else
		return 0;
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
	for (int ii = 30; ii < imgs_crop.rows - 30; ii += 30) {
		for (int jj = 0; jj < imgs_crop.cols; jj++) {
			//std::cout << "(int)imgss.at<uchar>(ii, jj) = " << (int)imgss.at<uchar>(ii, jj) << "   y_data = " << y_data << std::endl;
			imgout << (int)imgs_crop.at<uchar>(ii, jj) << " ";
		}
		labelout << y << std::endl;
		imgout << std::endl;
	}
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
	for (int ii = 30; ii < imgs_crop.rows - 30; ii += 3) {
		for (int jj = 0; jj < imgs_crop.cols; jj++) {
			//std::cout << "(int)imgss.at<uchar>(ii, jj) = " << (int)imgss.at<uchar>(ii, jj) << "   y_data = " << y_data << std::endl;
			imgout << (int)imgs_crop.at<uchar>(ii, jj) << " ";
		}
		labelout << y << std::endl;
		imgout << std::endl;
	}
	labelout.close();
	imgout.close();
	//imgout << std::endl;
}






