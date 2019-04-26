#include<iostream>
using namespace std;

int main()
{
  do {
    cout<<"Select \n1.Admin \n2.Teacher \n3.Student \n4.Exit. \n";
    int cho;
    cin>>cho;
    switch (cho)
    {
      case 1:cout<<"Admin is being worked on.\n";break;
      case 2:cout<<"Teacher is being workerd on.\n";break;
      case 3:cout<<"Student is being worked on.\n";break;
      case 4:return 0;break;
      default:cout<<"Enter the correct value";break;
    }
  } while(1);
}
