#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

class Admin
{
  public:
    string aName, bName, edition, isbn;
    long nob;

    int checkISBN(){
        string temp;
        int count=0;
        ifstream in("ISBN.txt");
        while(getline(in,temp)){
          ++count;
          if(temp==isbn){
            return count;
          }
        }
        in.close();
        return 0;
    }


};

class addBook : public Admin
{
  public:
     
     void input(){
      system("cls");
      cout<<"                ======================= LIBRARY MANAGEMENT SYSTEM ======================="<<endl<<endl;
      cout<<"                -------------------------------- ADD BOOK -------------------------------"<<endl;
      cout<<"                . Enter name of book    : ";
      getline(cin,bName);
      getline(cin,bName);
      cout<<"                . Enter name of author  : ";
      getline(cin,aName);
      cout<<"                . Enter edition of book : ";
      getline(cin,edition);
      cout<<"                . Enter ISBN of book    : ";
      getline(cin,isbn);
      cout<<"                . Enter number of book  : ";
      cin>>nob;
     }
    
     void addB(int n){
      int x, z=0, count=0;
      string temp;
       if(n!=0){
        //transffering data of NOB to temp
         ifstream in("NOB.txt");
         ofstream out("temp.txt");
         while(in>>x){
            ++count;
            if(count==n){
              x=x+nob;
              if(x<=0){
                z=1;
              }
            }
            if(z!=1){
              out<<x<<endl;
            }
         }
         out.close();
         in.close();
         //transferring the data of temp to NOB
         ifstream in1("temp.txt");
         ofstream out1("NOB.txt");
         while(in1>>x){
          out1<<x<<endl;
         }
         out1.close();
         in1.close();
       }

       else{
          //writing to book name
          ofstream out1("BookName.txt",ios::app);
          out1<<bName<<endl;
          out1.close();

          //writing to author name
          ofstream out2("AuthorName.txt", ios::app);
          out2<<aName<<endl;
          out2.close();

          //writing to edition
          ofstream out3("Edition.txt", ios::app);
          out3<<edition<<endl;
          out3.close();

          //writing to isbn
          ofstream out4("ISBN.txt",ios::app);
          out4<<isbn<<endl;
          out4.close();

          //writing to number of books
          ofstream out5("NOB.txt",ios::app);
          out5<<nob<<endl;
          out5.close();

          //writing to confirm
          string temp;
          cout<<"                Your data has been successfully saved ."<<endl;
          cout<<"                              THANK YOU !"<<endl<<endl;;
          cout<<"                     Enter any key to continue : ";
          cin>>temp;
       }
     }

};

class libraryStatus : public Admin
{
  public:
     void Status(){
         long x=0, y=0;
           system("cls");
           cout<<"          ========================== LIBRARY MANAGEMENT SYSTEM =========================="<<endl;
           cout<<"          -------------------------------- LIBRARY STATUS -------------------------------"<<endl;
         ifstream in1("BookName.txt");
         ifstream in2("AuthorName.txt");
         ifstream in3("Edition.txt");
         ifstream in4("ISBN.txt");
         ifstream in5("NOB.txt");
         while(getline(in1,bName) && getline(in2,aName) && getline(in3,edition) && getline(in4,isbn) && in5>>nob){
           cout<<"            Book - "<<++x<<endl;
           cout<<"          . Name of book        : "<<bName<<endl;
           cout<<"          . Name of author      : "<<aName<<endl;
           cout<<"          . Edition of book     : "<<edition<<endl;
           cout<<"          . ISBN of book        : "<<isbn<<endl;
           cout<<"          . Number of book      : "<<nob<<endl<<endl;
           y += nob;
         }
           cout<<endl;
           cout<<"             Total number of books in library : "<<y<<endl;
           cout<<"                        Thank you ! "<<endl<<endl;
           cout<<"                 Press any key to continue : ";
           string temp;
           cin>>temp;
     }
};

class Delete : public Admin
{
   public:
   
     void input(){
        system("cls");
        cout<<"            ======================= LIBRARY MANAGEMENT SYSTEM ======================"<<endl;
        cout<<"             . Enter ISBN of book              : ";
        getline(cin,isbn);
        getline(cin,isbn);
        cout<<"             . Enter number of book for delete : ";
        cin>>nob;
     }

