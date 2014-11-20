//
//  CPrimerThe5Chapter.h
//  testc
//
//  Created by 椒盐 on 14-11-20.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#ifndef __testc__CPrimerThe5Chapter__
#define __testc__CPrimerThe5Chapter__

#include <stdio.h>

namespace Jiaoyan {
    class CPrimerThe5Chapter{
    public:
        CPrimerThe5Chapter();
        ~CPrimerThe5Chapter();
        static CPrimerThe5Chapter* sharedCPrimerThe5Chapter();
        bool init();
        
    private:
        
    };
}

#endif /* defined(__testc__CPrimerThe5Chapter__) */
