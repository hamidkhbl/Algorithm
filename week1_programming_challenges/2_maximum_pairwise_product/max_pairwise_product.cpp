#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<long long> numbers) {
    int n = numbers.size();

    int max_index= -1;
    for(int i = 0; i < n; ++i){
        if((max_index == -1)||(numbers[i] > numbers[max_index])){
            max_index = i;
        }
    }

    int max_2_index = -1;
    for(int j = 0; j < n; ++j){
        if((max_2_index == -1|| numbers[j] > numbers[max_2_index]) && j != max_index){
            max_2_index = j;
        }
    }

    return ((long long)numbers[max_index]) * ((long long)numbers[max_2_index]);
}

int main() {
    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
