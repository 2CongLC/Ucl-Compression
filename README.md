# Ucl Compression
 Visual Basic .Net - Ucl Compression ( chỉ hỗ trợ .Netframe Work 4.8 trở xuống )
 * Thư viện dùng để nén và giải nén ucl Compression
 * Cách dùng : chú ý đây là kiểu nén 1 chiều, muốn giải nén phải lấy chuỗi Length từ nguồn (target) thì mới giải nén được
```vbnet
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
 ```

* Email : 2conglc.vn@gmail.com
* © 2024