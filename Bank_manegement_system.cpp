#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <fstream>

using namespace std;
int g = 0;
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

        output<<uName<<" "<<pass<<" "<<name<<" "<<email<<" "<<gender<<" "<<phone<<endl;
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
            int g = 1;
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
    cout << "What would you like to do Today?\n";
    cout << "1) Show Balance\n";
    cout << "2) Withdraw Money\n";
    cout << "3) Deposit Money\n";
    cout << "3) Create An Account\n";
    cout << "4) Exit\n";
    cout << "Enter Your Choice: ";
    
    cin >> choice;
    switch(choice){
        case 1:
           showBalance();
           break;
        case 2:
           withdrawMoney();
           }
           break;
        case 3:
           login();
           if (g = 1){
            cout << "Please Login Correctly\n";
           }
           else{
           depositMoney();
           }
           break;
        case 4:
           break;
        default:
           cout << "Please Enter A valid Choice";
           break;
        }
    return 0;
}
void depositMoney(){
   cout << "******************Money Deposit ************************************";
};
void withdrawMoney(){
   cout << "HEllo World 2money";
};
void showBalance(){
   cout << "HEllo World BALANCE";
};