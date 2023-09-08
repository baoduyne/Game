#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<windows.h>


using namespace std;

struct student{

string name;
int age;
float point;
student(){};
student(string n , int ag , float po) : name(n) , age(ag), point(po) {};
vector<student> vt;

};


void read_file(student* std){
   std->vt.clear();
   fstream file ;
   file.open("test.txt" , ios:: in);
    string line;
    int flag = 1;
    while(getline(file,line)){
      if(flag == 1){

       string s1,s2,s3;
       stringstream ss;
       ss<<line;
       ss>>s1>>s2;
       std->name = s2;
       ss.clear();

       flag++;
       continue;
      }
       if(flag == 2 ){
        string s1,s2,s3;
       stringstream ss;
       ss<<line;
       ss>>s1>>s2;
       ss.clear();
       ss<<s2;
       ss>>std->age;
        ss.clear();
        flag ++;
        continue;
       }
       if(flag == 3){
        string s1,s2,s3;
       stringstream ss;
       ss<<line;
       ss>>s1>>s2;
       ss.clear();
       ss<<s2;
       ss>>std->point;
        ss.clear();
        std->vt.push_back(student(std->name , std->age , std->point));
        flag = 1;
        continue;
       }
    }
   file.close();
}

student* get_information(){
     student *std = new student;
     read_file(std);
     string name ; int age ; float point ;
     cout<<"name: ";cin>>std->name;
     cout<<"age: "; cin>>std->age;
     cout<<"point: "; cin>>std->point;
     
    std->vt.push_back(student(std->name , std->age ,std->point)) ;
     fstream file;
     cout<<std->vt.size()<<endl;
     file.open("test.txt" , ios::out);
     for(int i = 0 ; i< std->vt.size() ; i++){
        file<<"Name: "<<std->vt[i].name<<endl;
        file<<"Age: "<<std->vt[i].age<<endl;
        file<<"Point: "<<std->vt[i].point<<endl;
     }
     file.close();
     return std;
}


void show(student* std){
   read_file(std);

   for(int k = 0 ; k<std->vt.size(); k++){
      //
      


      for(int j = 0 ; j<std->vt[k].name.size() ; j++){
      if(j== 0){
         for(int i = 41 ; i<=79 ; i++){
            if(k!=0){
               for(int k_ = 0 ; k_ <k ; k_++){
        cout<<"Name: "<<std->vt[k].name<<endl;
        cout<<"Age: "<<std->vt[k].age<<endl;
        cout<<"Point: "<<std->vt[k].point<<endl;
               
            }
      }
      char ch = i;
         cout<<"Name: "<<ch;
      system("cls");
      Sleep(20);
      if(ch == std->vt[k].name[j]){
          break;
      } 
      }
      }
      else{
         for(int i = 41 ; i<=79 ; i++){
            if(k!=0){
               for(int k_ = 0 ; k_ <k ; k_++){
        cout<<"Name: "<<std->vt[k_].name<<endl;
        cout<<"Age: "<<std->vt[k_].age<<endl;
        cout<<"Point: "<<std->vt[k_].point<<endl;
               }
            }
      char ch = i;

      cout<<"Name: ";
      for(int j_ = 0 ; j_ < j ; j_++){
         cout<<std->name[j_];
      }
      cout<<ch;
      system("cls");
      Sleep(50);
      if(ch == std->vt[k].name[j]){
          break;
      }
      } 

    }
    }
    //
    for(int j = 0 ; j < sizeof(std->vt[k].age) ;j++){
      if(j==0){

      
       for(int i = 30 ; i<=39; i++){
  if(k!=0){
               for(int k_ = 0 ; k_ <k ; k_++){
        cout<<"Name: "<<std->vt[k_].name<<endl;
        cout<<"Age: "<<std->vt[k_].age<<endl;
        cout<<"Point: "<<std->vt[k_].point<<endl;
               
            }
      }


         int it = i;
         cout<<"Name: "<<std->vt[k].name<<endl;
         cout<<"Age: "<<it;
         system("cls");
         Sleep(20);

         if(it == std->vt[k].age / 10) {
            break;
         }
       }
      }
       

       else{


         for(int i = 30 ; i<=39; i++){

if(k!=0){
               for(int k_ = 0 ; k_ <k ; k_++){
        cout<<"Name: "<<std->vt[k_].name<<endl;
        cout<<"Age: "<<std->vt[k_].age<<endl;
        cout<<"Point: "<<std->vt[k_].point<<endl;
               
            }
      }
         int it = i;
         cout<<"Name: "<<std->vt[k].name<<endl;
         cout<<"Age: "<<std->vt[k].age / 10<<it;
         system("cls");
         Sleep(20);

         if(it == std->vt[k].age - ((std->vt[k].age / 10) * 10 ) ) {
            break;
         }

         }
       

      }
    }
     //
    stringstream ss;
    ss<<std->vt[k].point;
    string point;
    ss>>point;
    ss.clear();
   
    for(int j = 0 ; j<point.size() ; j++){
      if(point[j] == '.') {
         cout<<".";continue;
      }

      if(j==0) {
         for(int i = 30 ; i<= 39 ; i++){
            if(k!=0){
               for(int k_ = 0 ; k_ <k ; k_++){
        cout<<"Name: "<<std->vt[k_].name<<endl;
        cout<<"Age: "<<std->vt[k_].age<<endl;
        cout<<"Point: "<<std->vt[k_].point<<endl;
               
            }
      }
            
            char chr = i;
            cout<<"Name: "<<std->vt[k].name<<endl;
            cout<<"Age: "<<std->vt[k].age<<endl;
            cout<<"Point: "<<chr;
            system("cls");
            Sleep(20);
            
            if(chr == point[0]) {
               break;
            }
         }
      }

      else{
          for(int i = 30 ; i<= 39 ; i++){
            if(k!=0){
               for(int k_ = 0 ; k_ <k ; k_++){
        cout<<"Name: "<<std->vt[k_].name<<endl;
        cout<<"Age: "<<std->vt[k_].age<<endl;
        cout<<"Point: "<<std->vt[k_].point<<endl;
               
            }
      }
           
            char chr = i;
             cout<<"Name: "<<std->vt[k].name<<endl;
            cout<<"Age: "<<std->vt[k].age<<endl;
            cout<<"Point: "<<point[j]<<chr;
            system("cls");
            Sleep(20);
            
            if(chr == point[j]) {
               break;
            }
         }
      }
     
      
    }
   
    //

   
   
}

for(int i = 0 ; i<std->vt.size();i++){
   cout<<"Name: "<<std->vt[i].name<<endl;
        cout<<"Age: "<<std->vt[i].age<<endl;
        cout<<"Point: "<<std->vt[i].point<<endl;
   
}
}

      
int main(){
   student *std;
   
  std = get_information();
   read_file(std);

   for(int i = 0 ; i < std->vt.size(); i++){
      cout<<std->vt[i].name<<endl;
   }
   system("pause");
   show(std);
   system("pause");
   
   

}