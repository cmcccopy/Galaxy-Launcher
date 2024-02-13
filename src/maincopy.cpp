#include <iostream>
#include "../Configure.h" //引入我们的头文件
#include "ExternalAdd.h"

int main(int argc, char *argv[])
{
    
    std::cout << "Hello, world!" ;
    std::cout << "Current Version: " << CURRENT_VERSION << ", Current Major: " << CURRENT_MAJOR << "\n" << std::endl; //调用我们的define的常量
    ExternalAdd(2,3); //调用外部函数
    return 0;
}