     void dBook(int n){
          string temp;
          long x;
          int s=0; 
          int count=0;
         if(n==0){
          cout<<"                         Sorry entered ISBN is not found "<<endl;
          cout<<"                          press any key to continue : ";
          cin>>temp;
         }
         else{
             //for number of books
             ifstream in1("NOB.txt");
             ofstream out1("temp.txt");
             while(in1>>x){
              ++count;
              if(count==n){
                x = x - nob;
                if(x<=0){
                  s=1;
                }
                if(s!=1){
                  out1<<x<<endl;
                }
              }
              else{
                  out1<<x<<endl;
              }
             }
             out1.close();
             in1.close();

             ifstream in2("temp.txt");
             ofstream out2("NOB.txt");
             while(in2>>x){
              out2<<x<<endl;
             }
             out2.close();
             in2.close();

             //for name of books
             count=0;
             ifstream in3("BookName.txt");
             ofstream out3("temp.txt");
             while(getline(in3,temp)){
              ++count;
               if(count==n){
                if(s!=1){
                  out3<<temp<<endl;
                }
               }
               else{
                out3<<temp<<endl;
               }
             }
             out3.close();
             in3.close();

             ifstream in4("temp.txt");
             ofstream out4("BookName.txt");
             while(getline(in4,temp)){
              out4<<temp<<endl;
             }
             out4.close();
             in4.close();

             //for author name
             count=0;
             ifstream in5("AuthorName.txt");
             ofstream out5("temp.txt");
             while(getline(in5,temp)){
              ++count;
              if(count==n){
                if(s!=1){
                  out5<<temp<<endl;
                }
              }
              else{
                out5<<temp<<endl;
              }
             }
             out5.close();
             in5.close();

             ifstream in6("temp.txt");
             ofstream out6("AuthorName.txt");
             while(getline(in6,temp)){
              out6<<temp<<endl;
             }
             out6.close();
             in6.close();

             //for edition of book
             count=0;
             ifstream in7("Edition.txt");
             ofstream out7("temp.txt");
             while(getline(in7,temp)){
              ++count;
              if(count==n){
                if(s!=1){
                  out7<<temp<<endl;
                }
              }
              else{
                out7<<temp<<endl;
              }
             }
             out7.close();
             in7.close();

             ifstream in8("temp.txt");
             ofstream out8("Edition.txt");
             while(getline(in8,temp)){
              out8<<temp<<endl;
             }
             out8.close();
             in8.close();

             //for ISBN of book
              count=0;
             ifstream in9("ISBN.txt");
             ofstream out9("temp.txt");
             while(getline(in9,temp)){
               ++count;
               if(count==n){
                if(s!=1){
                  out9<<temp<<endl;
                }
               }
               else{
                out9<<temp<<endl;
               }
             }
             out9.close();
             in9.close();

             ifstream in10("temp.txt");
             ofstream out10("ISBN.txt");
             while(getline(in10,temp)){
              out10<<temp<<endl;
             }
             out10.close();
             in10.close();

             cout<<"             Your data has been successfully deleted."<<endl;
             cout<<"                   Press any key to continue : ";
             cin>>temp;

         }
     }

     void restart(){
        ofstream out1("BookName.txt");
        out1.close();
        
        ofstream out2("AuthorName.txt");
        out2.close();

        ofstream out3("Edition.txt");
        out3.close();

        ofstream out4("ISBN.txt");
        out4.close();

        ofstream out5("NOB.txt");
        out5.close();
        
        string temp;
        system("cls");
        cout<<"           ======================= LIBRARY MANAGEMENT SYSTEM ======================="<<endl<<endl;
        cout<<"                         Your files has been successfully rastarted : "<<endl<<endl;
        cout<<"                               Press any key to continue : ";
        cin>>temp;
          
     }
     

};

class Student
{
  public:   
   string name, roll, faculty, batch, phone, address, gender;
   long nb;
   string si;
     
     void dis(){
                    system("cls");
                    cout<<"               ==================== LIBRARY MANAGEMENT SYSTEM =================="<<endl;
                    cout<<"               ----------------------------- STUDENT ----------------------------"<<endl<<endl;
                    cout<<"                      _________________________________________________"<<endl;
                    cout<<"                      |                                               |"<<endl;
                    cout<<"                      |         1. Go to home                         |"<<endl;
                    cout<<"                      |         2. Login                              |"<<endl;
                    cout<<"                      |         3. Borrow book                        |"<<endl;
                    cout<<"                      |         4. Return book                        |"<<endl;
                    cout<<"                      |         5. Student status                     |"<<endl;
                    cout<<"                      |         6. Clear all data of students         |"<<endl;
                    cout<<"                      |         7. Exit                               |"<<endl;
                    cout<<"                      |_______________________________________________|"<<endl;
     }

