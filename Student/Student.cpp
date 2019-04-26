/*1.A class will be a struct or object having data field : Hash table which would be all encompasing of student data, a list of teachers(along with their roles) allocated to the class, the time table of the class.
2.Hash(NOT REALLY) table will consist of the students detail along with his marks and attendance, as well as teacher review.
3.Hash(NOT REALLY) is based on roll no assignment.
4.Roll_no will be consisting of te following information
5.Class will consist of an array of all students,timetable,and list of teachers
6.Check for first time log-in or registered student,
  sign-in can be throught the mail.
7.GR number generator.
8.Decide whether to read or write from excel or from sql.
9.Format output data.
10.Read from sql tables or excel tables.
*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class student
{
    struct details
    {
        string name;
        int roll_no;
        string phone_no;
        string mail_id;
    //NOTE USING HASH table use for class details where class may be stored in trees
    };
    fstream register_student;
    vector<details> Table;
    public:
    student(){}
    void registe()
    {
      register_student.open("registered student.txt",ios::app);
      details temp;
      cout<<"Enter the name of the student";
      getline(cin,temp.name);
      cout<<"Enter the phone no of the student";
      getline(cin,temp.phone_no);
      register_student<<temp.name<<":"<<temp.phone_no<<endl;
      register_student.close();
    }
    void sign_in() // allowing user to sign-in or not letting them any access.
    {
      int set_permission=0;
      do
      {
        string name,password;
        cout<<"Enter your name";
        cin>>name;
        cout<<"Enter password";
        cin>>password;
        if(name=="admin"&&password=="12345")
          {
            cout<<"Welcome";
            set_permission=1;
          }
        else
            cout<<"Wrong password";
      }while(set_permission!=1);
    }
    void accept()
    {
      cout<<"Enter the following details respectively";
      string name,p_no,gr_n;
      cout<<"Enter your name";
      cin>>name;
      cout<<"Enter your phone number";
      cin>>p_no;
      cout<<"Enter your GR number";
      cin>>gr_n;
    }
    void display()
    {
      cout<<"The details are as follows:\n";
      cout<<"Name: "<<"\tGR.NO: "<<"\tPhone number\n";
      cout<<"Rahul: "<<"\t17u652: "<<"\t9867275096\n";
    }
    void edit() // allow a person to edit the detail
    {}
    void change_password() // allows user to change the password.
    {

    }

};

int main()
{
  student s;
  //s.sign_in();
  //s.accept();
  //s.display();
  s.registe();
  return 0;

}
