//file indexed well enough
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
struct at
{
  int index;
  int offset;
};

int main()
{
  /*string line="Hey : there: This :shit :is :crazy ";
  /*stringstream check1(line);
  string in;
  while(getline(check1,in,':'))
  {
    cout<<in<<endl;
  }*/
  string s;
  fstream file;
  file.open("try.txt");
  int off[5];
  string temp="";
  int i=0;
  while(getline(file,s))
  {
    if(i==0)
    {
      off[i]=0;
    }
    else
    off[i]=off[i-1]+temp.size()+1;
    temp=s;
    i++;
  }
  for(int i=0;i<5;i++)
  {
    cout<<off[i]<<endl;
  }
  file.close();
cout<<"1st part Done\n";
  file.open("try.txt");
  i=4;
  s="";
  while(i>=0)
  {
    file.seekg(off[i],ios::beg);
    getline(file,s);
  //  if(seekg(off[i]=='\n'))
    cout<<s<<"\n";
    i--;
  }

  return 0;
}
