#pragma once
#include "header.h"

#include <vector>
#include <string>
#include <string_view>
#include <fstream>


namespace sqf
{
	namespace rapify
	{
		class pbo
		{
			header m_fileheader;
			std::vector<header> m_headers;
			std::ifstream m_file_handle;
		public:
			pbo() {}
			~pbo()
			{
				m_file_handle.close();
			}
			static sqf::rapify::pbo read(std::string_view fpath);
			void write(std::string_view fpath, std::vector<std::string> files);
		};
	}
}