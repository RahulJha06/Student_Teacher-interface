#include<iostream>
#include<cstring>
using namespace std;
struct tt
{
      string sub1,sub2,sub3,sub4,rec,day,t_extra;
   string days;
    char t1[20],t2[20],t3[20],t4[20],t5[20];
    struct tt *next;
}*start=NULL;
void create()
       {
        tt *n=new tt;

        n->next=NULL;
        strcpy(n->t1,"8:00 AM-9:00 AM");
        strcpy(n->t2,"9:00 AM-10:00 AM");
        strcpy(n->t3,"10:00 AM-11:00 AM");
        strcpy(n->t4,"11:00 AM-12:00 NOON");
        strcpy(n->t5,"12:00 NOON-1:00 PM");
        if(start==NULL)
        {
            start=n;
        }
        else{
            tt *temp=start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
        }
        }
void c7()
{
    tt *n=start;
    for(int i=0;i<7;i++)
    {
        create();
    }

}
void initialize()
{
    tt *n=start;
    int i=0;
    while(i<7)
    {
    if(i==0)
        {
            n->day="MONDAY";
            n->sub1="DSGT";
            n->sub2="DSLD";
            n->rec="RECESS";
            n->sub3="FDS";
            n->sub4="OOP";
        }
        if(i==1)
        {
            n->day="TUESDAY";
            n->sub1="DSLD";
            n->sub2="FDS";
            n->rec="RECESS";
            n->sub3="COMT";
            n->sub4="OOP";
        }
        if(i==2)
        {
            n->day="WEDNESDAY";
            n->sub1="DSGT";
            n->sub2="COMT";
            n->rec="RECESS";
            n->sub3="DSLD";
            n->sub4="FDS";
        }
         if(i==3)
        {
            n->day="THURSDAY";
            n->sub1="DSGT";
            n->sub2="DSLD";
            n->rec="RECESS";
            n->sub3="OOP";
            n->sub4="COMT";
        }
        if(i==4)
        {
            n->day="FRIDAY";
            n->sub1="FDS";
            n->sub2="FDS";
            n->rec="RECESS";
            n->sub3="DSGT";
            n->sub4="COMT";
        }
        if(i==5)
        {
            n->day="SATURDAY";
            n->sub1="NO LECTURES";
            n->sub2="NO LECTURES";
            n->rec="NO LECTURES";
            n->sub3="NO LECTURES";
            n->sub4="NO LECTURES";
        }
        if(i==6)
        {
            n->day="SUNDAY";
            n->sub1="NO LECTURES";
            n->sub2="NO LECTURES";
            n->rec="NO LECTURES";
            n->sub3="NO LECTURES";
            n->sub4="NO LECTURES";
        }
        i++;
        n=n->next;
    }

}
void tt_display()
{c7();
 initialize();
    tt *temp=start;
    while(temp!=NULL)
    {
        cout<<"\n"<<temp->day<<"\n"<<temp->t1<<"\t\t"<<temp->sub1<<"\n"<<temp->t2<<"\t"<<temp->sub2<<"\n"<<temp->t3<<"\t"<<temp->rec<<"\n"<<temp->t4<<"\t"<<temp->sub3<<"\n"<<temp->t5<<"\t"<<temp->sub4<<"\t";
        temp=temp->next;
    }
   
}

