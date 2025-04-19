#include<fstream>
#include<string>
#include<iostream> 
using namespace std;
typedef struct tongxulu
{
    string name;
    string id;
    char sex[5];
    string major;
    int classnumber;
    char room[9];
    string home;
    string phonenum;
    string qq;
    string wechat;
}tongxu;
int num = 0;//全局变量，记录学生的数量
tongxu per[50];
void intoinfo();        //导入数据到程序
void show(int n);       //显示数据
void modifyinfo();      //修改数据
void outinfo();         //将程序中的数据导出
int search_index();     //通过名字查询，并返回索引
void menu();            //生成菜单
void add();             //添加
void delect();          //删除
void sort();			//排序
int main()
{
    int a;
    intoinfo();
    menu();
sentence1:  cout << "输入命令：", cin >> a;
    switch (a)
    {
    case 1:
        for (int i = 1; i <= num; i++)
        {
            int I = i - 1;
            show(I);
        }
        break;
    case 2:
        add();
        break;
    case 3:
        delect();
        break;
    case 4:
        show(search_index() - 1);
        break;
    case 5:
        modifyinfo();
        break;
    case 0:
        sort();
        outinfo();
        exit(0);
        break;
    default:
        break;
    }
    goto sentence1;  //每次switch执行命令之后重新执行，直到a！=0才
}
void intoinfo()
{
    fstream file;
    file.open("result.xlsx");
    for (int i = 1; i <= 50; i++)
    {
        int I = i - 1;
        file >> per[I].name, file << "\t";
        file >> per[I].id, file << "\t";
        file >> per[I].sex, file << "\t";
        file >> per[I].major, file << "\t";
        file >> per[I].classnumber, file << "\t";
        if (per[I].classnumber == 0)
        {
            num = i - 1;
            break;
        }
        file >> per[I].room, file << "\t";
        file >> per[I].home, file << "\t";
        file >> per[I].phonenum, file << "\t";
        file >> per[I].qq, file << "\t";
        file >> per[I].wechat, file << "\n";
    }
    file.close();
}
void show(int n)
{
    cout << per[n].name << "\t" << per[n].id << "\t" << per[n].sex << "\t" << per[n].major << "\t";
    cout << per[n].classnumber << "\t" << per[n].room << "\t" << per[n].home << "\t" << per[n].phonenum << "\t";
    cout << per[n].qq << "\t" << per[n].wechat << "\t" << endl;
}
void outinfo()
{
    ofstream fout;
    fout.open("result.xlsx");
    for (int i = 1; i <= num; i++)
    {
        int I = i - 1;
        fout << per[I].name << "\t" << per[I].id << "\t" << per[I].sex << "\t" << per[I].major << "\t" << per[I].classnumber << "\t"
            << per[I].room << "\t" << per[I].home << "\t" << per[I].phonenum << "\t" << per[I].qq << "\t" << per[I].wechat << "\n";
    }
    fout.close();
}
int search_index()
{
    string object_name;
    int object_index;
    cout << "input the name: ";
    cin >> object_name;
    for (int i = 1; i <= num; i++)
    {
        if (object_name == per[i - 1].name)
        {
            return i;
        }
    }
}
void modifyinfo()
{
    int index;
    index = search_index();
    cout << "his information:" << endl;
    show(index - 1);
    cout << "name: ", cin >> per[index - 1].name;
    cout << "id: ", cin >> per[index - 1].id;
    cout << "sex: ", cin >> per[index - 1].sex;
    cout << "major: ", cin >> per[index - 1].major;
    cout << "classnumber: ", cin >> per[index - 1].classnumber;
    cout << "room: ", cin >> per[index - 1].room;
    cout << "home: ", cin >> per[index - 1].home;
    cout << "phonenum: ", cin >> per[index - 1].phonenum;
    cout << "qq: ", cin >> per[index - 1].qq;
    cout << "wechat: ", cin >> per[index - 1].wechat;
    cout << "modify successfuly" << endl;
}
void menu()
{
    cout << "************************************************" << endl;
    cout << "*       欢迎使用学生通讯录管理系统             *" << endl;
    cout << "************************************************" << endl;
    cout << "*=================主菜单===================*" << endl;
    cout << "*****  1.显示学生信息       2.添加学生信息   *****" << endl;
    cout << "****   3.删除学生信息       4.查询学生信息   *****" << endl;
    cout << "****   5.修改学生信息       0.退出（并保存）  ****" << endl;
    cout << "*==========================================*" << endl;
}
void add()
{
    cout << "name: ", cin >> per[num].name;
    cout << "id: ", cin >> per[num].id;
    cout << "sex: ", cin >> per[num].sex;
    cout << "major: ", cin >> per[num].major;
    cout << "classnumber: ", cin >> per[num].classnumber;
    cout << "room: ", cin >> per[num].room;
    cout << "home: ", cin >> per[num].home;
    cout << "phonenum: ", cin >> per[num].phonenum;
    cout << "qq: ", cin >> per[num].qq;
    cout << "wechat: ", cin >> per[num].wechat;
    num += 1;//学生数量加1
}
void delect()
{
    string obj_name;
    cout << "输入你想删除的名字：", cin >> obj_name;
    for (int i = 1; i < num; i++)
    {
        int I = i - 1;
        if (obj_name == per[I].name)
        {
            for (int j = i; j < 50; j++)
            {
                int J = j - 1;
                per[J] = per[J + 1];
            }
        }
    }
    cout << "delect successfuly" << endl;
    num -= 1;//学生数量减1
}
void sort()
{
    for (int i = 1; i <= num; i++)
    {
        int I = i - 1;
        for (int j = 1; j < num; j++)   //采取选择排序
        {
            int J = j - 1;
            if (per[J].id >= per[J + 1].id)
            {
                tongxu temp;
                temp = per[J];
                per[J] = per[J + 1], per[J + 1] = temp;
            }
        }
    }
}