/*1.Admin's will need to be preconfigured

2.Privilege level.
3.Registration of a student(Call students routine).
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;
class data{
  string name;
  string admin_id;
  string phone_no;
  string mail_id;
  friend class admin;
public:
  data():name("-1"),roll_no("-1"),phone_no("-1"),mail_id("-1"){}
  friend istream & operator>>(istream &in,data &s) //Final for printing the data and reading the entire data at one time
  {
    cout<<"Enter the name: ";
    getline(in,s.name);
    cout<<"Enter the roll_no: ";
    in>>s.roll_no;
    cin.ignore();
    cout<<"Enter the phone_no: ";
    getline(in,s.phone_no);
    cout<<"Enter the mail_id: ";
    getline(in,s.mail_id);
    return in;
  }
  friend ostream & operator<<(ostream &out,data &s)//works fine though edit the way it is wriiten in output file as reading misbehaves.
  {
    out<<"Name: "<<s.name<<"\nRoll_no: "<<s.roll_no<<"\nPhone NUmber: "<<s.phone_no<<"\nEmail id: "<<s.mail_id<<endl<<endl;
    return out;
  }
  void read(string temp)
  {
    stringstream inter(temp);

      if(getline(inter,name,':'))
        if(getline(inter,roll_no,':'))
          if(getline(inter,phone_no,':'))
            if(getline(inter,mail_id,':'));
  }
  int save()
  {
    int temp;
    fstream file;
    file.open("studentlist.txt",ios::app);
    temp=file.tellg();
    file<<name<<":"<<roll_no<<":"<<phone_no<<":"<<mail_id<<":"<<endl;
    file.close();
    return temp;
  }
};

class Admin
{
  fstream admin;
  vector<admin_detail> list_admin;
public:
   Admin()
   {
     list_admin.clear();
   }
   void read_admin()
   {
     string s="";
     data temp;
     admin.open("Admins.txt",ios::in);
     while(getline(admin,s))
     {
        if(s[0]!='#')//Work on comments later
        {
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
  a.read_admin();// done
  a.display();//done
  a.accept_admin_details();
  a.display();
  switch (choice)
  {
    case 1://Add a new admin.
    case 2://Edit the admin's detail.
    case 3://Registration details.
    case 4://Editing the teachers details.
    case 5://Editing the Students details.
    case 6:return 0;
  }
}
