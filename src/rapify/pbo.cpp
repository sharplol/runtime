#include "pbo.h"
#include <sstream>
#include <ctime>



sqf::rapify::pbo sqf::rapify::pbo::read(std::string_view fpath)
{
	pbo p;
	// Open the actual file
	std::ifstream file(fpath.data(), std::ifstream::binary);

	// Read file header
	p.m_fileheader = header::read(file);

	// Read headers of files until we hit an empty one
	header h;
	do
	{
		h = header::read(file);
		p.m_headers.push_back(h.read(file));
	} while (!h.is_empty());

	// Get position after reading all headers
	auto pos = file.tellg();

	// And write the file offset into every header
	for (auto& it : p.m_headers)
	{
		it.file_offset(pos);
		pos += it.filesize();
	}
	// Seek to end
	file.seekg(pos);

	// Theoretical checksum etc.
	// Will be ignored here.
}

void sqf::rapify::pbo::write(std::string_view fpath, std::vector<std::string> files)
{
}