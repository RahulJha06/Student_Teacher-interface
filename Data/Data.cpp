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
