#include<isotream>\
#include<fstream>
using namespace std;
class student()
{
  struct data()
  {
    string name, roll_no, address;
  };
  vector<data> Table;
public:
  void copy(string s)
  {
    data temp;
    string t;
    int i=0;
    while(s[i]!='\0')
    {
      while(s[i]!=':')
      {
        t+=s[i];
        i++;
      }
      temp.name+=t;
      i++;
      t
      while(s[i])
    }
  }
  void read()
  {
    fstream file;
    string s="",temp;
    int i=0;
    file.open("Student.txt",ios::in);
    while(getline(file,s)
    {
      copy(s);
    }

  }
}
int main()
{}
