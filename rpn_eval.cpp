#include<iostream>
#include"rpn_calc.h"

int main (int argc, char* argv[]) {
    std::cout << rpn_eval(argc, argv) << '\n';
 
    return 0;
}
