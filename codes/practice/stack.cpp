#include <iostream>
#include<>
#include<>
using namespace std;
template<class T>
class treenode
{
friend class stack;
friend class tree;
T t;
treenode *right;
treenode *left;
}
class node
{
friend class list;
treenode data;
node *next;

}
template<class tr>
class stack
{
node *tops;
public:
 stack(){tops=NULL}
 
 
 tr push(treenode T)
  { 
   tops->next=tops;
   tops->data=T->t;
  }
}

int main()
{
 do
  {
  
  }while(1);
return 0;
}


