#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
int main(){
    srand(time(NULL));
    int a = rand() % 10000000000000 + 1;
    int guess;
    do {
        cout << "\nGuess the Number: \n";
        cin >> guess;
        if (guess > a){
            cout << "\nLower\n";
            guess = 0;
        }
        else if (guess < a){
           cout << "\nHigher\n";
           guess = 0;
        } 
        else{
            cout << "\nCorrect\n";
            guess = 0;
            break;

        }
    }while (1 == 1);
    return 0;
}