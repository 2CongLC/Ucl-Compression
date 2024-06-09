'https://www.clbgamesvn.com/diendan/showthread.php?t=314825
Imports System
Imports System.Collections
Imports System.IO
Imports System.IO.Compression
Imports System.Runtime
Imports System.Text
Imports System.Text.RegularExpressions
Imports UclCompression

Module Program

    
    Sub Main(args As String())

        Dim source As String = "Hello ,i am UCL Compression"

        Dim buffer As Byte() = Encoding.ASCII.GetBytes(source)
        Console.WriteLine("Data Length : {0}", buffer.Length)

        Dim compressed As Byte() = Ucl.NRV2B_99_Compress(buffer, 10)
        Console.WriteLine("Compressed Length : {0}", compressed.Length)

        Dim uncompressed As Byte() = Ucl.NRV2B_Decompress_8(compressed, buffer.Length)
        Console.WriteLine("UnCompressed Length : {0}", uncompressed.Length)


        Console.ReadLine()
    End Sub


End Module
