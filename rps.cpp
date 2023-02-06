#include <iostream>
#include <string>
#include<limits>
using namespace std;

void check_winner(int p1, int p2){
    // check for rps winner using modulo method (if (a + 1) mod 3 == b mod 3)
    if (p1 == p2){
        cout << "tie" << endl;
    } else if ((p1 + 1) % 3 == p2 % 3){
        cout << "CPU wins" << endl;
    } else {
        cout << "Player wins" << endl;
    }
}

int main(){
    // array of strings for printing the result
    string rps[3] = {"rock", "paper", "scissors"};
    // cpu chooses randomly from 0 to 2
    int cpu_choice = rand()%3;
    int player_index;
    
    // input validation loop
    while(1) {
        cout << "1 - rock\n2 - paper\n3 - scissors\n";
        // if the player makes an input and the player's input is between 1 and 3
        if (cin >> player_index && player_index >= 1 && player_index <= 3) {
            // break to continue and resolve the winner
            break;
        } else {
            // otherwise, clear the cin, do something with limits (copied from stackoverflow) and go back to top of while loop
            cout << player_index << endl;
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // player index should be between 0 and 2 for the array
    player_index--;

    // print the choices, and then determine the winner
    cout << "player: " << rps[player_index] << endl << "CPU: " << rps[cpu_choice] << endl;
    check_winner(player_index, cpu_choice);

    return 0;
}