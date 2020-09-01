#ifndef MENU_H
#define MENU_H
#include"CTDL.h"
#include"VatTu.h"
#include"HoaDon.h"
#include"NhanVien.h"
void MenuVT()
{
	system("cls");
	string arrVT[5] ={"         Nhap vat tu         ","      Hieu chinh vat tu      ","          Xoa Vat tu         ","      In Danh Sach Vat Tu    "};
	veMenu(arrMenuVT,arrVT,4);
	int vitri=0;
	int key;
	while(true)
	{      
			Nocursortype();
			textcolor(setMauTiTle);
			gotoxy(28,33);
			cout << "UP/DOWN ARROW = Thay doi lua chon \tENTER = Chon \tESC = Thoat";
			veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri++;
					if(vitri==4)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						VatTuNhap();
						break;
					case 1:
						VatTuHieuChinh();
						break;
					case 2:
						VatTuXoa();
						break;
					case 3:
						VatTuQuanLyXuat();
						break;
				}
				veMenu(arrMenuVT,arrVT,4);
			}
			else if(key == 27)
			{
				VatTuwriteToFile(t);
				system("cls");
				return;
			}
		}
}
void MenuNV()
{
	system("cls");
	string arrVT[6] ={"        Nhap nhan vien       ","    Hieu Chinh Nhan Vien    ","         Xoa nhan vien       ","    In danh sach nhan vien   "};
	veMenu(arrMenuVT,arrVT,4);
	int vitri=0;
	int key;
	while(true)
	{
			textcolor(setMauTiTle);
			gotoxy(28,33);
			cout << "UP/DOWN ARROW = Thay doi lua chon \tENTER = Chon \tESC = Thoat";
			Nocursortype();
			veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri++;
					if(vitri==4)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						NhanVienNhap();
						break;
					case 1:
						NhanVienHieuChinh();
						break;
					case 2:
						NhanVienXoa();
						break;
					case 3:
						NhanVienQuanLyXuat();
						break;
				}
				veMenu(arrMenuVT,arrVT,4);
			}
			else if(key == 27)
			{
				system("cls");
				return;
			}
		}

}
void MenuHD()
{
	system("cls");
	string arrNameHD[6] ={"       Lap Hoa Don Nhap      ","       Lap Hoa Don Xuat      ","     In Hoa Don Theo SoHD    ","       Thong Ke Hoa Don      ","   10 VT Co Doanh Thu Nhat   ",};
	veMenu(arrMenuVT,arrNameHD,5);
	int vitri=0;
	int key;
	while(true)
	{
			Nocursortype();
			textcolor(setMauTiTle);
			gotoxy(28,33);
			cout << "UP/DOWN ARROW = Thay doi lua chon \tENTER = Chon \tESC = Thoat";
			veKhungHCN(yMapMN,arrMenuVT[vitri],arrNameHD[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrNameHD[vitri]);
					vitri++;
					if(vitri==5)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{	
					
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrNameHD[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				veKhungHCN(yMapMN,arrMenuVT[vitri],arrNameHD[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						HoaDonThem(0);
						break;
					case 1:
						HoaDonThem(1);
						break;
					case 2:
						HoaDonXuatThongTin();
						break;
					case 3:
						TKHDQuanLyXuat();
						break;
					case 4:
						DS10VTQuanLyXuat();
				}
				veMenu(arrMenuVT,arrNameHD,5);
			}
			else if(key == 27)
			{
				system("cls");
				return;
			}
		}
}
void MenuChinh()
{ 
	system("cls");
	string arrTuKhoa[4] = { "            Vat Tu           " ,"           Nhan vien         ","            Hoa don          ","             Thoat           "};
	veMenu(arrMenuVT,arrTuKhoa,4);
	int vitri =0;
	int key;
	int check =0;
	while(check ==0)
	{
			Nocursortype();
			drawTitle_1(40,25);
			textcolor(setMauTiTle);
			gotoxy(28,33);
			cout << "UP/DOWN ARROW = Thay doi lua chon \tENTER = CHhon \tESC = Thoat";
			veKhungHCN(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri]);
					vitri++;
					if(vitri==4)
					{
						vitri=0;
					}
				}
				else if(key == 72 and vitri>0)
				{  
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri]);
					vitri--;
					
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				veKhungHCN(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						MenuVT();
						break;
					case 1:
						MenuNV();
						break;
					case 2:
						MenuHD();
						break;
					case 3:
						if(veKhungYesNo("       Ban co muon thoat?",0))
						{
							system("cls");
							return;
						}
						else
						{
							system("cls");
							veMenu(arrMenuVT,arrTuKhoa,4);
							continue;
						}
						break;
				}
				veMenu(arrMenuVT,arrTuKhoa,4);
			}
			else if(key == 27)
			{
				if(veKhungYesNo("       Ban co muon thoat?",0))
				{
					system("cls");
					return;
				}
				else
				{
					system("cls");
					veMenu(arrMenuVT,arrTuKhoa,4);
					continue;
				}
			}
		}
}
#endif
