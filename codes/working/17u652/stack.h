#include <iostream>
using namespace std;

 template<class t>
class stack;
 template<class T>
 class node;
 

template<class t>
class stack
 {
  node<t> *tops;
 public:
  stack(){tops=NULL;}
  void push(t t1)
  { 
   node<t> *n;
   n=new node<t>;
   n->data=t1;
   if(tops==NULL)
      tops=n;
   else
      {
      n->next=tops;
      tops=n;
      }     
  }
  void pop()
  {
   if(tops==NULL)
    cout<<"Stack Underflow";
   else
    {
    node<t> *n;n=tops;
    tops=tops->next;
    cout<<n->data;
    delete n; 
    } 
  }
 };

 template<class T>
 class node
 {
 friend class stack<T>;
 T data;
 node *next;
 };


/*int main()
{
 stack<int> s;
 int x;
 do
  {cout<<"1 for push ; 2:POP 3:BREAK";
  cin>>x;
  switch(x) 
   {
   case 1:int y;
          cin>>y;
          s.push(y);
          break;
   case 2:s.pop();break;
   case 3:exit(0);
   default: cout<<"Error";break;
  }
  }while(1); 
return 0;
}
*/

