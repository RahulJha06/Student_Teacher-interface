#include<iostream>
#include<climits>
#include<vector>
#include<fstream>
#include"teacher.h"
#include"submission.h"
using namespace std;

template<class t>
inline void check(t &t1)
{
do
{
cin.clear();
cin.ignore(INT_MAX,'\n');
cin>>t1;
}while(cin.fail());
}



     teacher::teacher()
        {
        cout<<"Enter the no of teachers";
        cin>>size;
        t.resize(size);
        }
       void teacher:: get_info()
        {
          cout<<"Enter the details of the teachers";
                for(int i=0;i<size;i++)
                {
                cin.ignore();
                cout<<"Name";getline(cin,t[i].name);
              //  cout<<"Contact details";getline(cin,t[i].cont);
              //  cout<<"Address";getline(cin,t[i].address);
                cout<<"Enter the cabinet number of the teacher";
                getline(cin,t[i].cab_no);
                cout<<"Specialization of the teacher";getline(cin,t[i].spec);
                t[i].review=0;
                cout<<endl;
                }
               /* int x;
                cout<<"DO U WANT TO SAVE THE ENTRIES(1-for yes 0-for no)"; 
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin>>x;*/
                        
        }
  void teacher::get_info(int id)
    {
        
                cout<<"Enter your details"<<endl;
                          cin.ignore();
                cout<<"Name";getline(cin,t[id].name);
                cout<<"Contact details";getline(cin,t[id].cont);
                cout<<"Address";getline(cin,t[id].address);
               /* cout<<"Enter the cabinet number of the teacher";
                getline(cin,t[i].cab_no);*/
                cout<<"Your Specialization";getline(cin,t[id].spec);
                cout<<endl;
                
             
    }
   void teacher::display() 
    {
        for(int i=0;i<size;i++)
         {
          cout<<"DETAILS OF ALL THE TEACHERS =>";
          cout<<t[i].name<<" "<<t[i].cab_no<<" "<<t[i].spec<<" "<<t[i].cont;
         }
     }
   void teacher::display(int rn)  
    {
        
         
          cout<<"DETAILS OF ALL THE TEACHERS =>";
          cout<<t[rn].name<<" "<<t[rn].cab_no<<" "<<t[rn].spec<<" "<<t[rn].cont;
         
    }   
    bool teacher:: check(int id)
    {
    if(id<t.size())
    return true;
    else 
    return false;
    }
    void teacher::save()
    {
    fstream f;
    f.open("teachers.txt");
    while(f)
        {
        for(int i=0;i<t.size(); i++)
        f<<i<<"\t"<<t[i].name<<"\t"<<t[i].cab_no<<"\t"<<t[i].cont<<"\t"<<t[i].address<<"\t"<<t[i].spec<<"\t"<<t[i].review<<endl;
        
        break; }
     f.close();
     return;   
   
    }
    
    //friend void attendance();  
    int teacher::review(int r)
    {if(r!=1)
        {
        cout<<"Enter the rating of the teacher out of 10";
        for(int i=0;i<t.size();i++)
                {int review;
                        do{
                                cin>>review;
                                if(cin.fail())
                                check(review);
                          }while(0>review||review>10);
        if(t[i].review==0)
                t[i].review=review;
        else                      
                t[i].review=(t[i].review+review)/2; 
                }
       return 1;
       }
     else if(r==1)             
      {cout<<"Review already completed";return 1;}
      
    }

        void teach_menu(teacher &t,int id)
     {
        int cho,x;
        
        cout<<"***TEACHERS MENU***"<<endl;
        cout<<"Select your choice"<<endl;
       do{ 
                cout<<"\n 1:VIEW YOUR DETAILS\n 2:EDIT YOUR DETAILS\n 3:TAKE ATTENDANCE\n 4:Update subission status\n 5:EXIT"<<endl;
                  cin>>cho;                         
                if(cin.fail())
                check(cho);
                else if(!cin.fail())       
         switch(cho)
                {
                case 1:t.display(id);break;
                case 2:t.get_info(id);break;
                case 3://t.attendance(id);
                        cout<<"Working";break;
                case 4:teach_setsub();break;
                case 5:{cout<<"DO you want to save the changes before leaving press 1:Save&Exit  0:Exit withouy saving";
                        cin.ignore();
                        cin>>x;
                      // if(cin.fail())
                      // check(x);
                        if(x)
                      {t.save();return;}
                       else
                       return;
                       }
                default:cout<<"Enter a valid input";
                }
           }while(cho!=4);
        }
   
    void teach_if(teacher &t1)
    {
        int id;
         cout<<"Enter your teachers id no=";
        cin>>id;
        if(cin.fail())
        check(id);        
         if(t1.check(id))
        teach_menu(t1,id);
         else
        return;//corr(t1);//correction
    }

         