     int checkLogin(){
      string temp;
      string str;
      int count=0;

      //checcking for name
      ifstream in1("sName.txt");
      while(getline(in1,temp)){
        str=name;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(temp == str){
            ++count;
        }
     }
       in1.close();

       //checking for faculty
      ifstream in2("faculty.txt");
      while(getline(in2,temp)){
        str=faculty;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(str == temp){
            ++count;
        }
      }
      in2.close();

      //checking for batch
      ifstream in3("batch.txt");
      while(getline(in3, temp)){
        str=batch;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(temp == str){
            ++count;
        }
      }
      in3.close();

      //checking for roll
      ifstream in4("roll.txt");
      while (getline(in4,temp))
      {
        str=roll;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(temp == str){
            ++count;
        }
      }
      in4.close();

      //returning some value
      return count;

     }

     void inputStudent(){
      system("cls");
      cout<<"          ========================== LIBRARY MANAGEMENT SYSTEM =============================="<<endl<<endl;
      cout<<"          -------------------------------- STUDENT SECTION -----------------------------------"<<endl;
      cout<<"           . Enter your name       : ";
      getline(cin,name);
      getline(cin,name);
      cout<<"           . Enter your gender     : ";
      getline(cin,gender);
      cout<<"           . Enter your batch      : ";
      getline(cin,batch);
      cout<<"           . Enter your faculty    : ";
      getline(cin,faculty);
      cout<<"           . Enter your roll no.   : ";
      getline(cin,roll);
      cout<<"           . Enter your mobile no. : ";
      getline(cin,phone);
      cout<<"           . Enter your address    : ";
      getline(cin,address);
     }
     
     void inputUR(){
      system("cls");
      cout<<"            ========================== LIBRARY MANAGEMENT SYSTEM ============================"<<endl<<endl;
      cout<<"            ------------------------------- STUDENT SECTION -----------------------------------"<<endl;
      cout<<"            . Enter your unique roll number : ";
      getline(cin,roll);
      getline(cin,roll);
    
     }

     int checkUniqueRoll(){
       int count=0;
       string str[4];
       string temp;
       str[0]="PUR";
      ifstream in1("batch.txt");
      ifstream in2("faculty.txt");
      ifstream in3("roll.txt");
      while(getline(in1,str[1]) && getline(in2,str[2]) && getline(in3,str[3])){
        ++count;
        temp=str[0]+str[1]+str[2]+str[3];
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        transform(roll.begin(), roll.end(), roll.begin(), ::toupper);
        if(roll==temp){
          return count;
        }

      }
      in3.close();
      in2.close();
      in1.close();
       
       return 0;

     }
     
};

class Login : public Student
{
   public:
    
      void LogginStudent(int x){
           
           string temp;

        if(x==4){
          cout<<endl;
          cout<<"                     You are already logged in."<<endl;
          cout<<"                     Press any key to continue : ";
          cin>>temp;    
        }
           
        else{
          //adding student name
          ofstream out1("sName.txt", ios::app);
          out1<<name<<endl;
          out1.close();

          //adding batch
          ofstream out2("batch.txt",ios::app);
          out2<<batch<<endl;
          out2.close();

          //adding faculty
          ofstream out3("faculty.txt", ios::app);
          out3<<faculty<<endl;
          out3.close();

          //adding roll number
          ofstream out4("roll.txt",ios::app);
          out4<<roll<<endl;
          out4.close();

          //adding mobile number
          ofstream out5("phone.txt",ios::app);
          out5<<phone<<endl;
          out5.close();

          //adding address
          ofstream out6("address.txt",ios::app);
          out6<<address<<endl;
          out6.close();

          //adding gender
          ofstream out7("gender.txt",ios::app);
          out7<<gender<<endl;
          out7.close();

          //adding defoult zero as number of book in students acount
          x=0;
          ofstream out8("Snob.txt",ios::app);
          out8<<x<<endl;
          out8.close();


          cout<<"            You are successfully logged in."<<endl;
          cout<<"              Press any key to continue : ";
          cin>>temp;

        }

      }

};

