#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data initialData(4, 2);

    std::cout << "Intial Data:" << std::endl;
    initialData.printData();

    uintptr_t raw = Serializer::serialize(&initialData);
    Data *dataFinal = Serializer::deserialize(raw);

    std::cout << "Final Data:" << std::endl;
    dataFinal->printData();

    return 0;
}
