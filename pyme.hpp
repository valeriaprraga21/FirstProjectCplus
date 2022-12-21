#include <iostream>
#include "employee.hpp"
//#include "account.hpp"
#include <vector>
using namespace std;

class pyme{

    private: 
    //attributes
    string name; 
    string location; 
    vector <employee> employees; 
    account bank_account;  

    public: 
    //constructor
    pyme(string _name, vector <employee> _employees, account _bank_account){
        name = _name;  
        employees = _employees; 
        bank_account = _bank_account;
    }

    public: 
    //getters

    string get_name(void){
        return name; 
    }

    string get_location(void){
        return location; 
    }

    vector <employee> get_employees(void){
        return employees; 
    }

    account get_bank_account(void){
        return bank_account; 
    }

    public: 
    //setters

    void set_name(string _name){
        name = _name;
    }

    void set_location(string _location){
        location = _location;
    }

    void set_employees(vector <employee> _employees){
        employees = _employees;
    }

    void set_bank_account(account _bank_account){
        bank_account = _bank_account; 
    }

    void paySalary()
    {

        for (int i=0; i < employees.size() ;i++){

            float amount  = employees[i].get_total_paycheck();
            cout<<"amount: " << amount<<endl;
            bank_account.change_balance(-1 * amount);
            // employees[i].get_bank_account().change_balance(amount);
            employees[i].deposit();
        }
    }

    void print_employees(void){
         for (int i = 0; i < employees.size(); i++)
            {
                cout << "Employee " << i+1 << ":" << endl;
                cout << "Name: " << employees[i].get_name() << " " << employees[i].get_last_name() << endl;
                cout << "Number of children: " <<  employees[i].get_children() << endl;
                cout << "Number of extra hours: " <<  employees[i].get_extra_hours() << endl;
                cout << "Salary: $" <<  employees[i].get_salary() << endl;
                cout << "Total paycheck: $" << employees[i].get_total_paycheck()<<endl;
                cout << "Bank Account Balance: " <<  employees[i].get_bank_account().get_balance() << endl;
                cout<<endl;
            }
    }

};