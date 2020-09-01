#include"Menu.h"
int main(){
	resizeConsole(900,600);
	//fullScreen();
	VatTuInit(t);
	dsnv.soLuongNV=0;
	VatTureadFromFile(t);
	NhanVienreadFromFile();
	HoaDonreadFromFile();
	MenuChinh();
	getch();
return 0;	
}

