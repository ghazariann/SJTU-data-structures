#include <math.h>
#include <string.h>
#include <iostream>
#include "../Stack.cpp"

using namespace std;

class calc {
    char *expression;
    enum token { OPAREN,
                 ADD,
                 SUB,
                 MULTI,
                 DIV,
                 EXP,
                 CPAREN,
                 VALUE,
                 EOL };  // 枚举类型
    void BinaryOp(token op, seqStack<int> &dataStack);
    token getOp(int &value);  // 引用参数及返回值
   public:
    calc(char *s) {
        expression = new char[strlen(s) + 1];
        strcpy(expression, s);
    }
    ~calc() { delete expression; }
    calc &operator=(const calc &other);
    int result();
};
void calc::BinaryOp(token op, seqStack<int> &dataStack) {
    int num1, num2;
    if (dataStack.isEmpty()) {
        cerr << "Missing operand!";
        exit(1);
    } else
        num2 = dataStack.pop();
    if (dataStack.isEmpty()) {
        cerr << "Missing operand";
        exit(1);
    } else
        num1 = dataStack.pop();
    switch (op) {
        case ADD:
            dataStack.push(num1 + num2);
            break;
        case SUB:
            dataStack.push(num1 - num2);
            break;
        case MULTI:
            dataStack.push(num1 * num2);
            break;
        case DIV:
            dataStack.push(num1 / num2);
            break;
        case EXP:
            dataStack.push(pow(num1, num2));
    }  // 计算结果进栈
}

calc::token calc::getOp(int &value) {
    while (*expression) {
        while (*expression && *expression == ' ')  // 忽略空格
            ++expression;
        if (*expression <= '9' && *expression >= '0') {
            value = 0;
            while (*expression >= '0' && *expression <= '9') {
                value = value * 10 + *expression - '0';
                ++expression;
            }
            return VALUE;  // 读入操作数
        }
        switch (*expression) {  // 读入运算符
            case '(':
                ++expression;
                return OPAREN;
            case ')':
                ++expression;
                return CPAREN;
            case '+':
                ++expression;
                return ADD;
            case '-':
                ++expression;
                return SUB;
            case '*':
                ++expression;
                return MULTI;
            case '/':
                ++expression;
                return DIV;
            case '^':
                ++expression;
                return EXP;
        }
    }
    return EOL;
}

int calc::result() {
    token lastOp, topOp;
    int result_value, CurrentValue;
    seqStack<token> opStack;
    seqStack<int> dataStack;
    char *str = expression;
    while (true) {
        lastOp = getOp(CurrentValue);
        if (lastOp == EOL) break;
        switch (lastOp) {
            case VALUE:
                dataStack.push(CurrentValue);
                break;
            case CPAREN:  // ”)”
                while (!opStack.isEmpty() && (topOp = opStack.pop()) != OPAREN) // case ()
                    BinaryOp(topOp, dataStack);
                if (topOp != OPAREN)
                    cerr << "Missing left parenthesis!" << endl;  // 错误信息输出流
                break;
            case OPAREN:  // '('
                opStack.push(OPAREN);
                break;
            case EXP:
                opStack.push(EXP);
                break;  // 乘方入栈 右结合，其余运算左结合
            case MULTI:
            case DIV:
                while (!opStack.isEmpty() && opStack.top() >= MULTI)  // opStack.top() != OPAREN, ADD, SUB
                    BinaryOp(opStack.pop(), dataStack);
                opStack.push(lastOp);
                break;
            case ADD:
            case SUB:
                while (!opStack.isEmpty() && opStack.top() != OPAREN)
                    BinaryOp(opStack.pop(), dataStack);
                opStack.push(lastOp);
        }
    }
    while (!opStack.isEmpty())
        BinaryOp(opStack.pop(), dataStack);
    if (dataStack.isEmpty()) {
        cout << "No result\n";
        return 0;
    }
    result_value = dataStack.pop();
    if (!dataStack.isEmpty()) {
        cout << "Missing Operator";
        return 0;
    }
    expression = str;
    return result_value;
}

int main() {
    // calc exp1("3*(1+1)^2^3/(4 - 2) - 10");
    // cout << exp1.result( )<< endl;
    // calc exp2("3*6/9+5");
    // cout << exp2.result() << endl;
    // calc exp3("6/3*4+1");
    // cout << exp3.result( )<< endl;
    return 0;
}