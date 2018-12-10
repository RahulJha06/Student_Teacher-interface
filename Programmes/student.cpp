#include<iostream>
#include<climits>
#include<vector>
#include"student.h"
#include"timetable.h"
#include"submission.h"
using namespace std;

student::student()
   {
    cout<<"Enter the number of students in the class";cin>>size;
        while(cin.fail())
        {
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "ENTER the number of student again.\n";
        cin >>size;
        }
        s.resize(size);
   }

void student::get_info()
    {
     cout<<"Enter the details of the student";
     for(int i=0;i<size;i++)
       {
        cin.ignore();
        cout<<"Name";getline(cin,s[i].name);
        cout<<"Class";getline(cin,s[i].cls);
     
       }
     } 
void student::get_info(int rn)
   {
    cout<<"Enter your details=>"<<endl;
        
         {    cin.ignore();                                
          cout<<"Contact details =>";getline(cin,s[rn].cont);
          cout<<"Address =>";getline(cin,s[rn].address);
          
         }
         cout<<endl;
   }
void student::display()
  {
   for(int i=0;i<size;i++)
    {
    cout<<s[i].name<<" "<<s[i].cls<<"  ";          
    cout<<s[i].cont<<" "<<s[i].address<<" "<<s[i].address<<endl;
    }
  }
void student::display(int rn)
 {
  cout<<s[rn].name<<" "<<s[rn].cls<<" "<<s[rn].cont<<" "<<s[rn].address<<" "<<s[rn].atd<<endl;
 }
        
bool student::check(int rn)
{
 if(rn<s.size())
   return true;
 else 
   return false;
}
 /*char* student::create_new()
 {
 char *s;
 cin.ignore();
 cout<<"Enter the name of the file";
 getline(cin,*s);
 fstream *fs=new fstream(*s);
 return *s;
 }
*/
void stud_menu(int rn,student s1)
{
 cout<<"******MENU********";
 cout<<"Select your choice";
 cout<<"1:Edit info \n 2:View info \n 3:Check Attendance\n 4:View timetable\n 5:Check submission\n "<<endl;
 int cho;//choice
 cin>>cho;
 switch(cho)
    { 
      case 1:s1.get_info(rn);break;
      case 2:s1.display(rn);break;
      case 3:cout<<"Work in progress";break;
      case 4:tt_display();break;
      case 5:stud_chsub();break;
      default: cout<<"INVALID CHOICE";
    }
     cout<<"Do u wish to continue";
                         cout<<"Press 1 for yes and 0 to exit";
                         int x;
                         cin>>x;
                         if(x)
                         stud_menu(rn,s1);
                          else return;
                }

        void stud_if(student &s1)//student interface
                {       
                        cout<<"Enter the roll number of the student";
                        int rn;
                        cin>>rn;
                        if(cin.fail())
                        {
                        
                        cin.ignore();
                        
                        }
                    if(s1.check(rn))
                        stud_menu(rn,s1); 
                    else
                       cout<<"Sorry roll number is not registerd please talk to your teacher or the admin";
                     
                       cout<<"Do u wish to enter the roll no again";
                       
                       int x=0;//temporary variable to form the loop
                     do
                      {
                        cout<<"Press 1 for yes and 0 for exit";
                        cin>>x;
                      if(x==1)
                        stud_if(s1);
                      else if(x==0)
                         return; 
                      else
                       {
                        cin.ignore(INT_MAX,'\n');
                        cout<<"Wrong input";
                        
                       }
                      }while(x!=1&&x!=0);
                  }        
