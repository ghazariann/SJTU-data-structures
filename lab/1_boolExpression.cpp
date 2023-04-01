#include <string.h>

#include <iostream>
using namespace std;

template <class T>
class seqStack {
   private:
    T *elem;
    int top_p;  // 栈顶
    int maxSize;
    void doubleSpace();

   public:
    seqStack(int initSize = 10);
    ~seqStack();
    bool isEmpty() const;
    void push(const T &x);
    T pop();
    T top() const;
};
template <class T>
void seqStack<T>::doubleSpace() {
    T *tmp = elem;
    elem = new T[2 * maxSize];
    for (int i = 0; i < maxSize; ++i)
        elem[i] = tmp[i];
    maxSize *= 2;
    delete[] tmp;
}
template <class T>
seqStack<T>::seqStack(int initSize) {
    elem = new T[initSize];
    maxSize = initSize;
    top_p = -1;
}
template <class T>
seqStack<T>::~seqStack() { delete[] elem; }
template <class T>
bool seqStack<T>::isEmpty() const { return top_p == -1; }
template <class T>
void seqStack<T>::push(const T &x) {
    if (top_p == maxSize - 1) doubleSpace();
    elem[++top_p] = x;
}
template <class T>
T seqStack<T>::pop() { return elem[top_p--]; }
template <class T>
T seqStack<T>::top() const { return elem[top_p]; }

class boolCalc {
    char *expression;
    enum token { OPAREN,
                 NOT,
                 AND,
                 OR,
                 CPAREN,
                 VALUE,
                 COMMA,
                 EOL };  // 枚举类型
    void BinaryOp(token op, seqStack<int> &dataStack);
    token getOp(int &value);  // 引用参数及返回值
   public:
    boolCalc(const char *s) {
        expression = new char[strlen(s) + 1];
        strcpy(expression, s);
    }
    ~boolCalc() { delete expression; }
    boolCalc &operator=(const boolCalc &other);
    int result();
};
void boolCalc::BinaryOp(token op, seqStack<int> &dataStack) {
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
        case AND:
            dataStack.push(num1 && num2);
            break;
        case OR:
            dataStack.push(num1 || num2);
            break;
    }
}

boolCalc::token boolCalc::getOp(int &value) {
    while (*expression) {
        while (*expression && *expression == ' ')
            ++expression;
        if (*expression == 'f' || *expression == 't') {
            value = (*expression == 'f') ? 0 : 1;
            ++expression;
            return VALUE;
        }

        switch (*expression) {
            case '(':
                ++expression;
                return OPAREN;
            case ')':
                ++expression;
                return CPAREN;
            case '|':
                ++expression;
                return OR;
            case '&':
                ++expression;
                return AND;
            case '!':
                ++expression;
                return NOT;
            case ',':
                ++expression;
                return COMMA;
        }
    }
    return EOL;
}

int boolCalc::result() {
    token lastOp, topOp, topCalcOp;
    int result_value, CurrentValue;
    seqStack<token> calcStack;
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
            case CPAREN:
                topCalcOp = calcStack.pop();
                if (topCalcOp == NOT) {
                    dataStack.push(!dataStack.pop());
                    topOp = opStack.pop();
                }  // ”)”
                else {
                    while (!opStack.isEmpty() && (topOp = opStack.pop()) == COMMA)  // case ()
                        BinaryOp(topCalcOp, dataStack);
                }
                if (topOp != OPAREN)
                    cerr << "Missing left parenthesis!" << endl;
                break;
            case OPAREN:  // '('
            case COMMA:   // ','
                opStack.push(lastOp);
                break;
            case OR:
            case AND:
            case NOT:
                calcStack.push(lastOp);
                break;
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
    string expression;
    cin >> expression;  // "|(&(t,f,t),!(t))"
    const char *expression_char = expression.c_str();
    boolCalc expr(expression_char);
    cout << expr.result() << endl;
    return 0;
}