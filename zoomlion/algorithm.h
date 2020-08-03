#pragma once
#ifndef MY_TMP_H
#define MY_TMP_H

#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstdio>
#include<math.h>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp> 
#include <fstream>
#include <cstring>
#include<sstream>

struct count_Trough_struct;

//template<class T>
class zk_algorithm
{
public:

	int length;

	int al_result;

	zk_algorithm();

	~zk_algorithm();

	//template<class T>
	int max_x(int* x);

	//template<class T>
	int min_x(int* x);

	//template<class T>
	double min_x_double(double* x);

	int round_x(double x);

	//template<class T>
	std::vector<int> norm(int* x);

	//template<class T>
	double cout_var(int* x);

	//template<class T>
	int count_vague(int* x);

	//struct count_Trough_struct;

	//template<class T>
	count_Trough_struct count_Trough(std::vector<int> x);

	//template<class T>
	int distance_Trough(std::vector<int> x);

	//template<class T>
	double Rcognition_roller(int* line_pixel);

	int my_algorithm_pos_predict(cv::Mat img, int continue_normal = 22, int reg_score = 13, int blur_degree = 14);
	//int my_algorithm_pos_predict(T& img, int continue_normal = 22, int reg_score = 13, int blur_degree = 14);


	//int my_algorithm_pos_test(std::string imgs_path_t, int continue_normal_t, int reg_score_t, int blur_degree_t);
	int my_algorithm_pos_test(std::string imgs_path_t, int continue_normal_t = 22, int reg_score_t = 13, int blur_degree_t = 14);

	void read_video_algorithm(cv::String video_path);
	//void read_video_algorithm(T& video_path);



	void write_txt(cv::String data_path, cv::String label_path, cv::Mat imgss, int y);

	void write_txt_pos(cv::String data_path, cv::String label_path, cv::Mat imgss, int y);

	double test_hoist(cv::String imgs_path, cv::String test_y);
};


/*
int my_algorithm_pos_predict(cv::Mat img, int continue_normal = 22, int reg_score = 13, int blur_degree = 14);


template<class T>
count_Trough_struct count_Trough(T& x);

*/
//count_Trough_struct count_Trough(T& x);

#endif

