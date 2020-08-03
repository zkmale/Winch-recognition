#include"RrConfig.h"
#include<iostream>
#include<stdio.h>

namespace rr {
	
	para_super RrConfig::ReadCfig() {
		rr::RrConfig config;
		config.ReadConfig("aa.ini");
		para_super result;
		//result.hostname = config.ReadString("MYSQL", "HostName", "");
		//std::string hostname = config.ReadString("MYSQL", "HostName", "");
		result.length = config.ReadInt("GLOBLE", "length", 0);
		result.norm_max = config.ReadInt("NORM", "norm_max", 0);
		result.fist_width = config.ReadInt("DISTANCS_TROUGH", "fist_width", 0);
		result.rope_min = config.ReadInt("DISTANCS_TROUGH", "rope_min", 0);
		result.rope_max = config.ReadInt("DISTANCS_TROUGH", "rope_max", 0);
		result.width_min = config.ReadInt("DISTANCS_TROUGH", "width_min", 0);
		result.width_max = config.ReadInt("DISTANCS_TROUGH", "width_max", 0);
		result.dist_1 = config.ReadFloat("RCOGNITION_ROLLER", "dist_1", 0.);
		result.dist_2 = config.ReadFloat("RCOGNITION_ROLLER", "dist_2", 0.);
		result.dist_3 = config.ReadFloat("RCOGNITION_ROLLER", "dist_3", 0.);
		result.dist_4 = config.ReadFloat("RCOGNITION_ROLLER", "dist_4", 0.);
		result.dist_5 = config.ReadFloat("RCOGNITION_ROLLER", "dist_5", 0.);
		result.path = config.ReadString("MAIN", "path", "");
		result.continue_normal_ts = config.ReadInt("MY_ALGORITHM_POS_TEST", "continue_normal_ts", 0);
		result.reg_score_ts = config.ReadInt("MY_ALGORITHM_POS_TEST", "reg_score_ts", 0);
		result.blur_degree_ts = config.ReadInt("MY_ALGORITHM_POS_TEST", "blur_degree_ts", 0);
		result.test_or_predect = config.ReadInt("MAIN", "test_or_predect", 0);
		result.video_path = config.ReadString("MAIN", "video_path", "");
		result.test_y = config.ReadString("MAIN", "test_y", "");
		//result.core = config.ReadInt("MYSQL", "core", 0);
		//int port = config.ReadInt("MYSQL", "Port", 0);
		//result.user = config.ReadString("MYSQL", "UserName", "");
		//std::string user = config.ReadString("MYSQL", "UserName", "");
		return result;
	}
}
