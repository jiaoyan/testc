//
//  CPrimerThe11Chapter.h
//  testc
//
//  Created by 椒盐 on 14-12-24.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#ifndef __testc__CPrimerThe11Chapter__
#define __testc__CPrimerThe11Chapter__

#include <stdio.h>

namespace Jiaoyan {
    
    class CPrimerThe11Chapter {
    public:
        CPrimerThe11Chapter();
        ~CPrimerThe11Chapter();
        static CPrimerThe11Chapter* sharedCPrimerThe11Chapter();
        bool init();
    private:
    };
}

#endif /* defined(__testc__CPrimerThe11Chapter__) */
