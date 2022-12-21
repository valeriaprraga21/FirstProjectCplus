#include <iostream>
#include "account.hpp"
using namespace std;

class employee{

    private:
        string name;
        string last_name;
        int children;
        int extra_hours;
        float salary;
        account bank_account;
        float total_paycheck;

    //constructor
    public:
        employee(string _name, string _last_name, int _children, int _extra_hours, float _salary, account _bank_account){
        name= _name;
        last_name = _last_name;
        children = _children;
        extra_hours = _extra_hours;
        salary = _salary;
        bank_account = _bank_account;
        total_paycheck = salary + (0.02*children*salary) + (0.01*extra_hours*salary); 
        }
    //getters

    public: 

    string get_name(void){
        return name;
    }

    string get_last_name(void){
        return last_name;
    }

    int get_children(void){
        return children;
    }

    int get_extra_hours(void){
        return extra_hours;
    }

    float get_salary(void){
        return salary;
    }

    float get_total_paycheck(void){
        return total_paycheck;
    }

    account get_bank_account(void){
        return bank_account;
    }

    //setters
    public: 

    void set_name(string aname){
        name = aname;
    }

    void set_last_name(string alast_name){
        last_name = alast_name;
    }

    void set_children(int achildren){

        children = achildren;
        if (children < 0){ 
            children = 0; 
        }
        if (children > 0){
            total_paycheck = total_paycheck + (0.02*children*salary);
        }
    }

    void set_extra_hours(int aextra_hours){
        extra_hours = aextra_hours;
        if (extra_hours > 0){
            total_paycheck = total_paycheck + (0.01*extra_hours*salary);
        }

    }

    void set_salary(int asalary){
        salary = asalary;
    }

    void set_bank_account(account abank_account){
       bank_account = abank_account ;
    }

    void deposit()
    {
        bank_account.change_balance(total_paycheck);
    }
    //methods

};
