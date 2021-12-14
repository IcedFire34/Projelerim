
namespace Direnc_Renk_Kodları
{
    partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        private void InitializeComponent()
        {
            this.cmb_1 = new System.Windows.Forms.ComboBox();
            this.cmb_2 = new System.Windows.Forms.ComboBox();
            this.cmb_3 = new System.Windows.Forms.ComboBox();
            this.cmb_4 = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.lbl_deger = new System.Windows.Forms.Label();
            this.lbl_tolerans = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // cmb_1
            // 
            this.cmb_1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_1.ForeColor = System.Drawing.SystemColors.WindowText;
            this.cmb_1.FormattingEnabled = true;
            this.cmb_1.Items.AddRange(new object[] {
            "Kahverengi",
            "Kırmızı",
            "Turuncu",
            "Sarı",
            "Yeşil",
            "Mavi",
            "Mor",
            "Gri",
            "Beyaz"});
            this.cmb_1.Location = new System.Drawing.Point(108, 12);
            this.cmb_1.Name = "cmb_1";
            this.cmb_1.Size = new System.Drawing.Size(108, 21);
            this.cmb_1.TabIndex = 0;
            this.cmb_1.SelectedIndexChanged += new System.EventHandler(this.cmb_1_SelectedIndexChanged);
            // 
            // cmb_2
            // 
            this.cmb_2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_2.FormattingEnabled = true;
            this.cmb_2.Items.AddRange(new object[] {
            "Siyah",
            "Kahverengi",
            "Kırmızı",
            "Turuncu",
            "Sarı",
            "Yeşil",
            "Mavi",
            "Mor",
            "Gri",
            "Beyaz"});
            this.cmb_2.Location = new System.Drawing.Point(108, 39);
            this.cmb_2.Name = "cmb_2";
            this.cmb_2.Size = new System.Drawing.Size(108, 21);
            this.cmb_2.TabIndex = 1;
            // 
            // cmb_3
            // 
            this.cmb_3.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_3.FormattingEnabled = true;
            this.cmb_3.Items.AddRange(new object[] {
            "Siyah",
            "Kahverengi",
            "Kırmızı",
            "Turuncu",
            "Sarı",
            "Yeşil",
            "Mavi",
            "Mor",
            "Gri",
            "Beyaz"});
            this.cmb_3.Location = new System.Drawing.Point(108, 66);
            this.cmb_3.Name = "cmb_3";
            this.cmb_3.Size = new System.Drawing.Size(108, 21);
            this.cmb_3.TabIndex = 2;
            // 
            // cmb_4
            // 
            this.cmb_4.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_4.FormattingEnabled = true;
            this.cmb_4.Items.AddRange(new object[] {
            "Kahverengi",
            "Kırmızı",
            "Turuncu",
            "Sarı",
            "Yeşil",
            "Mavi",
            "Mor",
            "Gri",
            "Altın",
            "Gümüş"});
            this.cmb_4.Location = new System.Drawing.Point(108, 93);
            this.cmb_4.Name = "cmb_4";
            this.cmb_4.Size = new System.Drawing.Size(108, 21);
            this.cmb_4.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(10, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(42, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "1.Renk";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(10, 42);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(42, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "2.Renk";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(10, 69);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(85, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "3.Renk (Çarpan)";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(10, 96);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(92, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "4.Renk (Tolerans)";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(222, 15);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(42, 13);
            this.label5.TabIndex = 8;
            this.label5.Text = "Deger :";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(225, 64);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(79, 23);
            this.button1.TabIndex = 9;
            this.button1.Text = "Hesapla";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // lbl_deger
            // 
            this.lbl_deger.AutoSize = true;
            this.lbl_deger.Location = new System.Drawing.Point(270, 15);
            this.lbl_deger.Name = "lbl_deger";
            this.lbl_deger.Size = new System.Drawing.Size(13, 13);
            this.lbl_deger.TabIndex = 10;
            this.lbl_deger.Text = "0";
            // 
            // lbl_tolerans
            // 
            this.lbl_tolerans.AutoSize = true;
            this.lbl_tolerans.Location = new System.Drawing.Point(282, 42);
            this.lbl_tolerans.Name = "lbl_tolerans";
            this.lbl_tolerans.Size = new System.Drawing.Size(13, 13);
            this.lbl_tolerans.TabIndex = 11;
            this.lbl_tolerans.Text = "0";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(222, 42);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(54, 13);
            this.label6.TabIndex = 12;
            this.label6.Text = "Tolerans :";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(397, 131);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.lbl_tolerans);
            this.Controls.Add(this.lbl_deger);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cmb_4);
            this.Controls.Add(this.cmb_3);
            this.Controls.Add(this.cmb_2);
            this.Controls.Add(this.cmb_1);
            this.ForeColor = System.Drawing.SystemColors.ControlText;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Direnc Renk Kodları";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cmb_1;
        private System.Windows.Forms.ComboBox cmb_2;
        private System.Windows.Forms.ComboBox cmb_3;
        private System.Windows.Forms.ComboBox cmb_4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label lbl_deger;
        private System.Windows.Forms.Label lbl_tolerans;
        private System.Windows.Forms.Label label6;
    }
}

