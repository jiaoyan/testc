//
//  CPrimerThe4Chapter.h
//  testc
//
//  Created by 椒盐 on 14-11-20.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#ifndef __testc__CPrimerThe4Chapter__
#define __testc__CPrimerThe4Chapter__

#include <stdio.h>

namespace Jiaoyan {
    class CPrimerThe4Chapter {
    public:
        CPrimerThe4Chapter();
        ~CPrimerThe4Chapter();
        static CPrimerThe4Chapter* sharedCPrimerThe4Chapter();
        bool init();
    };
}

#endif /* defined(__testc__CPrimerThe4Chapter__) */
