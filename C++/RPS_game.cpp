#include <iostream>
#include <string>

using namespace std;
char compchoice();

int main(){
   char choice;
   char userchoice;
    
   do{
    cout << "\nRock Paper Sissors Game" <<  endl;
    cout << "***********************" << endl;
    cout << "'R' For Rock" << endl;
    cout << "'P' For Paper" << endl;
    cout << "'S' For Scissors" << endl;
    cout << "Enter Your Choice: ";
    cin >> userchoice;
    }while(choice != 'R' && choice != 'S' && choice && 'P');
   char a = compchoice();
   cout << "Computer Choose: " << a << endl;
   if (a == 'R' && userchoice == 'R'){
      cout << "You Choose Rock And the Computer Choose Rock, So ";
      cout << "You Tied";
    }
   else if (a == 'R' && userchoice == 'P'){
      cout << "You Choose Paper And the Computer Choose Rock, So ";
      cout << "You Won";
    }
   else if (a == 'R' && userchoice == 'S'){
      cout << "You Choose Scissors And the Computer Choose Rock, So ";
      cout << "You Lost";
    }
   else if (a == 'P' && userchoice == 'R'){
      cout << "You Choose Rock And the Computer Choose Paper, So ";
      cout << "You Lost";
    }
   else if (a == 'P' && userchoice == 'P'){
      cout << "You Choose Paper And the Computer Choose Paper, So ";
      cout << "You Tied";
    }
   else if (a == 'P' && userchoice == 'S'){
      cout << "You Choose Scissors And the Computer Choose Paper, So";
      cout << "You Won";
    }
   else if (a == 'S' && userchoice == 'R'){
      cout << "You Choose Rock And the Computer Choose Scissors, So ";
      cout << "You Won";
    }
   else if (a == 'S' && userchoice == 'P'){
      cout << "You Choose Paper And the Computer Choose Sissors, So ";
      cout << "You Lost";
    }
   else if (a == 'S' && userchoice == 'S'){
      cout << "You Choose Scissors And the Computer Choose Scissor, So ";
      cout << "You Tied";
    }
   else{
      cout << "Error Deciding";
   }
   return 0;
}
char compchoice(){
    srand(time(NULL));
    char b;
    int a = rand() % 3;
    switch(a){
        case 0:
           b = 'R';
           break;
        case 1:
           b = 'P';
           break;
        case 2:
           b = 'S';
           break;
        default:
           cout << "Error";
           break;
    }
    return b;
    
};