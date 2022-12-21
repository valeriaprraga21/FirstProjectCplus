#include <iostream>

using namespace std; 

class account {

    private:
        //attributes 
        string username;
        float balance;
    public:
        //constructor
        account(string _username, float _balance){
        username = _username;
        balance = _balance;
        }

        account(void){
            username = "";
            balance = 0; 
        }

        //getters
        string get_username(void){
            return username;
        }
        
        float get_balance(void){
            return balance;
        }

        //setters
        void set_username(string _username){
            username = _username;

        }

        void set_balance(float _balance){
            balance = _balance;
        }

        //methods

        void change_balance(float amount){
            //pay all employees
            cout<<"debuggggg"<<endl;
            cout<<balance<<endl;
            balance = balance + amount;
            cout<<balance<<endl;
            cout<<endl;
        }
};