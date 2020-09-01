#ifndef HOA_DON_H
#define HOA_DON_H
#include"CTDL.h"
#include"Design.h"
#include"NhanVien.h"
#include"Backend.h"
void HoaDonwritetoFile();
NODE_HOADON * HoaDonSearch(string soHD);
NODECT_HOADON* CT_HoaDonGetNode(CT_HOADON data)
{
	
	NODECT_HOADON* p = new NODECT_HOADON;
	p->pNext = NULL;
	p->Data = data;
	return p;
}
NODECT_HOADON *CT_HoaDonAddTail(NODECT_HOADON *dsct,NODECT_HOADON* p)//////chen dau
{
	if(dsct == NULL)
	{
		p->pNext = NULL;
		return p;
	}
	else
	{
		dsct->pNext = CT_HoaDonAddTail(dsct->pNext, p);
	}
}
void CT_HoaDOnNhapNhap(string MSHD)
{ 
	int vitri,key;
	string maVT,sl,VAT,dongia;
	int sls,dg;
	double vat;
	int y;
	int flag =1;
	int exit =0;
	int dong =0;
	int vtr;
	string mangKiemtra[MAXTK];
	int nArr =0;
	int tong=0;
	NODE_HOADON *q = HoaDonSearch(MSHD);
	NODE_VATTU *p;
	veKhungCT();
	veKhungCTKhuyet1(10,8);
	veKhungCTKhuyet2(10,8);
	gotoxy(12,8);
	while(exit ==0)
	{
		while(!kbhit())
		{
			key =getch();
			if(flag ==1)
			{
				vitri =12+maVT.size();
			}
			else if(flag ==2)
			{
				vitri=45+sl.size();
			}
			else if(flag ==3)
			{
				vitri = 67+dongia.size();
			}
			else if(flag ==4)
			{
				vitri =88+VAT.size();
			}
			
			y=8+dong*2;
			if(key ==0)
			{
				key =getch();
			}
			else if(key ==27)
			{
				if(veKhungYesNo("       Ban co muon thoat?",0))
				{
					if(q->data.fisrtCT == NULL)
					{
						delete q;
					}
					else
					{
						HoaDonwritetoFile();
					}
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					gotoxy(vitri,y);
					HienThiDauNhay();
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
			{
				if(flag ==1&&maVT.size() <10)
				{
					gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					maVT.insert(maVT.end(),1,char(key));
				}
				else if(flag == 2&&(key >= 48&& key <=57) &&sl.size()<10)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sl.insert(sl.end(),1,char(key));
					sls = atoi(sl.c_str());
				}
				else if(flag == 3&&(key >= 48&& key <=57)&&dongia.size()<10)
				{
					gotoxy(vitri,y);
					cout << (char)key;
					dongia.insert(dongia.end(),1,char(key));
					dg = atoi(dongia.c_str());
				}
				else if(flag == 4&&(key >= 48&& key <=57))
				{
					gotoxy(vitri,y);
					cout << (char)key;
					VAT.insert(VAT.end(),1,char(key));
					vat = atoi(VAT.c_str());
				}
			}
			else if(key == 13||key ==9)
			{
				 if(flag ==1)
				{
					if(VatTukiemTraTrungMa(t,maVT) == NULL)
					{
						while(!kbhit())
						{
							Canhbao("Ma vat tu khong ton tai.Xin nhap lai!!",34,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(maVT.size() ==0)
					{
						while(!kbhit())
						{
							Canhbao("Chua nhap ma vat tu",40,1);
						}
						do
						{
							int key1 =getch();
						}while(key!=13||key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						bool ktrtrung = false;
						for(int j =0; j <nArr+1;j++)
						{
							if(mangKiemtra[j]==maVT)
							{
								ktrtrung = true;
								break;
							}
						}
						if(ktrtrung == true)
						{
							while(!kbhit())
								{
									Canhbao("Trong mot hoa don khong duoc nhap trung vat tu.Xin nhap lai!!",34,1);
								}
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(12+maVT.size(),y);
						}
						else
						{
							p = VatTuSearch(t,maVT);
							gotoxy(31,y);
							cout << p->Data.TenVT;
							gotoxy(58,y);
							cout << p->Data.DVT;
							gotoxy(45,y);
							flag=2;
						}
						
					}
				}
				else if(flag ==2)
				{
					if(sl.size() == 0)
					{
						while(!kbhit())
						{
							Canhbao("Chua nhap so luong cho hoa don",40,1);
						}
						do
						{
							int key1 =getch();
						}while(key!=13||key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(67,y);
						flag=3;
					}
				}
				else if(flag==3)
				{
					if(dongia.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Chua nhap so luong cho hoa don",40,1);
						}
						do
						{
							int key1 =getch();
						}while(key!=13||key!=9);
						gotoxy(vitri,y);	
					}
					else
					{
						gotoxy(88,y);
						flag=4;
					}
				}
				else if(flag ==4)
				{
					if(VAT.size()==0)
					{
						vat=0;
						
						gotoxy(88,y);
						cout << vat;
						p->Data.SoLuongTon+=sls;
						VatTuwriteToFile(t);
						CT_HOADON cthd;
						if(nArr < MAXTK)
						{
							mangKiemtra[nArr++] = maVT;
						}
						strcpy(cthd.MaVT,maVT.c_str());
						cthd.soluong = sls;
						cthd.dongia = dg;
						cthd.VAT =vat;
						int kq = sls*dg+(vat/100)*dg;
						tong+=kq;
						q->data.fisrtCT=CT_HoaDonAddTail(q->data.fisrtCT,CT_HoaDonGetNode(cthd));
						sl="";
						maVT="";
						dongia ="";
						VAT="";
						dong++;
						XoaKhungtongtien(12+(dong-1)*2);
						veKhungTongGiaTien(12+dong*2);
						textcolor(setMauWarning);
						gotoxy(55,13+dong*2);
						cout << to_Currency(tong);
						gotoxy(80,13+dong*2);
						cout << "VND";
						textcolor(7);
						veKhungCTKhuyet1(10,8+dong*2);
						veKhungCTKhuyet2(10,8+dong*2);
					}
					else
					{
						p->Data.SoLuongTon+=sls;
						VatTuwriteToFile(t);
						CT_HOADON cthd;
						strcpy(cthd.MaVT,maVT.c_str());
						cthd.soluong = sls;
						cthd.dongia = dg;
						cthd.VAT =vat;
						if(nArr < MAXTK)
						{
							mangKiemtra[nArr++] = maVT;
						}
						int kq = sls*dg+(vat/100)*dg;
						tong+=kq;
						q->data.fisrtCT=CT_HoaDonAddTail(q->data.fisrtCT,CT_HoaDonGetNode(cthd));
						sl="";
						maVT="";
						dongia ="";
						VAT="";
						dong++;
						XoaKhungtongtien(12+(dong-1)*2);
						veKhungTongGiaTien(12+dong*2);
						textcolor(setMauWarning);
						gotoxy(55,13+dong*2);
						cout << to_Currency(tong);
						gotoxy(80,13+dong*2);
						cout << "VND";
						textcolor(7);
						veKhungCTKhuyet1(10,8+dong*2);
						veKhungCTKhuyet2(10,8+dong*2);
						gotoxy(12,8+dong*2);
						flag=1;
						exit=1;
						break;
					}
				}
			}
			else if(key ==8)
			{
				if(flag==1 && maVT.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					maVT.erase(maVT.end()-1);
				}
				else if(flag ==2 && sl.size() >=0)
				{
					if(sl.size()==0)
					{
						gotoxy(31,y);
						cout << "           ";
						gotoxy(12+maVT.size(),y);
						flag=1;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sl.erase(sl.end()-1);
						sls =atoi(sl.c_str());
					}
				}
				else if(flag ==3 && dongia.size() >=0)
				{
					if(dongia.size() ==0)
					{
						gotoxy(57,y);
						cout << "      ";
						gotoxy(45+sl.size(),y);
						flag=2;
						
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						dongia.erase(dongia.end()-1);
						dg=atoi(dongia.c_str());
					}
				}
				else if(flag ==4 && VAT.size()>=0)
				{
					if(VAT.size()==0)
					{
						gotoxy(67+dongia.size(),y);
						flag=3;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						VAT.erase(VAT.end()-1);
						vat=atoi(VAT.c_str());
					}
				}
			}
		else 
			key=getch();	
		}
	}
}
NODECT_HOADON *CT_HoaDonSearch(string maVT);
void CT_HoaDonXuatNhap(string MSHD)
{ 
	int vitri,key;
	string maVT="",sl="",dongia="";
	int sls,vat,dg;
	int y;
	int flag =1;
	int exit =0;
	int dong =0;
	int vtr;
	int tong =0;
	NODE_VATTU *p;
	int gianhap;
	NODE_HOADON* q = HoaDonSearch(MSHD);
	NODECT_HOADON *k;
	veKhungCT();
	veKhungCTKhuyet1(10,8);
	veKhungCTKhuyet2(10,8);
	gotoxy(12,8);
	while(exit ==0)
	{
		while(!kbhit())
		{
			
			if(flag ==1)
			{
				vitri =12+maVT.size();
			}
			else if(flag ==2)
			{
				vitri=45+sl.size();
			}
			else if(flag ==3)
			{
				vitri = 67+dongia.size();
			}
			y=8+dong*2;
			key =getch();
			if(key ==0)
			{
				key =getch();
			}
			else if(key ==27)
			{
				if(veKhungYesNo("       Ban co muon thoat?",0))
				{
					if(q->data.fisrtCT == NULL)
					{
						delete q;
					}
					else
					{
						HoaDonwritetoFile();
					}
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					gotoxy(vitri,y);
					HienThiDauNhay();
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
			{
				if(flag ==1&&maVT.size() <10)
				{
					gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					maVT.insert(maVT.end(),1,char(key));
				}
				else if(flag == 2&&(key >= 48&& key <=57))
				{
					gotoxy(vitri,y);
					cout << (char)key;
					sl.insert(sl.end(),1,char(key));
					sls = atoi(sl.c_str());
				}
				else if(flag == 3&&(key >= 48&& key <=57))
				{
					gotoxy(vitri,y);
					cout << (char)key;
					dongia.insert(dongia.end(),1,char(key));
					dg = atoi(dongia.c_str());
				}
			}
			else if(key == 13||key ==9)
			{
				 if(flag ==1)
				{
					if(VatTukiemTraTrungMa(t,maVT) == NULL)
					{
						while(!kbhit())
						{
							Canhbao("Ma vat tu khong ton tai.Xin nhap lai!!",34,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(maVT.size() ==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!!",34,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						
						k = CT_HoaDonSearch(maVT);
						p = VatTuSearch(t,maVT);
						gotoxy(31,y);
						cout << p->Data.TenVT;
						gotoxy(58,y);
						cout << p->Data.DVT;
						gotoxy(45,y);
						flag=2;
					}
				}
				else if(flag ==2)
				{
					if(sl.size() ==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!!",34,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(p->Data.SoLuongTon < sls)
					{
						while(!kbhit())
						{
							Canhbao("So luong trong kho khong du de xuat < "+to_String(p->Data.SoLuongTon)+" >",34,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(67,y);
						flag=3;
					}
				}
				else if(flag==3)
				{   
					if(dongia.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Chua nhap so luong cho hoa don",40,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);	
					}
					
					else if(k->Data.dongia > dg)
					{
						while(!kbhit())
						{
							Canhbao("Gia xuat phai lon hon gia nhap < "+to_String(k->Data.dongia)+" >",40,1);
						} 
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						vat =k->Data.VAT;
						gotoxy(90,y);
						cout << vat;
						p->Data.SoLuongTon-=sls;
						VatTuwriteToFile(t);
						CT_HOADON cthd;
						strcpy(cthd.MaVT,maVT.c_str());
						cthd.soluong = sls;
						cthd.dongia = dg;
						cthd.VAT =vat;
						int kq = sls*dg+(vat/100)*dg;
						tong+=kq;
						q->data.fisrtCT=CT_HoaDonAddTail(q->data.fisrtCT,CT_HoaDonGetNode(cthd));
						sl="";
						maVT="";
						dongia ="";
						dong++;
						XoaKhungtongtien(12+(dong-1)*2);
						veKhungTongGiaTien(12+dong*2);
						textcolor(setMauWarning);
						gotoxy(55,13+dong*2);
						cout << tong;
						gotoxy(80,13+dong*2);
						cout << "VND";
						textcolor(7);
						veKhungCTKhuyet1(10,8+dong*2);
						veKhungCTKhuyet2(10,8+dong*2);
						gotoxy(12,8+dong*2);
						flag=1;
					}
				}
				
			}
			else if(key ==8)
			{
				if(flag==1 && maVT.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					maVT.erase(maVT.end()-1);
				}
				else if(flag ==2 && sl.size() >=0)
				{
					if(sl.size()==0)
					{
						gotoxy(31,y);
						cout << "           ";
						gotoxy(12+maVT.size(),y);
						flag=1;
						
						
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sl.erase(sl.end()-1);
						sls =atoi(sl.c_str());
					}
				}
				else if(flag ==3 && dongia.size() >=0)
				{
					if(dongia.size()==0)
					{
						gotoxy(45+sl.size(),y);
						flag=2;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						dongia.erase(dongia.end()-1);
						dg=atoi(dongia.c_str());
					}
				}
			}
		else key = getch();	
		}
	}
}
void CT_HoaDonXuat(CT_HOADON data,int stt)
{
	gotoxy(20,3+yMap +stt*2);
	cout << data.MaVT;
	gotoxy(36+((21-to_String(data.soluong).size())/2),3+yMap +stt*2);
	cout << data.soluong;
	gotoxy(60,3+yMap +stt*2);
	cout << to_Currency(data.dongia);
	gotoxy(77,3+yMap + stt*2);
	cout << "VND";
	gotoxy(74+((26-to_String(data.VAT).size())/2),3+yMap +stt*2);
	cout << data.VAT;
}
								// KET THUC CHI TIET HOA DON
								// BAT DAU HOA DON
								
NODE_HOADON* HoaDonGetnode(HOADON data)
{
	NODE_HOADON* p = new NODE_HOADON;
	if(p==NULL)
		return NULL;
	p->data = data;
	p->pNext = NULL;
   
	return p;
}
NODE_HOADON *HoaDonAddTail(NODE_HOADON *dshd,NODE_HOADON *p)
{
	if(dshd == NULL)
	{
		p->pNext = NULL;
		return p;
	}
	else
		dshd->pNext = HoaDonAddTail(dshd->pNext, p);
}
NODE_HOADON* HoaDonSearch(string soHD)
{
	NODE_HOADON *q;
	for(int i = 0; i < dsnv.soLuongNV+1; i++)
	{
		NODE_HOADON *p = dsnv.nv[i].fisrtHD;
		while(p != NULL)
		{
			if(strcmp(p->data.SoHD, soHD.c_str()) == 0)
			{
				q = p;
				return q;
			}
			p = p->pNext;
		}
	}
	return NULL;
}
int LayThoiGianSoSanh(Date &a, Date &b)
{
	if(a.nam > b.nam)
	{
		return 1;
	}
	else if(a.nam < b.nam)
	{
		return -1;
	}
	else
	{
		if(a.thang > b.thang)
		{
			return 1;
		}
		else if(a.thang < b.thang)
		{
			return -1;
		}
		else
		{
			if(a.ngay > b.ngay)
			{
				return 1;
			}
			else if(a.ngay < b.ngay)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}
void HoaDonNhapNgay(Date &date,int &exit)
{
	string sngay=to_String(date.ngay) ;
	string sthang=to_String(date.thang);
	string snam =to_String(date.nam);
	int key, check =0,vitri;
	int flag =3;
	int y =3;
	while(check ==0)
	{
		while(!kbhit())
		{
			key = getch();
			if(flag==1)
			{
				vitri = 47+sngay.length();
			}
			else if(flag==2)
			{
				vitri = 56+sthang.length();
			}
			else if(flag==3)
			{
				vitri = 63+snam.length();
			}
			if(key ==27)
			{
				check=2;
				exit =1;
				break;
			}
			else if(key >= 48 && key <=57)
			{
				if(flag ==1 && sngay.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sngay.insert(sngay.end(),1,char(key));
					date.ngay = atoi(sngay.c_str());
				}
				else if(flag ==2&&sthang.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sthang.insert(sthang.end(),1,char(key));
					date.thang = atoi(sthang.c_str());
				}
				else if(flag ==3 &&snam.length() <4)
				{
					gotoxy(vitri,y);
					cout << char(key);
					snam.insert(snam.end(),1,char(key));
					date.nam = atoi(snam.c_str());
				}
			}
			else if(key ==13 || key ==9)
			{
				if(flag ==1)
				{
					if(date.ngay < 0 || date.ngay > 31)
					{
						while(!kbhit())
						 Canhbao("Nhap sai ngay.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
						
					}
					else if(date.ngay ==0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else{
						
						gotoxy(56+sthang.length(),y);
						flag =2;
					}
				}
				else if(flag ==2)
				{
					if(date.thang < 0 || date.thang >12)
					{
						
						while(!kbhit())
						 Canhbao("Nhap sai thang.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(date.thang == 0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						
						if(date.thang ==2)
						{
							if(date.ngay >28 )
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(47+sngay.length(),y);
								flag =1;
							}
							else
							{
								gotoxy(63+snam.length(),y);
								flag =3;
							}
						}
						else if(date.thang ==4 || date.thang ==6 || date.thang ==9 || date.thang ==11)
						{
							if(date.ngay >30)
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(47+sngay.length(),y);
								flag =1;
							}
							else
							{
								gotoxy(63,y);
								flag =3;
							}
						}
						else 
						{
							gotoxy(63+snam.length(),y);
							flag =3;
						}
						
					}
				}
				else if(flag ==3)
				{
					if(date.nam == 0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						
						if(date.nam%4==0)
						{
							if(date.thang ==2)
							{
								if(date.ngay >29)
								{
									while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
									do{
										int key1 = getch();
									}while(key!=13&&key!=9);
									gotoxy(47+sngay.length(),y);
									flag =1;
								}
								else
								{
									check =1;
									break;
								}
							}
							else
							{
								check =1;
								break;
							}
						}
						else
						{
							check =1;
							break;
						}
						
					}
				}
			}
			else if(key == 8)
			{
				if(flag ==1 && sngay.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					sngay.erase(sngay.end()-1);
					date.ngay = atoi(sngay.c_str());
				}
				else if(flag ==2 && sthang.size() >=0)
				{
					if(vitri ==vitri-sthang.size())
					{
						gotoxy(47+sngay.size(),y);
						flag =1;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sthang.erase(sthang.end()-1);
						date.thang = atoi(sthang.c_str());
					}
					
				}
				else if(flag == 3&& snam.size() >=0)
				{
					if(vitri ==vitri-snam.size())
					{				
						gotoxy(56+sthang.size(),y);
						flag =2;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						snam.erase(snam.size()-1);
						date.nam = atoi(snam.c_str());
					}
				}
			}
		else key = getch();	
		}
	}
	if(check ==1) return;
}
NODECT_HOADON *CT_HoaDonSearch(string maVT)
{
	for(int i =0;i < dsnv.soLuongNV+1; i++)
	{
		for(NODE_HOADON *p=dsnv.nv[i].fisrtHD;p!=NULL;p=p->pNext)
		{
			if(p->data.loai == 'N')
			{
				for(NODECT_HOADON *q = p->data.fisrtCT;q!=NULL;q=q->pNext)
				{
					if(strcmp(q->Data.MaVT,maVT.c_str())==0)
					{
						return q;
					}
				}	
			}	
		}	
	}	
}
void HoaDonNhap(int tinhieu)
{
	system("cls");
	textcolor(setMauTiTle);
	gotoxy(44, 2);
	if(tinhieu ==0)
	{
		cout << "HOA DON NHAP VAT TU";
	}
	else
	{
		cout << "HOA DON XUAT VAT TU";
	}
	textcolor(7);
	gotoxy(60, 4);
	cout << "So Hoa Don: ";
	gotoxy(26,4);
	cout << "Ma Nhan Vien: ";
	textcolor(7);
	HOADON hd;
	int vtr;
	Date date;
	LayThoiGian(date.ngay, date.thang,date.nam);
	string MSHD, MaNV;
	int key,flag=1;
	bool loop =0;
	gotoxy(42, 3);
	cout << "Ngay   "<< " Thang   "<< " Nam     ";
	gotoxy(47,3);
	cout << date.ngay;
	gotoxy(56,3);
	cout << date.thang;
	gotoxy(63,3);
	cout << date.nam;
	int exit =0;
	HoaDonNhapNgay(date,exit);
	if(exit ==1)
	{
		system("cls");
		return;
	}
	gotoxy(40,4);
		while(loop==0)
		{
			while(!kbhit())
			{
				int vitri;
				key = getch();
				if(flag==1) vitri =40+MaNV.length();
				else if(flag == 2) vitri = 72 +MSHD.length();
				if (key == 113){
					clrscr();
					NhanVienQuanLyXuat();
					
				}
				else if(key  == 27)
				{
					if(veKhungYesNo("       Ban co muon thoat?",0))
					{
						system("cls");
						return;
					}
					else
					{
						XoaKhungYN();
						gotoxy(vitri,4);
				    	HienThiDauNhay();
					}
				}
				if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
				{
					if(flag == 1 && MaNV.size()<10)
					{
						gotoxy(vitri,4);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						MaNV.insert(MaNV.end(),1,(char)key);
					}
					else if(flag ==2 && MSHD.size() < 20)
					{
						gotoxy(vitri,4);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						MSHD.insert(MSHD.end(),1,(char)key);
						
					}	
				}
				else if(key ==13 || key ==9)
				{
					if(flag==1)
					{
						if(MaNV.size() ==0)
						{
							while(!kbhit())
							{
								Canhbao("Khong duoc de trong!.Xin nhap lai!!",30,1);
							}
							do{
								int key1 = getch();
							}while(key!=13&&key!=9);
							gotoxy(vitri,8);
						}
						else if(NhanVienKiemTraTrungMa(MaNV)==true)
						{
							while(!kbhit())
								{
									Canhbao("Ma "+MaNV+" Khong ton tai!.Xin nhap lai!!",30,1);
								}
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(vitri,4);
						}
						else
						{
							gotoxy(72,4);
							flag =2;
						}
						
					}
					else if(flag == 2)
					{
						if(MSHD.length() > 20)
						{
							while(!kbhit())
							{
								Canhbao("So hop dong khong qua 20 ki tu!.Xin nhap lai!!",30,1);
							}
							do{
								int key1 = getch();
							}while(key!=13&&key!=9);
							gotoxy(vitri,4);
						}
						else if(HoaDonSearch(MSHD) != NULL)
						{
							while(!kbhit())
							{
								Canhbao("So hop dong "+MSHD+" da ton tai!.Xin nhap lai!!",30,1);
							}
							do{
								int key1 = getch();
							}while(key!=13&&key!=9);
							gotoxy(vitri,4);						
						}
						
						else
						{
							strcpy(hd.SoHD,MSHD.c_str());
							if(tinhieu ==0)
							{
								hd.loai='N';
							}
							else if(tinhieu == 1)
							{
								hd.loai='X';
							}
							hd.fisrtCT=NULL;
							hd.date = date;
							for(int i =1;i<dsnv.soLuongNV;i++)
							{
								if(strcmp(dsnv.nv[i].MaNV,MaNV.c_str())==0)
								{
									vtr =i;
									break;
								}
							}
							loop =1;
							break;
						}	
						}
					}
				else if(key == 8)
				{
						if(flag == 1&& MaNV.size() >0)
						{
							vitri--;
							gotoxy(vitri,4);
							cout << " ";
							gotoxy(vitri,4);
							MaNV.erase(MaNV.end()-1);
						}
						if (MaNV.size()==0)
							HoaDonNhap(0);
						else if(flag == 2&&MSHD.size()>=0)
						{
							if(MSHD.size() == 0)
							{
								gotoxy(40+MaNV.size(),4);
								flag =1;
							}
							else
							{
								vitri--;
								gotoxy(vitri,4);
								cout << " ";
								gotoxy(vitri,4);
								MSHD.erase(MSHD.end()-1);
							}
						}		
				}
			else key = getch();	
			}
	}
	dsnv.nv[vtr].fisrtHD=HoaDonAddTail(dsnv.nv[vtr].fisrtHD,HoaDonGetnode(hd));
	if(tinhieu ==0)
	{
		CT_HoaDOnNhapNhap(MSHD);
	}
	else if(tinhieu == 1)
	{
		CT_HoaDonXuatNhap(MSHD);
	}
}
	
void HoaDonThem(int tinhieu)
{
	if(dsnv.soLuongNV == 0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	if(t == NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
	HoaDonNhap(tinhieu);
	
}
int NhanVienkiemtraXoa(string MNV)
{
	for(int i = 0; i < dsnv.soLuongNV+1; i++)
	{
		if(strcmp(dsnv.nv[i].MaNV,MNV.c_str())==0)
		{
			if(dsnv.nv[i].fisrtHD != NULL)
			{
				return 1;
			}
		}
		
	}
	return 0;
}
// xUat thong tin hoa don theo so hoa don nhap vao
int HoaDonKiemtraTonTai()
{
	for(int i = 0; i < dsnv.soLuongNV+1; i++)
	{
		if(dsnv.nv[i].fisrtHD != NULL)
		{
			return 1;
		}
	}
	return 0;
}
void HoaDonXuatThongTin()
{
	string SoHD;
	string arrTukhoa[]={"So HD","Ngay Lap","Loai"};
	int key,vitri,check =0,stt=0;
	if(HoaDonKiemtraTonTai()== 0)
	{
		veKhungTB("         Khong co hoa don");
		system("cls");
		return;
	}
		system("cls");
		gotoxy(36,3);
		cout <<"So Hoa Don: ";
		int y =3;
		NODE_HOADON *q;
		gotoxy(48,y);
		while(check ==0)
		{
			while(!kbhit())
			{
				vitri = 48+SoHD.length();
				key =getch();
				if(key ==27)
				{
					if(veKhungYesNo("      Ban co muon thoat khong?",0))
					{
						system("cls");
						return;
					}
					else
					{
						XoaKhungYN();
						gotoxy(vitri,y);
				    	HienThiDauNhay();
					}
				}
				else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
				{
					if(SoHD.length()  <20)
					{
						gotoxy(vitri,y);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						SoHD.insert(SoHD.end(),1,(char)key);
				   }
				}
				else if(key == 13 || key ==9)
				{
					if(HoaDonSearch(SoHD)==NULL)
					{
						while(!kbhit())
							Canhbao("Khong tim thay so hoa don"+SoHD+".Xin kiem tra lai!!",30,1);
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						q= HoaDonSearch(SoHD);
						textcolor(setMauTiTle);
						gotoxy(46,2);
						cout << "THONG TIN HOA DON";
						textcolor(7);
						gotoxy(36,3);
						cout <<"                                                          ";
						gotoxy(20,3);
						cout<<"So Hoa Don: ";
						gotoxy(32,3);
						cout << q->data.SoHD;
						gotoxy(56,3);
						cout << "Ngay Lap: ";
						gotoxy(66,3);
						cout << q->data.date.ngay << " / " << q->data.date.thang << " / " << q->data.date.nam;
						gotoxy(82,3);
						cout << "Loai: ";
						gotoxy(88,3);
						if(q->data.loai =='N')
						{
							cout << "Nhap";
						}
						else if(q->data.loai=='X')
						{
							cout << "Xuat";
						}
						NODECT_HOADON *p;
						string arr[] ={"Ma Vat Tu","So Luong","Don Gia","%VAT"};
						veKhungChiTiet(arr,1);
						for(p = q->data.fisrtCT;p!=NULL;p=p->pNext)
						{
							Nocursortype();
							CT_HoaDonXuat(p->Data,stt);
							stt++;
						}
					}
				}
				else if(key == 8 && SoHD.length() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout << " ";
					gotoxy(vitri,y);
					SoHD.erase(SoHD.end()-1);
				}
			else key = getch();	
			}
		}
}
int CT_HoaDonDem(char soHD[21])
{
	int dem;
	for(int i =0; i < dsnv.soLuongNV+1;i++)
	{
		for(NODE_HOADON *p = dsnv.nv[i].fisrtHD; p!=NULL; p = p->pNext)
		{
			for(NODECT_HOADON *q = p->data.fisrtCT; q!=NULL; q = q->pNext)
			{
				if(strcmp(p->data.SoHD,soHD)==0)
				{
					dem++;
				}
			}
		}
	}
	return dem;
}
void HoaDonwritetoFile()
{
	const char* path ="HOADON.txt";
	ofstream ofs(path,ios::out);
	for(int i =0; i < dsnv.soLuongNV;i++)
	{
		if(dsnv.nv[i].fisrtHD != NULL)
		{
			for(NODE_HOADON *p = dsnv.nv[i].fisrtHD; p!=NULL; p = p->pNext)
			{
				ofs << dsnv.nv[i].MaNV << endl;
				ofs << p->data.SoHD << ',' << p->data.date.ngay << ',' << p->data.date.thang << ',' << p->data.date.nam << ',' << p->data.loai << endl;
				ofs << CT_HoaDonDem(p->data.SoHD) << endl;
				for(NODECT_HOADON *q = p->data.fisrtCT; q!=NULL; q = q->pNext)
				{	
					ofs << q->Data.MaVT << '-' << q->Data.soluong << '-' << q->Data.dongia << '-' << q->Data.VAT << endl;
				}
			}
		}
	}
	ofs.close();
}
void HoaDonreadFromFile()
{
	const char* path ="HOADON.txt";
	ifstream ifs(path,ios::in);
	string MNV,Ho,Ten,Phai,soHD,MVT;
	char loai;
	string ngay,thang,nam,soluong,dongia,vat;
	int vtr;
	HOADON hd;
	NODE_HOADON *q;
	CT_HOADON cthd;
	int n;
	if(ifs.fail())
	{
		return;
	}
	while(!ifs.eof())
	{
		getline(ifs,MNV);
		for(int i =0;i<dsnv.soLuongNV;i++)
		{
			if(strcmp(dsnv.nv[i].MaNV,MNV.c_str())==0)
			{
				vtr =i;
				break;
			}
		}
		getline(ifs,soHD,',');
		getline(ifs,ngay,',');
		getline(ifs,thang,',');
		getline(ifs,nam,',');
		ifs.get(loai);
		strcpy(hd.SoHD,soHD.c_str());
		hd.loai = loai;
		hd.date.ngay = atoi(ngay.c_str());
		hd.date.thang = atoi(thang.c_str());
		hd.date.nam = atoi(nam.c_str());
		hd.fisrtCT = NULL;
		dsnv.nv[vtr].fisrtHD = HoaDonAddTail(dsnv.nv[vtr].fisrtHD,HoaDonGetnode(hd));
		q = HoaDonSearch(soHD);
		ifs >> n;
		ifs.ignore();
		for(int i = 0;i<n;i++)
		{
			getline(ifs,MVT,'-');
			getline(ifs,soluong,'-');
			getline(ifs,dongia,'-');
			getline(ifs,vat);
			strcpy(cthd.MaVT,MVT.c_str());
			cthd.soluong = atoi(soluong.c_str());
			cthd.dongia = atoi(dongia.c_str());
			cthd.VAT = atoi(vat.c_str());
			q->data.fisrtCT = CT_HoaDonAddTail(q->data.fisrtCT,CT_HoaDonGetNode(cthd));
		}
	}
	ifs.close(); 
}
								// END
								// THONG KE HOA DON
struct THONGKE
{
	char SoHD[21];
	Date date;
	char Loai;
	string HoTenNV;
	int donGia;
};
struct DS_THONGKE
{
	THONGKE *tk= new THONGKE[MAXTK];
	int soTK;
};
void TKHDXuat(THONGKE tk, int stt)
{
	int y =9+stt*2;
	gotoxy(arrToaDoBangThongKeHD[0]+2,y);
	cout << tk.SoHD;
	gotoxy(arrToaDoBangThongKeHD[1]+3,y);
	cout << tk.date.ngay << "/"<<tk.date.thang << "/" <<tk.date.nam;
	gotoxy(arrToaDoBangThongKeHD[2]+3,y);
	if(tk.Loai=='N')
	{
		cout << "Nhap";
	}
	else if(tk.Loai=='X')
	{
		cout <<"Xuat";
	}
	gotoxy(arrToaDoBangThongKeHD[3]+2,y);
	cout << tk.HoTenNV;
	gotoxy(arrToaDoBangThongKeHD[4]+2,y);
	cout << to_Currency(tk.donGia);
	gotoxy(arrToaDoBangThongKeHD[5]-4,y);
	cout << "VND";
}

void TKHDXuatDS(DS_THONGKE &l, int vitri=0)
{
	Nocursortype();
	int stt=0;
	for(int i = vitri;i < l.soTK;i++)
	{
		TKHDXuat(l.tk[i],stt);
		stt++;
		if(stt==14)
		{
			break;
		}
	}
}
void ContentRemoveTK()
{
	int y;
	for(int i =0; i< 14;i++)
	{
		y =9+i*2;
		gotoxy(arrToaDoBangThongKeHD[0]+1,y);
		cout << "                     ";
		gotoxy(arrToaDoBangThongKeHD[1]+1,y);
		cout << "                   ";
		gotoxy(arrToaDoBangThongKeHD[2]+1,y);
		cout << "         ";
		gotoxy(arrToaDoBangThongKeHD[3]+1,y);
		cout << "                         ";
		gotoxy(arrToaDoBangThongKeHD[4]+1,y);
		cout << "                       ";
	}
}
void TKHDXuLyDS(DS_THONGKE &dstk,Date &first, Date &final)
{
	int checkDate1,checkDate2;
	int donGia =0,kq;
	string name;
	for(int i =0;i < dsnv.soLuongNV;i++)
	{
		for(NODE_HOADON* p = dsnv.nv[i].fisrtHD; p!= NULL; p= p->pNext)
		{
			name ="";
			checkDate1 = LayThoiGianSoSanh(p->data.date,first);
			checkDate2 = LayThoiGianSoSanh(p->data.date,final);
			if((checkDate1 ==1|| checkDate1 ==0) && (checkDate2 == -1|| checkDate2 == 0))
			{
				name +=dsnv.nv[i].Ho;
				name+=" ";
				name+=dsnv.nv[i].Ten;
				strcpy(dstk.tk[dstk.soTK].SoHD, p->data.SoHD);
				dstk.tk[dstk.soTK].date = p->data.date;
				dstk.tk[dstk.soTK].Loai=p->data.loai;
				dstk.tk[dstk.soTK].HoTenNV = name;
				for(NODECT_HOADON* q =p->data.fisrtCT; q!=NULL; q=q->pNext)
				{
					kq = q->Data.soluong*q->Data.dongia+(q->Data.VAT/100)*q->Data.dongia;
					donGia +=kq;
				}
				dstk.tk[dstk.soTK].donGia = donGia;
				dstk.soTK++;
			}
		}
	}
}
void TKHDNgayNhap(Date &first, Date &final,int& exit)
{
	int xMapNgay =36,xMapThang =41,xMapNam=46;
	int xMapNgay2 = 69,xMapThang2=74,xMapNam2=79;
nhaplai:
	int flag =1;
	int check =0;
	int y=3;
	int vitri;
	int key,lengh,kq;
	string sngay,sthang,snam,sngay2,sthang2,snam2;
	gotoxy(36,y);
	while(check == 0)
	{
		
		while(!kbhit())
		{
			if(flag ==1){
				vitri =xMapNgay+ sngay.length();
			}
			else if(flag ==2)
			{
				vitri =xMapThang+sthang.length();
			}
			else if(flag ==3)
			{
				vitri=xMapNam+snam.length();
			}
			if(flag ==4){
				vitri =xMapNgay2+ sngay2.length();
			}
			else if(flag ==5)
			{
				vitri =xMapThang2+sthang2.length();
			}
			else if(flag ==6)
			{
				vitri=xMapNam2+snam2.length();
			}
			key = getch();
			if(key == 27)
			{
				exit =1;
				check =1;
				break;
			}
			else if(key >= 48 && key <= 57)
			{
				if(flag ==1 && sngay.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sngay.insert(sngay.end(),1,char(key));
					first.ngay = atoi(sngay.c_str());
				}
				else if(flag == 2&& sthang.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sthang.insert(sthang.end(),1,char(key));
					first.thang = atoi(sthang.c_str());
				}
				else if(flag ==3 && snam.length() <4)
				{
						gotoxy(vitri,y);
					cout << char(key);
					snam.insert(snam.end(),1,char(key));
					first.nam = atoi(snam.c_str());
				}
				else if(flag ==4&&sngay2.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sngay2.insert(sngay2.end(),1,char(key));
					final.ngay = atoi(sngay2.c_str());
				}
				else if(flag == 5&&sthang2.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sthang2.insert(sthang2.end(),1,char(key));
					final.thang = atoi(sthang2.c_str());
				}
				else if(flag ==6&&snam2.length() <4)
				{
					gotoxy(vitri,y);
					cout << char(key);
					snam2.insert(snam2.end(),1,char(key));
					final.nam = atoi(snam2.c_str());
				}
			}
			else if(key == 13 || key ==9)
			{
				if(flag ==1)
				{
					if(first.ngay < 0 || first.ngay > 31)
					{
						while(!kbhit())
						 Canhbao("Nhap sai ngay.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
						
					}
					else if(first.ngay ==0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else{
						gotoxy(xMapThang,y);
						flag =2;
					}
				}
				else if(flag ==2)
				{
					if(first.thang == 0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(first.thang < 0 || first.thang >12)
					{
						
						while(!kbhit())
						 Canhbao("Nhap sai thang.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					
					else
					{
						
						if(first.thang ==2)
						{
							if(first.ngay >28 )
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(xMapNgay+sngay.length(),y);
								flag =1;
							}
							else
							{
								gotoxy(xMapNam,y);
								flag =3;
							}
						}
						else if(first.thang ==4 || first.thang ==6 || first.thang ==9 || first.thang ==11)
						{
							if(first.ngay >30)
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(xMapNgay+sngay.length(),y);
								flag =1;
							}
							else
							{
								gotoxy(xMapNam,y);
								flag =3;
							}
						}
						else 
						{
							gotoxy(xMapNam,y);
							flag =3;
						}
						
					}
				}
				else if(flag ==3)
				{
					if(first.nam < 2000 || first.nam > LayThoiGianNam())
					{
						
						while(!kbhit())
						 Canhbao("Nhap sai nam, nam phai be hon "+to_String(LayThoiGianNam())+".Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						
						if(first.nam%4==0)
						{
							if(first.thang ==2)
							{
								if(first.ngay >29)
								{
									while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
									do{
										int key1 = getch();
									}while(key!=13&&key!=9);
									gotoxy(xMapNgay+sngay.length(),y);
									flag =1;
								}
								else
								{
									gotoxy(xMapNgay2,y);
									flag =4;
								}
							}
							else
							{
								gotoxy(xMapNgay2,y);
								flag =4;
							}
						}
						else
						{
							gotoxy(xMapNgay2,y);
							flag =4;
						}
						
					}
				}
				else if(flag ==6)
				{
						
					if(final.nam == 0)
					{
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(final.nam < first.nam || final.nam > LayThoiGianNam())
					{
						while(!kbhit())
						 Canhbao("Nhap sai nam,nam phai be hon "+to_String(LayThoiGianNam())+".Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						check =1;
						break;
					}
				}
				else if(flag == 4)
				{
					if(final.ngay == 0)
					{
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(final.ngay < 0 || final.ngay >31)
					{
						while(!kbhit())
						 Canhbao("Nhap sai ngay.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
						
					}
					 
					else{
						gotoxy(xMapThang2,y);
						flag =5;
					}
				}
				else if(flag =5)
				{
					 if(final.thang ==0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(final.thang <0 || final.thang >12)
					{
						while(!kbhit())
						 Canhbao("Nhap sai thang.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					
					else
					{
						if(final.thang == 2)
						{
							if(final.ngay >28 )
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(xMapNgay2+sngay2.length(),y);
								flag =4;
							}
							else
							{
								gotoxy(xMapNam2,y);
								flag =6;
							}
						}
						else if(final.thang ==4 || final.thang ==6 || final.thang ==9 || final.thang ==11)
						{
							if(final.ngay >30)
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(xMapNgay2+sngay2.length(),y);
								flag =4;
							}
							else
							{
								gotoxy(xMapNam2,y);
								flag =6;
							}
						}
						else
						{
							gotoxy(xMapNam2,y);
							flag =6;
						}
					}
				}
			}
			else if(key == 8)
			{
				if(flag ==1 && sngay.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					sngay.erase(sngay.end()-1);
					first.ngay = atoi(sngay.c_str());
				}
				else if(flag ==2 && sthang.size() >=0)
				{
					if(sthang.size() == 0)
					{
						gotoxy(36+sngay.size(),y);
						flag=1;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sthang.erase(sthang.end()-1);
						first.thang = atoi(sthang.c_str());
					}
					
				}
				else if(flag == 3&& snam.size() >=0)
				{
					if(snam.size()==0)
					{
						gotoxy(41+sthang.size(),y);
						flag =2;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						snam.erase(snam.size()-1);
						first.nam = atoi(snam.c_str());
					}
					
				}
				if(flag ==4 && sngay2.size() >=0)
				{
					if(sngay2.size() ==0)
					{
						gotoxy(46+snam.size(),y);
						flag =3;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sngay2.erase(sngay2.end()-1);
						final.ngay = atoi(sngay2.c_str());
					}
				
				}
				else if(flag ==5 && sthang2.size() >=0)
				{
					if(sthang2.size() ==0)
					{
						gotoxy(69+sngay2.size(),y);
						flag =4;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sthang2.erase(sthang2.end()-1);
						final.thang = atoi(sthang2.c_str());
					}
					
				}
				else if(flag == 6&& snam2.size() >=0)
				{
					if(snam2.size() ==0)
					{
						gotoxy(74+sthang2.size(),y);
						flag =5;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						snam2.erase(snam2.size()-1);
						final.nam = atoi(snam2.c_str());
					}
					
				}
			}
		else key = getch();	
		
		}
	}
}
void TKHDQuanLyXuat()
{
	DS_THONGKE dstk;
	string arrTuKhoa[] = { "So HD","Ngay Lap","Loai","Ho ten NV Lap","Don Gia" };
	dstk.soTK =0;
	Date first, final;
	int vitri =0,page=0, key;
	string name = "BANG LIET KE HOA DON TRONG KHOANG THOI GIAN";
	string name2 = "TU NGAY :    /    /     \t DEN NGAY :    /    /     ";
	if(HoaDonKiemtraTonTai()== 0)
	{
		veKhungTB("         Khong co hoa don");
		system("cls");
		return;
	}
	system("cls");
	textcolor(setMauTiTle);
	gotoxy(32, 2);
	cout << name;	
	gotoxy(26, 3);
	textcolor(7);
	cout << name2;
	int exit =0;
	TKHDNgayNhap(first,final,exit);
	if(exit ==1)
	{
		system("cls");
		return;
	}
	TKHDXuLyDS(dstk,first,final);
	if(dstk.soTK ==0)
	{
		veKhungTB("         Khong co du lieu");
		system("cls");
		return;
	}
	int total = (dstk.soTK%14==0 ? dstk.soTK/14 : dstk.soTK/14+1);
	textcolor(setMauTiTle);
	gotoxy(50,37);
	cout << page+1 << "/" <<  total;
	textcolor(7);
		veKhungThongKeHD(arrTuKhoa);
		TKHDXuatDS(dstk,vitri);
		while(true)
		{
			while(!kbhit())
			{
				textcolor(setMauTiTle);
				gotoxy(50,37);
				cout << page+1;
				textcolor(7);
				key = getch();
				if(key == 224)
				{
					key = getch();
					if(key == 75 && page >0)
					{
						page--;
						vitri-=14;
						ContentRemoveTK();
						TKHDXuatDS(dstk,vitri);
					}
					else if(key ==77 && page < total - 1)
					{
						page++;
						vitri+=14;
						ContentRemoveTK();
						TKHDXuatDS(dstk,vitri);
					}
				}
				else if(key == 27)
				{
					system("cls");
					return;
				}
			 } 
		}
	
}
int HoaDonkiemtraXuat()
{
	for(int i = 0; i < dsnv.soLuongNV+1; i++)
	{
		for(NODE_HOADON* p= dsnv.nv[i].fisrtHD; p!=NULL; p = p->pNext)
		{
			if(p->data.loai=='X')
			{
				return 1;
			}
		}
	}
	return 0;
}
void DS10VTDoanhThu(Date &first, Date &final, int DT[][2],string MVT[],int &nArr)
{
	int dem = VatTuCountNode(t)+1;
	int dt[dem][2];
	string mvt[dem];
	int n;
	VatTuLNR(t,mvt,n);
	for(int a = 0; a < n; a++)
	{
		dt[a][0] = 0;
		dt[a][1] = 0;
	}
	int checkDate1,checkDate2;
	for(int i =0;i < dsnv.soLuongNV;i++)
	{
		for(NODE_HOADON* p = dsnv.nv[i].fisrtHD; p!= NULL; p= p->pNext)
		{
			checkDate1 = LayThoiGianSoSanh(p->data.date,first);
			checkDate2 = LayThoiGianSoSanh(p->data.date,final);
			if((checkDate1 ==1|| checkDate1 ==0) && (checkDate2 == -1|| checkDate2 == 0) && p->data.loai =='X')
			{
				for(NODECT_HOADON* q =p->data.fisrtCT; q!=NULL; q=q->pNext)
				{
					for(int j = 0; j < n; j++)
					{
						if( strcmp(q->Data.MaVT,mvt[j].c_str()) == 0)
						{
							dt[j][0] += q->Data.dongia*q->Data.soluong+q->Data.VAT/100*q->Data.dongia;
							dt[j][1] += q->Data.soluong;
						}
					}
				}
			}
		}
	}
	for(int i =0; i < dem;i++)
	{
		if(dt[i][0] > 0)
		{
			DT[nArr][0]=dt[i][0];
			DT[nArr][1]=dt[i][1];
			MVT[nArr] = mvt[i];
			nArr++;
		}
	}
}
int HoanDoiInt(int &a, int &b)
{
	int temp;
	temp =a;
	a = b;
	b = temp;
}
void DS10VTSort(int DT[][2], string MVT[], int &nArr)
{
	for(int i =0; i < nArr;i++)
	{
		for(int j = nArr-1; j > i; j--)
		{
			if((DT[j-1][0]) < (DT[j][0]))
			{
				HoanDoiString(MVT[j-1],MVT[j]);
				HoanDoiInt(DT[j-1][0],DT[j][0]);
				HoanDoiInt(DT[j-1][1],DT[j][1]);
			}
		}
	}
}
void DS10VTXuat(int DT[][2], string MVT[],int nArr)
{
	Nocursortype();
	int stt =0;
	int y;
	DS10VTSort(DT,MVT,nArr);
	for(int i = 0; i < nArr; i++)
	{
		if(i==10)
		{
			break;
		}
		y = 7+stt*2;
		veKhungKhuyet1(18,7+stt*2);
		veKhungKhuyet2(18,7+stt*2);
		gotoxy(20,7+stt*2);
		cout << MVT[i];
		gotoxy(35,y);
		cout << VatTuSearch(t,MVT[i])->Data.TenVT;
		gotoxy(57,y);
		cout << to_Currency(DT[i][0]);
		gotoxy(72,y);
		cout << "VND";
		gotoxy(79,y);
		cout << DT[i][1];
		stt++;
	}
}
void DS10VTQuanLyXuat()
{
	const int MAX = VatTuCountNode(t);
	int nArr=0;
	int DT[MAX][2];
	string MVT[MAX];
	if(HoaDonkiemtraXuat()== 0)
	{
		veKhungTB("      Chua xuat vat tu nao");
		system("cls");
		return;
	}
	Date first, final;
	string name = "BANG LIET KE VAT TU CO DOANH THU CAO TRONG KHOANG THOI GIAN";
	string name2 = "TU NGAY :    /    /     \t DEN NGAY :    /    /     ";
	system("cls");
	textcolor(setMauTiTle);
	gotoxy(26, 2);
	cout << name;
	gotoxy(26, 3);
	textcolor(7);
	cout << name2;
	int exit =0;
	TKHDNgayNhap(first,final,exit);
	if(exit ==1)
	{
		system("cls");
		return;
	}
	DS10VTDoanhThu(first,final,DT,MVT,nArr);
	if(nArr == 0)
	{
		veKhungTB("         Khong co du lieu");
		system("cls");
		return;
	}
	veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","Doanh Thu","   SL");
	veKhungKhuyet1(18,7);
	veKhungKhuyet2(18,7);
	DS10VTXuat(DT,MVT,nArr);
	int key;
	while(true)
	{
		while(!kbhit())
		{
			key = getch();
			if(key == 27)
			{
				system("cls");
				return;
			}
		}
	} 
}
#endif
