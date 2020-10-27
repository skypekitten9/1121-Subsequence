#include <iostream>
#include <queue>
#include <sstream>
#include <list>
using namespace std;

int GetValue(int startValue, int goal, vector<int>& inputList);

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> inputList;
        std::priority_queue<int> pQ;
        std::stringstream ss(line);

        int inputAmount;
        int goal;
        ss >> inputAmount;
        ss >> goal;

        int value;
        string line2;
        std::getline(std::cin, line2);
        std::stringstream ss2(line2);
        for (size_t i = 0; i < inputAmount; i++) {
            ss2 >> value;
            inputList.push_back(value);
        }

        int bestValue = 100000000;
        int result = 0;
        for (int i = 0; i < inputList.size(); i++) {
            result = GetValue(i, goal, inputList);

            if (result == 0) {
                break;
            }

            if (result <= bestValue) {
                bestValue = result;
            }
        }

        if (bestValue >= 100000000) {
            bestValue = 0;
        }
        cout << bestValue << endl;
    }

}

int GetValue(int startValue, int goal, vector<int>& inputList) {
    int result = 0;
    for (int i = startValue; i < inputList.size(); i++) {
        result += inputList[i];
        if (result >= goal) {
            return (i - startValue + 1);
        }
    }

    return 0;
}