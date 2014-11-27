//
//  CPrimerThe7Chapter.cpp
//  about 函数
//  testc
//
//  Created by 王蛟炎 on 14/11/27.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include "CPrimerThe7Chapter.h"
#include <iostream>

using namespace std;

namespace Jiaoyan {
    static CPrimerThe7Chapter* s_SharedCPrimerThe7Chapter = NULL;
    
    CPrimerThe7Chapter::CPrimerThe7Chapter()
    {
        
    }
    
    CPrimerThe7Chapter::~CPrimerThe7Chapter()
    {
        
    }
    
    CPrimerThe7Chapter *CPrimerThe7Chapter::sharedCPrimerThe7Chapter()
    {
        if (s_SharedCPrimerThe7Chapter) {
            return s_SharedCPrimerThe7Chapter;
        }
        s_SharedCPrimerThe7Chapter = new CPrimerThe7Chapter();
        return s_SharedCPrimerThe7Chapter;
    }
    
    bool CPrimerThe7Chapter::init()
    {
        //函数的返回值tip
        //C++函数的返回值不能是数组，可以是任意其他类型，但是可以将数组作为结构或者对象组成部分来返回

        //为什么需要原型
        //原型将函数的返回值类型，参数类型和数量告诉编译器
        //确保编译器正确处理函数返回值,检查使用的参数数目是否正确，参数类型是否正确
        
        //在编译阶段进行的原型化被称为静态类型检查
        
        //函数和数组
        //对于函数 int sum_arr(int arr[],int n);
        //该函数的第一个参数是一个数组，实际上C++传递的参数是一个指针，实际上的定义是int sum_arr(int *arr,int n);
        //在C++中，当且仅当在头文件或者说原型中，int arr[]和 int *arr 等价，例如在函数体中不能用int arr[]来声明指针
        //两个恒等式 arr[i] = *(arr + i);  &arr[i] = arr +i;
        const int arSize = 7;
        int cookies[arSize] = {1,2,3,4,5,6,7};
        cout << "sizeof(cookies) : " << sizeof(cookies) << endl;//这里输出28,7个int字节
        cout << "result = " << sum_arr(cookies, arSize) << endl;
        cout << "result = " << sum_arr(cookies, 3) << endl;
        cout << "result = " << sum_arr(cookies+3, 4) << endl;//和下面的调用实际上一样，侧面证明了其实第一个参数是传递一个指针
        cout << "result = " << sum_arr(&cookies[3], 4) << endl;
        
        return true;
    }
    
    int CPrimerThe7Chapter::sum_arr(int arr[],int n)
    {
        int total = 0;
        //cout << "sizeof(arr) : " << sizeof(arr) << endl;//这里的sizeof是8，64位的int指针的长度
        //这就是为什么需要传入数组长度的原因
        for (int i = 0; i < n; i++) {
            total += arr[i];
        }
        return total;
    }
}