#include<iostream>
#include<cstring>
#include<climits>
#include<vector>
#include<fstream>
using namespace std;

class teacher
{

        int size=0;     
        struct teach    
        {
        string name;
        int review; //review by students
        string cab_no;
        string cont;
        string address; 
        string spec;
        };
        vector<teach> t;
        fstream f1;
public:
teacher();
void get_info();
void get_info(int);
void display();
void display(int);
bool check(int);
void save();
int review(int);
};

void teach_menu(teacher&, int);
void teach_if(teacher&);
