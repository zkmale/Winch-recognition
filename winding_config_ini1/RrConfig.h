#pragma once

#ifndef RR_CONFIG_H_
#define RR_CONFIG_H_
#include <string>
#include <map>
#include<vector>
namespace rr
{
	struct para_super {
		int length;
		int norm_max;
		int fist_width;
		int rope_min;
		int rope_max;
		int width_min;
		int width_max;
		float dist_1;
		float dist_2;
		float dist_3;
		float dist_4;
		float dist_5;
		std::string path;
		int continue_normal_ts;
		int reg_score_ts;
		int blur_degree_ts;
		int test_or_predect;
		std::string video_path;
		std::string test_y;
	};

	class RrConfig
	{
	public:
		RrConfig()
		{
		}
		~RrConfig()
		{
		}
		para_super ReadCfig();
		bool ReadConfig(const std::string & filename);
		std::string ReadString(const char* section, const char* item, const char* default_value);
		bool ReadBool(const char* section, const char* item, const char* default_value);
		int ReadInt(const char* section, const char* item, const int& default_value);
		float ReadFloat(const char* section, const char* item, const float& default_value);
	private:
		bool IsSpace(char c);
		bool IsCommentChar(char c);
		void Trim(std::string & str);
		bool AnalyseLine(const std::string & line, std::string& section, std::string & key, std::string & value);

	private:
		//std::map<std::string, std::string> settings_;
		std::map<std::string, std::map<std::string, std::string> >settings_;
	};
}
#endif

