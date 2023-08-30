#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;

void gotoxy(int x,int y)
{
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD a={x,y};
  SetConsoleCursorPosition(h,a);

}

class MONEY {
    public:
    long long money;

    public:
    MONEY(){};
    MONEY(long long m) : money(m){};
    void add_money(long long amount);
    void remove_money(long long amount);

};

class member : public MONEY {
private:

string name;
string username;
int PIN;

public:

member(){};
member(long long m,string n , string u , int p) : MONEY(m) ,name(n) , username(u) , PIN(p) {};

void change_member();
void delete_member(bool& bl);
void change_information(string user,long long mon);
void login(int& id_);

void read_file();
void test_file();

void cout_name(int id_);
void cout_money(int id_);

void remove_money(int id_);

void get_user(int id_,string& user){
  read_file();
  user = mem[id_].username;
}

int return_money(int id_){
  read_file();
  return mem[id_].money;
}

void co_memname(){
  for(int i = 0 ; i< mem.size() ;i++){
    cout<<mem[i].username;
  }
}


vector<member> mem;

};

class bot : public MONEY {
private:
string name;
public:
bot(){};
bot(long long m) : MONEY(m){};
void create_bot();
void erase_bot();

void add_money1(long long mon);
void remove_money1(long long mon);
void cout_name(){
  cout<<name;
}


void cout_money(){
  cout<<money;
}

long long return_money(){
  return money;
}


};

void taixiu_(int tx,long long mon,int ID,long long &botmoney){
MONEY M;
member mb;
bot bt;
string txiu;

string user;

  srand(time(NULL));

  int rd = rand() %2+1;

  if(rd == 1){
  txiu = "Tai";
}
if(rd == 2){
  txiu = "Xiu";
}


   if(rd == tx){
     mb.money = mb.return_money(ID);
      mb.money = mon + mb.money;
      long long moon= mb.money;
    mb.get_user(ID,user);
    mb.change_information(user,moon);
  
    botmoney = botmoney -mon;
    Sleep(4000);
    gotoxy(46,16);cout<<"Result: "<<txiu;

    
   }
   else {
    mb.money = mb.return_money(ID);
    mb.money = mb.money-mon;
    long long moon = mb.money; 

   mb.get_user(ID,user);
   mb.change_information(user,moon);
   botmoney = botmoney + mon;
   Sleep(4000);
   gotoxy(46,16);cout<<"Result: "<<txiu;
   }  
  


}


void login(){
  member mb;
  bot bt;
  int id;
  mb.read_file();

  mb.login(id);
  gob:
  system("cls");
  gotoxy(0,1); cout<<"Welcome: ";mb.cout_name(id);
  gotoxy(30,1);cout<<"Money: "; mb.cout_money(id); cout<<" $";
  gotoxy(60,1) ; cout<<"Sum88.com";

  gotoxy(0,3);cout<<"Join a random room (1)";
  gotoxy(0,4);cout<<"Quit               (0)"<<endl;

  bt.create_bot();

  int choice;
  gotoxy(0,5); cout<<"> ";cin>>choice;



  switch (choice)
  {
  case 1:
  gob1:
    mb.read_file();
    gotoxy(46,16);system("cls");
      gotoxy(0,1); cout<<"Welcome: ";mb.cout_name(id);
      gotoxy(30,1);cout<<"Money: "; mb.cout_money(id);cout<<" $";
      gotoxy(60,1); cout<<"Sum88.com";

      gotoxy(90,1); cout<<"Press 0 to Quit";

      gotoxy(45,10);cout<<"Tai";gotoxy(45,12);cout<<"(T)";
      gotoxy(55,10);cout<<"Xiu";gotoxy(55,12);cout<<"(X)";
      
      gotoxy(0,20);cout<<"Name: ";bt.cout_name();
      gotoxy(30,20);cout<<"Money: ";bt.cout_money();cout<<" $";
      gotoxy(60,20); cout<<"Sum88.com";
      gotoxy(90,20); cout<<"Press 0 to Quit";


      
      if(bt.money <= 0 ){
         gotoxy(46,14);cout<<"You win!";
         gotoxy(46,15);system("pause");
         goto gob;
      }

      if(mb.return_money(id) <= 0){
        gotoxy(46,14);cout<<"Out of money!";
        gotoxy(46,15);system("pause");
        goto gob;
      }

      

      char tx;
      int taixiu=0;

      gotoxy(46,13);cout<<"> ";
      cin>>tx;
      if(tx == '0') goto gob;
      if( tx == 'T' || tx == 't') taixiu = 1;
      if( tx == 'X' || tx == 'x') taixiu = 2;

      if(taixiu == 1 || taixiu== 2){
      
        
      
      long long mn;
      gotoxy(46,14);cout<<"Money: ";cin>>mn;


        long long bt_mn;
        bt_mn = bt.return_money();
         taixiu_(taixiu,mn,id,bt_mn);
         bt.money = bt_mn;
         gotoxy(46,18);system("pause");
         goto gob1;
      }
      else{
        gotoxy(46,14);cout<<"T or X !";system("pause");
        goto gob1;
      }

    
  
  system("pause");


  }



}


