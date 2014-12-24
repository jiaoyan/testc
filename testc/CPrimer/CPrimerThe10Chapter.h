//
//  CPrimerThe10Chapter.h
//  testc
//
//  Created by 椒盐 on 14-12-23.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#ifndef __testc__CPrimerThe10Chapter__
#define __testc__CPrimerThe10Chapter__

#include <stdio.h>

namespace Jiaoyan {
    
    class CPrimerThe10Chapter {
    public:
        CPrimerThe10Chapter();
        ~CPrimerThe10Chapter();
        static CPrimerThe10Chapter* sharedCPrimerThe10Chapter();
        bool init();
    private:
    };
}

#endif /* defined(__testc__CPrimerThe10Chapter__) */
