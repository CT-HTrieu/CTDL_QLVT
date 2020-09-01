#ifndef VAT_TU_H
#define VAT_TU_H
#include"CTDL.h"
#include"Design.h"
#include"Backend.h"
void VatTuInit(Tree &root)
{
	root = NULL;
}
NODE_VATTU* VatTuCreateNode(VATTU data)///tao nodes
{
	NODE_VATTU* p = new NODE_VATTU;
	if(p == NULL)
	{
		exit(1);
	}
	p->Data = data;
	p->pLeft = NULL;
	p->pRight = NULL;	
	return p;
}

void VatTuInsertNode(Tree &root, VATTU data)
{
     if(root==NULL){
     	root = VatTuCreateNode(data);
     	
	 }else
	 {
	 	 if(strcmp(root->Data.MaVT,data.MaVT) > 0)
	 	 	VatTuInsertNode(root->pLeft,data);
	 	 else if(strcmp(root->Data.MaVT,data.MaVT)< 0 )
		  	VatTuInsertNode(root->pRight,data);	
	 }
}
// tim node the mang
//////////////////////////////////////////////dang sau
NODE_VATTU* VatTuSearch(Tree t, string x)
{
	if(t == NULL)
	{
		return NULL;
	}
	while(t->Data.MaVT !=x)
	{
		if(strcmp(t->Data.MaVT,x.c_str()) == 1)
		{
			t = t->pLeft;
		}
		else
		{
			t = t->pRight;
		}
	}
    return t;
}
NODE_VATTU* VatTukiemTraTrungMa(Tree t,string maVT)
{
	if(t != NULL)
	{
		if(strcmp(t->Data.MaVT, maVT.c_str()) == 0)
		{
			NODE_VATTU *p = new NODE_VATTU;
			p  = t;
			return p;
		}
		if(strcmp(t->Data.MaVT, maVT.c_str()) == 1)
			return VatTukiemTraTrungMa(t->pLeft, maVT);
		if(strcmp(t->Data.MaVT, maVT.c_str()) == -1)
			return VatTukiemTraTrungMa(t->pRight, maVT);
	}
	return NULL;
}
int NhanVienKiemTraTrungMa(string MNV)
{
	for(int i=0;i<dsnv.soLuongNV;i++)
	{
		if(strcmp(dsnv.nv[i].MaNV,MNV.c_str())==0)
		{
			return false;
		}
	}
	return true;
}
int VatTuCountNode(Tree &t)
{
	if(t == NULL)
	{
		return 0;
	}
	else 
	{
		return 1+VatTuCountNode(t->pLeft) + VatTuCountNode(t->pRight);
	}
}

