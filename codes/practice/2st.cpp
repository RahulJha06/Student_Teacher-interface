#include<iostream>
#include<stack>
using namespace std;
template<class t>
class queue
{
 stack<t> s;
 stack<t> s1;
 
 public:
  void enque(t t1)
   {
    while(!s1.empty())
       {
        s.push(s1.top());
        s1.pop();
       }
    s.push(t1);
     while(!s.empty())
      {
       s1.push(s.top());
       s.pop();
      }   
   }
   void deque()
   {
      s1.pop();
   }
   void  print()
   { if(!s1.empty())
    cout<<s1.top();
   }
};

int main()
{
queue<int> q;

char c;
 do
 {
  int x;
  cin>>x;
  switch(x)
   {
   case 1: cout<<"Enter number to enque:";
           int y;cin>>y;
              q.enque(y);break;
   case 2: q.deque();break;
   case 3: q.print();break;
   default: break;
   }
  cout<<"Y/N CONTINUE";
  cin>>c;
 }while(c=='y'||c=='Y');

}
