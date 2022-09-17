
Public Class Form1
    Dim Mtotal(50, 1) As Double
    Dim fila As Integer

    Dim i As Integer
    Dim j As Integer

    Dim sum As Double
    Dim mult As Double

    Dim A(1, 1) As Double
    Dim B(1, 1) As Double
    Dim C(1, 1) As Double
    Public D(50, 1) As Double
    Dim contador As Integer
    Dim z As Integer



    Private Sub PictureBox1_Click(sender As Object, e As EventArgs) Handles PictureBox1.Click
        End
    End Sub

    Private Sub Button7_Click(sender As Object, e As EventArgs) Handles Button7.Click
        contador = 0
        fila = 0
        If (TextBox1.Text = "") Or (TextBox2.Text = "") Or (TextBox3.Text = "") Or (TextBox4.Text = "") Or (TextBox5.Text = "") Or (TextBox6.Text = "") Or (TextBox7.Text = "") Or (TextBox8.Text = "") Or (TextBox9.Text = "") Or (TextBox10.Text = "") Then
            MessageBox.Show("Ingresar datos solicitados")

        Else
            Label8.Show()
            Label13.Show()
            Label14.Show()
            Label15.Show()
            Label12.Show()

            Button1.Show()
            Button2.Show()
            Button3.Show()
            Button4.Show()
            Button8.Show()
            Button9.Show()
            Button10.Show()
            Button11.Show()
            Rotar.Show()
            expa.Show()
            cor.Show()
            rot.Show()
            com.Show()
            Transformar.Show()
        End If

    End Sub

    Private Sub Rotar_Click(sender As Object, e As EventArgs) Handles Rotar.Click
        Mtotal(fila, 0) = Math.Cos(Val(rot.Text))
        Mtotal(fila, 1) = (-1) * Math.Sin(Val(rot.Text))
        Mtotal(fila + 1, 0) = Math.Sin(Val(rot.Text))
        Mtotal(fila + 1, 1) = Math.Cos(Val(rot.Text))
        fila = fila + 2
        contador = contador + 1

        expa.Text = ""
        cor.Text = ""
        rot.Text = ""
        com.Text = ""
    End Sub


    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Transformar.Click
        If contador = 1 Then
            D(0, 0) = Mtotal(0, 0)
            D(0, 1) = Mtotal(0, 1)
            D(1, 0) = Mtotal(1, 0)
            D(1, 1) = Mtotal(1, 1)
        Else
            z = 2
            For w = 0 To contador - 2
                For i = 0 To 1
                    For j = 0 To 1
                        sum = 0
                        For k = 0 To 1
                            sum = sum + D(i, k) * Mtotal(z + 2, i)
                        Next k
                        D(i, j) = sum
                    Next j
                    z = z + 2
                Next i

            Next w
            D(0, 0) = Mtotal(0, 0)
            D(0, 1) = Mtotal(0, 1)
            D(1, 0) = Mtotal(1, 0)
            D(1, 1) = Mtotal(1, 1)


            z = 0
            For w = 0 To contador - 2
                For i = 0 To 1
                    For j = 0 To 1
                        sum = 0
                        For k = 0 To 1
                            sum = sum + D(i, k) * Mtotal(z + 2, j)
                            z = z + 1
                        Next k
                        D(i, j) = sum
                        z = z - 2
                    Next j
                Next i
                z = z + 2
            Next w
        End If
        Form2.Show()

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Mtotal(fila, 0) = Val(expa.Text)
        Mtotal(fila, 1) = 0
        Mtotal(fila + 1, 0) = 0
        Mtotal(fila + 1, 1) = 1
        fila = fila + 2
        contador = contador + 1

        expa.Text = ""
        cor.Text = ""
        rot.Text = ""
        com.Text = ""
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Mtotal(fila, 0) = 1
        Mtotal(fila, 1) = 0
        Mtotal(fila + 1, 0) = 0
        Mtotal(fila + 1, 1) = Val(expa.Text)
        fila = fila + 2
        contador = contador + 1

        expa.Text = ""
        cor.Text = ""
        rot.Text = ""
        com.Text = ""
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        Mtotal(fila, 0) = Val(com.Text)
        Mtotal(fila, 1) = 0
        Mtotal(fila + 1, 0) = 0
        Mtotal(fila + 1, 1) = 1
        fila = fila + 2
        contador = contador + 1

        expa.Text = ""
        cor.Text = ""
        rot.Text = ""
        com.Text = ""
    End Sub

    Private Sub Button11_Click(sender As Object, e As EventArgs) Handles Button11.Click
        Mtotal(fila, 0) = 1
        Mtotal(fila, 1) = 0
        Mtotal(fila + 1, 0) = 0
        Mtotal(fila + 1, 1) = -1
        fila = fila + 2
        contador = contador + 1

        expa.Text = ""
        cor.Text = ""
        rot.Text = ""
        com.Text = ""
    End Sub

    Private Sub Button10_Click(sender As Object, e As EventArgs) Handles Button10.Click
        Mtotal(fila, 0) = -1
        Mtotal(fila, 1) = 0
        Mtotal(fila + 1, 0) = 0
        Mtotal(fila + 1, 1) = 1
        fila = fila + 2
        contador = contador + 1

        expa.Text = ""
        cor.Text = ""
        rot.Text = ""
        com.Text = ""
    End Sub

    Private Sub Button9_Click(sender As Object, e As EventArgs) Handles Button9.Click
        Mtotal(fila, 0) = 1
        Mtotal(fila, 1) = Val(cor.Text)
        Mtotal(fila + 1, 0) = 0
        Mtotal(fila + 1, 1) = 1
        fila = fila + 2
        contador = contador + 1

        expa.Text = ""
        cor.Text = ""
        rot.Text = ""
        com.Text = ""
    End Sub

    Private Sub Button8_Click(sender As Object, e As EventArgs) Handles Button8.Click
        Mtotal(fila, 0) = 1
        Mtotal(fila, 1) = 0
        Mtotal(fila + 1, 0) = Val(cor.Text)
        Mtotal(fila + 1, 1) = 1
        fila = fila + 2
        contador = contador + 1

        expa.Text = ""
        cor.Text = ""
        rot.Text = ""
        com.Text = ""
    End Sub
    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Mtotal(fila, 0) = 1
        Mtotal(fila, 1) = 0
        Mtotal(fila + 1, 0) = 0
        Mtotal(fila + 1, 1) = Val(com.Text)
        fila = fila + 2
        contador = contador + 1

        expa.Text = ""
        cor.Text = ""
        rot.Text = ""
        com.Text = ""
    End Sub
End Class
