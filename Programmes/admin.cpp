#include<iostream>
#include<vector>
#include<climits>
#include"teacher.h"
#include"student.h"
#include"admin.h"
using namespace std;

void admin_if(student &s,teacher &t)
{
int check;
cout<<"*******ADMIN'S MENU*******";
do
{cout<<"\n 1:Edit students info\n 2:Edit teachers info\n 3:Send holiday notice\n 4:EXIT\n";
cin>>check;

switch(check)
{
case 1:students(s);break;
case 2:teac_(t);break;
case 3:cout<<"Working";break;
case 4:return;
default:cout<<"INVALID INPUT";break;
}
}while(1);
}

void students(student &s)

{
cout<<"Press 1:READ FROM DATA BASE ,0:OverWrite the previous data base."<<endl;
int check;
cin>>check;
if(check)
{
//s.read();
s.display();
}
else
{
s.get_info();
s.display();
}
}

void teac_(teacher &t)
{
cout<<"Press 1:READ FROM DATA BASE ,0:OverWrite the previous data base."<<endl;
int check;
cin>>check;
if(check)
//t.read();
t.display();
else
{
t.get_info();
t.display();
}
}


