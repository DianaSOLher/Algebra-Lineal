Public Class Form2
    Dim BMP As New Drawing.Bitmap(1200, 700)
    Dim GFX As Graphics = Graphics.FromImage(BMP)
    Dim V1x, V1y As Integer
    Dim V2x, V2y As Integer
    Dim V3x, V3y As Integer
    Dim V4x, V4y As Integer
    Dim V5x, V5y As Integer



    Private Sub PictureBox2_Click(sender As Object, e As EventArgs) Handles PictureBox2.Click
        End
    End Sub

    Dim TV1x, TV1y, TV2x, TV2y, TV3x, TV3y, TV4x, TV4y, TV5x, TV5y As Double

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        GFX.FillRectangle(Brushes.White, 0, 0, PictureBox1.Width, PictureBox1.Height)
        GFX.DrawLine(Pens.Black, 460, 0, 460, 2000)
        GFX.DrawLine(Pens.Black, 0, 315, 2000, 315)

        'GFX.DrawLine(Pens.Black, 350, 0, 350, 470)
        'GFX.DrawLine(Pens.Black, 0, 225, 700, 225)



        TV1x = 1 * ((V1x * Form1.D(0, 0)) + (V1y * Form1.D(0, 1)))
        TV1y = 1 * ((V1x * Form1.D(1, 0)) + (V1y * Form1.D(1, 1)))
        TV2x = 1 * ((V2x * Form1.D(0, 0)) + (V2y * Form1.D(0, 1)))
        TV2y = 1 * ((V2x * Form1.D(1, 0)) + (V2y * Form1.D(1, 1)))
        TV3x = 1 * ((V3x * Form1.D(0, 0)) + (V3y * Form1.D(0, 1)))
        TV3y = 1 * ((V3x * Form1.D(1, 0)) + (V3y * Form1.D(1, 1)))
        TV4x = 1 * ((V4x * Form1.D(0, 0)) + (V4y * Form1.D(0, 1)))
        TV4y = 1 * ((V4x * Form1.D(1, 0)) + (V4y * Form1.D(1, 1)))
        TV5x = 1 * ((V1x * Form1.D(0, 0)) + (V1y * Form1.D(0, 1)))
        TV5y = 1 * ((V5x * Form1.D(1, 0)) + (V5y * Form1.D(1, 1)))

        GFX.DrawString("TV0", SystemFonts.DefaultFont, Brushes.Red, 460, 315)
        GFX.DrawLine(Pens.Green, 460, 315, (460 + CInt(TV1x)), (315 - CInt(TV1y)))
        GFX.DrawString("TV1", SystemFonts.DefaultFont, Brushes.Red, (460 + TV1x), (315 - TV1y))
        GFX.DrawLine(Pens.Green, (460 + CInt(TV1x)), (315 - CInt(TV1y)), (460 + CInt(TV2x)), (315 - CInt(TV2y)))
        GFX.DrawString("TV2", SystemFonts.DefaultFont, Brushes.Red, (460 + TV2x), (315 - TV2y))
        GFX.DrawLine(Pens.Green, (460 + CInt(TV2x)), (315 - CInt(TV2y)), (460 + CInt(TV3x)), (315 - CInt(TV3y)))
        GFX.DrawString("TV3", SystemFonts.DefaultFont, Brushes.Red, (460 + TV3x), (315 - TV3y))
        GFX.DrawLine(Pens.Green, (460 + CInt(TV3x)), (315 - CInt(TV3y)), (460 + CInt(TV4x)), (315 - CInt(TV4y)))
        GFX.DrawString("TV4", SystemFonts.DefaultFont, Brushes.Red, (460 + TV4x), (315 - TV4y))
        GFX.DrawLine(Pens.Green, (460 + CInt(TV4x)), (315 - CInt(TV4y)), (460 + CInt(TV5x)), (315 - CInt(TV5y)))
        GFX.DrawString("TV5", SystemFonts.DefaultFont, Brushes.Red, (460 + TV5x), (315 - TV5y))
        GFX.DrawLine(Pens.Green, (460 + CInt(TV5x)), (315 - CInt(TV5y)), 460, 315)
        PictureBox1.Image = BMP

    End Sub

    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        GFX.FillRectangle(Brushes.White, 0, 0, PictureBox1.Width, PictureBox1.Height)
        GFX.DrawLine(Pens.Black, 460, 0, 460, 2000)
        GFX.DrawLine(Pens.Black, 0, 315, 2000, 315)
        PictureBox1.Image = BMP
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        GFX.FillRectangle(Brushes.White, 0, 0, PictureBox1.Width, PictureBox1.Height)
        GFX.DrawLine(Pens.Black, 460, 0, 460, 2000)
        GFX.DrawLine(Pens.Black, 0, 315, 2000, 315)
        'GFX.DrawLine(Pens.Black, 350, 0, 350, 470)
        ' GFX.DrawLine(Pens.Black, 0, 225, 700, 225)

        PictureBox1.Image = BMP
        V1x = 12 * Val(Form1.TextBox1.Text)
        V1y = 12 * Val(Form1.TextBox2.Text)
        V2x = 12 * Val(Form1.TextBox3.Text)
        V2y = 12 * Val(Form1.TextBox4.Text)
        V3x = 12 * Val(Form1.TextBox5.Text)
        V3y = 12 * Val(Form1.TextBox6.Text)
        V4x = 12 * Val(Form1.TextBox7.Text)
        V4y = 12 * Val(Form1.TextBox8.Text)
        V5x = 12 * Val(Form1.TextBox9.Text)
        V5y = 12 * Val(Form1.TextBox10.Text)

        'Verice de salida o V1 = 225,160
        GFX.DrawString("V0", SystemFonts.DefaultFont, Brushes.Red, 460, 315)
        GFX.DrawLine(Pens.Blue, 460, 315, (460 + V1x), (315 - V1y))
        GFX.DrawString("V1", SystemFonts.DefaultFont, Brushes.Red, (460 + V1x), (315 - V1y))
        GFX.DrawLine(Pens.Blue, (460 + V1x), (315 - V1y), (460 + V2x), (315 - V2y))
        GFX.DrawString("V2", SystemFonts.DefaultFont, Brushes.Red, (460 + V2x), (315 - V2y))
        GFX.DrawLine(Pens.Blue, (460 + V2x), (315 - V2y), (460 + V3x), (315 - V3y))
        GFX.DrawString("V3", SystemFonts.DefaultFont, Brushes.Red, (460 + V3x), (315 - V3y))
        GFX.DrawLine(Pens.Blue, (460 + V3x), (315 - V3y), (460 + V4x), (315 - V4y))
        GFX.DrawString("V4", SystemFonts.DefaultFont, Brushes.Red, (460 + V4x), (315 - V4y))
        GFX.DrawLine(Pens.Blue, (460 + V4x), (315 - V4y), (460 + V5x), (315 - V5y))
        GFX.DrawString("V5", SystemFonts.DefaultFont, Brushes.Red, (460 + V5x), (315 - V5y))
        GFX.DrawLine(Pens.Blue, (460 + V5x), (315 - V5y), 460, 315)
        PictureBox1.Image = BMP
    End Sub

End Class