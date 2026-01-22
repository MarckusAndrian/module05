#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: Bad argument." << std::endl;
        return (1);
    }
    RPN r;

    r.handleOp(av[1]);
    return 0;
}