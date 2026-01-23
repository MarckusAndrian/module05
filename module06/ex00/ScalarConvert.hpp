#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>

class ScalarConvert
{
private:
    ScalarConvert();
    ScalarConvert(ScalarConvert const &other);
    ScalarConvert &operator=(ScalarConvert const &rhs);
    ~ScalarConvert();
    /* data */
public:

    static void convert(std::string const &s);
};
