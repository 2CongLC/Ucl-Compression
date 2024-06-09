Imports System
Imports System.IO
Imports System.Text
Imports UclCompression


Public Class Form1

    Private Sub LinkLabel1_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles LinkLabel1.LinkClicked
        Process.Start("https://2conglc-vn.blogspot.com/")
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click

        If OpenFileDialog1.ShowDialog = DialogResult.OK AndAlso SaveFileDialog1.ShowDialog = DialogResult.OK Then
            Dim buffer As Byte() = IO.File.ReadAllBytes(OpenFileDialog1.FileName)
            Dim compressed As Byte() = Ucl.NRV2B_99_Compress(buffer, 10)
            IO.File.WriteAllBytes(SaveFileDialog1.FileName, compressed)
            MessageBox.Show("Đã xong !")
        End If
    End Sub
    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click

        If OpenFileDialog1.ShowDialog = DialogResult.OK AndAlso SaveFileDialog1.ShowDialog = DialogResult.OK Then
            Dim buffer As Byte() = IO.File.ReadAllBytes(OpenFileDialog1.FileName)
            Dim compressed As Byte() = Ucl.NRV2D_99_Compress(buffer, 10)
            IO.File.WriteAllBytes(SaveFileDialog1.FileName, compressed)
            MessageBox.Show("Đã xong !")
        End If
    End Sub


    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click

        If OpenFileDialog1.ShowDialog = DialogResult.OK AndAlso SaveFileDialog1.ShowDialog = DialogResult.OK Then
            Dim buffer As Byte() = IO.File.ReadAllBytes(OpenFileDialog1.FileName)
            Dim compressed As Byte() = Ucl.NRV2E_99_Compress(buffer, 10)
            IO.File.WriteAllBytes(SaveFileDialog1.FileName, compressed)
            MessageBox.Show("Đã xong !")
        End If
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click

        Dim buffer As Byte() = Encoding.ASCII.GetBytes("123abc")

        Dim compressed As Byte() = Ucl.NRV2B_99_Compress(buffer, 10)
        Dim uncompressed As Byte() = Ucl.NRV2B_Decompress_8(compressed, buffer.Length)

        MessageBox.Show("Đã xong !")

    End Sub
End Class
