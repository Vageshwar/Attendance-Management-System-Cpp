#include<cstdio>
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

string extract_dept()
{
    int i=0;
    char dept1[3];
    string username;
    username = "CSE.staff1";
    while(username[i]!='.')
    {
        dept1[i]=username[i];
        i++;
    }
    dept1[i]='\0';
    std::string dept(dept1);
    return dept;

}

void only_prest(fstream f)
{
}
void only_abst(fstream f);


int takeatdd()
{
    string course;
    int roll;
    roll =1;
    int s;
    cout << "\n\n\tSelect Course\n\n\t\t1. DLD \n\n\t2. COA\n\n\t3. SE\n\n\t4. OOP\n\n\t";
    cin >> s;
    switch(s)
    {
    case 1:
        course = "DLD.dat";
        break;
    case 2:
        break;
    case 3:
        break;
    default :
        cout << "Invalid Input\n\n\t";
    }
    fstream file(course.c_str());
    cout <<"\n\n\t Take attendance of\n\n\t\t1. Only absent Numbers\n\n\t2. Only present Numbers\n\n";
    cin>>s;
    switch(s)
    {
    case 1:
        only_prest(file);
        break;
    case 2:
        only_abst(file);
        break;
    }
}
