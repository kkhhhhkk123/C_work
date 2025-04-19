#include <iostream>
#include<fstream>
#include<string>
using namespace std;

void login();
void intoinfo();
void outinfo();
void menu();
void calculate_year();
void calculate_month();
void calculate_day();
void now();
void add();
void show();

typedef struct inmoney
{
    double work, house, other, sum;
}income;
typedef struct outmoney
{
    double food, life, study, other, sum;
}expense;
typedef struct money
{
    int year, mon, day;
    expense exp;
    income inc;
    double sum = inc.sum - exp.sum;

}Mon;

Mon record[100];
int num;//记录有记录的天数

int main()
{
    int a;
    login();
    intoinfo();
    menu();
sentence1:cout << "请输入命令: ", cin >> a;
    switch (a)
    {
    case 1:
        add();
        break;
    case 2:
        show();
        break;
    case 3:
        calculate_year();
        break;
    case 4:
        calculate_month();
        break;
    case 5:
        calculate_day();
        break;
    case 6:
        now();
        break;
    case 0:
        outinfo();
        exit(0);
        break;
    default:
        break;
    }
    goto sentence1;
}
void login()
{
    string username, userpassword;
    cout << "请输入用户名: ", cin >> username;
    cout << "请输入密码: ", cin >> userpassword;
    if ((username != "admin") || (userpassword != "123456"))
    {
        cout << "输入错误 " << endl;
        exit(0);
    }
}
void intoinfo()
{
    fstream file;
    file.open("record.xlsx");
    //file << "\n";
    for (int i = 1; i <= 100; i++)
    {
        int I = i - 1;
        file >> record[I].year, file << "\t";
        if (record[I].year == 0)
        {
            num = i - 1;
            break;
        }
        file >> record[I].mon, file << "\t";
        file >> record[I].day, file << "\t";

        file >> record[I].exp.food, file << "\t";
        file >> record[I].exp.life, file << "\t";
        file >> record[I].exp.study, file << "\t";
        file >> record[I].exp.other, file << "\t";
        file >> record[I].exp.sum, file << "\t";

        file >> record[I].inc.work, file << "\t";
        file >> record[I].inc.house, file << "\t";
        file >> record[I].inc.other, file << "\t";
        file >> record[I].inc.sum, file << "\t";

        file >> record[I].sum, file << "\n";
    }
    file.close();
}
void outinfo()
{
    ofstream fout;
    fout.open("record.xlsx");
    //fout << "yeaer \t month \t day \t food \t life \t study \t other \t expense_sum \t work \t house \t other \t income_sum \t sum \n ";
    for (int i = 1; i <= num; i++)
    {
        int I = i - 1;
        fout << record[I].year << "\t" << record[I].mon << "\t" << record[I].day << "\t"
            << record[I].exp.food << "\t" << record[I].exp.life << "\t" << record[I].exp.study << "\t" << record[I].exp.other << "\t"
            << record[I].exp.sum << "\t" << record[I].inc.work << "\t" << record[I].inc.house << "\t"
            << record[I].inc.other << "\t" << record[I].inc.sum << "\t" << record[I].sum << "\n";
    }
    fout.close();
}
void add()
{
    cout << "year: ", cin >> record[num].year;
    cout << "month: ", cin >> record[num].mon;
    cout << "day: ", cin >> record[num].day;
    cout << "input the expense \n" << "food: ", cin >> record[num].exp.food;
    cout << "life: ", cin >> record[num].exp.life;
    cout << "study: ", cin >> record[num].exp.study;
    cout << "other:  ", cin >> record[num].exp.other;
    cout << "input the income \n" << "work: ", cin >> record[num].inc.work;
    cout << "house: ", cin >> record[num].inc.house;
    cout << "other: ", cin >> record[num].inc.other;
    record[num].exp.sum = record[num].exp.food + record[num].exp.life + record[num].exp.study + record[num].exp.other;
    record[num].inc.sum = record[num].inc.work + record[num].inc.house + record[num].inc.other;
    record[num].sum = record[num].inc.sum - record[num].exp.sum;
    num += 1;
}
void calculate_year()
{
    int temp = record[0].year;
    int Inc, Exp, Sum;
    Inc = 0, Exp = 0, Sum = 0;
    for (int i = 1; i <= num; i++)
    {
        int I = i - 1;
        Sum += record[I].sum;
        Inc += record[I].inc.sum;
        Exp += record[I].exp.sum;
        if (record[I + 1].year != temp)
        {
            cout << temp << " year:income is " << Inc << " ,expense is " << Exp << " ,sum is " << Sum << " ." << endl;
            temp = record[I + 1].year;
            Sum = 0;
            Inc = 0;
            Exp = 0;
        }
    }
}
void calculate_month()
{
    int temp = record[0].mon;
    int Inc, Exp, Sum;
    Inc = 0, Exp = 0, Sum = 0;
    for (int i = 1; i <= num; i++)
    {
        int I = i - 1;
        Sum += record[I].sum;
        Inc += record[I].inc.sum;
        Exp += record[I].exp.sum;
        if (record[I + 1].mon != temp)
        {
            cout << record[I].year << "-" << temp << " income is " << Inc << " ,expense is " << Exp << " ,sum is " << Sum << " ." << endl;
            Sum = 0;
            Inc = 0;
            Exp = 0;
            temp = record[I + 1].mon;
        }
    }
}
void calculate_day()
{
    for (int i = 1; i <= num; i++)
    {
        int I = i - 1;
        cout << record[I].year << "-" << record[I].mon << "-" << record[I].day << " income is " << record[I].inc.sum
            << " , expense is " << record[I].exp.sum << " ,sum is  " << record[I].sum << " ." << endl;
    }
}
void now()
{
    int Sum, Inc, Exp;
    Sum = 0, Inc = 0, Exp = 0;
    for (int i = 1; i <= num; i++)
    {
        int I = i - 1;
        Sum += record[I].sum;
        Inc += record[I].inc.sum;
        Exp += record[I].exp.sum;
    }
    cout << "up to now,the income is " << Inc << " ,the expense is " << Exp << " ,the sum is " << Sum << " ." << endl;
}

void menu()
{
    cout << "************************************************" << endl;
    cout << "*       欢迎使用个人理财管理系统             *" << endl;
    cout << "************************************************" << endl;
    cout << "*=================主菜单===================*" << endl;
    cout << "*****  1.添加信息           2.显示信息   *****" << endl;
    cout << "****   3.查年收支结余信息   4.查月收支结余信息 ***" << endl;
    cout << "****   5.查日收支结余信息   6.到目前的情况  ****" << endl;
    cout << "****   0.退出并保存                         ****" << endl;
    cout << "*==========================================*" << endl;
}
void show()
{
    cout << "time\t\tfood\tlife\tstudy\tother\tsum\twork\thouse\tother\tsum\tsum" << endl;
    for (int i = num; i >= 1; i--)
    {
        int I = i - 1;
        cout << record[I].year << "-" << record[I].mon << "-" << record[I].day << "\t"
            << record[I].exp.food << "\t" << record[I].exp.life << "\t" << record[I].exp.study << "\t" << record[I].exp.other << "\t" << record[I].exp.sum << "\t"
            << record[I].inc.work << "\t" << record[I].inc.house << "\t" << record[I].inc.other << "\t" << record[I].inc.sum << "\t" << record[I].sum << endl;
    }
}
