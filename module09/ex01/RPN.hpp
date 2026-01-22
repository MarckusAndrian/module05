#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

class RPN {
private:
    std::string _input;
public:
    RPN();
    RPN(RPN const& other);
    RPN &operator=(RPN const &rhs);
    ~RPN();

    void handleOp(std::string const&);
    int identityChar(char c) const;
    void setInput(std::string const&);
    void doOp(std::stack<int> &op, char o);
};

#endif