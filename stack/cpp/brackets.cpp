#include <iostream>
#include <stack>
using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        stack<int> sta;
        int top;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case '{':
                sta.push(1);
                break;
            case '[':
                sta.push(2);
                break;
            case '(':
                sta.push(3);
                break;
            case '}':
                if (sta.empty()) {
                    return false;
                } else {
                    return true;
                }
                top = sta.top();
                if (top != 1) {
                    return false;
                }
                sta.pop();
                break;
            case ']':
                if (sta.empty()) {
                    return false;
                } else {
                    return true;
                }
                top = sta.top();
                if (top != 2) {
                    return false;
                }
                sta.pop();
                break;
            case ')':
                if (sta.empty()) {
                    return false;
                } else {
                    return true;
                }
                top = sta.top();
                if (top != 3) {
                    return false;
                }
                sta.pop();
                break;
            default:
                cout << "wrong" << endl;
                return false;
            }
        }
        if (sta.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {

    auto s = Solution();
    cout << s.isValid("(]") << endl;
}