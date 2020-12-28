#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    if (N == number) {
        return 1;
    }
    string temp = "";
    set<int>::iterator it;
    vector<set<int>> ex(9, set<int>());
    for (int i = 1; i < 9; i++) {
        for (int j = 0; j < i; j++) {
            temp += to_string(N);
        }
        ex[i].insert(stoi(temp));
        temp = "";
    }
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < i; j++) {
            for (int num1 : ex[j]) {
                for (int num2 : ex[i - j]) {
                    ex[i].insert(num1 + num2);
                    ex[i].insert(num1 - num2);
                    ex[i].insert(num1 * num2);
                    if (num2 != 0) {
                        ex[i].insert(num1 / num2);
                    }
                }
            }
        }
        if (ex[i].find(number) != ex[i].end()) {
            answer = i;
            break;
        }
    }
    return answer;
}