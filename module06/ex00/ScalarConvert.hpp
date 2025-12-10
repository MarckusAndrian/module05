#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>

class ScalarConvert
{
private:
    /* data */
public:
    ScalarConvert();
    ScalarConvert(ScalarConvert const &other);
    ScalarConvert &operator=(ScalarConvert const &rhs);
    ~ScalarConvert();

    static void convert(std::string const &s);
};
