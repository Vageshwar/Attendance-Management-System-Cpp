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
    char ab[80];
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
    std::cout <<"\nEnter Date (DD\\MM\\YYYY): ";
    std::cin >> a.date;
    std::cout <<"\nEnter Absent number seperated by comma\n press enter to save: ";
   /*ch = _getch();
    while(ch != 13){//character 13 is enter
        cout << ch;
        temp[i]=ch;i++;
        ch = _getch();
    }*/
    cin >> a.ab;
    int l;
    l = strlen(a.ab);
    i =l;
    while(i!=0)
    {
        a.ab[i]=a.ab[i-1];
        i--;
    }
    a.ab[0]='{';
    a.ab[l+1]='}';
    return 1;
}

void view()
{
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Attendance List*****************************");
    gotoxy(2,2);
    printf("Course                  Absent_No                 Date");
    j=4;
    fp=fopen("attd.dat","r");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
	gotoxy(2,j);
	cout<<a.course;
	gotoxy(26,j);
	printf("%s ",a.ab);
	gotoxy(52,j);
	cout<<a.date;
	printf("\n\n");
	j++;
    }
}
void take()
{
    string c;
    cout<<"Enter Any Sub name";
    cin>>c;
    system("cls");
	int i;
	system("cls");
	fp=fopen("attd.dat","ab+");
	if(getdata(c)==1)
	{
	fseek(fp,0,SEEK_END);
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
    cout << "Attendance Taken\n\n";
	}
	view();
	//_getch();

}



void takeatdd()
{
    system("cls");
    int i;
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Only Present   ");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Only Absent");
	printf("\xDB\xDB\xDB\xDB\xB2 3. Return");
	gotoxy(20,13);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,14);
	printf("Enter your choice:");
	switch(_getch())
	{
		case '1':
		take();
		break;
        case '2':
		take();
	    break;
		case '3':
	    {
		system("cls");
		gotoxy(16,3);
		printf("Created by\n\t\tRoll numbers");
		gotoxy(16,4);
		printf("\n\t\t49,50,51,52 ");
		gotoxy(16,5);
		printf("\n\nReturning\n");
		for(i=0;i<5;i++)
        {
            printf(".\n");
            delay(300);
        }
		view_staff();
	    }
	    default:
		{
		gotoxy(10,23);
		printf("\aWrong Entry!!Please re-entered correct option");
		if(_getch())
		takeatdd();
		}
    }
}
