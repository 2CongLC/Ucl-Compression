﻿using System;
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
				string signature = new string(br.ReadChars(4)); // Offset = 0, Length = 4
                                int count = br.ReadInt32(); // Offset = 4, Length = 4
                                int index = br.ReadInt32(); // Offset = 8, Length = 4
                                int data = br.ReadInt32(); // Offset = 12, Length = 4
                                int crc32 = br.ReadInt32(); // Offset = 16, Length = 4
                                byte[] reserved = br.ReadBytes(12); //Offset = 20, Length = 12

                                Console.WriteLine("sig : {0}", signature);
                                Console.WriteLine("count : {0}", count);
                                Console.WriteLine("index : {0}", index);
                                Console.WriteLine("data : {0}", data);
                                Console.WriteLine("crc32 : {0}", crc32);

                                br.BaseStream.Seek(index, SeekOrigin.Begin); //br.BaseStream.Position = index
                                List<FileData> subfiles = new List<FileData>();
                                for (int i = 0; i < count; i++)
                                {
                                        subfiles.Add(new FileData());
                                }

                                string p = Path.GetDirectoryName(input) + "\\" + Path.GetFileNameWithoutExtension(input);
                                Directory.CreateDirectory(p);

                                foreach (FileData fd in subfiles)
                                {
                                       Console.WriteLine("File ID : {0} - File Offset : {1} - File Size : {2} - IsCompress : {3}", fd.id, fd.offset, fd.size, fd.isCompress);

                                       br.BaseStream.Position = fd.offset;

                                       using (BinaryWriter bw = new BinaryWriter(File.Create(p + "//" + fd.id)))
                                       {
                                           bw.Write(br.ReadBytes(fd.size));
                                       }
                                 }

                           Console.WriteLine("unpack done!!!"); 	
			}
			Console.ReadLine();	
		} // End Main

	} // End Class
} // End NameSpace
