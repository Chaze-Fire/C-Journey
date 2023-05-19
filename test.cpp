#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
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
        }

        input.close();
        cout<<"Done!"<<endl;
    }
    else {
        cout<<"Please enter a valid choice!"<<endl;
    }

    return 0;

   }