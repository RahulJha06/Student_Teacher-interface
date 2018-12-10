
#include<iostream>
#include<cstring>
#include<climits>
#include<vector>
#include<fstream>
using namespace std;
class student
{
int size=0;
struct stud
{
string name;
int atd;//attendance
string cls;
char div;
string cont;
string pass;//password
string address;
};
vector<stud> s;
public:
student();
void get_info();
void get_info(int);
void display();
void display(int);
bool check(int);

};

void stud_if(student &s);
void stud_menu(int ,student);

