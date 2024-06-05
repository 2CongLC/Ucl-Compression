#pragma once

using namespace System;

namespace UclCompression
{
	public ref class Ucl
	{
	private:
		static bool initialized;
		static void assertInit();

	public:
		static array<Byte>^ NRV2B_99_Compress(array<Byte>^ data, int compressionLevel);
		static array<Byte>^ NRV2D_99_Compress(array<Byte>^ data, int compressionLevel);
		static array<Byte>^ NRV2E_99_Compress(array<Byte>^ data, int compressionLevel);

		static array<Byte>^ NRV2B_Decompress_8(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2B_Decompress_LE16(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2B_Decompress_LE32(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2B_Decompress_Safe8(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2B_Decompress_SafeLE16(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2B_Decompress_SafeLE32(array<Byte>^ data, int uncompressedSize);

		static array<Byte>^ NRV2D_Decompress_8(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2D_Decompress_LE16(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2D_Decompress_LE32(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2D_Decompress_Safe8(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2D_Decompress_SafeLE16(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2D_Decompress_SafeLE32(array<Byte>^ data, int uncompressedSize);

		static array<Byte>^ NRV2E_Decompress_8(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2E_Decompress_LE16(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2E_Decompress_LE32(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2E_Decompress_Safe8(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2E_Decompress_SafeLE16(array<Byte>^ data, int uncompressedSize);
		static array<Byte>^ NRV2E_Decompress_SafeLE32(array<Byte>^ data, int uncompressedSize);
	};
}
