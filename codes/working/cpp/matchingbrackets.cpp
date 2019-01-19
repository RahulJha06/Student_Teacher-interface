#include<iostream>
#include<stack>
using namespace std;

int main()
{
 cout<<"START";
 string s,s2;
 cin>>s;

  stack<char> s1;
  int i=0;

 while(s[i]!='\0') 
  {
   
  if(s[i]=='('||s[i]=='{'||s[i]=='[')
   {s1.push(s[i]);i++;
   }
  else 
   {
   if(!s1.empty())
    {
      
      
     if(s[i]==')')
      {
       if(s1.top()=='(')
       {s1.pop();i++;}      
      else
       {cout<<"NO";exit(0);} 
      }
     else if(s[i]=='}')
      {
       if(s1.top()=='{') 
        {s1.pop();i++;}      
      else
       {cout<<"NO";exit(0);} 
      }
     else if(s[i]==']')
       {   if(s1.top()=='[') 
        {s1.pop();i++;}      
      else
       {cout<<"NO";exit(0);}
       }
         
     }
    else
     {cout<<"NO";break;} 
    
  }
 }
  s2="yes"; 
  cout<<s2;

return 0;
}
