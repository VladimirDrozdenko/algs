#include <iostream>
#include <stack>
#include <string>
using namespace std;

static int typeOfBracket(char ch) {
    if (ch == '[' || ch == ']') return 0;
    if (ch == '(' || ch == ')') return 1;
    if (ch == '{' || ch == '}') return 2;
    if (ch == '<' || ch == '>') return 3;
    return -1; // must never reach this point
}

static bool checkBrackets(const string& str) {
    stack<char> s;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] == '<' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        } else if (str[i] == ')' || str[i] == '>' || str[i] == ']' || str[i] == '}') {
            if (!s.empty() && typeOfBracket(s.top()) == typeOfBracket(str[i])) {
                s.pop();
            }
        }
    }

    return s.empty();
}

int main() {
    string str = "((([]<dasdas>{asdas[<  ](dasd)sdasd}))[asda])";
    if (checkBrackets(str)) {
        cout << "Valid expression!" << endl;
    } else {
        cout << "The expression is messed up." << endl;
    }
}
