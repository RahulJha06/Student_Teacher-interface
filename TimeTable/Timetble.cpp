//Work on an algorithm for timetable creation.
//Three solutions for the problem
//Solution number 1: Bruteforce: Pick a room when its free and check if the student and teacher are free , if yes then remove the time slot from the teacher and the student's list and add it to the final timetable.
//2.Back tracking aka picking up all possible moves and combinations trying them and coming back from the step where it goes wrong.
//3.Some shit called Genetic Algorithm.

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class timetable
{
  vector<vector<string>> tt;

  public:
    timetable()
    {
      tt.resize(7);
      for(int i=0;i<tt.size();i++)
       tt[i].resize(5);
      tt[0][0]="Sunday";
      tt[1][0]="Monday";
      tt[2][0]="Tuesday";
      tt[3][0]="Wednesday";
      tt[4][0]="Thursday";
      tt[5][0]="Friday";
      tt[6][0]="Saturday";
    }
    void display()
  {
    for(int i=0;i<tt.size();i++)
     cout<<tt[i][0];
  }
  void accept()
  {
    cout<<"Enter the subjects and their frequency";
    vector<pair<string,int>> table;

  }
};

int main()
{
  timetable t;
  t.display();
}
