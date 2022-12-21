#include <iostream>
#include <ctime>
//#include "employee.hpp"
//#include "account.hpp"
#include "pyme.hpp"
#include <vector>
#include <ctime>
using namespace std;

vector <employee> random_employees(void)
{
    srand(time(0));
    string names[10] = {"Carolina", "Valeria", "Andrea", "Camila", "Adriana", "Pedro", "Pablo", "Carlos", "Juan", "Camilo"};
    string last_names[10] = {"Gonzalez", "Perez","Ochoa", "Rondon", "Muñoz", "Segura", "Parraga", "Mora", "Pelaez"};
    vector <employee> rand_employees;

    for (int i = 0; i < 3; i++)
    {
        int rand_name = 1 + (rand() % 9);
        int rand_lastname = 1 + (rand() % 9);
        int children = 1 + (rand() % 5);
        int extra_hours = 1 + (rand() % 5);
        float salary = 1 + (rand() % 10);
        string name = names[rand_name];
        string last_name = last_names[rand_lastname];
        string username = names[rand_name]+last_names[rand_lastname];
        float balance = 10 + (rand() % 20);
        account employee_acc(username, balance);
        employee employeee(name, last_name, children , extra_hours, salary, employee_acc);
        rand_employees.push_back(employeee);
    }

    return rand_employees;
}

// int print_employees(vector <employee> employees){

//     for (int i = 0; i < employees.size(); i++)
//     {
//         cout << "Employee " << i+1 << ":" << endl;
//         cout << "Name: " << employees[i].get_name() << " " << employees[i].get_last_name() << endl;
//         cout << "Number of children: " <<  employees[i].get_children() << endl;
//         cout << "Number of extra hours: " <<  employees[i].get_extra_hours() << endl;
//         cout << "Salary: $" <<  employees[i].get_salary() << endl;
//         cout << "Total paycheck: $" << employees[i].get_total_paycheck()<<endl;
//         cout << "Bank Account Balance: " <<  employees[i].get_bank_account().get_balance() << endl;
//         cout<<endl;
//     }

//     return 0;
// }

// int paySalary(vector <employee>& employees, pyme& empresa1){

//     for (int i=0; i < employees.size() ;i++){

//         float amount  = employees[i].get_total_paycheck();
//         cout<<"amount: " << amount<<endl;
//         empresa1.get_bank_account().change_balance(-1 * amount);
//         cout <<"Pagando" << empresa1.get_bank_account().get_balance() << endl; 
//         employees[i].get_bank_account().change_balance(amount);

//     }

//     return 0; 
// }


int main(void){

    srand(time(0));

    vector <employee> employees = random_employees (); 
    

    account acc_pyme ("Greenlab", 100);
    pyme empresa1("Greenlab", employees, acc_pyme);
    
    cout << "Greenlab´s Employees: "<< endl;
    empresa1.print_employees();

    cout<<"Greenlab´s Balance before paying the employees: " << endl << empresa1.get_bank_account().get_balance() << endl;

    // paySalary(employees, empresa1);
    empresa1.paySalary();

    cout << "Greenlab´s Employees after being paid: "<< endl;
    empresa1.print_employees();


    cout<<"Greenlab´s Balance after paying the employees: " << endl << empresa1.get_bank_account().get_balance() << endl;
    
    return 0; 
}


