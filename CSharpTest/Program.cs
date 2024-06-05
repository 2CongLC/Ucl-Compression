using System;
using System.Linq;
using System.Text;
using UclCompression;

namespace UnPack
{
	class Program
	{
		public static BinaryReader br;
                public static string input;
		static void Main(string[] args)
		{
			if (args.Length == 0)
                        {
                             Console.WriteLine("Tool UnPack - 2CongLC.vn :: 2024");
                        }
                      else
                        {
                             input = args[0];
                         }
			
		        if (File.Exists(input))
                        {
                             br = new BinaryReader(File.OpenRead(input));
                        
			
			}
			Console.ReadLine();
		
		}
	}
}