void VatTuLNR(Tree t,string arrMVT[] ,int &nVT)//duyet cay
{   if (t == NULL)
			return;
	if (t != NULL)
	{
		VatTuLNR(t->pLeft,arrMVT,nVT);
		arrMVT[nVT++]=t->Data.MaVT;
		VatTuLNR(t->pRight,arrMVT,nVT);
	}
}
void GhiFileVatTu_NLR(NODE_VATTU *root, ofstream &f)//phai co &f de tranh loi ios_base is private
{
	if(root!= NULL)
	{
		f << root->Data.MaVT << endl << root->Data.TenVT << endl << root->Data.DVT << endl << root->Data.SoLuongTon << endl;
		GhiFileVatTu_NLR(root->pLeft, f);
		GhiFileVatTu_NLR(root->pRight, f);
	}
}
void VatTuwriteToFile(NODE_VATTU *Root)
{
    ofstream f;
    f.open("VATTU.TXT",ios_base::out);
    GhiFileVatTu_NLR(Root,f);
    f.close();
}
void VatTureadFromFile(Tree &root)
{   string data;
	fstream f;
	f.open("VATTU.TXT",ios::in);
	if(f == NULL)
		return;
		
	while(!f.eof()){
		VATTU vt;
		getline(f,data);
		if(data.size()==0)
			return;
		strcpy(vt.MaVT,data.c_str());
		getline(f,data);           strcpy(vt.TenVT,data.c_str());
		getline(f,data);           strcpy(vt.DVT,data.c_str());
		f >> vt.SoLuongTon;
		f.ignore();
		VatTuInsertNode(root,vt);			 
	}
	f.close();
}
void VatTuNhap()
{
	system("cls");
	VATTU data;
	textcolor(setMauTiTle);
	gotoxy(28,33);
    cout << "ENTER = De chuan hoa chuoi \tESC = Thoat";
	textcolor(setMauTiTle);
	gotoxy(40,2);
	cout << "THEM VAT TU CO THE NHAP VAO KHO";
	textcolor(7);
	gotoxy(42,3);
	cout << "Tong so vat tu hien tai: "<< VatTuCountNode(t);
	string maVT="", tenVT="",dvt="",slt="";
	bool ischeck=false;
	int vitri, key;
	int flag =0;
	int loop=0;
	int y;
	data.SoLuongTon=0;
	veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So luong ton","DVT");
	veKhungKhuyet1(18,7);
	veKhungKhuyet2(18,7);
	gotoxy(20,7);
	int dong=0;
	char space;
	int dem =0;
	while(loop ==0)
	{
		while(!kbhit())
		{    
		    key =getch();
			y=7+2*dong;
			if(flag ==0) vitri = 20+maVT.length();
			else if(flag == 1) vitri = 35+tenVT.length();
			else if (flag == 2) vitri = 63+slt.size();
			else if(flag ==3) vitri = 79+dvt.length();
		if (key == 0)
		  key = getch();
		  
	    else if(key == 27)
			{
				if(veKhungYesNo("       Ban co muon thoat?",0))
				{
					VatTuwriteToFile(t);
					if(dong!=0)
					{
						XoaKhungYN();
						veKhungTB("   Da luu toan bo vat tu");
					}
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					gotoxy(vitri,y);
					HienThiDauNhay();
					//continue;
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key == 32)
			{
				if(flag == 0 && maVT.size()<10 && key !=32)
				{
					gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					maVT.insert(maVT.end(),1,(char)key);
					vitri++;
				}
				else if(flag ==1 && tenVT.size() < 20)
				{
					gotoxy(vitri,y);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (tenVT.size() ==0 || space == ' ') )
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
					tenVT.insert(tenVT.end(),1,(char)key);
					vitri++;
						
				}
				else if ((flag == 2 )&& (key >= 48&& key <=57) && slt.size()<10)
					{   gotoxy(vitri,y);
						cout<<(char)key;
						slt.insert(slt.end(),1,char(key));
						data.SoLuongTon=atoi(slt.c_str());///chuyen char sang int
					}
				else if(flag ==3 && dvt.size() < 8 && key !=32)
				{
					gotoxy(vitri,y);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (dvt.size() ==0 || space == ' ') )
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
					dvt.insert(dvt.end(),1,(char)key);	
					vitri++;
				}
			}
			//////////////phim enter
			else if(key ==13 || key ==9)
			{
				if(flag ==0)
				{
					if(maVT.size() ==0)
					{
						while(!kbhit())
							Canhbao("Khong duoc de trong.Xin nhap lai!!",30,1);
						do{
							int key1 = getch();
							
						}while(key!=13&&key!=27);
						gotoxy(vitri,y);
					}
					else if(maVT.size() > 10)
					{
						while(!kbhit())
						{
							Canhbao("Do dai ma vat tu khong qua 10 ky tu.Xin nhap lai",30,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=27);
						gotoxy(vitri,y);
					}
					else if(VatTukiemTraTrungMa(t,maVT) !=NULL)
					{
							while(!kbhit())
						{
							Canhbao("Ma "+maVT+" da ton tai trong he thong.Xin nhap lai",30,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(35,y);
						flag =1;
					}
				}
				else if(flag ==1)
				{   
				   tenVT = kt32(tenVT);
					if(tenVT.size() ==0)
					{
						while(!kbhit())
							Canhbao("Khong duoc de trong.Xin nhap lai!!",30,1);
						do{
							int key1 = getch();
							
						}while(key!=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(63,y);
						flag = 2; 
						
					}
				}
				else if(flag ==2)
				{  slt=kt32(slt);  
				  if(slt.size()==0)
						{
						   while(!kbhit())
						   	Canhbao("so luong ton bat buoc phai nhap khong qua 10 so!!!",30,1);
						   do{
						   	  int key1 = getch();
						   }while(key!= 13 and key!= 27);
						   gotoxy(vitri,y);
						}
					else{
						flag=3;
						gotoxy(79,y);
					}	
					
					}
				else if(flag == 3)
				{
					dvt = kt32(dvt);
					if(dvt.size() ==0)
					{
						while(!kbhit())
							Canhbao("Khong duoc de trong.Xin nhap lai!!",30,1);
						do{
							int key1 = getch();
							
						}while(key!=13&&key!=27);
						gotoxy(vitri,y);
				}	
				else
					{
						strcpy(data.MaVT,maVT.c_str());
						strcpy(data.TenVT,tenVT.c_str());
						strcpy(data.DVT,dvt.c_str());
						VatTuInsertNode(t,data);
						gotoxy(67,3);
						cout << VatTuCountNode(t);
						dong++;
						maVT="";
						tenVT="";
						dvt="";
						slt="";
						data.SoLuongTon=0;
						veKhungKhuyet1(18,7+dong*2);
						veKhungKhuyet2(18,7+dong*2);
						gotoxy(20,7+dong*2);
						flag =0;
					}
				}
				
			}
			else if(key ==8)
			{
				if(flag ==0 && maVT.size() > 0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout << " ";
					gotoxy(vitri,y);
					maVT.erase(maVT.end()-1);
				}
				else if(flag ==1 && tenVT.size() >=0)
				{
					if(vitri==vitri-tenVT.size())
					{
						gotoxy(20+maVT.size(),y);
						flag=0;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout << " ";
						gotoxy(vitri,y);
						tenVT.erase(tenVT.end()-1);
					}
					
				}
				else if(flag == 2 and slt.size() >= 0){
					if (vitri== vitri - slt.size())
						{
							gotoxy(35+tenVT.size(),y);
							flag= 1;
							
						}
					else{
						vitri--;
						gotoxy(vitri,y);
						cout<<" ";
						gotoxy(vitri,y);
						slt.erase(slt.end()-1);
					}	
				}
				else if(flag ==3 && dvt.size()>=0)
				{
					if(vitri==vitri-dvt.size())
					{
						gotoxy(63+dem,y);
						flag=2;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout << " ";
						gotoxy(vitri,y);
						dvt.erase(dvt.end()-1);
					}
					
					
				}
			}
		}
	}
}
void ContentRemove()
{
	for(int stt = 0;stt< 14;stt++)
	{
		gotoxy(arrToaDoBangChiTet[0]+1,3+yMap +stt*2);
		cout << "              ";
		gotoxy(arrToaDoBangChiTet[1]+1,3+yMap +stt*2);
		cout <<"                    ";
		gotoxy(arrToaDoBangChiTet[2]+1,3+yMap +stt*2);
		cout << "                ";
		gotoxy(arrToaDoBangChiTet[3]+1,3+yMap +stt*2);
		cout << "          ";
	}
}
void VatTuXuat(VATTU data,int stt)
{
	gotoxy(20,3+yMap +stt*2);
	cout << data.MaVT;
	gotoxy(40,3+yMap +stt*2);
	cout << data.TenVT;
	gotoxy(57+((26-to_String(data.SoLuongTon).size())/2),3+yMap +stt*2);
	cout << data.SoLuongTon;
	gotoxy(87,3+yMap +stt*2);
	cout << data.DVT;
}
void HoanDoiString(string &a, string &b)
{
	string temp;
	temp =a;
	a = b;
	b =temp;
}
void Sort(string *&arrMVT,int trai,int phai)
{
	int i =trai;
	int j =phai;
	string pivot = arrMVT[(trai+phai)/2];
	while(i <= j)
	{
		while(arrMVT[i] < pivot)
			i++;
		while(arrMVT[j] > pivot)
			j--;
		if(i <= j)
		{
			HoanDoiString(arrMVT[i],arrMVT[j]);
			i++;
			j--;
		}
	}
	if(trai < j)
	{
		Sort(arrMVT,trai,j);
	}
	if(i < phai)
	{
		Sort(arrMVT,i,phai);
	}
}
void VatTuSort(string arrMVT[],int &nVT)
{
	Sort(arrMVT,0,nVT-1);
}
void VatTuXuatDS(string MVT[],int &nArr, int vitri, int stt )
{
	int k =0;
	NODE_VATTU *p ;
	VatTuSort(MVT,nArr);
	for(int i =vitri; i < nArr; i++)
	{
		p= new NODE_VATTU;
		p = VatTuSearch(t,MVT[i]);
		if(stt == k){
		textcolor(32);
		VatTuXuat(p->Data,k++);
		}
		else{
			textcolor(7);
			VatTuXuat(p->Data,k++);
		}
		if(k == 14)
		{
			break;
		}
	}
}
void VatTuQuanLyXuat()
{
	if(t == NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
	Nocursortype();
	gotoxy(40,2);
	textcolor(setMauTiTle);
	cout << "DANH SACH VAT TU CO TRONG KHO";
	textcolor(7);
	string arr[4] ={"Ma vat tu", "Ten vat tu", "So luong ton","DVT"};
	veKhungChiTiet(arr,0);
	int page =0,i=0,vitri=0;
	
	int key;
	int n = VatTuCountNode(t);
	string MVT[n+1];
	int nArr = 0;
	VatTuLNR(t,MVT,nArr);//dua tu cay nhi phan sang mang tuyen tinh
	int total = (n%14 ==0) ? n /14 : n/14+1;
	gotoxy(54,34);
	textcolor(setMauTiTle);
	cout << page+1 <<" / " << total;
	textcolor(7);
	int stt = 0;
	VatTuXuatDS(MVT,nArr,vitri,stt);
	while(true)
	{
		while(!kbhit())
		{
			VatTuXuatDS(MVT,nArr,vitri,stt);
			gotoxy(54,34);
			textcolor(setMauTiTle);
			cout << page+1;
			textcolor(7);
			key = getch();
			 if(key == 224)
			{
				key =  getch();
				if(key == 75 && page >0)
				{   stt=0;
					page--;
					vitri-=14;
					ContentRemove();
					VatTuXuatDS(MVT,nArr,vitri,stt);
				}
				else if(key == 77 && page <total-1)
				{   stt=0;
					page++;
					vitri+=14;
					ContentRemove();
					VatTuXuatDS(MVT,nArr,vitri,stt);
				}
				else if (key == 80 ){
					ContentRemove();
					stt++;
					VatTuXuatDS(MVT,nArr,vitri,stt);
					if(stt == n-14*page)
						stt = 0;
				}
				else if (key == 72 and stt > 0)
				{
					ContentRemove();
					stt--;
					VatTuXuatDS(MVT,nArr,vitri,stt);
				}
			}
			else if(key == 27)
			{
				system("cls");
				return;
			}
			else if (key == 13)
			{
				system("cls");
				return;
			}
		}	
	}
}
string VatTuXuatDS1(string MVT[],int &nArr, int vitri, int stt )
{
	int k =0;
	NODE_VATTU *p ;
	string s="";
	VatTuSort(MVT,nArr);
	for(int i =vitri; i < nArr; i++)
	{
		p= new NODE_VATTU;
		p = VatTuSearch(t,MVT[i]);
		if(k==stt)
		  {
		  	  s= p->Data.MaVT;
		  	  return s;
		  }
		k++;
	}
return s;	
}


///////////////////////////////////////////////////ham xuat phu
int trastt()
{
	if(t == NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return 0;
	}
	system("cls");
	Nocursortype();
	gotoxy(40,2);
	textcolor(setMauTiTle);
	cout << "DANH SACH VAT TU CO TRONG KHO";
	textcolor(7);
	string arr[4] ={"Ma vat tu", "Ten vat tu", "So luong ton","DVT"};
	veKhungChiTiet(arr,0);
	int page =0,i=0,vitri=0;
	
	int key;
	int n = VatTuCountNode(t);
	string MVT[n+1];
	int nArr = 0;
	VatTuLNR(t,MVT,nArr);//dua tu cay nhi phan sang mang tuyen tinh
	int total = (n%14 ==0) ? n /14 : n/14+1;
	gotoxy(54,34);
	textcolor(setMauTiTle);
	cout << page+1 <<" / " << total;
	textcolor(7);
	int stt = 0;
	VatTuXuatDS(MVT,nArr,vitri,stt);
	while(true)
	{
		while(!kbhit())
		{
			VatTuXuatDS(MVT,nArr,vitri,stt);
			gotoxy(54,34);
			textcolor(setMauTiTle);
			cout << page+1;
			textcolor(7);
			key = getch();
			if(key == 0)
			{
				key = getch();
			}
			else if(key == 224)
			{
				key =  getch();
				if(key == 75 && page >0)
				{   stt=0;
					page--;
					vitri-=14;
					ContentRemove();
					VatTuXuatDS(MVT,nArr,vitri,stt);
				}
				else if(key == 77 && page <total-1)
				{   stt=0;
					page++;
					vitri+=14;
					ContentRemove();
					VatTuXuatDS(MVT,nArr,vitri,stt);
				}
				else if (key == 80 and stt < n){
					ContentRemove();
					stt++;
					VatTuXuatDS(MVT,nArr,vitri,stt);
					if(stt == n)
						stt = 0;
				}
				else if (key == 72 and stt > 0)
				{
					ContentRemove();
					stt--;
					VatTuXuatDS(MVT,nArr,vitri,stt);
				}
			}
			else if(key == 27)
			{
				system("cls");
				return -1;
			}
			else if (key == 13)
			      {   
					return stt+(page)*14;
		}	}
	}
}


/////////////////////////////




void VatTuDelete(Tree &root, string MVT)
{   
	if (root == NULL){
		return;
	}
	if(strcmp(root->Data.MaVT,MVT.c_str()) > 0 )
		return VatTuDelete(root->pLeft,MVT);
	else if(strcmp(root->Data.MaVT,MVT.c_str()) < 0)
		return VatTuDelete(root->pRight,MVT);	
	else{
		if(root->pLeft == NULL)
			root = root->pRight;
		else if (root->pRight == NULL)
			root=root->pLeft;
		else{
			NODE_VATTU *x = root->pLeft;//tim node con nho nhar ben phai
			while(x->pRight !=NULL)
			{
				x = x->pRight;
			}
			root->Data= x->Data;
			VatTuDelete(root->pLeft,x->Data.MaVT);
		}	
	}	
}
/*int VatTuKiemTraXoa(string MaVT)
{
	int MAX = VatTuCountNode(t)+1;
	string MVT[MAX];
	int nArr;
	VatTuLNR(t,MVT,nArr);
	NODE_VATTU *p ;
	for(int i =0; i < nArr; i++)
	{
		if(t->Data.MaVT==MaVT)
		{
			p = VatTuSearch(t,MaVT);
			if(p->Data.SoLuongTon > 0)
			{
				return 1;
			}
		}
	}
	return 0;
}*/
void VatTuXoa()
{
	if(t==NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
  system("cls");
  int n = VatTuCountNode(t);	
  string MVT[n+1];
  int nArr = 0,vitri =0;
  string i;
  VatTuLNR(t,MVT,nArr);
 while(true)
		{   	
			int j= trastt();
            if (j == -1)
	        {
	 	       clrscr();
	 	       return;
	        }
			else{  	  
			            i = VatTuXuatDS1(MVT,nArr,vitri,j);
						NODE_VATTU* p = VatTuSearch(t,i);
		        		system("cls");
		        		textcolor(32);
						gotoxy(38,2);
						cout<<"Danh Sach Vat Tu Can Xoa Thong tin";
						textcolor(7);
						veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
						gotoxy(40,2);
						cout << "Ma Vat Tu: "<<p->Data.MaVT;
						veKhungKhuyet1(18,7);
						veKhungKhuyet2(18,7);
						gotoxy(20,7);
						cout << p->Data.MaVT;
						gotoxy(36+((18-strlen(p->Data.TenVT)))/2,7);
						cout << p->Data.TenVT;
						gotoxy(68,7);
						cout << p->Data.SoLuongTon;
						gotoxy(79+((6-strlen(p->Data.DVT)))/2,7);
						cout << p->Data.DVT;
					     
						if(veKhungYesNo("    Ban co muon xoa "+i+"?",0))
						{
							VatTuDelete(t,i);
							system("cls");
							veKhungTB(" Xoa thanh cong "+i+"");
							system("cls");
							VatTuXoa();
						}
						else
						{
							ContentRemoveCT();
							gotoxy(20,7);
							cout << p->Data.MaVT;
							gotoxy(36+((18-strlen(p->Data.TenVT)))/2,7);
							cout << p->Data.TenVT;
							gotoxy(68,7);
							cout << p->Data.SoLuongTon;
							gotoxy(79+((6-strlen(p->Data.DVT)))/2,7);
							cout << p->Data.DVT;
							veKhungTB("           Da huy xoa ");
							system("cls");
							VatTuXoa();
						}
						return;
					}
          }
}

void VatTuHieuChinh()
{
	if(t==NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
	textcolor(7);
	int n = VatTuCountNode(t);	
    string MVT[n+1];
    int nArr = 0,vitri =0;
    string i;
    VatTuLNR(t,MVT,nArr);
	string mavt;
	int loop =0;
	NODE_VATTU *q;
	while(loop ==0)
	{   int j = trastt();
		if ( j == -1 )
				if(veKhungYesNo("      Ban co muon thoat khong?",0))
				{
					VatTuwriteToFile(t);
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					continue;
				}
		
	    else
				{   mavt = VatTuXuatDS1(MVT,nArr,vitri,j);
					q = VatTuSearch(t,mavt);
					system("cls");
					textcolor(32);
					gotoxy(38,2);
					cout<<"Danh Sach Vat Tu Can Thai Doi Thong tin";
					textcolor(7);
					veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
					veKhungKhuyet1(18,7);
					veKhungKhuyet2(18,7);
					gotoxy(20,7);
					cout << q->Data.MaVT;
					gotoxy(35,7);
					cout << q->Data.TenVT;
					gotoxy(60,7);
					cout << q->Data.SoLuongTon;
					gotoxy(79,7);
					cout << q->Data.DVT;
					loop =1;
					break;
				}
	}
	int exit = 0;
	int key,vtr;
	string tam2=q->Data.TenVT,tam3=q->Data.DVT;
	int slt = q->Data.SoLuongTon;
	int th=2;
	gotoxy(79+tam3.size(),7);
	HienThiDauNhay();
	char space;
	VATTU data;
	while(exit ==0)
	{
		while(!kbhit())
		{
			if(th==1)
			{
				vtr = 35+tam2.size();
			}
			else if(th ==2)
			{
				vtr = 79+tam3.size();
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
					VatTuHieuChinh();
					return;
				}
				else
				{
					XoaKhungYN();
					gotoxy(vtr,7);
					HienThiDauNhay();
				}
			}
		   
			else if((key >= 48 && key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key ==32)
			{
				if(th==1 && tam2.size() < 20)
				{
					gotoxy(vtr,7);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (tam2.size() ==0 || space == ' ') )
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
					tam2.insert(tam2.end(),1,(char)key);
				}
				else if(th==2 && tam3.size() <5)
				{
					gotoxy(vtr,7);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (tam3.size() ==0 || space == ' ') )
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
					tam3.insert(tam3.end(),1,(char)key);
				}
			}
			else if(key ==13||key ==9|| key == -32)
			{   
				if(th==1)
				{
					if(tam2.size()==0 )
					{
						tam2=q->Data.TenVT;
						gotoxy(35,7);
						cout << tam2;
					}
					else{
						gotoxy(79+tam3.size(),7);
						th=2;
					}
				}
				else if(th==2)
				{
					if(tam3.size()==0)
					{
						tam3=q->Data.DVT;
						gotoxy(79,7);
						cout << tam3;
					}
					else{
						
						if(veKhungYesNo("    Ban co muon thay doi khong ?",0))
						{
							
							strcpy(q->Data.TenVT,tam2.c_str());
							strcpy(q->Data.DVT,tam3.c_str());
							ContentRemoveCT();
							gotoxy(20,7);
							cout << q->Data.MaVT;
							gotoxy(35,7);
							cout << q->Data.TenVT;
							gotoxy(60,7);
							cout << slt;
							gotoxy(79,7);
							cout << q->Data.DVT;
							XoaKhungYN();
							veKhungTB("        Da sua thanh cong");
							system("cls");
							return;
						}
						else
						{
							gotoxy(20,7);
							cout << q->Data.MaVT;
							gotoxy(35,7);
							cout << q->Data.TenVT;
							gotoxy(60,7);
							cout << q->Data.SoLuongTon;
							gotoxy(79,7);
							cout << q->Data.DVT;
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
				if(th ==1 && tam2.size() >0 and vtr >= 35)
				{
					vtr--;
					gotoxy(vtr,7);
					cout << " ";
					gotoxy(vtr,7);
					tam2.erase(tam2.end()-1);
				
				}
				else if(th ==2 && tam3.size() >=0)
				{
					if(vtr==vtr-tam3.size())
					{
						gotoxy(35+tam2.size(),7);
						th=1;
					}
					else
					{
						vtr--;
						gotoxy(vtr,7);
						cout << " ";
						gotoxy(vtr,7);
						tam3.erase(tam3.end()-1);
					}
				}
			}
			else key = getch();
		}
	}
}
#endif
