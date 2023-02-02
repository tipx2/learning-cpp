#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include <iostream>
#include <cstring>
using namespace std;

void swapper(int &i, int &j){
    // pass by reference to swap the values of ints in two memory locations
    int temp = i;
    i = j;
    j = temp;
}

int main(int argc, char **argv){
    int values[10] = {10, 9, 7, 6, 8, 2, 3, 1, 5, 4};

    //seed and shuffle the array of values
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(values), std::end(values), std::default_random_engine(seed));

    // use std::copy to copy the shuffled array to "copied"
    int copied[10];
    copy(begin(values), end(values), begin(copied));
    int n = sizeof(values);
    
    // n^2 loop and main bubble sort code
    for(int i = 0; i<10; i++) {
        for(int j = i+1; j<10; j++){
            if(values[j] > values[i]) {
                swapper(values[i], values[j]);
            }
        }
    }
    
    // check for command line argument to print or not
    if (strcmp(argv[1], "print") == 0){
        // for-each loop through the copied shuffled array
        cout << "Input Array: ";
        for(int value : copied){
            cout << value << " ";
        }
        cout << endl;
        // for-each loop through the sorted output array
        cout << "Output Array: ";
        for(int value : values){
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}