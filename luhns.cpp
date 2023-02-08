#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string aryeh_credit_card;
    cout << "input aryeh's credit card number:\n";
    cin >> aryeh_credit_card;

    int total = 0;

    for(int i = aryeh_credit_card.length()-1; i>=0; i--){
        int value = aryeh_credit_card[i]-'0';
        if (i % 2 == 0){
            // -'0' converts string to int
            value *= 2;
            if (value >= 10){
                value = (value % 10) + (value / 10);
            }
        }
        total += value;
    }

    if (total % 10 == 0){
        cout << "valid" << endl;
    } else {
        cout << "stop trying to scam. put in your real card number right now or face the stevenified consequences." << endl;
    }
    return 0;
}
// 79927398713

// 79927397813