class Sdelete : public Student
{
  public:
       void restartStudentsData(){

      //clearing student name
      ofstream out1("sName.txt");
      out1.close();
      
      //clearing batch
      ofstream out2("batch.txt");
      out2.close();
      
      //clearing faculty
      ofstream out3("faculty.txt");
      out3.close();

      //clearing roll number
      ofstream out4("roll.txt");
      out4.close();

      //clearing phone number
      ofstream out5("phone.txt");
      out5.close();

      //clearing address
      ofstream out6("address.txt");
      out6.close();

      //clearing gender
      ofstream out7("gender.txt");
      out7.close();

      //clearing number of book borrowed by students
      ofstream out8("Snob.txt");
      out8.close();

      //clearing all data of book of students account
      ofstream out9("Sisbn.txt");
      out9.close();

      system("cls");
      cout<<"       ========================= LIBRARY MANAGEMENT SYSTEM ========================"<<endl<<endl;
      cout<<"                     All data of students has been cleared successfull ."<<endl; 
      cout<<"                                 Press any key to continue : ";
      string temp;
      cin>>temp;
     }
};

class Borrow : public Student, public Admin
{
  public:

  void inputBook(int n){
     string temp;
     if(n==0){
      cout<<"          Soryy this account is not logged in ."<<endl;
      cout<<"              Press any key to continue : ";
      cin>>temp;
     }
     else{
     cout<<"              . Enter ISBN of book   : ";
     getline(cin,isbn);
     cout<<"              . Enter number of book : ";
     cin>>nb;

     }

  }
  
  void addBookStudent(int n, int n1){
    string temp;
    long x;
    int i;
    long m,m1=0;
    int y=0;
    int count=0;
    if(n1==0){
      cout<<"             This book is not available in library ."<<endl;
      cout<<"                 Press any key to continue : ";
      cin>>temp;
    }
   
   else{
          //taking required data from Snob
       ifstream in("Snob.txt");
       while(in>>x){
        ++count;
        if(count==n){
          m=m1;
        }
        m1=m1+x;
       }
       in.close();
        
        //checking how many book is borrowes from library
        m1=0;
        ifstream in0("Snob.txt");
        while(in0>>x){
          y=y+x;
        }
        in0.close();

       //if no any book is borrowed from library by any students
       if(y==0){
        ofstream out("Sisbn.txt",ios::app);
        for(i=0;i<nb;i++){
          out<<isbn<<endl;
        }
        out.close();
       }
       
       else{

       //transferring Sisbn data into temp
       count=0;
       ifstream in1("Sisbn.txt");
       ofstream out1("temp.txt");
       while(getline(in1,temp)){
        ++count;
        if(m+1==count){
          for(i=0;i<nb;i++){
            out1<<isbn<<endl;
          }
        }
        out1<<temp<<endl;
       }
       out1.close();
       in1.close();
       
       //transferring temp data into Sisbn
       ifstream in2("temp.txt");
       ofstream out2("Sisbn.txt");
       while(getline(in2,temp)){
        out2<<temp<<endl;
       }
       out2.close();
       in2.close();
       
       }
       
       //transferring Snob data into temp
       count=0;
       ifstream  in3("Snob.txt");
       ofstream out3("temp.txt");
       while(in3>>x){
         ++count;
         if(count==n){
          x=x+nb;
         }
         out3<<x<<endl;
       }
       out3.close();
       in3.close();

       //transferring temp data into Snob
       ifstream in4("temp.txt");
      ofstream out4("Snob.txt");
      while(in4>>x){
        out4<<x<<endl;
      }
      out4.close();
      in4.close();

    cout<<"                          Book borrow completed ."<<endl;
    cout<<"                       Press any key to continue : ";
    cin>>temp;
   }

  }
  

};

class returnBook : public Student, public Admin
{
  public:
      void inputDB(int n){
        string temp;
        if(n==0){
          cout<<"      This student's account is not logged in ."<<endl;
          cout<<"             press any key continue : ";
          cin>>temp;
        }
        else{
        cout<<"            . Enter ISBN of book   : ";
        getline(cin,isbn);
        cout<<"            . Enter number of book : ";
        cin>>nb;
        }
      }

