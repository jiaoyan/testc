//
//  CPrimerThe8Chapter.h
//  testc
//
//  Created by 王蛟炎 on 14/11/29.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#ifndef __testc__CPrimerThe8Chapter__
#define __testc__CPrimerThe8Chapter__

#include <stdio.h>

#endif /* defined(__testc__CPrimerThe8Chapter__) */

namespace Jiaoyan {
    struct free_throw {
        int made;
    };
    
    class CPrimerThe8Chapter {
    public:
        CPrimerThe8Chapter();
        ~CPrimerThe8Chapter();
        static CPrimerThe8Chapter* sharedCPrimerThe8Chapter();
        bool init();
    private:
        void swapr(int &a,int &b);
        void swapp(int *a,int *b);
        void swapv(int a,int b);
        const free_throw & clone(free_throw &);
    };
}