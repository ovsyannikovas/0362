#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

void menu();//������ ����
int GetAllSubsets(int [], int);//��������� ���� ����������� ������� ���������
int GetOnlyKSubsets(int [], int, int);//��������� �-���������� �����������
int GetSubsetsWithNum(int [], int, int);//��������� ��������, ���������� ������������ �������
void MakingExtraArray(int [], int [], int, int);//��������� ��������������� �������
int CountingBits(int);//������� ���������� ������ � �������� ������ �����

int main()
{
    setlocale(LC_ALL, "rus");
    int choice, range = 0;
    menu();
    cin >> choice;
    switch (choice)
    {
       case 1:
           {
               cout << "����������, ������� ���������� ��������� � ���������" << endl;
               cin >> range;
               int sub[range];
               cout << "����������, ������� �������� ���������" << endl;
               for (size_t i = 0; i < range; i++)
               {
                   cin >> sub[i];
               }
               GetAllSubsets(sub,range);
               break;
           }
       case 2:
           {
               cout << "����������, ������� ���������� ��������� � ���������" << endl;
               cin >> range;
               int sub[range];
               cout << "����������, ������� �������� ���������" << endl;
               for (size_t i = 0; i < range; i++)
               {
                   cin >> sub[i];
               }
               int k;
               cout << "����������, ������� ���������� ��������� � ������� �������������" << endl;
               cin >> k;
               GetOnlyKSubsets(sub,range,k);
               break;
           }
       case 3:
           {
               cout << "����������, ������� ���������� ��������� � ���������" << endl;
               cin >> range;
               int sub[range];
               cout << "����������, ������� �������� ���������" << endl;
               for (size_t i = 0; i < range; i++)
               {
                   cin >> sub[i];
               }
               int x;
               cout << "����������, ������� �����:" << endl;
               cin >> x;
               GetSubsetsWithNum(sub,range,x);
               break;
           }
       default: cout << "���� ������� �������� �����" << endl; break;
    }
    return 0;
}
//������ ����, ������ ����������
void menu()
{
    cout << "����������, �������� ����������� ��������:" << endl;
    cout << "1 - �������� ��� ������������ ������� ���������" << endl;
    cout << "2 - �������� ��� �-���������� ������������" << endl;
    cout << "3 - �������� ��� ������������, ���������� �������\n" << endl;
}
/*������� GetAllSubsets �������� �� ���� �������� � ���������� ��������� (� ������ ������ ������ sub) � ���������� ��������� � ���� ���������(N);
������� GetAllSubsets ������� ��� ������������ ��������� � ���������� ���������;
���� ������� ���������� ���������, � ����� �������� ����
*/
int GetAllSubsets(int sub[], int N)
{
    int deg;
    deg = pow(2, N);//���������� ���������� ����� ������������ ��� 2 � ������� N(���������� ��������� ���������)
    for (size_t i = 0; i < deg; i++)//������� ����� (�������������� � ������� ����)
    {
        cout << "{";
        for (size_t j = 0; j < N; j++)//������� �����
                    if (i & (1 << j))//��� �������, ��� j-� ��� ����������, ����� ���������� j-� ������� ���������
                     cout << sub[j];
        cout << "}" << endl;
    }
    return 0;
}
/*������� GetOnlyKSubsets �������� �� ���� �������� � ���������� ��������� (� ������ ������ ������ sub),���������� ��������� � ���� ���������(N)
� ���������� ��������� � ������� �������������(�);
������� GetOnlyKSubcets ������� ��� ������������, ���������� ������������ ���������� ���������;
���� ������� ���������� ���������, � ����� �������� ����
*/
int GetOnlyKSubsets(int sub[], int N, int K)
{
    if (K > N) {cout << "���-�� ����� �� ���" << endl; return 0;}
    if (K == 0) cout << "{}"<< endl;
    int deg;
    deg = pow(2, N);//���������� ���������� ����� ������������ ��� 2 � ������� N(���������� ��������� ���������)
    int score[deg];
    for (int i = 1; i < deg; i++)//������� ����� (�������������� � ������� ����)
    {
        score[i] = CountingBits(i);
        if(score[i] == K){
        cout << "{";
        for (int j = 0; j < N; j++)//������� �����
                    if (i & (1 << j))//��� �������, ��� j-� ��� ����������, ����� ���������� j-� ������� ���������
                      {
                          cout << sub[j];
                      }
        cout << "}" << endl;
        }
    }
    return 0;
}
/*������� CountingBits ������� ���������� ������ � �������� ������ �����;
������� �� ���� ��������� ����� ����� x(� ������ ������, ����� ������������)*/
int CountingBits(int x)
{
    int b = 0;
    while (x > 0)
    {
        if (x % 2 != 0) b++;
        x /= 2;
    }
    return b;
}
/*������� GetSubsetsWithNum �������� �� ���� �������� � ���������� ��������� (� ������ ������ ������ sub), ���������� ��������� � ���� ���������(N)
� �����, ������� ������ �������������� � �������������;
������� GetSubsetsWithNum ������� ��� ������������ (��������� � ���������� ���������), ���������� ������������ �������;
���� ������� ���������� ���������, � ����� �������� ����
*/
int GetSubsetsWithNum(int sub[], int N, int X)
{
    int p[N-1];//�������������� ������ ��� ���������� �����, �� ������ ��������
    int deg;
    MakingExtraArray(sub, p, N, X);
    //�������� ����� �� �� ��������, ��� � � ���������� ����������� ���������
    deg = pow(2, N-1);
    for (size_t i = 0; i < deg; i++)
    {
        cout << "{" << X;
        for (size_t j = 0; j < N-1; j++)
                    if (i & (1 << j)) cout << p[j];
        cout << "}" << endl;
    }
    return 0;
}
/* ������� MakingExtraArray ������� ��� ����� ������� ���������, �� ������ ��������, � ���������� �������������� ������ �� ���� �����;
sub[] - ����������� ���������; p[] - �������������� ������; num - ���������� ��������� � ����������� ���������;
arg - �������� ����� (�����, � ������� �� ������ ����� ��� ������������);
*/
void MakingExtraArray(int sub[], int p[], int num, int arg)
{
    int ch;//������ ����������, ����� �� �������� ������� �������
    for (size_t i = 0; i < num; i++)//� ����� ����������� ��������� ������ �������, ������ ��������, � ������ ��� � ���������
    {
        if (sub[i] == arg)
        {
            ch = sub[i];
            sub[i] = sub[num-1];
            sub[num-1] = ch;
        }
    }
    for (size_t i = 0; i < num-1; i++)//�������� ����� � �������������� ������
    {
        p[i] = sub[i];
    }
}
