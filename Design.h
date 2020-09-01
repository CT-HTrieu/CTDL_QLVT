#ifndef DESIGN_H
#define DESIGN_H
#include"CTDL.h"
#define GRAY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15
                            // BAT DAU HAM GIAO DIEN
void HienThiDauNhay()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void fullScreen()
{
	system("mode con COLS=1000");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Bien cuc bo cho phan giao dien
int setMauChon = 32;
int setMauTiTle =10;
int setMauWarning =14;
int yMap = 3; // vi tri cho cac thanh phan trong bang thong ke va bang chi tiet
int xMap = 20;
void XoaKhungtongtien(int y)
{
	gotoxy(17,y);
	cout <<"                                                                                      ";
	gotoxy(17,y+1);
	cout <<"                                                                                      ";
	gotoxy(17,y+2);
	cout <<"                                                                                      ";
}
void veKhungTongGiaTien(int y)
{
	textcolor(10);
	gotoxy(18, y+1);
	cout << char(179);
	gotoxy(18,y);
	for(int i = 0; i < 67; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	gotoxy(43, y+1);
	cout << char(179);
	gotoxy(43, y);
	cout << char(194);
	gotoxy(18, y+2);
	cout << char(192);
	for(int i = 0; i < 66; i++)
	{
		cout << char(196);
	}
	gotoxy(43, y+2);
	cout << char(193);
	gotoxy(85, y+1);
	cout << char(179);
	gotoxy(85, y+2);
	cout << char(217);
	gotoxy(18, y);
	cout << char(218);
	gotoxy(20,y+1);
	cout << "Tong Gia Tien: ";
	textcolor(7);
}
void veKhungKhuyet1(int x, int y)
{
	gotoxy(18, y-1);
	cout << char(195);
	gotoxy(18, y);
	cout << char(179);
	for(int i = 0; i < 3; i++)
	{
		gotoxy(x + 15 + i*22, y);
		cout << char(179);
	}
	gotoxy(85, y);
	cout << char(179);
	gotoxy(x, y + 1);
	cout << char(195);
	for(int i = 0; i < 66; i++)
		cout << char(196);
	cout << char(180);
	gotoxy(85,y-1);
	cout << char(180);
	for(int i = 0; i < 3; i++)
	{
		gotoxy(x + 15 + i*22, y + 1);
		cout << char(197);
	}
	for(int i = 0; i < 3; i++)
	{
		gotoxy(x + 15 + i*22, y-1);
		cout << char(197);
	}
}
void veKhungKhuyet2(int x, int y)
{
	for(int i = 0; i < 3; i++)
	{
		gotoxy(x + 15 + i*22, y);
		cout << char(179);
	}
	gotoxy(85, y);
	cout << char(179);
	gotoxy(18, y);
	cout << char(179);
	gotoxy(x, y + 1);
	cout << char(192);
	for(int i = 0; i < 66; i++)
		cout << char(196);
	cout << char(217);
	for(int i = 0; i < 3; i++)
	{
		gotoxy(x + 15 + i*22, y + 1);
		cout << char(193);
	}
}

void veKhungHCN(int x, int y,string name, bool choose = false)
{
	if(choose	)
	{
	gotoxy(x,y);
	textcolor(14);
	for(int i=0;i<31;i++)
	{
		if(i==0)
			cout<<char(218);
		else if(i==30)
			cout<<char(191);
		else cout<<char(196);
	}
	gotoxy(x,y+1);
	cout<<char(179);
	gotoxy(x+30,y+1);
	cout<<char(179);
	gotoxy(x,y+2);
	for(int i=0;i<31;i++)
	{
		if(i==0)
			cout<<char(192);
		else if(i==30)
			cout<<char(217);
		else cout<<char(196);
	}
	
	}
	else
	{
		gotoxy(x,y);
	for(int i=0;i<31;i++)
	{
		if(i==0)
			cout<<char(218);
		else if(i==30)
			cout<<char(191);
		else cout<<char(196);
	}
	gotoxy(x,y+1);
	cout<<char(179);
	gotoxy(x+30,y+1);
	cout<<char(179);
	gotoxy(x,y+2);
	for(int i=0;i<31;i++)
	{
		if(i==0)
			cout<<char(192);
		else if(i==30)
			cout<<char(217);
		else cout<<char(196);
	}	
	}
	textcolor(7);
	gotoxy(x + 1 + (30 - name.length()) / 2, y + 1);
	if (choose)
	{
		textcolor(setMauChon);
		cout << name;
	}
	else
	{
		textcolor(7);
		cout << name;
	}
	textcolor(7);
}
// ham in button menu
int arrMenuVT[8] ={7,11,15,19,23,27,31};
int yMapMN = 40;
void veMenu(int *arr, string *arrTuKhoa, int n) //n: so chuc nang can show ra man hinh
{

	for (int i = 0; i < n; i++)
	{
		veKhungHCN(yMapMN, arr[i], arrTuKhoa[i]);
	}
}
int ytk = 0;
int arrToaDoBangThongKeHD[6] ={ 2,24,44,54,81,105};
void veKhungThongKeHD(string *arrTuKhoa)
{
	for (int i = 0; i < 5; i++)
	{
		gotoxy(arrToaDoBangThongKeHD[i] + 1 + ((arrToaDoBangThongKeHD[i + 1] - arrToaDoBangThongKeHD[i] - arrTuKhoa[i].length()) / 2), ytk + 7);
		textcolor(10);
		cout << arrTuKhoa[i];
		textcolor(7);

	}
	for (int j = ytk + 6; j <= 36; j++)
	{
		gotoxy(arrToaDoBangThongKeHD[0], j);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[5], j);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[1], j);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[2], j);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[3], j);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[4], j);
		cout << char(179);
	}
	for (int i = arrToaDoBangThongKeHD[0]; i <= arrToaDoBangThongKeHD[5]; i++)
	{
		gotoxy(i, ytk + 6);
		if (i == arrToaDoBangThongKeHD[1] || i == arrToaDoBangThongKeHD[2] || i == arrToaDoBangThongKeHD[3] || i == arrToaDoBangThongKeHD[4])
			cout << char(194);
		else if (i == arrToaDoBangThongKeHD[0])
		{
			cout << char(218);
		}
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << char(191);
		}

		else
		{
			cout << char(196);
		}
		gotoxy(i, ytk + 8);
		if (i == arrToaDoBangThongKeHD[1] || i == arrToaDoBangThongKeHD[2] || i == arrToaDoBangThongKeHD[3] || i == arrToaDoBangThongKeHD[4])
			cout << char(197);
		else if (i == arrToaDoBangThongKeHD[0])
		{
			cout << char(195);
		}
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << char(180);
		}
		else
		{
			cout << char(196);
		}
		gotoxy(i, ytk + 36);
		if (i == arrToaDoBangThongKeHD[1] || i == arrToaDoBangThongKeHD[2] || i == arrToaDoBangThongKeHD[3] || i == arrToaDoBangThongKeHD[4])
			cout << char(193);
		if (i == arrToaDoBangThongKeHD[0])
			cout << char(195);
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << char(180);
		}
		else
		{
			cout << char(196);
		}
		gotoxy(i, ytk+ 38);

		if (i == arrToaDoBangThongKeHD[0])
		{
			cout << (char)192;
		}
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << (char)217;
		}
		else
		{
			cout << (char)196;
		}
		gotoxy(arrToaDoBangThongKeHD[0], 37);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[5], 37);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[0] + 2, ytk + 37);
		cout << "<--Truoc ";
		gotoxy(arrToaDoBangThongKeHD[5] -7, ytk + 37);
		cout << "Sau-->";
	}
}
void YesNoSua(int x, int y, int ht)
{
	if(ht == 0)
	{
		textcolor(42);
		gotoxy(x-2, y);
		cout << " Co ";
		textcolor(11);
		gotoxy(x + 20, y);
		cout << "Khong";
	}
	else
	{
		textcolor(11);
		gotoxy(x-2, y);
		cout << " Co ";
		textcolor(42);
		gotoxy(x + 20, y);
		cout << "Khong";
	}
}
int YesNo(int x, int y)
{
	Nocursortype();
	textcolor(42);
	gotoxy(x-2, y);
	cout << " Co ";
	textcolor(11);
	gotoxy(x + 20, y);
	cout << "Khong";
	int i = 0;
	int c;
	while(int(c) != 13)
	{
		c = getch();
		if(c == 224)
		{
			c = getch();
			if(c == 75)
			{
				if(i == 0)
					i = 1;
				else i--;
				YesNoSua(44, 14, i);
			}
			else if(c == 77)
			{
				if(i == 0)
					i = 1;
				else i--;
				YesNoSua(44, 14, i);
			}
		}
	}
	textcolor(7);
	return (!i);
}
int veKhungYesNo(string str, int tt)
{
	textcolor(14);
	gotoxy(38, 9);
	cout << char(218);
	for(int i = 0; i < 33; i++)
		cout << char(196);
//--------------------		
	gotoxy(39, 10);
	for(int i = 0; i < 32; i++)
		cout << " ";
	gotoxy(39, 11);
	for(int i = 0; i < 32; i++)
		cout << " ";
	gotoxy(39, 12);
	for(int i = 0; i < 32; i++)
		cout << " ";
	gotoxy(39, 13);
	for(int i = 0; i < 32; i++)
		cout << " ";
	gotoxy(39, 14);
	for(int i = 0; i < 32; i++)
		cout << " ";

	for(int i = 0; i < 5; i++)
	{
		gotoxy(38, 10 + i);
		cout << char(179);
		gotoxy(71, 10 + i);
		cout << char(179);
	}
	gotoxy(38, 15);
	cout << char(192);
	for(int i = 0; i < 32; i++)
		cout << char(196);
	cout << char(217);
	gotoxy(38, 9);
	cout << char(218);
	gotoxy(71, 9);
	cout << char(191);
	textcolor(7);
	gotoxy(39, 10);
	cout << str;
	return YesNo(44, 14);
}
void XoaKhungYN()
{
	for(int i = 0; i < 7; i++)
	{
		gotoxy(38, 9+i);
		cout << "                                  ";
	}
}
void XoaKhungTB()
{
	for(int i = 0; i < 7; i++)
	{
		gotoxy(39, 10+i);
		cout << "                                  ";
	}
}
void veKhungTB(string str)
{
	Nocursortype();
	textcolor(14);
	for(int i = 0; i < 7; i++)
	{
		gotoxy(39, 10+i);
		cout << "                                 ";
	}
	gotoxy(39, 10);
	cout << char(218);
	for(int i = 0; i < 32; i++)
		cout << char(196);
	cout << char(191);
	for(int i = 0; i < 5; i++)
	{
		gotoxy(39, 11 + i);
		cout << char(179);
		gotoxy(72, 11 + i);
		cout << char(179);
	}
	gotoxy(39, 16);
	cout << char(192);
	for(int i = 0; i < 32; i++)
		cout << char(196);
	cout << char(217);
	textcolor(7);
	gotoxy(40, 12);
	cout << str;
	gotoxy(55, 15);
	textcolor(42);
	cout << "OK";
	textcolor(7);
	getch();
}
void veKhungCTKhuyet1(int x, int y)
{
	gotoxy(10, y-1);
	cout << char(195);
	gotoxy(10, y);
	cout << char(179);
	for(int i = 0; i < 4; i++)
	{
		if(i==0)
		{
			gotoxy(25, y);
			cout << char(179);
		}
		else
		{
			gotoxy(x + 10 + i*22, y);
			cout << char(179);
		}
		
	}
	gotoxy(95, y);
	cout << char(179);
	gotoxy(x, y + 1);
	cout << char(195);
	for(int i = 0; i < 84; i++)
		cout << char(196);
	cout << char(180);
	gotoxy(95,y-1);
	cout << char(180);
	for(int i = 0; i < 4; i++)
	{
		if(i==0)
		{
			gotoxy(x + 15 + i*22, y +1);
			cout << char(197);
			gotoxy(x + 15 + i*22, y -1);
			cout << char(197);
		}
		else
		{
			gotoxy(x + 10 + i*22, y + 1);
			cout << char(197);
			gotoxy(x + 10 + i*22, y -1);
			cout << char(197);
		}
		
	}
}
void veKhungCTKhuyet2(int x, int y)
{
	for(int i = 0; i < 4; i++)
	{
		if(i==0)
		{
			gotoxy(x +15 + i*22, y);
			cout << char(179);
		}
		else
		{
			
			gotoxy(x + 10 + i*22, y);
			cout << char(179);
		}
		
	}
	gotoxy(95, y);
	cout << char(179);
	gotoxy(10, y);
	cout << char(179);
	gotoxy(x, y + 1);
	cout << char(192);
	for(int i = 0; i < 84; i++)
		cout << char(196);
	cout << char(217);
	for(int i = 0; i < 4; i++)
	{
		if(i==0)
		{
			gotoxy(x + 15 + i*22, y + 1);
			cout << char(193);
		}
		else
		{
			gotoxy(x + 10 + i*22, y + 1);
			cout << char(193);
		}
		
	}
}
void veKhungKQTimKiem(string name1,string name2,string name3,string name4)
{
	gotoxy(18, 5);
	cout << char(179);
	gotoxy(18, 4);
	cout << char(218);
	
	for(int i = 0; i < 66; i++)
		cout << char(196);
	cout << char(191);
	gotoxy(33, 5);
	cout << char(179);
	gotoxy(33, 4);
	cout << char(194);
	gotoxy(18, 6);
	cout << char(195);
	
	for(int i = 0; i < 66; i++)
		cout << char(196);
		for(int i = 1; i < 3; i++)
		{
			gotoxy(33 + i*22, 4);
			cout << char(194);
			gotoxy(33 + i*22, 5);
			cout << char(179);
			gotoxy(33 + i*22, 6);
			cout << char(197);
		}
	gotoxy(33, 6);
	cout << char(197);
	gotoxy(85, 5);
	cout << char(179);
	gotoxy(85, 6);
	cout << char(180);
	int i = 0;
	textcolor(10);
	gotoxy(20, 5);
	cout << name1;
	gotoxy(42, 5);
	cout << name2;
	gotoxy(63, 5);
	cout << name3;
	gotoxy(79, 5);
	cout << name4;
	textcolor(7);
}
void veKhungCT()
{
	gotoxy(10, 6);
	cout << char(179);
	gotoxy(10, 5);
	cout << char(218);
	
	for(int i = 0; i < 84; i++)
		cout << char(196);
	cout << char(191);
	gotoxy(25, 6);
	cout << char(179);
	gotoxy(25, 5);
	cout << char(194);
	gotoxy(10, 7);
	cout << char(195);
	
	for(int i = 0; i < 84; i++)
		cout << char(196);
		for(int i = 1; i < 4; i++)
		{
			gotoxy(20 + i*22, 5);
			cout << char(194);
			gotoxy(20 + i*22, 6);
			cout << char(179);
			gotoxy(20 + i*22, 7);
			cout << char(197);
		}
	gotoxy(25, 7);
	cout << char(197);
	gotoxy(95, 6);
	cout << char(179);
	gotoxy(95, 7);
	cout << char(180);
	int i = 0;
	textcolor(setMauTiTle);
	gotoxy(12, 6);
	cout << "Ma Vat Tu";
	gotoxy(29, 6);
	cout << "Ten Vat Tu";
	gotoxy(50, 6);
	cout << "So luong";
	gotoxy(71, 6);
	cout << "Don Gia";
	gotoxy(89,6);
	cout << "VAT(%)";
	textcolor(7);
}
// Ham ve bang hien thi detail dung cho vat tu nhan vien
int arrToaDoBangChiTet[5] = { 15,35,56,82,94 };
void veKhungChiTiet(string *arrTenCot, int x =0)
{ 
	
	yMap = yMap + x;
	// in ten cot
	for(int i =0; i<4;i++)
	{
		gotoxy(arrToaDoBangChiTet[i]+1 +((arrToaDoBangChiTet[i+1] - arrToaDoBangChiTet[i] -arrTenCot[i].length())/2),yMap +1);
		textcolor(setMauTiTle);
		cout << arrTenCot[i];
		textcolor(7);
	}
	// ket thuc in ten cot
	
	// int thanh doc
	for(int j = yMap; j <=yMap+32;j++)
	{
		gotoxy(arrToaDoBangChiTet[0],j);
		cout << (char)179;
		gotoxy(arrToaDoBangChiTet[4],j);
		cout << (char)179;
		if(j<yMap+30)
		{
			gotoxy(arrToaDoBangChiTet[1], j);
			cout << (char)179;
			gotoxy(arrToaDoBangChiTet[2], j);
			cout << (char)179;
			gotoxy(arrToaDoBangChiTet[3], j);
			cout << (char)179;
		}
	}
	// ket thuc in thanh doc
	for(int i = arrToaDoBangChiTet[0]; i <= arrToaDoBangChiTet[4];i++)
	{
		// in cac khop noi giua thnah ngang va doc
		gotoxy(i,yMap);
		if(i==arrToaDoBangChiTet[1] || i == arrToaDoBangChiTet[2] || i == arrToaDoBangChiTet[3])
			cout << (char)194; 
		
		else if(i == arrToaDoBangChiTet[0])
			cout << (char)218; 
		
		else if(i == arrToaDoBangChiTet[4])
			cout << (char)191; 
		
		else cout << (char)196;
		
		// ket thuc
		
		// in thanh ngang tren
		gotoxy(i,yMap+2);
		if(i == arrToaDoBangChiTet[1] || i == arrToaDoBangChiTet[2] || i ==arrToaDoBangChiTet[3])
			cout << (char)197;
	
		else if(i == arrToaDoBangChiTet[0])
			cout << (char)195;
			
		else if(i == arrToaDoBangChiTet[4])
			cout << (char)180;
		else
			cout << (char)196;
		// in thanh ngang duoi
		gotoxy(i,yMap + 30);
		if (i == arrToaDoBangChiTet[1] || i == arrToaDoBangChiTet[2] || i == arrToaDoBangChiTet[3])
			cout << (char)193;
		else if (i == arrToaDoBangChiTet[0])
			cout << (char)195;

		else if (i == arrToaDoBangChiTet[4])
		{
			cout << char(180);
		}
		else
		{
			cout << (char)196;
		}
		gotoxy(i, yMap + 32);

		if (i == arrToaDoBangChiTet[0])
		{
			cout << (char)192;
		}
		else if (i == arrToaDoBangChiTet[4])
		{
			cout << (char)217;
		}
		else
		{
			cout << (char)196;
		}
		gotoxy(arrToaDoBangChiTet[0] + 1, yMap + 31);
		cout << " <--Truoc                                                              Sau-->";
	}
}
void drawText(int x, int y, string text, int color){
	textcolor(color);
	gotoxy(x,y);
	cout << text;
	textcolor(15);
}

void drawTitle_1(int START_X, int START_Y){
	drawText(START_X,START_Y,  "   ____  _ __      _________ ",RED);
	drawText(START_X,START_Y+1,"  / __ \\| |\\ \\    / /__   __|",RED);
	drawText(START_X,START_Y+2," | |  | | | \\ \\  / /   | |   ",BLUE);
	drawText(START_X,START_Y+3," | |  | | |  \\ \\/ /    | |   ",PINK);
	drawText(START_X,START_Y+4," | |__| | |___\\  /     | |   ",BLUE);
	drawText(START_X,START_Y+5,"  \\___\\_\\______\\/      |_|   ",RED);
}
#endif
