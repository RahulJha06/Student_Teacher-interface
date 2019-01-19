#include <iostream>
#include<stack>
using namespace std;
class node
{
 int data;
 node *left;
 node *right;
 public:
  class tree
   {
    
    public:
    node *root;
     tree()
     {
     root=NULL;   
     }
      
     void create(int d)      //need for another function to traverse ad one function to create a new node
     {  
      node *key=new node;
      key->data=d;
      key->left=NULL;
      key->right=NULL;
      node *temp;
      if(root==NULL)
       {root=key;return;}
      else
       temp=root; 
     place(key,temp);
     }
    void place(node *key,node *temp)
     {
     if(key->data<temp->data)
      {if(temp->left==NULL)
       temp->left=key;
      else 
       place(key,temp->left);
      }
      else if(key->data>temp->data)  
         {if(temp->right==NULL) 
           temp->right=key;
       else
          place(key,temp->right);
         }
       else  
        return; 
      }
      
     void inoder(node *temp)
      {
       if(temp==NULL)
        return;
       else
         {
           inoder(temp->left);
           cout<<temp->data;
           inoder(temp->right);
         }
      }
      
        
   };
    tree t;
   void inter_face(int x)
    {
   
    t.create(x);  
    }  
    void inter_face()
    {
     t.inoder(t.root);
    } 
};
int main()
{ 
 node n;
 int x;
 do
  {
   cin>>x;
   if(x==-1)
    break;
   else
    n.inter_face(x);
  }while(1);
  n.inter_face();
return 0;
}

