//
//  CPrimerThe5Chapter.cpp
//  testc
//
//  Created by 椒盐 on 14-11-20.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include "CPrimerThe5Chapter.h"
#include <iostream>

namespace Jiaoyan {
    static CPrimerThe5Chapter* s_SharedCPrimerThe5Chapter = NULL;
    
    CPrimerThe5Chapter::CPrimerThe5Chapter(){
        
    }
    
    CPrimerThe5Chapter::~CPrimerThe5Chapter(){
        
    }
    
    CPrimerThe5Chapter* CPrimerThe5Chapter::sharedCPrimerThe5Chapter(){
        if (s_SharedCPrimerThe5Chapter)
            return s_SharedCPrimerThe5Chapter;
        s_SharedCPrimerThe5Chapter = new CPrimerThe5Chapter();
        return s_SharedCPrimerThe5Chapter;
    }
    
    bool CPrimerThe5Chapter::init(){
        using std::cout;
        using std::endl;
        using std::ios_base;
        for (int i = 0; i < 5; i++) {
            //for 循环中更新表达式在循环之后执行，此时循环体已经结束，
            //条件表达式在循环之前执行,此时循环体还未开始
            //cout << " i : " << i << endl;
        }
        
        //表达式和语句
        //任何值或者任何有效的值和运算符的组合都是表达式，在C++中每个表达式都有值
        int cooks = 2;
        int maids = (cooks = 4) + 3;//表达式cooks = 4的值为4
        cout << "maids : " << maids << endl;
        
        cout << "cooks < 3 : " << (cooks < 3) << endl;//0
        cout << "cooks > 3 : " << (cooks > 3) << endl;//1
        //通常cout在显示bool值之前将他们转换为int，但cout.setf函数调用设置了一个标记，该标记命令cout显示true和false
        cout.setf(ios_base::boolalpha);
        cout << "cooks < 3 : " << (cooks < 3) << endl;//false
        cout << "cooks > 3 : " << (cooks > 3) << endl;//true
        
        //从表达式到语句的转变很容易，加个分号就可以
        //但是语句去掉分号，不一定就是表达式
        //int s ;是一条语句，但是int s不是表达式，因为它没有值
        //因此下面的语法是非法的 cout << int s; int f = for(int i =0;i<1;i++)cout<<i;
        
        //前缀格式和后缀格式的效率不同，前缀会高一点
        double arr[2] = {1.0,2.0};
        double *pt = arr;
        cout << "*pt : " << *pt << endl;//pt指向arr[0]
        ++pt;
        cout << "*pt : " << *pt << endl;//pt指向arr[1]
        
        for (int i = 0,j = 10; i<10; i++,j--) {
            cout << " i = " << i << ", j = " << j << endl;
        }
        
        //逗号表达式的值是最后一部分的值
        //int i = 20,j = i+20,那么该表达式的值是40
        
        return true;
    }
}