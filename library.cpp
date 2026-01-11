#include <iostream>
#include <string>
#include <limits>
#include <unordered_map>
using namespace std;
namespace lib{
    class User{
        protected:
            static int id;
            static unordered_map<int,unordered_map<string,string>> users;
        public :
            User(){}
            User(string user_name,string email,int id,string ph_no){ //creating a user profile.
                users[id] = {};
                users[id]["User"] = user_name;  
                users[id]["Email"] = email;
                users[id]["Phone"] = ph_no;
                cout<<"User created successfully..."<<endl;
            }
            virtual void show_user_info(){
                cout<<"Name : ";
                cout<<"Email : ";
                cout<<"Phone number : ";
            }
            string show_info(int id){ //getter function 
                auto ph = users.find(id);
                if(ph != users.end()){
                    return users.at(id).at("Phone");

                }
                else{
                    return "NOT_FOUND";
                }
            }
    };

    class Librarian : public User{ //will have actions such as , Add a user, delete a user , assign user a book , check the user details and view their private info..
        protected:
            static string book_name;
            static int book_id;

        public: 
            unordered_map<int,unordered_map<string,string>> record;
            Librarian(){}
            Librarian(string user, string email,int id, string ph_no) : User(user,email,id,ph_no){}
            void delete_user(int id){
                auto it = users.find(id); //get's the user data iterator, and if the data does not exist, the first conditional statement will show and error and return to the main program.
                if (it== users.end()){ // checking if the it is pointing towards the users.end() which basically means, we searched the entire unordered map but we couldn't find the given id.
                    cout<<"Sorry Id does not exist..."<<endl;
                    return;
                }
                else{
                    users.erase(it);
                    cout<<"Successfully removed the user..."<<endl;
                    return;
                }
            }
            void assign_book(int id,string date,string book){
                if(users.find(id) == users.end()){
                    cout<<"User does not exist\n";
                    return;
                }
                record[id]["Book"] = book;
                record[id]["Date"] = date;
                cout<<"Successfully assiged the book to the user..."<<endl;
            }
            void remove_book(int id,string book){
                auto it = record.find(id);
                if(it == record.end()){
                    cout<<"Sorry the user does not exist..."<<endl;
                    return;
                }
                if(it->second.find("Book") == it->second.end() || it->second["Book"] != book){
                    cout << "Sorry, this book is not assigned to this user.\n";
                    return;
                }

                // If both checks passed, remove the record
                record.erase(it);
                cout << "User returned the book successfully.\n";
                return;
            }
            void show_book_assignment(int id){
                auto it = record.find(id);
                if(it == record.end()){
                    cout<<"Sorry the record does not exist..."<<endl;
                    return;
                }
                cout<<"Book : "<<it->second.at("Book")<<endl;
                cout<<"Date Borrowed on : "<<it->second.at("Date")<<endl;
            }
            void show_user_info(int id){
                auto it = users.find(id);
                if (it == users.end()){
                    cout<<"Sorry user does not exist.."<<endl;
                    return;
                }
                cout<<"Name : "<<it->second.at("User")<<endl;
                cout<<"Email : "<<it->second.at("Email")<<endl;
                cout<<"Phone number : "<<show_info(id)<<endl;
                auto fi = record.find(id);
                if (fi != record.end()){
                    cout<<"Book borrowed : "<<fi->second.at("Book")<<endl;
                    cout<<"Borrowed date : "<<fi->second.at("Date")<<endl;


                }
                
            }

    };
}

string lib::Librarian::book_name;
unordered_map<int, unordered_map<string, string>> lib::User::users;
int lib::Librarian::book_id;          //Giving my namespace access to shared variable so at any given point they can access or modify this.
int lib::User::id;  

int main(){
    string name,date,book,phone,email;
    int id,choice;
    lib::Librarian l1;
    while (true){
        cout<<"\nWelcome to INDEX library...."<<endl;
        cout<<"\n1.Add User : \n2.Remove User : \n3.Assign Book : \n4.Mark resubmission : \n5.Show Users : \n6.Show book borrow : \n7.Exit"<<endl;
        cout<<"Your action : ";
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(choice == 1){
            cout<<"Enter name : ";
            getline(cin,name);
            cout<<"Enter Email : ";
            getline(cin,email);
            cout<<"Enter your phone number : ";
            getline(cin,phone);
            cout<<"Enter your desired id : ";
            cin>>id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            l1 = lib::Librarian(name,email,id,phone);

        }
        else if(choice == 2){
            cout<<"Enter your id : ";
            cin>>id;
            l1.delete_user(id);
        }
        else if(choice == 3){
            cout<<"Enter the book name : ";
            getline(cin,book);
            cout<<"Enter the date in following format (DD MM YYYY) : ";
            getline(cin,date);
            cout<<"Enter your id : ";
            cin>>id;
            l1.assign_book(id,date,book);
        }
        else if(choice == 4){
            cout<<"Enter your id : ";
            cin>>id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter the book to mark submission : ";
            getline(cin,book);
            l1.remove_book(id,book);
        }
        else if(choice == 5){
            cout<<"Enter your id : ";
            cin>>id;
            l1.show_user_info(id);
        }
        else if(choice == 6){
            cout<<"Enter your id : ";
            cin>>id;
            l1.show_book_assignment(id);
        }
        else if(choice == 7){
            break;
        }
        else{
            cout<<"Please enter a valid option...";
        }
    }
    
    return 0;
    
    
}