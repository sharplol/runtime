#pragma once
#include <fstream>


namespace sqf
{
	namespace rapify
	{
		static unsigned long read_ulong(std::ifstream& file)
		{
			return ((unsigned long)file.get() << (32 - 8)) |
				((unsigned long)file.get() << (32 - 16)) |
				((unsigned long)file.get() << (32 - 24)) |
				((unsigned long)file.get() << (32 - 32));
		}
		static void write_ulong(std::ofstream& file, unsigned long val)
		{
			file << ((val << (32 - 8)) & 0xFF)
				<< ((val << (32 - 16)) & 0xFF)
				<< ((val << (32 - 24)) & 0xFF)
				<< ((val << (32 - 32)) & 0xFF);
		}
	}
}