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
        using std::cin;
        using std::ios_base;
        using std::string;
        for (int i = 0; i < 5; i++) {
            //for 循环中更新表达式在循环之后执行，此时循环体已经结束，
            //条件表达式在循环之前执行,此时循环体还未开始
            //cout << " i : " << i << endl;
        }
        
        /*
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
        */
        
        /*
        //前缀格式和后缀格式的效率不同，前缀会高一点
        double arr[2] = {1.0,2.0};
        double *pt = arr;
        cout << "*pt : " << *pt << endl;//pt指向arr[0]
        ++pt;
        cout << "*pt : " << *pt << endl;//pt指向arr[1]
        
        for (int i = 0,j = 10; i<10; i++,j--) {//for语句中的逗号运算符
            cout << " i = " << i << ", j = " << j << endl;
        }
        
        //逗号表达式的值是最后一部分的值
        //int i = 20,j = i+20,那么该表达式的值是40
        */
        
        /*
        //c风格的字符串的比较不能用==，这样比较的是两个字符串的地址,应该用strcmp函数来比较,相同则返回0
        //==不能用来比较字符串，但是可以用来比较字符
        char a[80] = "wang";
        char b[5] = "wang";
        cout << strcmp(a, b) << endl;//0,相等，说明strcmp并不管字符数组的长度，只在乎字符串的长度
        char ca = 'a';
        char cb = 'a';
        cout << (ca == cb) << endl;//1,相等，strcmp和==在两个字符串相同的时候返回值不一样
        
        //string对象的比较，string重载了操作符==,!=
        //只要两边有一个是string对象就可以使用
        string name = "wang";
        char names[80] = "wang";
        cout << (name == "wang") << endl;//1
        cout << (name == names) <<endl;//1
        */
        
        /*
        //clock函数
        float sec;
        cin >> sec;
        clock_t delay = sec * CLOCKS_PER_SEC;//CLOCKS_PER_SEC每秒钟包含的系统时间单位数
        clock_t start = clock();
        while (clock() - start < delay) {
            cout << "clock() : " <<  clock() << "," << start << "," << delay << endl;
        }
        cout << "done" << endl;
        */
        
        //类型别名,建立类型别名的方式有两种
        //一种是用预处理器,#define
        //另一种是使用关键字typedef
        
        /*
        //do while
        int n ;
        do {
            cin >> n;
        } while (n != 7);
        cout << "done" << endl;
        */
        
        /*
        //C++11基于范围的for循环
        double prices[5] = {1.0,2.0,3.0,4.0,5.0};
        for (double a : prices){
            a = 1.0;//这里不能改变数组中的值
            cout << a << endl;//1
        }
        cout << prices[4] << endl;//5
        //如果需要改变数组的值，那么循环要写成这样
        for (double &a : prices) {
            a = 1.0;
            cout << a << endl;//1
        }
        cout << prices[4] << endl;//1
        */
        
        /*
        //cin在读取char值的时候，cin将忽略空格和换行符
        char ch;
        cin >> ch;//cin只有在输入回车之后，才会把输入的内容发送给程序
        while (ch != '#') {
            cout << ch;
            cin >> ch;
        }
        */
        
        //用cin.get()来解决空格换行问题
        /*
        char ch;
        cin.get(ch);
        while (ch != '#') {
            cout << ch;
            cin.get(ch);
        }
        */
        
        //cin的EOF，暂时没有细看
        
        
        
        return true;
    }
}