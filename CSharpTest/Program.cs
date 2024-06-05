using System;
using System.Linq;
using System.Text;
using UclCompression;

namespace CSharpTest
{
	class Program
	{
		static void Main(string[] args)
		{
			var uncompressed = Encoding.UTF8.GetBytes("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque sagittis nunc eget sem elementum, id convallis mauris placerat. Pellentesque venenatis est a mauris interdum, vitae vestibulum nunc viverra. Sed volutpat odio vitae turpis facilisis, quis dignissim nisi tincidunt. Maecenas egestas molestie diam vel posuere. Praesent cursus est eu enim tincidunt facilisis. Proin gravida pharetra purus, porttitor egestas justo pellentesque sit amet. Cras nec iaculis arcu, at egestas enim. Aliquam aliquet mollis massa a iaculis. Sed vel eleifend justo, sit amet dictum massa.");
			var uncompressedString = string.Format("UnCompressed: {0};{1}", uncompressed.Length, BitConverter.ToString(uncompressed).Replace("-", ""));
			Console.WriteLine(uncompressedString);

			var compressed = Ucl.NRV2E_99_Compress(uncompressed, 10);
			var compressedString = string.Format("Compressed: {0};{1}", compressed.Length, BitConverter.ToString(compressed).Replace("-", ""));
			Console.WriteLine(compressedString);

			var decompressed = Ucl.NRV2E_Decompress_8(compressed, uncompressed.Length);
			var decompressedString = string.Format("DeCompressed: {0};{1}", decompressed.Length, BitConverter.ToString(decompressed).Replace("-", ""));
			Console.WriteLine(decompressedString);
			Console.WriteLine(Encoding.UTF8.GetString(decompressed));

			var mzip = "744;ff3c00750069003e006f0e6f007000bb74160e7f6e002000630073fd003d00220033db061a6500977630fd002e00350030f2276d5c309c7091df2fb7697ba6748afd7200660061efb6652bbe772f64fde2770073b7231f5e202e64fb8f31abef7817ef3200341b9279ec2f6b073225b7823800386b6fbd310237f01f775bbf025f361f6821d830b38e334bf937003100322e34d07372340735217c3700381527fc32003700329732c10033db15da36b3ef364e3904275d398873e437b838a3af67733300be351b6f5b8310b1b74c313517c52fd356d70a6b26ed6c006c1fde683674fd26650079be6b6300613f67677b327256f66500739f367b862f38c32e2f8bbb600092492492a0ff";
			var index = mzip.IndexOf(';');
			var uncompressedSize = int.Parse(mzip.Substring(0, index));
			var dataHex = mzip.Substring(index + 1);
			compressed = StringToByteArray(dataHex);
			decompressed = Ucl.NRV2E_Decompress_8(compressed, uncompressedSize);
			Console.WriteLine(Encoding.Unicode.GetString(decompressed));

			Console.ReadLine();
		}

		// https://stackoverflow.com/a/311179/1171898
		public static byte[] StringToByteArray(string hex)
		{
			var NumberChars = hex.Length;
			var bytes = new byte[NumberChars / 2];
			for (var i = 0; i < NumberChars; i += 2)
				bytes[i / 2] = Convert.ToByte(hex.Substring(i, 2), 16);

			return bytes;
		}
	}
}
