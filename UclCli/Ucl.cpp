#include "Ucl.h"
#include "include\ucl\ucl.h"

using namespace System;

typedef int(*ucl_compress)(const ucl_bytep src, ucl_uint src_len, ucl_bytep dst, ucl_uintp dst_len, ucl_progress_callback_p cb, int level, const struct ucl_compress_config_p conf, ucl_uintp result);
typedef int(*ucl_decompress)(const ucl_bytep src, ucl_uint  src_len, ucl_bytep dst, ucl_uintp dst_len, ucl_voidp wrkmem);

namespace UclCompression
{
	void Ucl::assertInit()
	{
		if (initialized)
			return;

		if (ucl_init() != UCL_E_OK)
			throw gcnew Exception("Failed to initialize UCL.");

		initialized = true;
	}

	array<Byte>^ compress(ucl_compress compressionFunc, array<Byte>^ data, int level)
	{
		if (level < 1) level = 1;
		else if (level > 10) level = 10;

		pin_ptr<System::Byte> dataPtr = &data[0];
		auto in = dataPtr;
		auto inSize = (ucl_uint)data->Length;
		auto outSize = inSize + inSize / 8 + 256;
		auto out = (ucl_bytep)ucl_malloc(outSize);

		auto resultCode = compressionFunc(in, inSize, out, &outSize, NULL, level, NULL, NULL);
		if (resultCode == UCL_E_OUT_OF_MEMORY)
			throw gcnew InsufficientMemoryException();
		else if (resultCode != UCL_E_OK)
			throw gcnew Exception("Failed to compress data, UCL error code: " + resultCode);

		auto result = gcnew array<Byte>(outSize);
		pin_ptr<System::Byte> resultPtr = &result[0];
		ucl_memcpy(resultPtr, out, outSize);
		ucl_free(out);

		return result;
	}

	array<Byte>^ decompress(ucl_decompress decompressionFunc, array<Byte>^ data, int uncompressedSize)
	{
		pin_ptr<System::Byte> dataPtr = &data[0];
		auto in = dataPtr;
		auto inSize = (ucl_uint)data->Length;
		auto outSize = (ucl_uint)uncompressedSize;
		auto out = (ucl_bytep)ucl_malloc(outSize);

		auto resultCode = decompressionFunc(in, inSize, out, &outSize, NULL);
		if (resultCode != UCL_E_OK || outSize != uncompressedSize)
			throw gcnew Exception("Failed to decompress data, UCL error code: " + resultCode);

		auto result = gcnew array<Byte>(outSize);
		pin_ptr<System::Byte> resultPtr = &result[0];
		ucl_memcpy(resultPtr, out, outSize);
		ucl_free(out);

		return result;
	}

	array<Byte>^ Ucl::NRV2B_99_Compress(array<Byte>^ data, int level)
	{
		assertInit();
		return compress(&ucl_nrv2b_99_compress, data, level);
	}

	array<Byte>^ Ucl::NRV2D_99_Compress(array<Byte>^ data, int level)
	{
		assertInit();
		return compress(&ucl_nrv2d_99_compress, data, level);
	}

	array<Byte>^ Ucl::NRV2E_99_Compress(array<Byte>^ data, int level)
	{
		assertInit();
		return compress(&ucl_nrv2e_99_compress, data, level);
	}

	array<Byte>^ Ucl::NRV2B_Decompress_8(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2b_decompress_8, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2B_Decompress_LE16(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2b_decompress_le16, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2B_Decompress_LE32(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2b_decompress_le32, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2B_Decompress_Safe8(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2b_decompress_safe_8, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2B_Decompress_SafeLE16(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2b_decompress_safe_le16, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2B_Decompress_SafeLE32(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2b_decompress_safe_le32, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2D_Decompress_8(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2d_decompress_8, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2D_Decompress_LE16(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2d_decompress_le16, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2D_Decompress_LE32(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2d_decompress_le32, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2D_Decompress_Safe8(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2d_decompress_safe_8, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2D_Decompress_SafeLE16(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2d_decompress_safe_le16, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2D_Decompress_SafeLE32(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2d_decompress_safe_le32, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2E_Decompress_8(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2e_decompress_8, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2E_Decompress_LE16(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2e_decompress_le16, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2E_Decompress_LE32(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2e_decompress_le32, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2E_Decompress_Safe8(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2e_decompress_safe_8, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2E_Decompress_SafeLE16(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2e_decompress_safe_le16, data, uncompressedSize);
	}

	array<Byte>^ Ucl::NRV2E_Decompress_SafeLE32(array<Byte>^ data, int uncompressedSize)
	{
		assertInit();
		return decompress(&ucl_nrv2e_decompress_safe_le32, data, uncompressedSize);
	}
}
