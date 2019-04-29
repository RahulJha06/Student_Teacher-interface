#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
//class student;
class data{
  string name;
  string roll_no;
  string phone_no;
  string mail_id;
  friend class  student;
public:
  data();
  friend ostream & operator <<(ostream &out,data &s);
    friend istream & operator>>(istream &in,data &s);
    void read(string temp);
    int save();
};
class student
{
  fstream file;
  vector<int> index;
public:
  student();
  void dis();
  void accept_registration();
  data search();
};
void student_interface();
