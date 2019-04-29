#include "../Student/Student.h"
using namespace std;
class admin
{struct admin_data
  {
  string name;
  string passwd;
  };
   admin_data def;
public:
  admin()
  {
    def.name="admin";
    def.passwd="12345";
  }
  void switch_to_student()
  {
    student_interface();
  }
  bool login()
  {
      admin_data temp;
    cout<<"Enter the name";
    cin>>temp.name;
    cout<<"Enter the password";
    cin>>temp.passwd;
    if(temp.name==def.name&&temp.passwd==def.passwd)
      return true;
    else
      return false;
  }
};
int main()
{
  admin a;
  if(a.login())
    a.switch_to_student();
  else
   return 0;
}
