//
//  main.cpp
//  testc
//
//  Created by 椒盐 on 14-11-13.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include <iostream>
#include <vector>
#include <array>
#include "CPrimer/CPrimerThe4Chapter.h"
#include "CPrimer/CPrimerThe5Chapter.h"
#include "CPrimer/CPrimerThe6Chapter.h"

int main(int argc, const char * argv[]) {
    using namespace Jiaoyan;
    CPrimerThe4Chapter* chapter4 = CPrimerThe4Chapter::sharedCPrimerThe4Chapter();
    chapter4->init();

//    CPrimerThe5Chapter* chapter5 = CPrimerThe5Chapter::sharedCPrimerThe5Chapter();
//    chapter5->init();
    
    CPrimerThe6Chapter* chapter6 = CPrimerThe6Chapter::sharedCPrimerThe6Chapter();
    chapter6->init();
    return 0;
}