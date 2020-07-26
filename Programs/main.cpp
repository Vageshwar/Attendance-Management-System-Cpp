#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<time.h>
#include<dos.h>
 using namespace std;

COORD coord = {0, 0};
COORD max_res,cursor_size;
 void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
 void welcome()
 {
    system("cls");
   char d[30]="Attendance Management System";
   char ch;
   int i=0,j;
    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
    delay(50);
    printf("*");
    }
    for(j=0;j<28;j++)
   {
   delay(50);
   printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
   delay(50);
   printf("*");
   }
   gotoxy(10,10);
   gotoxy(15,7);
 }
 int Login();
 int verifycredentials(string ,string);
 int view_student();
 int view_staff();
 int view_admin();
 int edit();
 int extract_roll_no(string );
 int pass_verify(string );


 int main()
 {

    welcome();
    if(!Login())
    {
        system("cls");
        cout << "\t\t\t\tLog in failed Try again (2 chances left)\n";
        if(!Login())
        {
            cout << "Log in failed Try again (1 chance left)\n";
            if(!Login())
                cout << "***\n\tLog in failed \nTry later\n";
        }

    }

 }

 int Login()
{
    char ch;
    string user,pass;
    cout<<"\tEnter Login Credentials\n";
    cout<<"Username: ";
    cin>>user;
    cout<<"\nPassword: ";

    ch = _getch();
    while(ch != 13){//character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout<<"\n\n";
    if(!pass_verify(pass))
    {
        cout<<"Invalid Password"<<endl;
        return 0;
    }
    //cout<<".....";
    //delay(2000);
    //cout<<"...................................";
    return verifycredentials(user,pass);
}

 int verifycredentials(string user,string pass)
 {
     int flag1=0,flag2=0;
     ifstream fp;
     fp.open("Login_stud.dat");

        if(fp)
        {

            string temp;
            while(getline(fp,temp))
            {
                if(temp==user)
                    flag1=1;
                if(temp==pass)
                    flag2=1;
            }
        }
        if(flag1==1 && flag2==1)
        {
            cout<<"\t\t\t\t\t----------Student Log in----------\n";
            extract_roll_no(user);
            view_student();
            return 0;
        }
        else
            {
                ifstream fpt;
                fpt.open("Login_staff.dat");
                flag1 = flag2 = 0;

                if(fpt)
                {

                    string temp;
                    while(getline(fpt,temp))
                    {
                        if(temp==user)
                            flag1=1;
                        if(temp==pass)
                            flag2=1;
                    }
                }
                if(flag1==1 && flag2==1)
                {
                    cout<<"\t\t\t\t\t----------Staff Log in----------\n";

                    view_staff();
                }
                else
                    return 0;
            }
 }

 int view_student()
 {
     cout<<"\n\n\t\t\t\t\tThis is Students View Page\n";
     ifstream sv;
     string temp;
     sv.open("attd.dat");
     if(sv)
     {
         cout<<"Course Name             Attendance Percentage"<<endl;
         while(getline(sv,temp))
         {
             cout<<temp;
         }
     }
 }

 int view_staff()
 {

 }
int pass_verify(string pass)
{
    int len,i;
    bool len_flag,u_flag,l_flag;
    len_flag=u_flag=l_flag=0;
    len = pass.size();
    if(len>=8)
        len_flag=1;
    for(i=0;i<len;i++)
    {
         if((pass[i]>=48&&pass[i]<=58))
        {
            u_flag=1;

            break;
        }
        else
        u_flag=0;
    }
    for(i=0;i<len;i++)
        if((pass[i]>=65&&pass[i]<=90))
        {
            l_flag=1;

            break;
        }
        else
            l_flag=0;
    if(len_flag==0 || u_flag==0 || l_flag==0)
    {
        return 0;
    }
    return 1;
}
int extract_roll_no(string username)
{
    string temp;
    int i,len,roll;
    len=username.size();
    temp[0] = username[len-2];
    temp[1] = username[len-1];
    temp[2] = '\0';
    //cout<<temp;
    return atoi(temp.c_str());
}
