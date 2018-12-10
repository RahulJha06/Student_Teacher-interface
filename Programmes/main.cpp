#include<iostream>
#include<vector>
#include<climits>
#include"teacher.h"
#include"student.h"
#include"admin.h"
using namespace std;
#define clr cout<<"\033[H\033[2J";
int check_password(int user)
{
string pass;
cout<<"Enter your password";
cin>>pass;
switch(user)
{
case 1:{if(pass=="ADMIN")
        return 1;
        else 
        return 0;break;}
case 2:{if(pass=="STUDENT")
        return 1;
        else 
        return 0;break;
        }
case 3:{if(pass=="TEACHER")
        return 1;
        else 
        return 0;break;
        }             
}
}
int main()
{
clr;
student s;
teacher t;
int check;
do
{
cout<<"1:ADMIN/ 2:STUDENT/ 3:TEACHER"<<endl;
int user;
cin>>user;
if(check_password(user))
{switch(user)
{
case 1:admin_if(s,t);break;
case 2:stud_if(s);break;//open student interface
case 3:teach_if(t);break;
default:cout<<"The input is invalid";      
}
cout<<"Press 1 to continue and 0 to exit"<<endl;
cin>>check;
}
else
cout<<"Wrong password input";
cout<<"Press 1 to continue and 0 to exit";
cin>>check;
}while(check); 
return 0;
}