void reg(){
  member mb;
  bot bt;
  mb.change_member();
  cout<<"Done !"<<endl;
  system("pause");
}

int main(){
goback:
system("cls");
member mb;
bot bt;
mb.read_file();


cout<<"Welcome to Sum88.com "<<endl;
cout<<""<<endl;
cout<<"Login     (1)"<<endl;
cout<<"Register  (2)"<<endl;
cout<<"> ";
int choice;
cin>>choice;
switch (choice)
{
case 1:
    login();
    goto goback;
    
break;

case 2:
reg();
goto goback;
default:
    cout<<"This choice doesnt exit!";
    goto goback;
    break;
}

system("pause");
}


void MONEY::add_money(long long amount){
    money = money + amount;
}

void MONEY::remove_money(long long amount){
   money = money - amount;
}

void member::change_member(){
  read_file();
  fstream file;
  file.open("member_taixiu.txt" , ios::out);
  b:
  cout<<"Username: "; cin>>username;
  for(int i = 0 ; i < mem.size();i++){
    if(username == mem[i].username){
        cout<<"This account has already existed!";
        goto b;
    }
  }
  cout<<"PIN: ";cin>>PIN;
  cout<<"Name: ";cin>>name;
  money = 5000;
  mem.push_back(member(money,name,username,PIN));
  for(int i = 0 ; i < mem.size() ; i++){
    file<<"Username: "<<mem[i].username<<endl;
    file<<"PIN: "<<mem[i].PIN<<endl;
    file<<"Name: "<<mem[i].name<<endl;
    file<<"Money: "<<mem[i].money<<endl;
  }
    file.close();
}

void member::delete_member(bool& bl){
    fstream file;
    file.open("member_taixiu.txt", ios::out);
      cout<<"Username: ";cin>>username;
      bl= false;
      for(int i = 0 ; i< mem.size();i++){
        if(username == mem[i].username) {
            mem.erase(mem.begin()+i);
            bl = true;
      }
      }

      if(bl == true){
        cout<<"Done! "<<endl;
      }
      if(bl == false){
        cout<<"Username doesnt exit!"<<endl;
      }
    file.close();
}

void member::change_information(string user,long long mon){
    fstream file;
    file.open("member_taixiu.txt",ios::out);
    
    for(int i = 0 ; i < mem.size() ;i++){
        if(user == mem[i].username) {
            mem[i].money = mon ;
         
        }
    }


     for(int i = 0 ; i < mem.size() ; i++){
    file<<"Username: "<<mem[i].username<<endl;
    file<<"PIN: "<<mem[i].PIN<<endl;
    file<<"Name: "<<mem[i].name<<endl;
    file<<"Money: "<<mem[i].money<<endl;
     }
    file.close();
}

void member::read_file(){
    mem.clear();
    fstream file;
    string line;
    int flag = 1 ;
    file.open("member_taixiu.txt" ,ios::in);
          while(getline(file,line)){
             string s1,s2;
             stringstream ss;
             stringstream ss1;
             ss<<line;
             ss>>s1>>s2;
             if(flag == 1) username = s2 ;
             if(flag == 2) { ss1<<s2;
             int p;
             ss1>>p;
             PIN = p;
             ss1.clear();
             }
             if(flag == 3) name = s2;
             if(flag == 4) {
                ss1<<s2;
                long long mon;
                ss1>>mon;
                money = mon;
                flag = 1;
                mem.push_back(member(money,name,username,PIN));
                ss.clear();
                continue;
             }
            flag++;
             ss.clear();

          }
    file.close();
}

void member::login(int& id_){
  b1:
  bool bl;
      cout<<"Username: ";cin>>username;
      bl= false;
      for(int i = 0 ; i< mem.size();i++){
        if(username == mem[i].username) {
            id_ = i;
            bl = true;
      }

      }

      if(bl == true){
        bool bl_ = false;
        cout<<"PIN> ";cin>>PIN;
        for(int i = 0 ; i< mem.size() ;i++){
          if(PIN == mem[i].PIN) {
              bl_ = true;
          }
        }

        if(bl_ == false){
          cout<<"wrong PIN!"<<endl;
          goto b1;
        }
      }
      if(bl == false){
        cout<<"Username doesnt exit!"<<endl;
        system("pause");
        system("cls");
        goto b1;
      }

}

void member::test_file(){
  for(int i = 0 ; i<mem.size() ; i++){
    cout<<mem[i].username;
  }
}

void member::cout_name(int id_){
  cout<<mem[id_].name;
}

void member::cout_money(int id_){
  cout<<mem[id_].money;
}
void bot::create_bot(){
srand(time(NULL));
int rd = rand() % 5 + 1 ;
if(rd == 1) name = "Alex";
if(rd == 2) name = "Brom";
if(rd == 3) name = "Rich";
if(rd == 4) name = "Gumball";
if(rd == 5) name = "Darwin";

int money_rd = rand() % 30 + 5000 ;
money = money_rd;

}

void bot::add_money1(long long mon){
  money = mon+ money;
}

void bot::remove_money1(long long mon){
  money = mon - money;
}