      void returnB(int n, int n1){
        string temp;
        int count=0;
        int count1=0;
        int x, x1,  m,m1=0;

        if(n1==0){
          cout<<"         This book is not of this library ."<<endl;
          cout<<"           press any key  to continue : ";
          cin>>temp;
        }

        else{

            ifstream in0("Snob.txt");
            while(in0>>x){
              ++count;
              if(count==n){
                m=m1;
                x1=x;
              }
              m1=m1+x;
            }
            in0.close();
            
            count=0;
            ifstream in10("Sisbn.txt");
            ofstream out10("temp.txt");
            while(getline(in10,temp)){
                ++count;
                if(count>m && count<=m+x1 && temp==isbn && count1<nb){
                        ++count1;
                }
                else{
                  out10<<temp<<endl;
                }
            }
            out10.close();
            in10.close();

            ifstream in11("temp.txt");
            ofstream out11("Sisbn.txt");
            while(getline(in11,temp)){
              out11<<temp<<endl;
            }
            out11.close();
            in11.close();
           
             
             count=0;
            ifstream in20("Snob.txt");
            ofstream out20("temp.txt");
            while(in20>>x){
              ++count;
              if(count==n){
                x=x-nb;
                if(x<0){
                  x=0;
                }
              }
              out20<<x<<endl;
            }
            out20.close();
            in20.close();
             
            ifstream in22("temp.txt");
            ofstream out22("Snob.txt");
            while(in22>>x){
              out22<<x<<endl;
            }
            out22.close();
            in22.close();

             count1;
            if(count1!=nb){
              cout<<"         sorry only "<<count1<<" book has been returned ."<<endl;
              cout<<"                  press any key to continue : ";
              cin>>temp;
            }
            else{
              cout<<"            your "<<count1<<" book has been returned ."<<endl;
              cout<<"                 press any key to continue : ";
              cin>>temp;
            }
        }

      }
};

class studentStatus : public Admin, public Student
{
  public:

    void inputU(){
      string temp;
      system("cls");
      cout<<"         ============================== LIBRARY MANAGEMENT SYSTEM ================================"<<endl<<endl;
      cout<<"        ------------------------------------ STUDENT SECTION -------------------------------------"<<endl;
      cout<<"       . Enter unique roll number : ";
      getline(cin,roll);
      getline(cin,roll);
    }

    void showD(int n){
            int Q;
            string temp;
            int count=0, count1;
            int y=0;
            int x,m,m1=0;

         if(n==0){
          cout<<"              This account is not registered ."<<endl;
          cout<<"                press any key to continue : ";
          cin>>temp;
         }

         else{
               system("cls");
               cout<<"         ============================== LIBRARY MANAGEMENT SYSTEM ================================"<<endl<<endl;
               cout<<"         ----------------------------------- STUDENT SECTION -------------------------------------"<<endl;
              
               //printing name
               ifstream in1("sName.txt");
               while(getline(in1, temp)){
                ++count;
                if(count==n){
                  cout<<"           . Name of student            : "<<temp<<endl;
                }
               }
               in1.close();

               //printing Roll number
                  cout<<"           . Roll number of student     : "<<roll<<endl;

              //printing phone number
              count=0;
              ifstream in2("phone.txt");
              while(getline(in2,temp)){
                 ++count;
                 if(count==n){
                  cout<<"           . Mobile number of student   : "<<temp<<endl;
                 }
              }
              in2.close();

              //printing address
              count=0;
              ifstream in3("address.txt");
              while(getline(in3,temp)){
                ++count;
                if(count==n){
                  cout<<"          . Address of student         : "<<temp<<endl;
                }
              }
              in3.close();
             
            //for printin all information about borrowed
               count=0;
               ifstream in4("Snob.txt");
               while(in4>>x){
               ++count;
               if(count==n){
                y=x;
                m=m1;
               }
               m1=m1+x;
               }
               in4.close();
                
                count=0;
                Q=0;
               ifstream in5("Sisbn.txt");
               while(getline(in5,temp)){
                  ++count;
                  if(count>m && count<=m+y){
                     Admin T;
                     T.isbn = temp;
                     x = T.checkISBN();
                     count1=0;
                     ifstream in6("BookName.txt");
                     while(getline(in6,bName)){
                        ++count1;
                        if(count1==x){
                          cout<<endl;
                          cout<<"           Book - "<<++Q<<endl;
                          cout<<"           . Name of book                 : "<<bName<<endl;
                          cout<<"           . ISBN of the book             : "<<temp<<endl;
                        }  
                     }
                     in6.close();

                  }
               }
               in5.close();
              
               cout<<"                   Total number of book : "<<y<<endl;
               cout<<"                Press any key to continue : ";
               cin>>temp;
         }

    }

};

