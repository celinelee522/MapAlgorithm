namespace 지도
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.MapLayout = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.TB_ActualWidth = new System.Windows.Forms.TextBox();
            this.TB_ActualHeight = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.RB_RO = new System.Windows.Forms.RadioButton();
            this.RB_BU = new System.Windows.Forms.RadioButton();
            this.RB_CA = new System.Windows.Forms.RadioButton();
            this.RB_OB = new System.Windows.Forms.RadioButton();
            this.RB_DE = new System.Windows.Forms.RadioButton();
            this.RB_EX = new System.Windows.Forms.RadioButton();
            this.BtnDataSave = new System.Windows.Forms.Button();
            this.BtnReceiveData = new System.Windows.Forms.Button();
            this.BtnSetLength = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.MapLayout)).BeginInit();
            this.SuspendLayout();
            // 
            // MapLayout
            // 
            this.MapLayout.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.MapLayout.Location = new System.Drawing.Point(12, 12);
            this.MapLayout.Name = "MapLayout";
            this.MapLayout.RowTemplate.Height = 30;
            this.MapLayout.Size = new System.Drawing.Size(1407, 760);
            this.MapLayout.TabIndex = 0;
            this.MapLayout.CellMouseClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.MapLayout_CellMouseClick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 832);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(98, 18);
            this.label1.TabIndex = 1;
            this.label1.Text = "실제 너비: ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 868);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(98, 18);
            this.label2.TabIndex = 2;
            this.label2.Text = "실제 높이: ";
            // 
            // TB_ActualWidth
            // 
            this.TB_ActualWidth.Location = new System.Drawing.Point(117, 827);
            this.TB_ActualWidth.Name = "TB_ActualWidth";
            this.TB_ActualWidth.Size = new System.Drawing.Size(149, 28);
            this.TB_ActualWidth.TabIndex = 3;
            // 
            // TB_ActualHeight
            // 
            this.TB_ActualHeight.Location = new System.Drawing.Point(117, 868);
            this.TB_ActualHeight.Name = "TB_ActualHeight";
            this.TB_ActualHeight.Size = new System.Drawing.Size(149, 28);
            this.TB_ActualHeight.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(635, 792);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(86, 18);
            this.label3.TabIndex = 5;
            this.label3.Text = "색깔 선택";
            // 
            // RB_RO
            // 
            this.RB_RO.AutoSize = true;
            this.RB_RO.Location = new System.Drawing.Point(539, 830);
            this.RB_RO.Name = "RB_RO";
            this.RB_RO.Size = new System.Drawing.Size(99, 22);
            this.RB_RO.TabIndex = 6;
            this.RB_RO.TabStop = true;
            this.RB_RO.Text = "길 [RO]";
            this.RB_RO.UseVisualStyleBackColor = true;
            this.RB_RO.Click += new System.EventHandler(this.RB_RO_Click);
            // 
            // RB_BU
            // 
            this.RB_BU.AutoSize = true;
            this.RB_BU.Location = new System.Drawing.Point(539, 858);
            this.RB_BU.Name = "RB_BU";
            this.RB_BU.Size = new System.Drawing.Size(115, 22);
            this.RB_BU.TabIndex = 7;
            this.RB_BU.TabStop = true;
            this.RB_BU.Text = "빌딩 [BU]";
            this.RB_BU.UseVisualStyleBackColor = true;
            this.RB_BU.Click += new System.EventHandler(this.RB_BU_Click);
            // 
            // RB_CA
            // 
            this.RB_CA.AutoSize = true;
            this.RB_CA.Location = new System.Drawing.Point(539, 888);
            this.RB_CA.Name = "RB_CA";
            this.RB_CA.Size = new System.Drawing.Size(135, 22);
            this.RB_CA.TabIndex = 8;
            this.RB_CA.TabStop = true;
            this.RB_CA.Text = "자동차 [CA]";
            this.RB_CA.UseVisualStyleBackColor = true;
            this.RB_CA.Click += new System.EventHandler(this.RB_CA_Click);
            // 
            // RB_OB
            // 
            this.RB_OB.AutoSize = true;
            this.RB_OB.Location = new System.Drawing.Point(702, 830);
            this.RB_OB.Name = "RB_OB";
            this.RB_OB.Size = new System.Drawing.Size(135, 22);
            this.RB_OB.TabIndex = 9;
            this.RB_OB.TabStop = true;
            this.RB_OB.Text = "장애물 [OB]";
            this.RB_OB.UseVisualStyleBackColor = true;
            this.RB_OB.Click += new System.EventHandler(this.RB_OB_Click);
            // 
            // RB_DE
            // 
            this.RB_DE.AutoSize = true;
            this.RB_DE.Location = new System.Drawing.Point(702, 858);
            this.RB_DE.Name = "RB_DE";
            this.RB_DE.Size = new System.Drawing.Size(151, 22);
            this.RB_DE.TabIndex = 10;
            this.RB_DE.TabStop = true;
            this.RB_DE.Text = "도착지점 [DE]";
            this.RB_DE.UseVisualStyleBackColor = true;
            this.RB_DE.Click += new System.EventHandler(this.RB_DE_Click);
            // 
            // RB_EX
            // 
            this.RB_EX.AutoSize = true;
            this.RB_EX.Location = new System.Drawing.Point(702, 888);
            this.RB_EX.Name = "RB_EX";
            this.RB_EX.Size = new System.Drawing.Size(115, 22);
            this.RB_EX.TabIndex = 11;
            this.RB_EX.TabStop = true;
            this.RB_EX.Text = "기타 [EX]";
            this.RB_EX.UseVisualStyleBackColor = true;
            this.RB_EX.Click += new System.EventHandler(this.RB_EX_Click);
            // 
            // BtnDataSave
            // 
            this.BtnDataSave.Location = new System.Drawing.Point(1100, 792);
            this.BtnDataSave.Name = "BtnDataSave";
            this.BtnDataSave.Size = new System.Drawing.Size(319, 69);
            this.BtnDataSave.TabIndex = 12;
            this.BtnDataSave.Text = "데이터 저장하기";
            this.BtnDataSave.UseVisualStyleBackColor = true;
            // 
            // BtnReceiveData
            // 
            this.BtnReceiveData.Location = new System.Drawing.Point(1100, 868);
            this.BtnReceiveData.Name = "BtnReceiveData";
            this.BtnReceiveData.Size = new System.Drawing.Size(319, 69);
            this.BtnReceiveData.TabIndex = 13;
            this.BtnReceiveData.Text = "데이터 가져오기";
            this.BtnReceiveData.UseVisualStyleBackColor = true;
            // 
            // BtnSetLength
            // 
            this.BtnSetLength.Location = new System.Drawing.Point(298, 825);
            this.BtnSetLength.Name = "BtnSetLength";
            this.BtnSetLength.Size = new System.Drawing.Size(152, 71);
            this.BtnSetLength.TabIndex = 14;
            this.BtnSetLength.Text = "실제 길이 설정";
            this.BtnSetLength.UseVisualStyleBackColor = true;
            this.BtnSetLength.Click += new System.EventHandler(this.BtnSetLength_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(10, 910);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(506, 18);
            this.label4.TabIndex = 15;
            this.label4.Text = "(파이캠이 받아들이는 사진의 크기를 픽셀 단위로 입력하시오)";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1431, 1005);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.BtnSetLength);
            this.Controls.Add(this.BtnReceiveData);
            this.Controls.Add(this.BtnDataSave);
            this.Controls.Add(this.RB_EX);
            this.Controls.Add(this.RB_DE);
            this.Controls.Add(this.RB_OB);
            this.Controls.Add(this.RB_CA);
            this.Controls.Add(this.RB_BU);
            this.Controls.Add(this.RB_RO);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.TB_ActualHeight);
            this.Controls.Add(this.TB_ActualWidth);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.MapLayout);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.MapLayout)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView MapLayout;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox TB_ActualWidth;
        private System.Windows.Forms.TextBox TB_ActualHeight;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.RadioButton RB_RO;
        private System.Windows.Forms.RadioButton RB_BU;
        private System.Windows.Forms.RadioButton RB_CA;
        private System.Windows.Forms.RadioButton RB_OB;
        private System.Windows.Forms.RadioButton RB_DE;
        private System.Windows.Forms.RadioButton RB_EX;
        private System.Windows.Forms.Button BtnDataSave;
        private System.Windows.Forms.Button BtnReceiveData;
        private System.Windows.Forms.Button BtnSetLength;
        private System.Windows.Forms.Label label4;
    }
}

