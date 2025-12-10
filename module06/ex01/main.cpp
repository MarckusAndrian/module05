#include "Serializer.hpp"

int main()
{
    Data* data = new Data;
    uintptr_t raw = Serializer::serialize(data);

    std::cout << "data*: " << data << std::endl;
    std::cout << "raw: " << raw << std::endl;
    
    std::cout << "deserialize data: " << Serializer::deserialize(raw) << std::endl;
    delete data;
    return 0;
}