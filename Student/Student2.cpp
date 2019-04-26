#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
class data{
  string name;
  string roll_no;
  string phone_no;
  string mail_id;
  friend class student;
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

class student // an object of the class represents a class of students with maximum of 80 students;
{
  fstream file;
  vector<int> index;
public:
  student()
  {
    string temp;
    file.open("studentlist.txt");
    do
    {
      index.push_back(file.tellg());
    }while(getline(file,temp));
    file.close();
  }
  void dis() //successfully indexed
  {
    file.open("studentlist.txt");
    int i=0;
    string temp;
    data d;
    while(i<index.size())
    {
      file.seekg(index[i]);
      if(getline(file,temp))
      {
        d.read(temp);
        cout<<d;
        i++;
      }
      else
      break;
    }
  }
/*  void accept()
  {
    data temp;
    cin>>temp;
    Table.push_back(temp);
  }*/
  void accept_registration() //to register a student
  {

    data temp;
    cin>>temp;
    index.push_back(temp.save()+1);
  }
  data search()//works perfectly properly constructs an object and returns it after succesffuly reading from a file.
  {
    int roll_no;
    cout<<"Enter your roll no";
    cin>>roll_no;
    if(roll_no<index.size())
    {
      string s;
      fstream file;
      file.open("studentlist.txt");
      file.seekg(index[roll_no-1],ios::beg);
      data temp;
      getline(file,s);
      temp.read(s);
      file.close();
      //cout<<temp;
      return temp;
    }
    else
      cout<<"The record for the roll number does not exist";
  }

};
int main()
{
  student s;
  //s.accept();//verified working
//  s.display();//verified working
  //s.dis(); //verified working
 //s.accept_registration();// registers a student into the student list.
  //s.dis();
  s.search();
  return 0;
}
