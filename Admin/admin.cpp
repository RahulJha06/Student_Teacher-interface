/*1.Admin's will need to be preconfigured

2.Privilege level.
3.Registration of a student(Call students routine).
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;

class Admin
{
  fstream admin;
  struct admin_detail
  {
    string name,phone_no,passwd="12345";
    int priv_lvl=1;
  };
  vector<admin_detail> list_admin;
public:
   Admin()
   {
     list_admin.clear();
   }
   void read_admin()
   { string s="";
     admin_detail temp;
     admin.open("Admins.txt",ios::in);
     while(getline(admin,s))
     {
        if(s[0]!='#')//Work on comments later
        {
         s+='\0';
         temp=seperate(s);
         list_admin.push_back(temp);
       }
      }
     admin.close();
   }
   admin_detail seperate(string s)
   {
     admin_detail temp;
     int i=0;
     while(1)
     {
       while(s[i]!=':')
       {
         temp.name+=s[i];
         i++;
       }
       i++;
       temp.passwd="";
       while(s[i]!='\0')
       {
         temp.passwd+=s[i];
         i++;
       }
       return temp;
     }
   }
   void register_admin()
   {
     admin_detail temp; // temporary variable for storing values before pushing it into the vector.
     cout<<"Enter your username ";
     cin>>temp.name;
     cout<<"Enter the phone_no";
     cin>>temp.phone_no;
     list_admin.push_back(temp);
   }
   void display()
   { cout<<endl;
     for(int i=0;i<list_admin.size();i++)
     cout<<i<<"\t"<<left<<setw(10)<<list_admin[i].name<<"\t"<<list_admin[i].passwd<<endl;
   }
   void save()
   {
     admin_detail temp;
     temp.name="Ra";temp.passwd="xyz";temp.phone_no="789";
     admin.open("Admins.txt",ios::app);
     admin<<temp.name<<":"<<temp.passwd<<":"<<temp.phone_no;
   }
};
int main()
{
  Admin a;
  a.save();
  //a.read_admin();// done
  //a.display();//done
  //a.accept_admin_details();
  //a.display();
  /*switch (choice)
  {
    case 1://Add a new admin.
    case 2://Edit the admin's detail.
    case 3://Registration details.
    case 4://Editing the teachers details.
    case 5://Editing the Students details.
    case 6:return 0;
  }*/
}
