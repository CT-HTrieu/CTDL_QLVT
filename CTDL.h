#ifndef CAU_TRUC_DU_LIEU_H
#define CAU_TRUC_DU_LIEU_H
#include<iostream>
#include "mylib.h"
#include <string.h>
#include <fstream>
#include <ctime>
#include <cmath>
#include <ctype.h>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include<windows.h>
#include <sstream>
#include <iomanip>
#define MAXNV 500
#define MAXTK 100

using namespace std;
							// BAT DAU KHAI BAO
struct Date{
	int ngay;
	int thang;
	int nam;
};
///////////////danh sach CT_HoaDon lien ket don
struct CT_HOADON{
	char MaVT[11];
	int soluong;
	int dongia;
	double VAT;
};
struct NODECT_HOADON{
	CT_HOADON Data;
	NODECT_HOADON *pNext;
};
////////////////////Danh sach hoa don lien ket don
struct HOADON{
	char SoHD[21];
	Date date;
	char loai;
	NODECT_HOADON* fisrtCT;////////////con tro chi tiet hoa don
};
struct NODE_HOADON{
	HOADON data;
	NODE_HOADON *pNext;
};
typedef struct DS_HOADON DSHD;
//////////////////////////danh sach nhan vien mang con tro tuyen tinh
struct NHANVIEN{
	char MaNV[11];
	char Ho[21];
	char Ten[21];
	char Phai[4];
	NODE_HOADON* fisrtHD;///////////con tro danh sach hoa don
	
};
struct DSNV
{
	NHANVIEN *nv= new NHANVIEN[MAXNV+1];
	int soLuongNV;
};
DSNV dsnv;
/////////////////////////////Vat tu cay nhi phan tim kiem
struct VATTU{
	char MaVT[11];
	char TenVT[21];
	char DVT[10];
	int SoLuongTon;
};
struct NODE_VATTU{
	VATTU Data;
	NODE_VATTU *pLeft;
	NODE_VATTU *pRight;
};
typedef NODE_VATTU* Tree;
Tree t;
////////////////////////////
#endif
