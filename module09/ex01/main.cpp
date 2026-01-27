#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Bad argument." << std::endl;
        return (1);
    }
    RPN r;

    r.handleOp(av[1]);
    return 0;
}