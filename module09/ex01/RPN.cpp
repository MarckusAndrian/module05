#include "RPN.hpp"

RPN::RPN(){
}

RPN::RPN(RPN const& other){
    *this = other;
}

RPN &RPN::operator=(RPN const &rhs){
    if (this != &rhs)
    {
        _input = rhs._input;
    }
    return *this;
}

RPN::~RPN(){}

void RPN::setInput(std::string const &input)
{
    size_t i = 0;
    if (input.empty())
        throw std::runtime_error("Error: Empty input");
    while(input[i] && input[i] == ' ')
        i++;
    if (input.find_first_not_of("0987654321 *-+/") != std::string::npos)
        throw std::runtime_error("Error: Invalid number.");
    if ((input[i] < '0' || input[i] > '9'))
        throw std::runtime_error("Error: Begin with operator");
    for(; i < input.size(); i++)
    {
        while(input[i] == ' ')
            i++;
        if ((i < input.size() - 1) && (input[i + 1] != ' '))
        {
            throw std::runtime_error("Error: Two consecutives characteres not spaces");
        }
    }
    _input = input;
}

int RPN::identityChar(char c) const{
    if (c >= '0' && c <= '9')
        return 0;
    if (c == ' ')
        return 1;
    return -1;
}

void RPN::doOp(std::stack<int>& op, char o)
{
    int op1, op2, res;

    op2 = op.top();
    op.pop();
    op1 = op.top();
    op.pop();
    switch (o)
    {
    case '+':
        res = op1 + op2;
        break;
    case '-':
        res = op1 - op2;
        break;
    case '/':
        if (op2 == 0)
            throw std::runtime_error("Error: 0 as devisor is impossible.");
        res = op1 / op2;
        break;
    case '*':
        res = op1 * op2;
        break;
    
    default:
        break;
    }
    op.push(res);
}

void RPN::handleOp(std::string const &input)
{
    try{
        size_t i = 0;
        std::stack<int> op;
        setInput(input);
        while (input[i] == ' ')
            i++;
        for (; i < _input.size(); i++)
        {
            while (identityChar(input[i]) == 1)
               i++;
            if (i >= input.size())
                break;
            if (identityChar(input[i]) == -1)
            {
                if (op.size() < 2)
                    throw std::runtime_error("Error: calculation impossible");
                try{
                    doOp(op, input[i]);
                }
                catch(std::exception const &e)
                {
                    std::cout << e.what() << std::endl;
                    return ;
                }
            }
            if (identityChar(input[i]) == 0)
            {
                op.push(std::atoi(&(input[i])));
            }
        }
        if (op.size() > 1)
            throw std::runtime_error("Error: operator missed");
        std::cout << op.top() << std::endl;
    }catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
