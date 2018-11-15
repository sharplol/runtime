#pragma once
#include "epackmode.h"

#include <vector>
#include <string>

namespace sqf
{
	namespace rapify
	{
		class header
		{
			////////////////////////
			// ACTUAL PBO CONTENT //
			////////////////////////

			std::string m_filename;
			epackmode m_packmode;
			unsigned long m_original_size;

			unsigned long m_timestamp;
			unsigned long m_filesize;

			std::vector<std::string> m_extensions;

			///////////////////
			// HELPER FIELDS //
			///////////////////
			unsigned long m_file_offset;

		public:
			header() : m_original_size(0), m_timestamp(0), m_filesize(0) {}
			std::string filename() { return m_filename; }
			void filename(std::string val) { m_filename = val; }

			epackmode packmode() { return m_packmode; }
			void packmode(epackmode val) { m_packmode = val; }
			void packmode(unsigned long val) { m_packmode = val; }

			unsigned long original_size() { return m_original_size; }
			void original_size(unsigned long val) { m_original_size = val; }

			unsigned long timestamp() { return m_timestamp; }
			void timestamp(unsigned long val) { m_timestamp = val; }

			unsigned long filesize() { return m_filesize; }
			void filesize(unsigned long val) { m_filesize = val; }

			unsigned long file_offset() { return m_file_offset; }
			void file_offset(unsigned long val) { m_file_offset = val; }

			static header read(std::ifstream& file);
			void write(std::ofstream& file);

			bool is_empty() {
				return m_filename.empty() &&
					m_packmode == epackmode::UNCOMPRESSED &&
					m_original_size == 0 &&
					m_timestamp == 0 &&
					m_filesize == 0 &&
					m_extensions.empty();
			}
		};
	}
}