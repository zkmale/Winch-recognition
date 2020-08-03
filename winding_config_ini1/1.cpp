#include <stdio.h>
#include<iostream>
#include "algorithm.h"
#include "RrConfig.h"

int main() {
	//std::string path1 = "E:\\zoomlion\\data\\smallDataSets\\smallDataSets\\test\\imgs\\img00111.jpg";
	/*
	rr::para_super mm;
	rr::RrConfig config;
	mm = config.ReadCfig();
	*/
	//std::string test_y = "E:\\zoomlion\\data\\smallDataSets\\smallDataSets\\test\\y_Test.txt";
	//std::string video_path = "E:\\zoomlion\\data\\kk.mp4";
	std::string path_one = "E:\\zoomlion\\data\\smallDataSets\\smallDataSets\\test\\imgs\\img00029.jpg";
	zk_algorithm p;
	//std::string path = "E:\\zoomlion\\data\\smallDataSets\\smallDataSets\\test\\imgs\\*.jpg";
	if (p.test_or_predect == 1) {
		p.read_video_algorithm(p.video_path);
	}
	else if (p.test_or_predect == 0)
	{
		p.test_hoist(p.path, p.test_y, p.continue_normal_ts, p.reg_score_ts, p.blur_degree_ts);
	}
	
	//p.read_video_algorithm(video_path);
	//p.read_video_algorithm(video_path);
	//p.test_hoist(p.path, test_y, p.continue_normal_ts, p.reg_score_ts, p.blur_degree_ts);
	//p.read_video_algorithm(video_path);
	//int tt = p.my_algorithm_pos_test(path_one);
	//std::cout << "tt = " << tt << std::endl;
	system("pause");
	return 0;
}


