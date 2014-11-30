//
//  CPrimerThe8Chapter.cpp
//  about 深入函数
//  testc
//
//  Created by 王蛟炎 on 14/11/29.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include "CPrimerThe8Chapter.h"
#include <iostream>
using namespace std;

namespace Jiaoyan {
    static CPrimerThe8Chapter* s_SharedCPrimerThe8Chapter = NULL;
    
    CPrimerThe8Chapter::CPrimerThe8Chapter(){
        
    }
    
    CPrimerThe8Chapter::~CPrimerThe8Chapter(){
        
    }
    
    CPrimerThe8Chapter *CPrimerThe8Chapter::sharedCPrimerThe8Chapter(){
        if (s_SharedCPrimerThe8Chapter) {
            return s_SharedCPrimerThe8Chapter;
        }
        s_SharedCPrimerThe8Chapter = new CPrimerThe8Chapter;
        return s_SharedCPrimerThe8Chapter;
    }
    
    bool CPrimerThe8Chapter::init(){
        //内联函数
        //内联函数是C++为了提高程序运行速度所做得一项改进，常规函数和内联函数的主要区别不在于编写方式，而在于编译器如何将他们组合到程序中
        //程序在执行到函数调用指令时，程序将在函数调用后立即存储该指令的内存地址，并将函数参数复制到堆栈
        //跳到标记函数起点的内存单元，执行函数代码，将返回值放入寄存器中，然后跳回到地址被保存的指令处
        //内联函数则是另一种方式，编译器将使用相应的函数代码替换函数调用，所以对于内联函数，程序无须跳到另一个位置执行函数代码再跳回来
        //inline double square(double x){return x*x}
        
        //内联和宏
        //宏是纯粹的文本替换，会引发很多意想不到的问题
        //#define SQUARE(X) X*X
        //SQUARE(5.0+4.0);
        //上述使用宏定义的函数在执行的时候，会执行为5.0 + 4.0 * 5.0 +4.0,与我们的意图不符
        
        //引用变量
        int rats = 10;
        int &rr = rats;
        cout << &rats << "," << rats << endl;
        cout << &rr << "," << rr << endl;
        //可以发现rats和其引用rr的地址和值都相同
        //声明引用的时候必须同时初始化，因为引用是一个别名，声明的时候不指定他是谁的别名就没有意义了，这一点跟const指针类似
        
        //引用经常被用作函数参数
        //引用传递的好处是，被调用的函数也可以访问调用函数中得变量
        int a = 10;
        int b = 20;
        //swapr(a, b);//交换成功
        //swapp(&a, &b);//交换成功
        //swapv(a, b);//fail
        cout << "a : " << a << endl;
        cout << "b : " << b << endl;
        
        //按引用传递和按值传递看起来使用方式相同，只能通过函数定义才能知道
        //swapr(a+5,b);这样调用swapr函数是错误的，因为第一个参数是引用，所以实参应该是一个变量，而a+5是表达式并不是变量
        
        //函数的返回值是引用的时候应该要注意的问题:
        //不要返回局部变量的引用，因为在函数结束后局部变量都被回收，返回局部变量的引用明显会有问题
        //那么返回引用的函数只有一个办法，就是把参数中得引用返回，这样的参数与本函数回收无关了
        //还有一个办法就是new一块空间，然后返回指针，然后再调用完该指针后手动释放
        //还有一个办法就是声明一个指针，将指针指向引用参数
        free_throw ft = {1};
        
        const free_throw &ftb = clone(ft);
        cout << ftb.made << &ftb << endl;
        cout << ft.made << &ft << endl;//可以看到两者地址不一样
        
        
        return true;
    }
    
    void CPrimerThe8Chapter::swapr(int &a,int &b){
        //引用传递
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    
    void CPrimerThe8Chapter::swapp(int *a,int *b){
        //指针传递
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void CPrimerThe8Chapter::swapv(int a,int b){
        //值传递
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    
    const free_throw & CPrimerThe8Chapter::clone(free_throw &ft){
        //该函数比较重要，这里隐藏了new内存空间的操作
        //声明了指针P，并将指针p的内容设置为ft,在这里相当于new了一块内存空间
        //这里使用delete会有错误，因为确实没有new方法
        //????
        free_throw * p;
        *p = ft;
        return *p;
    }
}