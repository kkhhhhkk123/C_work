#include<fstream>
#include<string>
#include<iostream> 
using namespace std;
typedef struct STU
{
    long long id;
    string name;
    string sex;
    double score[4];
    double sum_score;
    double aver_score;
}stu;
int num = 0;//全局变量，记录学生的数量
stu per[50];
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
        file >> per[I].id, file << "\t";
        if (per[I].id == 0)
        {
            num = i - 1;
            break;
        }
        file >> per[I].name, file << "\t";
        file >> per[I].sex, file << "\t";
        file >> per[I].score[0], file << "\t";
        file >> per[I].score[1], file << "\t";
        file >> per[I].score[2], file << "\t";
        file >> per[I].score[3], file << "\t";
        file >> per[I].sum_score, file << "\t";
        file >> per[I].aver_score, file << "\n";
    }
    file.close();
}
void show(int n)
{
    cout << per[n].id << "\t" << per[n].name << "\t" << per[n].sex << "\t" << per[n].sex << "\t";
    cout << per[n].score[0] << "\t" << per[n].score[1] << "\t" << per[n].score[2] << "\t" << per[n].score[3] << "\t";
    cout << per[n].sum_score << "\t" << per[n].aver_score << "\t" << endl;
}
void outinfo()
{
    ofstream fout;
    fout.open("result.xlsx");
    for (int i = 1; i <= num; i++)
    {
        int I = i - 1;
        fout << per[I].id << "\t" << per[I].name << "\t" << per[I].sex << "\t"
            << per[I].score[0] << "\t" << per[I].score[1] << "\t" << per[I].score[2] << "\t" << per[I].score[3] << "\t"
            << per[I].sum_score << "\t" << per[I].aver_score << "\n";
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
    cout << "id: ", cin >> per[index - 1].id;
    cout << "name: ", cin >> per[index - 1].name;
    cout << "sex: ", cin >> per[index - 1].sex;
    cout << "C score: ", cin >> per[index - 1].score[0];
    cout << "math score: ", cin >> per[index - 1].score[1];
    cout << "English : ", cin >> per[index - 1].score[2];
    cout << "Chinses: ", cin >> per[index - 1].score[3];
    per[index - 1].sum_score = per[index - 1].score[0] + per[index - 1].score[1] +
        per[index - 1].score[2] + per[index - 1].score[3];
    per[index - 1].aver_score = per[index - 1].sum_score / 4;
}
void menu()
{
    cout << "************************************************" << endl;
    cout << "*       欢迎使用学生成绩管理系统                   *" << endl;
    cout << "************************************************" << endl;
    cout << "*=================主菜单===================*" << endl;
    cout << "*****  1.显示学生信息       2.添加学生信息   *****" << endl;
    cout << "****   3.删除学生信息       4.查询学生信息   *****" << endl;
    cout << "****   5.修改学生信息       0.退出（并保存）  ****" << endl;
    cout << "*==========================================*" << endl;
}
void add()
{
    cout << "id: ", cin >> per[num].id;
    cout << "name: ", cin >> per[num].name;
    cout << "sex: ", cin >> per[num].sex;
    cout << "C score: ", cin >> per[num].score[0];
    cout << "math score: ", cin >> per[num].score[1];
    cout << "English : ", cin >> per[num].score[2];
    cout << "Chinses: ", cin >> per[num].score[3];
    per[num].sum_score = per[num].score[0] + per[num].score[1] +
        per[num].score[2] + per[num].score[3];
    per[num].aver_score = per[num].sum_score / 4;
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
                stu temp;
                temp = per[J];
                per[J] = per[J + 1], per[J + 1] = temp;
            }
        }
    }
}