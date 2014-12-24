//
//  CPrimerThe9Chapter.cpp
//  about 内存模型和名称空间
//  testc
//
//  Created by 椒盐 on 14-12-22.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include "CPrimerThe9Chapter.h"

namespace Jiaoyan {
    static CPrimerThe9Chapter* s_SharedCPrimerThe9Chapter = NULL;
    
    CPrimerThe9Chapter::CPrimerThe9Chapter()
    {
        
    }
    
    CPrimerThe9Chapter::~CPrimerThe9Chapter()
    {
        
    }
    
    CPrimerThe9Chapter *CPrimerThe9Chapter::sharedCPrimerThe9Chapter(){
        if (s_SharedCPrimerThe9Chapter) {
            return s_SharedCPrimerThe9Chapter;
        }
        s_SharedCPrimerThe9Chapter = new CPrimerThe9Chapter;
        return s_SharedCPrimerThe9Chapter;
    }
    
    bool CPrimerThe9Chapter::init(){
        //不要将函数的定义或变量声明放到头文件中，如果在头文件中包含一个函数定义，然后在其他两个文件中包含该头文件
        //那么，同一个程序中包含同一个函数的两个定义，除非是内联函数，否则会报错
        
        //将结构声明放在头文件中是可以的，因为他们不创建变量，而只是在源代码文件中声明结构变量时，告诉编译器如何创建该结构变量
        //同理，模板声明不是将被编译的代码，他们指示编译器如何生成与源代码中的函数调用相匹配的函数定义
        
        //被声明为const的数据和内联函数有特殊的链接属性，放在头文件中没有问题
        
        //included的""和<>的区别
        //使用<>的时候，C++编译器将在存储标准头文件的主机系统的文件系统中查找
        //使用""的时候，C++编译器将首先查找当前的工作目录或源代码目录，如果没有找到头文件，则将在标准位置在查找
        
        //头文件的管理
        //在同一个文件中只能将同一个头文件包含一次，为了避免多次包含同一个头文件，可以使用预处理器编译指令
        //#ifndef __testc__CPrimerThe9Chapter__
        //#define __testc__CPrimerThe9Chapter__
        //#endif
        //编译器首次遇到该文件时，名称__testc__CPrimerThe9Chapter__没有定义，在这种情况下编译器将查看ifndef和endif之间的内容
        //并读取定义的__testc__CPrimerThe9Chapter__的一行，如果在同一个文件中遇到其他包含该头文件的代码，编译器将知道
        //__testc__CPrimerThe9Chapter__已经被定义了，从而跳到endif后面的一行上
        
        //自动变量和栈
        
        //静态持续变量
        //c++为静态存储持续性变量也提供了3种链接性，外部链接性(可在其他文件中访问)，内部链接性(只能在当前文件中访问)，
        //无链接性(只能在当前函数或代码块中访问)
        //由于静态变量的数目在程序运行期间是不变的，因此程序不需要使用特殊的装置(如：栈)来管理他们，编译器将分配固定的内存块来存储所有的静态变量
        
        //要创建链接性为外部的静态持续变量，必须在代码块外面声明
        //要创建链接性为内部的静态持续变量，必须在代码块外面声明，并使用static限定符
        //要创建没有链接性的静态持续变量，必须在代码块内部声明，并使用static限定符
        /*
        int global = 1000;//external linkage
        static int one_file = 1000;//internal linkage
        int main(){
        }
        void fun1(){
            static int count = 1;//no linkage
            int lllma = 1;
        }
        */
        //如上，所有静态持续变量(global,one_file,count)在整个程序执行期间都存在
        //其中，count只能在fun1函数中使用他，就像自动变量lllma一样，然而，与lllma不同的是，即使在fun1没有被执行的时候，count也留在内存中
        //one_file的链接性为内部，因此只能在包含上述代码的文件中使用它，global的链接性为外部，因此可以在程序的其他文件中使用它
        
        //单定义规则
        //在每个使用外部变量的文件中，都必须声明他，使用extern
        
        //无链接性的静态持续变量在函数多次调用的时候不会多次初始化
        //如上的count在多次调用fun1的时候不会每次在执行该函数的时候都把count初始化为1，count的值在程序运行时已经被初始化，在函数调用时不会再次初始化
        
        //const的链接性
        
        //C++不允许在一个函数中定义另外一个函数
        
        //extern "C" 表示使用C语言链接性
        
        //编译器使用三块独立的内存：一块用于静态变量，一块用于自动变量，一块用于动态存储
        
        //定位new运算
        //通常，new负责在堆中找到一个足以能够满足要求的内存块，new运算符还有一种变体，定位new运算符
        //定位new运算符可以让我们指定要使用的位置，可以勇士这种特性来设置其内存管理规程，处理需要通过特定地址进行访问的硬件的或在待定位置创建对象
        
        //using声明和using编译指令
        //using Jiaoyan::fun;//声明fun名称，添加到它所属的声明区域中
        //using namespace std;//using编译指令
        
        //未命名的名称空间
        //namespace {
        //    int ice;
        //}
        //这个名称空间中声明的名称的潜在作用域为：从声明点到该声明区域末尾。从这个方面看，他们与全局变量相似。
        //然而，由于这种名称空间没有名称，因此不能显式的使用using编译指令或using声明来使它在其他位置都可用
        //具体的说，不能在未命名名称空间所属文件之外的其他文件中，使用该名称空间中的名称
        //这个和链接性为内部的静态变量类似
        //static int counts;
        //int main(){
        //}
        
        //namespace{
        //  int counts;}
        //int main(){
        //}
        
        
        
        
        return true;
    }
    
    
}