int main()
{
    addBook AB;
    libraryStatus ls;
    Delete D;
    Student S;
    Login L;
    Sdelete sd;
    Borrow B;
    returnBook R;
    studentStatus ss;

    int n, n1, q=0;
    string s;
 while(1){
        //creating home interface;
 {
     system("cls");
   cout<<"               ==================== LIBRARY MANAGEMENT SYSTEM =================="<<endl;
   cout<<"               ------------------------------ HOME -----------------------------"<<endl<<endl;
   cout<<"                      _________________________________________________"<<endl;
   cout<<"                      |                                               |"<<endl;
   cout<<"                      |         1. Admin                              |"<<endl;
   cout<<"                      |         2. Student                            |"<<endl;
   cout<<"                      |         3. Exit                               |"<<endl;
   cout<<"                      |_______________________________________________|"<<endl;
   cout<<"                       Choose an option from above : ";
   cin>>n;
 }
 switch(n){
    case 1: do{
               //creating Admin interface  
                {
                    system("cls");
                    cout<<"               ==================== LIBRARY MANAGEMENT SYSTEM =================="<<endl;
                    cout<<"               ------------------------------ ADMIN -----------------------------"<<endl<<endl;
                    cout<<"                      _________________________________________________"<<endl;
                    cout<<"                      |                                               |"<<endl;
                    cout<<"                      |         1. Go to home                         |"<<endl;
                    cout<<"                      |         2. Add books                          |"<<endl;
                    cout<<"                      |         3. Library status                     |"<<endl;
                    cout<<"                      |         4. Delete numbers of book             |"<<endl;
                    cout<<"                      |         5. Restart all files                  |"<<endl;
                    cout<<"                      |         6. Exit                               |"<<endl;
                    cout<<"                      |_______________________________________________|"<<endl;
                    cout<<"                       Choose an option from above : ";
                    cin>>n;
                }
                switch(n){
                    case 1:  q=1;
                            break;
                    case 2: AB.input();
                            n = AB.checkISBN();
                            AB.addB(n);
                            break;
                    case 3:ls.Status();
                           break;
                    case 4: D.input();
                            n = D.checkISBN();
                            D.dBook(n);
                            break;
                    case 5: D.restart();
                            break;
                    case 6: {
                              system("cls");
                              cout<<"            ========================== LIBRARY MANAGEMENT SYSTEM ======================"<<endl<<endl;
                              cout<<"                             Your program has been successfully close ."<<endl;
                              cout<<"                                              Thank you !"<<endl;
                              cout<<"                                         Enter any key to closed    : ";
                              cin>>s;
                              exit(0);
                              }
                    default: continue;
                }
          }while(q!=1);
           break;
    case 2:  do{
                    S.dis();
                    cout<<"                       Choose an option from above : ";
                    cin>>n;
                   
                    //creating nested case in case 2
                 switch(n)
                   {
                    case 1:  q=1;
                             break;
                    case 2:  L.inputStudent();
                             n = L.checkLogin(); 
                             L.LogginStudent(n);
                             break;
                    case 3: B.inputUR();  
                            n = B.checkUniqueRoll();
                            B.inputBook(n);
                            if(n!=0){
                            n1 = B.checkISBN();
                            B.addBookStudent(n , n1);
                            }
                            break;
                    case 4: R.inputUR();
                            n = R.checkUniqueRoll();
                            R.inputDB(n);
                            if(n!=0){
                              n1=R.checkISBN();
                              R.returnB(n , n1);
                            }
                            break;
                    case 5: ss.inputU();
                            n = ss.checkUniqueRoll();
                            ss.showD(n);
                            break;
                    case 6: sd.restartStudentsData();
                            break;
                    case 7:  {
                               system("cls");
                               cout<<"            ========================== LIBRARY MANAGEMENT SYSTEM ======================"<<endl<<endl;
                               cout<<"                             Your program has been successfully close ."<<endl;
                               cout<<"                                              Thank you !"<<endl;
                               cout<<"                                         Enter any key to closed    : ";
                               cin>>s;
                               exit(0);
                              }
                    default: continue;
                   }
                   
               }while(q!=1);
              break; 
    case 3: {
                 system("cls");
              cout<<"            ========================== LIBRARY MANAGEMENT SYSTEM ======================"<<endl<<endl;
              cout<<"                             Your program has been successfully close ."<<endl;
              cout<<"                                              Thank you !"<<endl;
              cout<<"                                         Enter any key to closed    : ";
              cin>>s;
              exit(0);
            }
            
    default: continue;
 }
 }
 return 0;
}