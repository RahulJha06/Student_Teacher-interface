#include <iostream>
#include<stack>
using namespace std;

int main()
{
  string s1,s2;
  getline(cin,s2);
stack<char> s;
int i=0;
while(s2[i]!='\0')
 {
   if(s2[i]=='['||s2[i]=='('||s2[i]=='{')
    {
        s.push(s2[i]);
        i++;
    } 
   else
       {  
         if(s.empty())
          break;
        else if(!s.empty())
        { char *p;
          *p=s.top();
          if(s2[i]==']') 
         {
          if(*p=='[')
          {s.pop();i++;}  
          else
           {cout<<"NO";exit(0);}
         }
         else if(s2[i]==')')
          {
              if(*p=='(')
               {s.pop();i++;}    
              else
               {cout<<"NO";exit(0);}
          }
         else if(*p=='}')
          {
              if(s.top()=='{')
               {s.pop();i++;}    
              else
               {cout<<"NO";exit(0);}

          }
         else 
          s1="YES";
        }
    }   
 }   
 cout<<s1;
  return 0;
}



