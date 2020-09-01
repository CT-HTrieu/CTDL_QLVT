#ifndef NHAN_VIEN_H
#define NHAN_VIEN_H
#include"CTDL.h"
#include"Design.h"
#include"Backend.h"
								// NHAN VIEN
void NhanVienAddTail(string MaNV, string Ho, string Ten, string Phai)
{

	strcpy(dsnv.nv[dsnv.soLuongNV].MaNV,MaNV.c_str());
	strcpy(dsnv.nv[dsnv.soLuongNV].Ho,Ho.c_str());
	strcpy(dsnv.nv[dsnv.soLuongNV].Ten,Ten.c_str());
	strcpy(dsnv.nv[dsnv.soLuongNV].Phai,Phai.c_str());
	dsnv.nv[dsnv.soLuongNV].fisrtHD =NULL;
	dsnv.soLuongNV++;
}
void NhanVienwritetoFile()
{
	const char* path ="NHANVIEN.txt";
	ofstream ofs(path,ios::out);
	ofs << dsnv.soLuongNV << endl;
	for(int i =0; i < dsnv.soLuongNV;i++)
	{
		ofs << dsnv.nv[i].MaNV << '@' << dsnv.nv[i].Ho << '@' << dsnv.nv[i].Ten << '@'  << dsnv.nv[i].Phai<< endl;
	}
	ofs.close();
}
void NhanVienreadFromFile()
{
	const char* path ="NHANVIEN.txt";
	ifstream ifs(path,ios::in);
	string MNV,Ho,Ten,Phai;
	int x;
	int n;
	if(ifs.fail())
	{
		return;
	}
	ifs >> n;
	ifs.ignore();
	for(int i =0; i < n;i++)
	{
		getline(ifs,MNV,'@');
		getline(ifs,Ho,'@');
		getline(ifs,Ten,'@');
		getline(ifs,Phai);
		NhanVienAddTail(MNV,Ho,Ten,Phai);
	}
	ifs.close();
}
void NhanVienNhap()
{
	system("cls");
	Yescursortype();
	veKhungKQTimKiem("Ma Nhan Vien","Ho","Ten","Phai");
	textcolor(setMauTiTle);
	gotoxy(40,2);
	cout << "THEM NHAN VIEN VAO HE THONG";
	textcolor(7);
	string MaNV ="";
	string Ho="";
	string Ten="";
	string Phai="";
	int flag=1;
	int loop =0;
	int vitri,key;
	int dong=0;
	int y;
	gotoxy(36,3);
	cout << "So nhan vien hien co trong he thong: " << dsnv.soLuongNV;
	veKhungKhuyet1(18, 7);
	veKhungKhuyet2(18,7);
	gotoxy(20,7);
	char space;
	int dem = 0;
	while(loop ==0)
	{
		while(!kbhit())
		{
			y = 7+dong*2;
			
			if(flag ==1)
			{	
				vitri=20+MaNV.size();
			}
			else if(flag ==2)
			{	
				vitri=35+Ho.size();
			}
			else if(flag ==3)
			{	
				vitri=57+Ten.size();
			}
			else if(flag ==4)
			{	
				vitri=79+Phai.size();
			}
			key = getch();
			if(key == 27)
			{
				if(veKhungYesNo("       Ban co muon thoat?",0))
				{
					NhanVienwritetoFile();
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					continue;
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key == 32)
			{
				if(flag == 1 && MaNV.size() < 10 && key !=32)
				{
					gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					MaNV.insert(MaNV.end(),1,(char)key);
				}
				else if(flag ==2 && Ho.size() < 20 )
				{  
					gotoxy(vitri,y);
					if(key == 32 )
					{
						space = char(32);
						dem++;
					}
					else if((key >=97 && key <=122) && (Ho.size() ==0 || space==' ' ))
					{
						space = 'a';
						key = key - 32;
					}
		
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					Ho.insert(Ho.end(),1,(char)key);
				}
				else if(flag ==3 && Ten.size() < 20)
				{
					gotoxy(vitri,y);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Ten.size() ==0 || space == ' ') )
					{
						space='a';
						key = key -32;
					}
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					Ten.insert(Ten.end(),1,(char)key);	
				}
				else if(flag ==4 && Phai.size() < 3)
				{
					gotoxy(vitri,y);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Phai.size() ==0  || space == ' ' ))
					{
						space='a';
						key = key -32;
					}
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					Phai.insert(Phai.end(),1,(char)key);
				}
			}
			else if(key ==13||key ==9)
			{
				if(flag ==1)
				{ 
					if(MaNV.size() > 10 )
					{
						while(!kbhit())
						{
							Canhbao("Do dai ma nhan vien khong qua 10 ki tu",30,1);
						}	
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else if(NhanVienKiemTraTrungMa(MaNV)==false)
					{
						while(!kbhit())
						{
							Canhbao("Ma "+MaNV+" da ton tai.Xin nhap lai!",30,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else if(MaNV.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong ma nhien vien",30,1);
						}	
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					
					else
					{
						gotoxy(35,y);
						flag =2;
					}
				}
				else if(flag ==2)
				{   Ho = kt32(Ho);
					if(Ho.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(57,y);
						flag =3;
					}
				}
				else if(flag ==3)
				{    Ten = kt32(Ten);
					if(Ten.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(79,y);
						flag =4;
					}
					
				}
				else if(flag ==4)
				{ 
					if(Phai.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else if(Phai != "Nam" && Phai !="Nu")
					{
						while(!kbhit())
						{
							Canhbao("Nhap sai phai : Nam/Nu.Xin nhap lai!",36,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{ 
						NhanVienAddTail(MaNV,Ho,Ten,Phai);
						gotoxy(73,3);
						cout << dsnv.soLuongNV;
						MaNV ="";
						Ten ="";
						Ho ="";
						Phai= "";
					    dong++;
						veKhungKhuyet1(18, 7+dong*2);
						veKhungKhuyet2(18,7+dong*2);
						gotoxy(20,7+dong*2);
						flag = 1;		
					}
				}
			}
			else if(key ==8)
			{
				if(flag ==1 && MaNV.size() > 0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout << " ";
					gotoxy(vitri,y);
					MaNV.erase(MaNV.end()-1);
				}
				else if(flag ==2 && Ho.size() >=0)
				{
					if(Ho.size() == 0)
					{
						gotoxy(20+MaNV.size(),y);
						flag=1;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout << " ";
						gotoxy(vitri,y);
						Ho.erase(Ho.end()-1);
						if (dem > 0 )
							dem--;
						else dem = 0;	
					}
					
				}
				else if(flag ==3 && Ten.size()>=0)
				{
					if(Ten.size()==0)
					{
						gotoxy(35+Ho.size(),y);
						flag=2;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout << " ";
						gotoxy(vitri,y);
						Ten.erase(Ten.end()-1);
					}
					
				}
				else if(flag == 4 && Phai.size()>=0)
				{
					if(Phai.size()==0)
					{
						gotoxy(57+Ten.size(),y);
						flag=3;
					}
					else
					{
				     	vitri--;
						gotoxy(vitri,y);
						cout << " ";
						gotoxy(vitri,y);
						Phai.erase(Phai.end()-1);
					}
					
				}
			}
			else key = getch();
			
		}
	}
	if(loop ==1)
	{
		return;
	}
}
	
void HoanDoiChar(char a[21],char b[21])
{
	char temp[31];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}
void NhanVienSort()
{
	for(int i =0;i<dsnv.soLuongNV;i++)
	{
		for(int j =dsnv.soLuongNV-1;j >i;j--)
		{
			if(strcmp(dsnv.nv[i].Ten,dsnv.nv[j].Ten) ==1)
			{
				HoanDoiChar(dsnv.nv[i].MaNV,dsnv.nv[j].MaNV);
				HoanDoiChar(dsnv.nv[i].Ho,dsnv.nv[j].Ho);
				HoanDoiChar(dsnv.nv[i].Ten,dsnv.nv[j].Ten);
				HoanDoiChar(dsnv.nv[i].Phai,dsnv.nv[j].Phai);
			}
			else if(strcmp(dsnv.nv[i].Ten,dsnv.nv[j].Ten)==0)
			{
				if(strcmp(dsnv.nv[i].Ho,dsnv.nv[j].Ho) == 1)
				{
					HoanDoiChar(dsnv.nv[i].MaNV,dsnv.nv[j].MaNV);
					HoanDoiChar(dsnv.nv[i].Ho,dsnv.nv[j].Ho);
					HoanDoiChar(dsnv.nv[i].Ten,dsnv.nv[j].Ten);
					HoanDoiChar(dsnv.nv[i].Phai,dsnv.nv[j].Phai);
				}
			}
			
		}
	}
}
void NhanVienXuat(NHANVIEN data,int stt)
{
	gotoxy(20,3+yMap +stt*2);
	cout << data.MaNV;
	gotoxy(39,3+yMap +stt*2);
	cout << data.Ho;
	gotoxy(63,3+yMap +stt*2);
	cout << data.Ten;
	gotoxy(87,3+yMap +stt*2);
	cout << data.Phai;
}
void NhanVienXuatDS(int vitri,int stt)
{
	Nocursortype();
	
	int k=0;
	for(int i =vitri;i< dsnv.soLuongNV;i++)
	{   if (stt==k)
		{   textcolor(32);
			NhanVienXuat(dsnv.nv[i],k);

		}
		else {
			textcolor(7);
			NhanVienXuat(dsnv.nv[i],k);

		}
		k++;
		if(k == 14)
		{
			break;
		}
	}
}
void NhanVienQuanLyXuat()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	system("cls");
	NhanVienSort();
	string arr[]={"Ma NV","Ho","Ten","Phai"};
	gotoxy(45,2);
	textcolor(setMauTiTle);
	cout << "DANH SACH NHAN VIEN";
	textcolor(7);
	Nocursortype();
	veKhungChiTiet(arr,0);
	int key;
	int page =0,i=0,vitri=0;
	int total = (dsnv.soLuongNV%14 ==0) ? dsnv.soLuongNV /14 : dsnv.soLuongNV/14+1;
	gotoxy(54,34);
	textcolor(setMauTiTle);
	cout << page+1 <<" / " << total;
	textcolor(7);
	int stt=0;
	//NhanVienXuatDS(vitri,stt);
	while(true)
	{
		while(!kbhit())
		{   NhanVienXuatDS(vitri,stt);
			gotoxy(54,34);
			textcolor(setMauTiTle);
			cout << page+1;
			textcolor(7);
			key = getch();
			if(key == 0)
			{
				key = getch();
			}
			else if (key == 224)
			{
				key = _getch();
				if (key == 75 && page > 0)
				{
					page--;
					vitri-=14;
					ContentRemove();
					NhanVienXuatDS(vitri,stt);
				}
				else if (key == 77 && page < total-1)
				{   stt=0;
					page++;
					vitri += 14;
					ContentRemove();
					NhanVienXuatDS(vitri,stt);
				}
				else if (key == 80)
				{
				  ContentRemove();
				  stt++;
				  NhanVienXuatDS(vitri,stt);
				  if (stt==dsnv.soLuongNV-14*page)
				  	{
				  		stt=0;
					}
				}
				else if (key == 72 and stt > 0)
				{   
					ContentRemove();
					stt--;
					NhanVienXuatDS(vitri,stt);
				}
			}
			else if (key == 27) // esc
			{
				system("cls");
				return;
			}
		}
	}
}
/////////////////////////
int Trastt()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return 0;
	}
	system("cls");
	NhanVienSort();
	string arr[]={"Ma NV","Ho","Ten","Phai"};
	gotoxy(45,2);
	textcolor(setMauTiTle);
	cout << "DANH SACH NHAN VIEN";
	textcolor(7);
	Nocursortype();
	veKhungChiTiet(arr,0);
	int key;
	int page =0,i=0,vitri=0;
	int total = (dsnv.soLuongNV%14 ==0) ? dsnv.soLuongNV /14 : dsnv.soLuongNV/14+1;
	gotoxy(54,34);
	textcolor(setMauTiTle);
	cout << page+1 <<" / " << total;
	textcolor(7);
	int stt=0;
	//NhanVienXuatDS(vitri,stt);
	while(true)
	{
		while(!kbhit())
		{   NhanVienXuatDS(vitri,stt);
			gotoxy(54,34);
			textcolor(setMauTiTle);
			cout << page+1;
			textcolor(7);
			key = getch();
			if(key == 0)
			{
				key = getch();
			}
			else if (key == 224)
			{
				key = _getch();
				if (key == 75 && page > 0)
				{
					page--;
					vitri-=14;
					ContentRemove();
					NhanVienXuatDS(vitri,stt);
				}
				else if (key == 77 && page < total-1)
				{   stt=0;
					page++;
					vitri += 14;
					ContentRemove();
					NhanVienXuatDS(vitri,stt);
				}
				else if (key == 80)
				{
				  ContentRemove();
				  stt++;
				  NhanVienXuatDS(vitri,stt);
				  if (stt==dsnv.soLuongNV-14*page)
				  	{
				  		stt=0;
					}
				}
				else if (key == 72 and stt > 0)
				{   
					ContentRemove();
					stt--;
					NhanVienXuatDS(vitri,stt);
				}
			}
			else if (key == 27) // esc
			{
				system("cls");
				return -1;
			}
			else if (key == 13)
				{
					system("cls");
					return stt+14*page;
					}	
			}
		}
}


/////////////

void NhanVienHieuChinh()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	system("cls");
	Yescursortype();
	textcolor(setMauWarning);
	gotoxy(40,2);
	cout << "Ma Nhan Vien: ";
	textcolor(7);
	string manv;
	int key1,vitri;
	int vtr;
	int y=2;
	int loop = 0;
	while(loop ==0)
	{
       int k = Trastt();
        if (k == -1)
				if(veKhungYesNo("     Ban co muon thoat khong?",0))
				{
					NhanVienwritetoFile();
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					gotoxy(vitri,y);
					HienThiDauNhay();
				}
		
		 else 
                {
					vtr=k;
					textcolor(32);
					gotoxy(38,2);
					cout<<"Danh Sach Nhan Vien Can Thai Doi Thong tin";
					textcolor(7);
					veKhungKQTimKiem("Ma Nhan Vien","Ho","Ten","Phai");
					veKhungKhuyet1(18,7);
					veKhungKhuyet2(18,7);
					gotoxy(20,7);
					cout << dsnv.nv[vtr].MaNV;
					gotoxy(35,7);
					cout << dsnv.nv[vtr].Ho;
					gotoxy(57,7);
					cout << dsnv.nv[vtr].Ten;
					gotoxy(79,7);
					cout << dsnv.nv[vtr].Phai;
					loop =1;
				}
	}
	int exit =0;
	int key,vtri;
	string MaNV =dsnv.nv[vtr].MaNV;
	string Ho=dsnv.nv[vtr].Ho;
	string Ten=dsnv.nv[vtr].Ten;
	string Phai=dsnv.nv[vtr].Phai;
	int th=3;
	gotoxy(79+Phai.size(),7);
	char space;
	VATTU data;
	HienThiDauNhay();
	while(exit ==0)
	{
		while(!kbhit())
		{
			if(th==1)
			{
				vtri = 35+Ho.size();
			}
			else if(th ==2)
			{
				vtri = 57+Ten.size();
			}
			else if(th==3)
			{
				vtri = 79+Phai.size();
			}
			key = getch();
			if(key == 0)
			{
				key == getch();
			}
			else if(key ==27)
			{
				if(veKhungYesNo("      Ban co muon thoat khong?",0))
				{
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					gotoxy(79+Phai.size(),7);
					HienThiDauNhay();
					continue;
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key ==32)
			{
				if(th==1 && Ho.size() < 20)
				{
					gotoxy(vtri,7);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Ho.size() ==0 || space == ' ') )
					{
						space='a';
						key = key -32;
					}
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << char(key);
					Ho.insert(Ho.end(),1,(char)key);
				}
				else if(th==2 && Ten.size() <20)
				{
					gotoxy(vtri,7);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Ten.size() ==0 || space == ' ') )
					{
						space='a';
						key = key -32;
					}
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << char(key);
					Ten.insert(Ten.end(),1,(char)key);
				}
				else if(th==3 && Phai.size() < 3 && key !=32)
				{
					gotoxy(vtri,7);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Phai.size() ==0 || space == ' ') )
					{
						space='a';
						key = key -32;
					}
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << char(key);
					Phai.insert(Phai.end(),1,(char)key);
				}
			}
			else if(key ==13||key ==9)
			{
				if(th==1)
				{
					if(Ho.size()==0)
					{
						Ho=dsnv.nv[vtr].Ho;
						gotoxy(35,7);
						cout << Ho;
						gotoxy(57+Ten.size(),7);
						th=2;
					}
					else{
						gotoxy(57+Ten.size(),7);
						th=2;
					}
				}
				else if(th==2)
				{
					if(Ten.size()==0)
					{
						Ten = dsnv.nv[vtr].Ten;
						gotoxy(57,7);
						cout << Ten;
						gotoxy(79+Phai.size(),7);
						th=3;
					}
					else{
						gotoxy(79+Phai.size(),7);
						th=3;
					}
				}
				else if(th ==3)
				{
					if(Phai.size()==0)
					{
						Phai = dsnv.nv[vtr].Phai;
						gotoxy(79,7);
						cout << Phai;
					}
					else if(Phai != "Nam" && Phai !="Nu")
					{
						while(!kbhit())
						{
							Canhbao("Nhap sai phai : Nam/Nu.Xin nhap lai!",36,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(79+Phai.size(),7);
					}
					else{
						if(veKhungYesNo("   Ban co muon thay doi khong ?",0))
						{
							strcpy(dsnv.nv[vtr].MaNV,MaNV.c_str());
							strcpy(dsnv.nv[vtr].Ho,Ho.c_str());
							strcpy(dsnv.nv[vtr].Ten,Ten.c_str());
							strcpy(dsnv.nv[vtr].Phai,Phai.c_str());
							system("cls");
							textcolor(32);
						    gotoxy(38,2);
						    cout<<"Danh Sach Nhan Vien Can Thai Doi Thong tin";
						    textcolor(7);
							veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
							veKhungKhuyet1(18,7);
							veKhungKhuyet2(18,7);
							gotoxy(20,7);
							cout << dsnv.nv[vtr].MaNV;
							gotoxy(35,7);
							cout << dsnv.nv[vtr].Ho;
							gotoxy(57,7);
							cout << dsnv.nv[vtr].Ten;
							gotoxy(79,7);
							cout << dsnv.nv[vtr].Phai;
							XoaKhungYN();
							veKhungTB("        Da sua thanh cong");
							system("cls");
							return;
						}
						else
						{
							system("cls");
							textcolor(32);
						    gotoxy(38,2);
						    cout<<"Danh Sach Nhan Vien Can Thai Doi Thong tin";
						    textcolor(7);
							veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
							veKhungKhuyet1(18,7);
							veKhungKhuyet2(18,7);
							gotoxy(20,7);
							cout << dsnv.nv[vtr].MaNV;
							gotoxy(35,7);
							cout << dsnv.nv[vtr].Ho;
							gotoxy(57,7);
							cout << dsnv.nv[vtr].Ten;
							gotoxy(79,7);
							cout << dsnv.nv[vtr].Phai;
							XoaKhungYN();
							veKhungTB("        Da huy tac vu sua");
							system("cls");
							return;
						}
					}
				}
			}
			else if(key ==8)
			{
				if(th ==1 && Ho.size() > 0)
				{
					vtri--;
					gotoxy(vtri,7);
					cout << " ";
					gotoxy(vtri,7);
					Ho.erase(Ho.end()-1);
					
				}
				else if(th ==2 && Ten.size() >=0)
				{
					if(Ten.size()==0)
					{
						gotoxy(35+Ho.size(),7);
						th=1;
					}
					else
					{
					vtri--;
					gotoxy(vtri,7);
					cout << " ";
					gotoxy(vtri,7);
					Ten.erase(Ten.end()-1);
					}
				}
				else if(th ==3 && Phai.size() >=0)
				{
					if(Phai.size()==0)
					{
						gotoxy(57+Ten.size(),7);
						th=2;
					}
					else
					{
					vtri--;
					gotoxy(vtri,7);
					cout << " ";
					gotoxy(vtri,7);
					Phai.erase(Phai.end()-1);
					}
				}
			}
			else key= getch();
		}
	}
}
void NhanVienDel(int i)
{
	for(int j=i;j<dsnv.soLuongNV-1;j++)
	{
		dsnv.nv[j]=dsnv.nv[j+1];
	}
	dsnv.soLuongNV-=1;
}
int NhanVienkiemtraXoa(string MNV);
void NhanVienXoa()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	system("cls");
	Yescursortype();
	while(true)
	{    int k =Trastt();
	  if ( k == -1)
			if(veKhungYesNo("     Ban co muon thoat khong?",0))
				{
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					gotoxy(54,2);
					HienThiDauNhay();
				}
		else
				{
					int vtr= k;
					textcolor(setMauTiTle);
					gotoxy(44,1);
					cout<<"Danh Sach Muon Xoa";
					textcolor(7);
					veKhungKQTimKiem("Ma Nhan Vien","Ho","Ten","Phai");
					veKhungKhuyet1(18,7);
					veKhungKhuyet2(18,7);
					gotoxy(20,7);
					cout << dsnv.nv[vtr].MaNV;
					gotoxy(36+((18-strlen(dsnv.nv[vtr].Ho))/2),7);
					cout << dsnv.nv[vtr].Ho;
					gotoxy(58+((18-strlen(dsnv.nv[vtr].Ten))/2),7);
					cout << dsnv.nv[vtr].Ten;
					gotoxy(79+((6-strlen(dsnv.nv[vtr].Phai))/2),7);
					cout << dsnv.nv[vtr].Phai;
					HOADON data;
					if(veKhungYesNo("     Ban co muon xoa khong?",0))
					{
						NhanVienDel(vtr);
						NhanVienwritetoFile();
						XoaKhungYN();
						veKhungTB("	        Xoa thanh cong ");
						system("cls");
						return;
					}
					else
					{
						ContentRemoveCT();
						gotoxy(20,7);
						cout << dsnv.nv[vtr].MaNV;
						gotoxy(36+((18-strlen(dsnv.nv[vtr].Ho))/2),7);
						cout << dsnv.nv[vtr].Ho;
						gotoxy(58+((18-strlen(dsnv.nv[vtr].Ten))/2),7);
						cout << dsnv.nv[vtr].Ten;
						gotoxy(79+((6-strlen(dsnv.nv[vtr].Phai))/2),7);
						cout << dsnv.nv[vtr].Phai;
						XoaKhungYN();
						veKhungTB("           Da huy xoa ");
						system("cls");
						NhanVienXoa();
						return;
					}
				}
			}	
}
#endif
