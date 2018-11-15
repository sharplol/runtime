#include "header.h"
#include "primitive.h"
#include <sstream>
#include <ctime>

unsigned long unix_timestamp()
{
	std::time_t result = std::time(nullptr);
	return result;
}

header sqf::rapify::header::read(std::ifstream & file)
{
	header h;
	std::stringstream sstream;
	int i;
	bool was_null = true;
	// Read Filename
	while ((i = file.get()) != -1)
	{
		if (i == '\0')
		{
			h.m_filename = sstream.str();
			sstream.str("");
			break;
		}
		else
		{
			sstream << (char)i;
		}
	}
	// Read Pack Mode
	h.m_packmode = read_ulong(file);
	// Read OriginalSize (only relevant if mode is packed)
	h.m_original_size = read_ulong(file);
	// Skip a single ulong for reasons only BI knows
	read_ulong(file);
	// Read the timestamp
	h.m_timestamp = read_ulong(file);
	// Read the filesize
	h.m_filesize = read_ulong(file);
	// Read Header-Extensions
	while ((i = file.get()) != -1)
	{
		if (i == '\0')
		{
			if (was_null)
			{
				break;
			}
			was_null = true;
			h.m_header_extension.push_back(sstream.str());
			sstream.str("");
		}
		else
		{
			was_null = false;
			sstream << (char)i;
		}
	}
	return h;
}

void sqf::rapify::header::write(std::ofstream & file)
{
	// Write filename
	file << m_filename << '\0';
	// Write Pack Mode
	write_ulong(file, m_packmode);
	// Write Original Size
	write_ulong(file, m_original_size);
	// Write Skip ulong
	write_ulong(file, 0);
	// Write timestamp
	write_ulong(file, unix_timestamp());
	// Write filesize
	write_ulong(file, m_filesize);
	// Write Header-Extensions
	for (auto& it : m_extensions)
	{
		file << it << (char)'\0';
	}
	// Write terminating NULL
	file << (char)'\0';
}
