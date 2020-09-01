#ifndef BACK_END_H
#define BACK_END_H
#include"CTDL.h"
							// BAT DAU HAM PHU
////////////////////////xoa khoang trang
string kt32(string &str)
{
    int size = str.length();
    for(int j = 0; j<=size; j++)
    {
        for(int i = 0; i <=j; i++)
        {
            if(str[i] == ' ' && str[i+1] == ' ')
            {
                str.erase(str.begin() + i);
            }
            else if(str[0]== ' ')
            {
                str.erase(str.begin());
            }
            else if(str[i] == '\0' && str[i-1]== ' ')
            {
                str.erase(str.end() - 1);
            }
        }
    }
    return str;
}
//////////////////////////////
string to_String(int num)
{
	string kq;
	ostringstream convert;
	convert << num;
	kq = convert.str();
	return kq;
}
string to_Currency(int num)
{
	int x;
	int A[20];
	int nArr=0;
	while(num!=0)
	{
		x =num%10;
		num =num/10;
		A[nArr++] = x;
	}
	string str="";
	for(int i =0; i<nArr; i++)
	{
		if(i%3==0&&i != 0)
		{
			str+=",";	
		}
		str+=to_String(A[i]);
	}
	string str1;
	for(int j = str.length()-1; j >=0 ; j--)
	{
			str1+=str.at(j);
	}
	return str1;
}
void Canhbao(string s,int xMap,int yMap)
{
    do
    {
       textcolor(12);
        gotoxy(xMap,yMap);
       	cout<<s;//hien thi 1 chuoi ki tu
        Sleep(500);
        gotoxy(xMap,yMap);
        for(int i=0;i<s.size();i++) cout<<" ";
        Sleep(200);
        textcolor(0);
    }
    while(!kbhit());
    gotoxy(xMap,yMap);
	for(int i=0;i<s.size();i++) cout<<" ";
	textcolor(7);
}
// Ham lay nam hien tai
int LayThoiGianNam(){
	time_t now = time(0); // lay thoi gian dua tren he thong hien tai
	
	tm *laytime = localtime(&now); 
	return 1900+laytime->tm_year;
}
void LayThoiGian(int &ngay, int &thang,int &nam){
	time_t hienTai = time(0);
	tm *ltm = localtime(&hienTai);
	ngay = ltm->tm_mday;
	thang = ltm->tm_mon +1;
	nam = ltm->tm_year +1900;
}
void ContentRemoveCT()
{
	gotoxy(19,7);
	cout << "            ";
	gotoxy(34,7);
	cout << "                    ";
	gotoxy(56,7);
	cout << "                  ";
	gotoxy(77,7);
	cout << "       ";
}

#endif
