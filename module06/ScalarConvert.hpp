#include <iostream>
#include <string>

class ScalarConvert
{
private:
    /* data */
public:
    ScalarConvert();
    ScalarConvert(ScalarConvert const &other);
    ScalarConvert&operator=(ScalarConvert const &rhs);
    ~ScalarConvert();

    static void convert(std::string const &s);
};
