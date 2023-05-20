#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <fstream>

using namespace std;
double money = 0;
void login(){

    string uName, pass, name, email, gender;
    string logname, logpass;
    string valname, valpass;
    int phone;
    int choice;
    cout<<"Enter choice:"<<endl;
    cout<<"1.Register\t\t2.Login"<<endl;
    cin>>choice;

    if (choice==1) {
        ofstream output;
        output.open("record.txt");
        cout<<"Enter username: "<<endl;
        cin>>uName;
        cout<<"Enter password: "<<endl;
        cin>>pass;
        cout<<"Enter name: "<<endl;
        cin>>name;
        cout<<"Enter email: "<<endl;
        cin>>email;
        cout<<"Enter gender: "<<endl;
        cin>>gender;
        cout<<"Enter phone number: "<<endl;
        cin>>phone;

        output<<uName<<" "<<pass<<" "<<name<<" "<<email<<" "<<gender<<" "<<phone<<" "<<money<<endl;
        output.close();
        cout<<"Registration complete!"<<endl;

    }
    else if(choice==2){
        //  login
        ifstream input("record.txt");

        if(!input) {
            cout<<"Error creating file!";
        }

        cout<<"Enter username:"<<endl;
        cin>>logname;
        cout<<"Enter password:"<<endl;
        cin>>logpass;

        if (input >> uName && input >> pass &&     // check if reading was successfull
        uName == logname && pass == logpass) { //input??uName trying to get to the file and read the already entered uName and match with the current entered name by user, same with pass
            cout<<"Login successful"<<endl;

        }
        else {
            cout<<"Login failed!"<<endl;
        }

        input.close();
    }
    else {
        cout<<"Please enter a valid choice!"<<endl;
    }
};

void showBalance();
void withdrawMoney();
void depositMoney();
int main(){
        int choice;
        cout << "*************************\n";
        cout << "Bank Manegement System\n";
        cout << "**************************\n";
        login();
    do {
        cout << "\nWhat would you like to do Today?\n";
        cout << "1) Show Balance\n";
        cout << "2) Withdraw Money\n";
        cout << "3) Deposit Money\n";
        cout << "3) Create An Account\n";
        cout << "4) Exit\n";
        cout << "Enter Your Choice: ";
        
        cin >> choice;
        ifstream input("record.txt");
    
        if(!input) {
            cout<<"Error creating file!";
        }
        input >> money;
        switch(choice){
            case 1:
               showBalance();
               input.close();
               break;
            case 2:
               withdrawMoney();
               input.close();
               break;
            case 3:
               depositMoney();
               input.close();
               break;
            case 4:
               break;
            default:
               cout << "Please Enter A valid Choice";
               break;
            }
    }while(1 == 1);

    return 0;
}
void depositMoney(){
    double deposit;
    cout << "\nPlease Enter How Much Money you would like to deposit: ";
    cin >> deposit;
    money = money + deposit;
    cout << "Money Deposited: " << deposit << endl;
    cout << "Money in your Account: " << money << endl;
};
void withdrawMoney(){
    double withdraw;
    cout << "Please Enter How Much Money you would like to withdraw: ";
    cin >> withdraw;
    if (money < withdraw){
        cout << "You Do No Have The Sufficient Funds!";
    }
    else if(money = withdraw){
        money = money - withdraw;
        cout << "Money withdrawed: " << withdraw << endl;
        cout << "Money left in the account: " << money << endl; 
    }
    else{
       money = money - withdraw;
       cout << "Money withdrawed: " << withdraw << endl;
       cout << "Money left in the account: " << money << endl; 
    }
};
void showBalance(){
   cout << "Your Balance is: " << money << endl;
};