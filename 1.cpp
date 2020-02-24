#include<iostream>
#include "algorithm.h"


int main() {
	//std::string path1 = "E:\\zoomlion\\data\\smallDataSets\\smallDataSets\\test\\imgs\\img00111.jpg";

	zk_algorithm p;
	std::string path = "E:\\zoomlion\\data\\smallDataSets\\smallDataSets\\test\\imgs\\*.jpg";
	std::string test_y = "E:\\zoomlion\\data\\smallDataSets\\smallDataSets\\test\\y_Test.txt";
	std::string video_path = "E:\\zoomlion\\data\\kk.mp4";
	std::string path_one = "E:\\zoomlion\\data\\smallDataSets\\smallDataSets\\test\\imgs\\img00029.jpg";
	//p.read_video_algorithm(video_path);
	//p.read_video_algorithm(video_path);
	//p.read_video_algorithm(video_path);
	p.test_hoist(path, test_y);
	//p.read_video_algorithm(video_path);
	//int tt = p.my_algorithm_pos_test(path_one);
	//std::cout << "tt = " << tt << std::endl;
	system("pause");
	return 0;
}







