#include<iostream>
#include<string.h>
#include<string>
#include<conio.h>
#include<windows.h>
#include<vector>
using namespace std;
struct student
{
  string name,pass,email,Que,Ans;
};
void gotoxy(int x,int y)
{
    COORD a;
    a.X=x;
    a.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);

}
struct mentor
{
   string name,email,pass;
   int id;
};
class STUDENT
{
    vector<student> v;
public:
    void Signup();
    void Authanatic();
    int Find(string &,string &,student**);
    void studentlog(student**);
    void chatSupport(student**);
    void TicketTracker(student**);
    vector<student> getS(){return v;}
    void Assign(vector<student> a){v=a;}
    void QueryView();
};
class Mentor
{
   vector<student> vc;
   vector<mentor> vm;
public:
    void setStudentInfo(vector<student> a){vc=a;}
    void Signup();
    void Authanatic();
    int Find(string &,string &);
    void mentorlog();
    void MentalS();
    vector<student> getvc()
    {
        vector<student> a;
        a=vc;
        vc.clear();
        return a;
    }
    vector<student> * GetUnsolve()
    {
        for(int i=0,n=vc.size();i<n;i++)
            if(!vc[i].Ans.size());


    }
};
void STUDENT :: QueryView()
{
    for(int i=0;i<30;cout<<endl,i++)
        for(int j=0;j<90;j++)
         if(i>5&&i<25&&j>30&&j<85||j>4&&j<26&&(i>1&&i<6||i>7&&i<10||i>11&&i<14||i>15&&i<18||i>19&&i<21)
        ||i>1&&i<4&&(j>30&&j<36||j>37&&j<48||j>49&&j<60||j>61&&j<72||j>73&&j<85))
         cout<<" ";
      else
         cout<<".";
      gotoxy(31,3);cout<<" S.L ";gotoxy(39,3);cout<<"QUERY";gotoxy(51,3);cout<<"STATUS";gotoxy(63,3);cout<<"ANSWER";
      gotoxy(75,3);cout<<"REMARK";
      gotoxy(6,8);cout<<"1.ASK QUERY";
      gotoxy(6,12);cout<<"2.SOLVED QUERY";
      gotoxy(6,16);cout<<"3.PENDING QUERY";
      gotoxy(6,20);cout<<"4.EXIT";
}
void STUDENT :: chatSupport(student** s)
{
    system("cls");
   QueryView();
   gotoxy(6,2);
   cout<<"WELCOME";
   gotoxy(6,3);
   cout<<"NAME: "<<(*s)->name;
   gotoxy(6,4);
   cout<<"EMAIL: "<<(*s)->email;
    string a;
    gotoxy(35,10);
    cout<<"YOUR QUETION: ";
    fflush(stdin);
    getline(cin,a);
    (*s)->Que=a;
}
void Mentor :: MentalS()
{
    for(int i=0,n=vc.size();i<n;i++){
     system("cls");
      cout<<"STUDENT QUETION:   "<<vc[i].Que<<endl;
      fflush(stdin);
      if(!vc[i].Ans.size())
        getline(cin,vc[i].Ans);
    }

}
void STUDENT :: TicketTracker(student** s)
{
    system("cls");
    cout<<" YOUR QUETION :  "<<(*s)->Que<<"\n";
    cout<<" \nSTATUS: "<<(*s)->Ans<<"\n";
    cout<<"Press Any Key For EXIT";
    getch();

}
void STUDENT :: studentlog(student **s)
{
  int x=1;
     while(x)
       {
        system("cls");
        gotoxy(20,1);
      cout<<"1.Chat Support";
      gotoxy(20,3);
      cout<<"2.Ticket Tracker";
       gotoxy(20,5);
      cout<<"3.EXIT";
      gotoxy(20,7);
      cout<<"Pres any Key";
      int k;
      cin>>k;
      switch(k)
      {
          case 1:chatSupport(s);break;
          case 2:TicketTracker(s);break;
          default:x=0;break;
      }
       }
}
void Mentor :: mentorlog()
{
  int x=1;
     while(x)
       {
        system("cls");
        gotoxy(20,1);
      cout<<"1.Solve Query";
      gotoxy(20,3);
      cout<<"2.send query next(if not solve)";
       gotoxy(20,5);
      cout<<"3.EXIT";
      gotoxy(20,7);
      cout<<"Pres any Key";
      int k;
      cin>>k;
      switch(k)
      {
          case 1:MentalS();break;
          case 2:break;
          default:x=0;break;
      }
       }
}
int STUDENT :: Find(string &sE,string &sP,student **s)
{
    for(int i=0,n=v.size();i<n;i++)
          if(v[i].email==sE&&v[i].pass==sP){
                *s=&v[i];
          return 1;
          }
    return 0;
}
int Mentor :: Find(string &sE,string &sP)
{
    for(int i=0,n=vm.size();i<n;i++)
          if(vm[i].email==sE&&vm[i].pass==sP)
          return 1;

    return 0;
}
void STUDENT :: Authanatic()
{
    int k=3;
    while(k){
     system("cls");
    gotoxy(35,0);
    cout<<"Sign In";
    gotoxy(16,2);
    for(int i=0;i<10;cout<<endl,i++)
    for(int j=0;j<45;j++){
            gotoxy(16+j,2+i);
                   if((i>1&&i<4||i>5&&i<8||i>9&&i<12)&&j>1&&j<43)
                    cout<<" ";
                   else
                   cout<<"-";
              }
          gotoxy(18,4);
         cout<<" EMAIL: ";
         gotoxy(18,8);
         cout<<" Password: ";
         string sE,sP;
         gotoxy(18,4);
         cout<<" EMAIL: ";
         cin>>sE;
         gotoxy(18,8);
         cout<<" Password: ";
         cin>>sP;
         student *s=NULL;
         if(Find(sE,sP,&s)){
           studentlog(&s);
            break;
         }
         else
            if(k==1){
            gotoxy(18,12);
       cout<<"YOU HAVE NO ANY USER NAME AND PASSWORD";
       gotoxy(18,14);
       cout<<"PLEASE SIGN UP";
       gotoxy(18,16);
       cout<<"PRESS ANY KEY FOR EXIT";
            }
    else
        {
           gotoxy(18,12);
            cout<<"PLEASE ENTER CORRECT USER NAME AND PASSWORD";
            gotoxy(18,14);
            cout<<"PRESS ANY KEY";
         }
         k--;
         getch();
    }
}
void Mentor :: Authanatic()
{
    int k=3;
    while(k){
     system("cls");
    gotoxy(35,0);
    cout<<"Sign In";
    gotoxy(16,2);
    for(int i=0;i<10;cout<<endl,i++)
    for(int j=0;j<45;j++){
            gotoxy(16+j,2+i);
                   if((i>1&&i<4||i>5&&i<8||i>9&&i<12)&&j>1&&j<43)
                    cout<<" ";
                   else
                   cout<<"-";
              }
          gotoxy(18,4);
         cout<<" EMAIL: ";
         gotoxy(18,8);
         cout<<" Password: ";
         string sE,sP;
         gotoxy(18,4);
         cout<<" EMAIL: ";
         cin>>sE;
         gotoxy(18,8);
         cout<<" Password: ";
         cin>>sP;
         if(Find(sE,sP)){
           mentorlog();
            break;
         }
         else
            if(k==1){
            gotoxy(18,12);
       cout<<"YOU HAVE NO ANY USER NAME AND PASSWORD";
       gotoxy(18,14);
       cout<<"PLEASE SIGN UP";
       gotoxy(18,16);
       cout<<"PRESS ANY KEY FOR EXIT";
            }
    else
        {
           gotoxy(18,12);
            cout<<"PLEASE ENTER CORRECT USER NAME AND PASSWORD";
            gotoxy(18,14);
            cout<<"PRESS ANY KEY";
         }
         k--;
         getch();
    }
}

