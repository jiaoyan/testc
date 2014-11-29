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
        
        /*
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
        */
        
        //为保证传递指针的时候，不改变原来的数据，可在声明时使用关键字const
        
        //对于处理数组的函数，必须将数组中的数据种类，起始位置和数组的元素数量传递给函数
        //还有另一种方法，类似STL模板类的iterater,通过传递两个指针来完成，一个指针标示数组的开头，一个指针标示数组的尾部
        //const int arSize = 7;
        //int cookies[arSize] = {1,2,3,4,5,6,7};
        //cout << sun_arr2(cookies, cookies +arSize) << endl;
        
        //c++禁止将const的地址赋给非const指针,如果一定要这么做，可以使用强制类型转换,const_cast
        //const int a = 20;
        //int *p = a;//invalid，因为这种定义是可以用p去改变a的值，但是a又是const不能改变的，矛盾
        
        //将指针指向指针，涉及的是一级间接关系，则将非const指针赋给const指针是可以的
        //int age = 20;
        //int *p = &age;
        //const int *pp = p;//valid , but *pp = 20 是非法的
        
        //然而进入2级关系时，(比如cookies数组里的元素是指针的情况下！！！)
        //const int ** pp;
        //int *p1;
        //const int a = 20;
        //pp = &p1;//invalid
        //*pp = &a;//valid
        //*p1 = 10;//valid,but运行时报错，10是常量
        
        //例如，如果cookies的定义修改为
        //const int cookies[7] = {1,2,3,4,5,6,7};
        //sum_arr(cookies,7);//valid,因为这里将指向const数据的指针赋给一个指向非const数据的指针
        
        //指针声明的参数尽量使用const
        //理由1：避免无意中修改数据
        //理由2：使用const可以处理const和非const得实参，否则将只能接受非const数据
        
        //函数和二维数组，函数参数是二维数组的时候
        //int data[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        //cout << sum_arr2wei(data,3) << endl;
        
        //函数和C风格字符串
        //C风格字符串：由一系列字符组成，以空值字符结尾
        //当字符串作为函数的参数时，传递的也是地址
        //表示字符串的方式有3种，char数组，""字符串常量，被设置为字符串地址的char指针
        //但是3种方式类型起始都是char*
        
        //c风格字符串与char数组有一个重要的区别，就是字符串有内置的结束字符（\0），这意味着不必将字符串的长度当做参数传递给函数
        //函数可以用循环依次检查字符串中的每个字符，直到遇到结尾的空值字符串为止
        //例如：
        //while (*str) {
            //str++;
        //}
        
        //返回C风格字符串的函数
        //实际上是返回一个字符串的地址，如果是在函数内部new出来的字符串，那么在函数外使用完该字符串后一定要delete
        //char * a = create_char('c', 10);
        //cout << a << endl;
        //delete []a;//注意这里一定要delete掉这个指针，new和delete的配对跨过了两个函数
        
        //函数和结构
        //结构与数组不同，结构将其数据组合成单个的实体或数据对象，该实体被视为一个整体，行为更接近于单值变量，如int
        //按值传递结构有一个缺点，如果结构非常大，则复制结构将增加内存要求，降低系统运行速度
        //所以往往将参数设计为传递结构的地址,而且用地址的方式还可以修改原本的结构内容,这是值传递所做不到的
        
        /*
        //函数和string对象
        string list[3];
        for (int i = 0; i < 3; i++) {
            getline(cin,list[i]);//getline函数，iostream库中,读取输入的一行字符串存入string对象中
        }
        for (int i = 0; i < sizeof(list)/sizeof(string); i++) {
            cout << list[i] << endl;
        }
        */
        
        //函数与C++11中的array对象
        //array<double, 4> *p;
        
        //递归
        //countdown(5);
        //!!!重点
        
        //函数指针
        //获取函数的地址很简单，只要使用函数名(后面什么都不要)就可以
        
        //声明函数指针
        //普通的函数声明，double sum(int);
        //函数指针的声明，double (*pf)(int);
        //sum就跟(*pf)一样是函数，那么pf就是指向函数的指针了
        //通常，要声明指向特定类型的函数指针，可以先编写类似sum的函数原型，然后再用(*pf)替换函数名，这样pf就是这类函数的指针
        
        //声明一个函数指针数组!!!
        //p1是一个普通函数 const double * p1 (const double * ,int);//参数是一个double数组，int，返回值是double数组
        //const double * (*pa[3])(const double * , int) = {p1,p2,p3};
        //const double * (*pf)(const double *, int) = p1;
        //两个声明对比，首先pa是一个包含3个元素的数组，所以先要使用pa[3],该声明的其他部分指出了数组包含的元素是什么样的
        //运算符[]的优先级高于*,因此*pa[3]表明pa是一个包含3个指针的数组
        //pa是数组，同时pa也表示指向函数指针的指针
        //那么如何声明指向整个数组的指针
        //const double *(* (*pb)[3])(const double * , int) = &pa;
        //pd是一个指针，指向一个包含三个元素的数组
        
        //tips:
        //int a[3]这种数组，使用a和&a都能得到一个地址，而且他们数值相同，但是他们的类型不同
        //a是数组中第一个元素的地址，&a是数组的地址
        //a+1是表示数组中第二个元素的地址，而&a+1是数组a后面的12个字节的内存块的地址
        //还有一个差别是，要得到第一个元素的值，*a就可以了，但是对于&a，需要两次**&a
        
        //typedef来简化声明
        //typedef const double * (*pf)(const double *, int);
        //pf f = p1;
        
        
        
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
    
    int CPrimerThe7Chapter::sun_arr2(int *begin,int *end){
        int total = 0;
        for (int *p = begin; p!= end; p++) {
            total += *p;
        }
        return total;
    }
    
    int CPrimerThe7Chapter::sum_arr2wei(int (*arr)[4],int size){
        //这里的括号必不可少，如果没有括号就变成了int *arr[4],指向4个int*元素的数组,而不是一个指向一个由4个int组成的数组的指针
        //还有一种格式可读性更强 int arr[][4],等价于int (*arr)[4],
        int total = 0;
        for (int i = 0; i < size ; i++) {
            for (int j = 0; j < 4; j++) {
                //total += arr[i][j];
                total += *((*(arr + i)) + j);//两种调用arr的写法是等价的
            }
        }
        return total;
    }
    
    char * CPrimerThe7Chapter::create_char(char c,int times){
        char *str = new char[times + 1];
        str[times] = '\0';
        while (times -- > 0) {
            str[times] = c;
        }
        return str;
    }
    
    void CPrimerThe7Chapter::countdown(int n){
        //该函数的输出要注意，先输出5个counting down，然后在倒叙输出5个kaboom
        cout << "counting down : " << n << endl;
        if (n > 0) {
            countdown(n-1);
        }
        cout << n << "kaboom" << endl;
    }
}