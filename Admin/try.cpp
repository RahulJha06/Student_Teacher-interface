#include<iostream>
#include<fstream>
using namespace std;
int main()
{
int a[2][2]={(1,2),(3,4)};
fstream f;
f.open("Try.txt",ios::out);
for(int i=0;i<2;i++)
 for(int j=0;j<2;j++)
  {
    f<<a[i][j];f<<"\t";
  }
  f<<endl;
return 0;
}
