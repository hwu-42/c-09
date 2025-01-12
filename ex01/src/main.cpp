#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int performOperation(int a, int b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Invalid operator");
}

int evaluateRPN(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isOperator(token)) {
            if (stack.size() < 2) throw std::runtime_error("Invalid expression");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = performOperation(a, b, token);
            stack.push(result);
        } else {
            int num;
            std::istringstream numStream(token);
            if (!(numStream >> num) || num < 0 || num >= 10) {
                throw std::runtime_error("Invalid token");
            }
            stack.push(num);
        }
    }

    if (stack.size() != 1) throw std::runtime_error("Invalid expression");
    return stack.top();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    try {
        int result = evaluateRPN(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}


