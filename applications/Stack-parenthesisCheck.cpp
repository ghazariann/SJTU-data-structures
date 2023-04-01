#include <iostream>
#include <stack>
#include <string>

bool is_valid_expression(const std::string& expression) {
    std::stack<char> s;
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    std::string expression1 = "((2 + 3) * 5)";
    std::string expression2 = "((2 + 3) * 5]";
    std::cout << "Expression 1 is " << (is_valid_expression(expression1) ? "valid" : "invalid") << std::endl;
    std::cout << "Expression 2 is " << (is_valid_expression(expression2) ? "valid" : "invalid") << std::endl;
    return 0;
}