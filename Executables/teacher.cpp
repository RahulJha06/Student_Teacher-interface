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
data::data():name("-1"),roll_no("-1"),phone_no("-1"),mail_id("-1"){}
istream & operator>>(istream &in,data &s) //Final for printing the data and reading the entire data at one time
{ //Eliminate new line from the istream
 cout<<"Enter the name:";
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
ostream & operator<<(ostream &out,data &s)//works fine though edit the way it is wriiten in output file as reading misbehaves.
{
	out<<"Name: "<<s.name<<"\nRoll_no: "<<s.roll_no<<"\nPhone NUmber: "<<s.phone_no<<"\nEmail id: "<<s.mail_id<<endl<<endl;
	return out;
}
void data::read(string temp)
{
	stringstream inter(temp);

		if(getline(inter,name,':'))
			if(getline(inter,roll_no,':'))
				if(getline(inter,phone_no,':'))
					if(getline(inter,mail_id,':'));
}
int data::save()
{
	int temp;
	fstream file;
	file.open("teacher.txt",ios::app);
	temp=file.tellg();
	file<<name<<":"<<roll_no<<":"<<phone_no<<":"<<mail_id<<":"<<endl;
	file.close();
	return temp;
}
class teacher
{
  fstream file;
  vector<int> index;
public:
  teacher();
  void dis();
  void accept_registration();
  data search();
};
void teacher_interface();
teacher::teacher()
{
	string temp;
	file.open("teacher.txt");
	 do{
		 index.push_back(file.tellg());
	 }while(getline(file,temp));
	 file.close();
}
void teacher::dis()
{
	file.open("teacher.txt");
	data d;
	int i=0;
	string s;
	while(1)
			{
				if(getline(file,s))
				{d.read(s);
				cout<<d;
				}
				else
				{cout<<"Error";break;}
			}

	file.close();
}
void teacher::accept_registration()
{
	data temp;
	cin>>temp;
	index.push_back(temp.save()+1);
}
data teacher::search()
{
	int roll_no;
	cout<<"Enter your roll no";
	cin>>roll_no;
	if(roll_no<index.size())
	{
		string s;
		fstream file;
		file.open("teacher.txt");
		file.seekg(index[roll_no-1],ios::beg);
		data temp;
		getline(file,s);
		temp.read(s);
		file.close();
		return temp;
	}
	else
	{  data temp;
		return temp;
	}
}

int main()
{
	teacher t;
	data d;
	t.dis();
	t.accept_registration();

	d=t.search();cout<<d;return 0;
}
