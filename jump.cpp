#include <vector>
#include <iostream>
#include <string>
using namespace std;

/* find minimal jumps to go over the end of a list {4,3,2,1,3,4}
given that you can choose which number to jump to up to it's value
i.e. 4 can jump to 3, 2, 1 or 3
*/

void vector_printer(vector<int> printed){
    for(int item : printed){
        cout << to_string(item) << " ";
    }
    cout << endl;
}


int go_down_path(vector<int> v, int index, int total = 0){
    if (index + v[index] >= v.size()){
        return total + 1;
    } else {
        int min = 2147483647;
        for(int i = index+1; i<=index + v[index]; i++){
            int path = go_down_path(v, i, total+1);
            if (path < min){
                min = path;
            }
        }
        return min;
    }
}

int main(){
    vector<int> jumper = {4,3,2,1,3,4}; //should be 2 jumps
    vector<int> jumper2 = {3, 8, 1, 1, 1, 1, 1, 1, 1, 1}; // 3 jumps

    cout << go_down_path(jumper, 0) << endl;
    cout << go_down_path(jumper2, 0) << endl;
    return 0;
}