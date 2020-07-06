#include <iostream>

void myFunction(int &&val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    int i = 52;
    myFunction(std::move(i));
    //std::cout << i << std::endl; // Not a good idea!

    return 0; 
}
