#include <iostream>
#include <string>
#include<limits>
using namespace std;

void check_winner(int p1, int p2){
    if (p1 == p2){
        cout << "tie" << endl;
    } else if ((p1 + 1) % 3 == p2 % 3){
        cout << "CPU wins" << endl;
    } else {
        cout << "Player wins" << endl;
    }
}

int main(){
    string rps[3] = {"rock", "paper", "scissors"};
    int cpu_choice = rand()%3;
    int player_index;
    
    while(1) {
        cout << "1 - rock\n2 - paper\n3 - scissors\n";
        if (cin >> player_index && player_index >= 1 && player_index <= 3) {
            break;
        } else {
            cout << player_index << endl;
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    player_index--;

    cout << "player: " << rps[player_index] << endl << "CPU: " << rps[cpu_choice] << endl;
    check_winner(player_index, cpu_choice);

    return 0;
}