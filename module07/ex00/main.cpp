#include "utils.tpp"

int main()
{
    {

        int a = 2; int b = 3;
        std::cout << "max btw a: " << a <<" and b: " << b <<" is: " << max<int>(a, b) << std::endl;
        swap<int>(a, b);
        std::cout << "after swap -> a: " << a << " b: " << b << std::endl;
    }

    {
        float a = 2.9f; float b = 3.0f;
        std::cout << "max btw a: " << a <<" and b: " << b <<" is: " << max<float>(a, b) << std::endl;
        swap<float>(a, b);
        std::cout << "after swap -> a: " << a << " b: " << b << std::endl;
    }

    {
        int a = 2; int b = 3;
        std::cout << "min btw a: " << a <<" and b: " << b <<" is: " << min<int>(a, b) << std::endl;
    }
    
    {
        float a = 2.9f; float b = 3.0f;
        std::cout << "min btw a: " << a <<" and b: " << b <<" is: " << min<float>(a, b) << std::endl;
    }

    std::cout << "\n --------------- SUBJECT-TEST ---------------" <<std::endl;
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    return (0);
}