void STUDENT:: Signup()
{
    system("cls");
    gotoxy(35,0);
    cout<<"Sign Up";
    gotoxy(16,2);
    for(int i=0;i<18;cout<<endl,i++)
    for(int j=0;j<45;j++){
            gotoxy(16+j,2+i);
                   if((i>1&&i<4||i>5&&i<8||i>9&&i<12||i>13&&i<16)&&j>1&&j<43)
                    cout<<" ";
                   else
                   cout<<"-";
              }
              gotoxy(18,4);
        cout<<" FIRST NAME: ";
              gotoxy(18,8);
        cout<<" LAST NAME: ";
        gotoxy(18,12);
         cout<<" EMAIL: ";
          gotoxy(18,16);
         cout<<" Password: ";

         string sN,sE,sP,te;
         gotoxy(18,4);
         cout<<" FIRST NAME: ";
         cin>>sN;
         te+=sN;
         te.push_back(' ');
          gotoxy(18,8);
         cout<<" LAST NAME: ";
          cin>>sN;
          te+=sN;
          sN=te;
          gotoxy(18,12);
         cout<<" EMAIL: ";
          cin>>sE;
          gotoxy(18,16);
         cout<<" Password: ";
         cin>>sP;
          student st;
          st.name=sN;
          st.email=sE;
          st.pass=sP;
          v.push_back(st);
          gotoxy(18,20);
          cout<<"Press Any Key To SAVE";
          getch();
}
void Mentor:: Signup()
{
    system("cls");
    gotoxy(35,0);
    cout<<"Sign Up";
    gotoxy(16,2);
    for(int i=0;i<22;cout<<endl,i++)
    for(int j=0;j<45;j++){
            gotoxy(16+j,2+i);
                   if((i>1&&i<4||i>5&&i<8||i>9&&i<12||i>13&&i<16||i>17&&i<20)&&j>1&&j<43)
                    cout<<" ";
                   else
                   cout<<"-";
              }
              gotoxy(18,4);
        cout<<" FIRST NAME: ";
              gotoxy(18,8);
        cout<<" LAST NAME: ";
        gotoxy(18,12);
         cout<<" EMPLOYEE ID: ";
        gotoxy(18,16);
         cout<<" EMAIL: ";
          gotoxy(18,20);
         cout<<" Password: ";

         string sN,sE,sP;
         int i;
         gotoxy(18,4);
         cout<<" FIRST NAME: ";
         cin>>sN;
         sN+=" ";
          gotoxy(18,8);
         cout<<" LAST NAME: ";
          cin>>sN;
          gotoxy(18,12);
         cout<<" EMPLOYEE ID: ";
         cin>>i;
          gotoxy(18,16);
         cout<<" EMAIL: ";
          cin>>sE;
          gotoxy(18,20);
         cout<<" Password: ";
         cin>>sP;
          mentor st;
          st.name=sN;
          st.email=sE;
          st.pass=sP;
          st.id=i;
          vm.push_back(st);
          gotoxy(18,24);
          cout<<"Press Any Key To SAVE";
          getch();
}
void fron()
{
    gotoxy(20,0);
    cout<<"WELCOME";
    gotoxy(22,1);
    cout<<"TO";
    gotoxy(15,2);
    cout<<"NEARO QUERY SUPPORT";
    gotoxy(15,6);
    cout<<"1.STUDENT REQUIRMENT";
    gotoxy(15,8);
    cout<<"2.MENTOR REQUIRMENT";
    gotoxy(15,10);
    cout<<"Press Above Any Key";


}
void studentF(STUDENT &s)
{
  int x=1;
  while(x){
      system("cls");
      gotoxy(30,0);
    cout<<"WELCOME";
    gotoxy(32,1);
    cout<<"TO";
    gotoxy(25,2);
    cout<<"NEARO QUERY SUPPORT";
      gotoxy(20,4);
      cout<<"1.SIGN UP";
      gotoxy(20,6);
      cout<<"2.Authentication";
      gotoxy(20,8);
      cout<<"3.EXIT";
      gotoxy(20,10);
      cout<<"Pres any Key";
      int k;
      cin>>k;
      switch(k)
      {
          case 1:s.Signup();break;
          case 2:s.Authanatic();break;
          default: x=0;
      }
  }
}
void mentalF(Mentor &m,STUDENT &s)
{
    m.setStudentInfo(s.getS());
    int x=1;
  while(x){
      system("cls");
      gotoxy(30,0);
    cout<<"WELCOME";
    gotoxy(32,1);
    cout<<"TO";
    gotoxy(25,2);
    cout<<"NEARO QUERY SUPPORT";
      gotoxy(20,4);
      cout<<"1.SIGN UP";
      gotoxy(20,6);
      cout<<"2.Authentication";
      gotoxy(20,8);
      cout<<"3.EXIT";
      gotoxy(20,10);
      cout<<"Pres any Key";
      int k;
      cin>>k;
      switch(k)
      {
          case 1:m.Signup();break;
          case 2:m.Authanatic();break;
          default: x=0;
      }
  }

}
int main()
{
   STUDENT s;
   Mentor m;
    while(1){
            system("cls");
                fron();
            int k;
            cin>>k;
            switch(k)
            {
              case 1:studentF(s);break;
              case 2:mentalF(m,s);s.Assign(m.getvc());break;
              default:exit(0);
            }

    }
}
