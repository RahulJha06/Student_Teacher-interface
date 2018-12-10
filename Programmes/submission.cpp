#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void teach_setsub()
{int sub;
cout<<"Please enter 1 ahead of student roll number is the submission is done and 0 if not done(serially)\n";
	 ofstream fout("aaa.txt",ios::out);//opening the file where the teacher will write 
       for(int i=0;i<5;i++)
     { 
       cout<<"\n"<<i+1<<".\t";
       cin>>sub;
       fout<<sub<<" ";
     }
	fout.close();
       
}

void stud_chsub()
{int roll_no;
cout<<"Please enter your roll number to check if you've done the submission\n";
       cin>>roll_no;
       ifstream fin("aaa.txt");//reading from the file for the display
	int temp=1,flag=0;
	string s;

	fin>>s;
       while(fin.good())
     	{
       		if(temp==roll_no)
		{

			flag=1;
			if(s.compare("1")==0)
				cout<<"\nSubmission done.";
			else
				cout<<"\nSubmission not done.(You won't get the noc)";
			break;		
		} 
	
		temp++;
	fin>>s;
     	}
	if(flag==0)
	{
		cout<<"\nInvalid roll entered....";
	}
}        




 

