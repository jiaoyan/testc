//
//  CPrimerThe7Chapter.h
//  testc
//
//  Created by 王蛟炎 on 14/11/27.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#ifndef __testc__CPrimerThe7Chapter__
#define __testc__CPrimerThe7Chapter__

#include <stdio.h>

#endif /* defined(__testc__CPrimerThe7Chapter__) */

namespace Jiaoyan {
    class CPrimerThe7Chapter {
    public:
        CPrimerThe7Chapter();
        ~CPrimerThe7Chapter();
        static CPrimerThe7Chapter* sharedCPrimerThe7Chapter();
        bool init();
    private:
        int sum_arr(int arr[],int n);
        int sun_arr2(int *begin,int *end);
        int sum_arr2wei(int (*arr)[4],int size);
        char *create_char(char c,int times);
        void countdown(int n);
    };
}