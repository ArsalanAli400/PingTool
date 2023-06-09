#include <iostream>
#include "nettools.hpp"

int main(int argc,char *argv[]) {
    nettools nt;                // Net tool calling
    std::cout << "Connecting with " << argv[1] << std::endl;
    float percentage = nt.ping10(argc, argv);
    std::cout << "connection pingrate: " << percentage << std::endl;
    return 0;
}
