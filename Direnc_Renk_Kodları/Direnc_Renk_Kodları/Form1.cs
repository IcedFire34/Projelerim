using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace Direnc_Renk_Kodları
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Dictionary<string, double> Renkler = new Dictionary<string, double>();
        Dictionary<string, double> Renkler_Tolerans = new Dictionary<string, double>();


        private void button1_Click(object sender, EventArgs e)
        {
            if (cmb_1.SelectedItem == null || cmb_2.SelectedItem == null || cmb_3.SelectedItem == null || cmb_4.SelectedItem == null) {
                MessageBox.Show("Renkleri bos gecmeyin !!!","HATA !");
            }
            else
            {
                double sonuc;
                string carpan = "";
                sonuc = (10 * Renkler[cmb_1.SelectedItem.ToString()] + Renkler[cmb_2.SelectedItem.ToString()]) * Math.Pow(10, Renkler[cmb_3.SelectedItem.ToString()]);
                if (sonuc / 1000000 >= 1)
                {
                    carpan = "M";
                    sonuc = sonuc / 1000000;
                }
                else if (sonuc / 1000 >= 1)
                {
                    carpan = "K";
                    sonuc = sonuc / 1000;
                }
                lbl_deger.Text = sonuc.ToString() + carpan;
                lbl_tolerans.Text = (sonuc * (1 - Renkler_Tolerans[cmb_4.SelectedItem.ToString()])).ToString() + carpan +" - " + (sonuc * (1 + Renkler_Tolerans[cmb_4.SelectedItem.ToString()])).ToString() + carpan;
            }

        }


        private void Form1_Load(object sender, EventArgs e)
        {
            Renkler.Add("Siyah", 0);
            Renkler.Add("Kahverengi", 1);
            Renkler.Add("Kırmızı", 2);
            Renkler.Add("Turuncu", 3);
            Renkler.Add("Sarı", 4);
            Renkler.Add("Yeşil", 5);
            Renkler.Add("Mavi", 6);
            Renkler.Add("Mor", 7);
            Renkler.Add("Gri", 8);
            Renkler.Add("Beyaz", 9);
            Renkler.Add("Altın", 10);
            Renkler.Add("Gümüş", 11);
      
            Renkler_Tolerans.Add("Kahverengi", 0.01);
            Renkler_Tolerans.Add("Kırmızı", 0.02);
            Renkler_Tolerans.Add("Turuncu", 0.03);
            Renkler_Tolerans.Add("Sarı", 0.04);
            Renkler_Tolerans.Add("Yeşil", 0.005);
            Renkler_Tolerans.Add("Mavi", 0.0025);
            Renkler_Tolerans.Add("Mor", 0.001);
            Renkler_Tolerans.Add("Gri", 0.0005);
            Renkler_Tolerans.Add("Altın", 0.05);
            Renkler_Tolerans.Add("Gümüş", 0.1);
        }

        private void cmb_1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cmb_1.SelectedItem == "Kırmızı")
            {
                cmb_1.BackColor = Color.Red;
            }
        }
    }
}
