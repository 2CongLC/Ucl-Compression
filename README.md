# Ucl Compression
 Visual Basic .Net - Ucl Compression ( chỉ hỗ trợ .Netframe Work 4.8 trở xuống )
 * Thư viện dùng để nén và giải nén ucl Compression
 * Cách dùng :
```vbnet
 If OpenFileDialog1.ShowDialog = DialogResult.OK AndAlso SaveFileDialog1.ShowDialog = DialogResult.OK Then
     Dim buffer As Byte() = IO.File.ReadAllBytes(OpenFileDialog1.FileName)
     Dim compressed As Byte() = Ucl.NRV2B_99_Compress(buffer, 10)
     IO.File.WriteAllBytes(SaveFileDialog1.FileName, compressed)
     MessageBox.Show("Đã xong !")
 End If
 ```
 * Hoặc :
 ```vbnet
  Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click

     Dim buffer As Byte() = Encoding.ASCII.GetBytes("123abc")

     Dim compressed As Byte() = Ucl.NRV2B_99_Compress(buffer, 10)
     Dim uncompressed As Byte() = Ucl.NRV2B_99_Compress(compressed, buffer.Length)

     MessageBox.Show("Đã xong !")

 End Sub
 ```
 * Email : 2conglc.vn@gmail.com
 * © 2024