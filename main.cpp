#include <iostream>
#include "nettools.hpp"

void execute_application(nettools net, int _argc_, char *_argv_[]){
    std::cout << "Connecting with " << _argv_[1] << std::endl;
    float percentage = net.ping10(_argc_, _argv_);
    std::cout << "connection pingrate: " << percentage << std::endl;
    // Exceteable application
    if (percentage > 50) {
        int i;
        std::cout << "Checking if processor is available..." << std::endl;
        if (system(NULL)) puts("Ok");
        else exit(1);
        std::cout << "Executing Calc... " << std::endl;
        i = system(
                "/home/arsalan/Nextcloud/Arsalan/development/cNet_ping/cmake-build-debug/ping 192.168.10.1");   // For local services
        std::cout << "The value returned was: " << i << std::endl;
        getchar();
    }else{
        std::cout << "No network access! can't start application" << std::endl;
    }
}

int main(int argc,char *argv[]) {
    nettools nt;                // Net tool calling
    execute_application(nt,argc,argv);
    return 0;
}