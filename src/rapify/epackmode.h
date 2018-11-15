#pragma once

namespace sqf
{
	namespace rapify
	{
		enum epackmode
		{
			UNCOMPRESSED = 0x00000000,
			PACKED = 0x43707273,
			PRODUCT_ENTRY = 0x56657273
		};
	}
}