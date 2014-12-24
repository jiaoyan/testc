//
//  CPrimerThe9Chapter.h
//  testc
//
//  Created by 椒盐 on 14-12-22.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#ifndef __testc__CPrimerThe9Chapter__
#define __testc__CPrimerThe9Chapter__

#include <stdio.h>
namespace Jiaoyan {
    
    class CPrimerThe9Chapter {
    public:
        CPrimerThe9Chapter();
        ~CPrimerThe9Chapter();
        static CPrimerThe9Chapter* sharedCPrimerThe9Chapter();
        bool init();
    private:
    };
}


#endif /* defined(__testc__CPrimerThe9Chapter__) */
