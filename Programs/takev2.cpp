#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<time.h>
#include<dos.h>
#include<iostream>

using namespace std;
FILE *fp,*ft,*fs;

COORD coord = {0, 0};
COORD max_res,cursor_size;
 void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct present
{
    std::string course,date;
    std::string pr[80];
};
struct absent
{
    std::string course,date;
    int ab[80];
};

struct present p;
struct absent a;


int* stoi(string str1, string str2)
{

}

int getdata(std::string course)
{
    string temp;
    char ch;
    int i;
    i=0;
    a.course=course;
    std::cout <<"\nEnter Date (DD\\MM\\YY): ";
    std::cin >> p.date;
    std::cout <<"\nEnter Absent number seperated by space\n press enter to save: ";
   ch = _getch();
    while(ch != 13){//character 13 is enter
        temp.push_back(ch);
        cout << ch;
        ch = _getch();
    }
    for(i = 0; temp[i] != '\0'; i++)
      a.ab[i] = temp[i];
    return 1;
}

void view()
{
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Attendance List*****************************");
    gotoxy(2,2);
    printf("Course               Absent_No                 Date");
    j=4;
    fp=fopen("attd.dat","r");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
	gotoxy(2,j);
	printf("%s",a.course);
	gotoxy(26,j);
	printf("%s",a.ab);
	gotoxy(52,j);
	printf("%s",a.date);
	printf("\n\n");
	j++;
    }
}

int main()
{
    std::string c;
    c = "DLD";
    system("cls");
	int i;
	system("cls");
	fp=fopen("attd.dat","a+");
	if(getdata(c)==1)
	{
	fseek(fp,0,SEEK_END);
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
	std::cout << "Attendance Taken\n\n";
	}
	view();
	//_getch();

}
