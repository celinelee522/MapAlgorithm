using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 지도
{
    public partial class Form1 : Form
    {
        string [,] CellData;
        string RadioBtnSelected;

        int CellSize = 20;//셀의 크기를 지정해주는 변수
        int nCol, nRow;
        int ActualCamWidth, ActualCamHeight;//저 셀의 크기와 현실의 셀 크기가 얼마나 차이가 나는지 알아보기 위하여 위의 변수들을 규명해야 한다.
        int CamX, CamY;
        double WidthScale, HeightScale;

        Car car1 = new Car();

        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            SetMapLayout();

            //테스팅을 위해서 임시로 자동차 위치 설정
            CamX = 443;
            CamY = 300;
        }

        void ReceiveCarPosition()
        {
            //현재 차 위치를 일정 시간 기준으로 다운로드 받는다
        }

        void SendDataToCar()
        {
            //현재 위치를 기준으로 차가 어디로 이동해야 될지 방향성을 제시해준다.
        }

        void SetMapLayout()
        {
            MapLayout.ColumnCount = 40;
            MapLayout.RowCount = 25;

            nCol = MapLayout.ColumnCount;
            nRow = MapLayout.RowCount;

            MapLayout.ColumnHeadersVisible = false;
            MapLayout.RowHeadersVisible = false;
            MapLayout.AllowUserToResizeColumns = false;
            MapLayout.AllowUserToResizeRows = false;
            MapLayout.AllowUserToAddRows = false;//이건 내가 추가한거
            MapLayout.AllowDrop = false;//?? 솔직히 이게 뭔지는 잘 모르겠다.

            for (int nCol = 0; nCol < MapLayout.ColumnCount; nCol++)
            {
                MapLayout.Columns[nCol].Width = CellSize;
            }

            for (int nRow = 0; nRow < MapLayout.RowCount; nRow++)
            {
                MapLayout.Rows[nRow].Height = CellSize;
            }

            CellData = new string[nRow, nCol];//nRow :  행, nCol :  열
        }

        void SetCellData()
        {

        }

        void ApproximateGrid_Car(Car c)
        {
            //여기 코드 주의...

            int array_RowIndex = c.Y/CellSize;
            int array_ColIndex = c.X/CellSize;

            DataGridViewCell cell = this.MapLayout.Rows[array_RowIndex].Cells[array_ColIndex];

            CellData[array_RowIndex, array_ColIndex] = "CA";
            cell.Style.BackColor = Color.Blue;
        }

        void ConvertCoordinates_CamToGrid(Car c)
        {
            c.X = Convert.ToInt32(CamX / WidthScale);
            c.Y = Convert.ToInt32(CamY / HeightScale);

            //MessageBox.Show("c.X: " + c.X.ToString() + "   " + "c.Y: " + c.Y.ToString());
        }

        void ConvertCoordinates_GridToCam()
        {
            //이거 나중에!
        }

        private void BtnSetLength_Click(object sender, EventArgs e)
        {
            /*
             * 자동차 위치가 파이캠 기준의 좌표를 통해 전송될 것인데 우리가 그리드를 통해 보는 것은
             * 좌표가 파이캠이랑 다르다. 그래서 이 괴리감을 줄이기 위해서 축척을 구하는 것이다.
             * 
             * 축척을 통해서 파이캠 기준 좌표 -> 데이터그리드 기준 좌표로 변환
             * (여기서 좌표 변환을 하지는 않고 축척만 구하는 함수다)
             * */
            ActualCamWidth = Convert.ToInt32(TB_ActualWidth.Text);
            ActualCamHeight = Convert.ToInt32(TB_ActualHeight.Text);

            WidthScale = ActualCamWidth / Convert.ToDouble(CellSize * nCol);
            HeightScale = ActualCamHeight / Convert.ToDouble(CellSize * nRow);

            ConvertCoordinates_CamToGrid(car1);
            ApproximateGrid_Car(car1);

            MessageBox.Show("가로 축척: " + WidthScale.ToString()  + "     " + "세로 축척: " + HeightScale.ToString());
        }

        private void MapLayout_CellMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {

            /*
             * 셀을 어떤 종류들로 카테고라이즈화할지 생각해보자. 
             * 1. 길 : 회색 [RO]
             * 2. 빌딩 (길이 아닌 구역) : 초록색 [BU]
             * 3. 현재 자동차 위치 : 파란색 [CA]
             * 4. 길 위에 있는 장애물 (현재 이거는 뭐 다양한 변수들이 존재하겠지만 현재로써는 다른 자동차들을 빨간색으로 표시): 빨간색 [OB]
             * 5. 도착해야할 지점 : 노란색 [DE]
             * 6. 그 외 (예외처리) : 검정색 [EX]
             * 7. 데이터가 입력 안된 경우 : 흰색 [NU]
             * */

            DataGridViewCell cell = this.MapLayout.Rows[e.RowIndex].Cells[e.ColumnIndex];

            switch (RadioBtnSelected)
            {
                case "NU": //구현은 해놨지만 실질적으로 코드 흐름상 전혀 작동 안함
                    cell.Style.BackColor = Color.White;
                    break;
                case "RO":
                    cell.Style.BackColor = Color.Gray;
                    break;
                case "BU":
                    cell.Style.BackColor = Color.Green;
                    break;
                case "CA":
                    cell.Style.BackColor = Color.Blue;
                    break;
                case "OB":
                    cell.Style.BackColor = Color.Red;
                    break;
                case "DE":
                    cell.Style.BackColor = Color.Yellow;
                    break;
                case "EX":
                    cell.Style.BackColor = Color.Black;
                    break;
            }
            CellData[e.RowIndex, e.ColumnIndex] = RadioBtnSelected;
            //MessageBox.Show(CellData[e.RowIndex, e.ColumnIndex]);
        }

        private void RB_RO_Click(object sender, EventArgs e) // 길
        {
            RadioBtnSelected = "RO";
        }

        private void RB_BU_Click(object sender, EventArgs e) // 빌딩
        {
            RadioBtnSelected = "BU";
        }

        private void RB_CA_Click(object sender, EventArgs e) // 현재 차
        {
            RadioBtnSelected = "CA";
        }

        private void RB_OB_Click(object sender, EventArgs e) // 장애물 (길 위에 있는 장애물)
        {
            RadioBtnSelected = "OB";
        }

        private void RB_DE_Click(object sender, EventArgs e) // 도착지점
        {
            RadioBtnSelected = "DE";
        }

        private void RB_EX_Click(object sender, EventArgs e) // 기타 등등
        {
            RadioBtnSelected = "EX";
        }
    }
}
