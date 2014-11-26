//
//  CPrimerThe6Chapter.cpp
//  testc
//
//  Created by 椒盐 on 14-11-24.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include "CPrimerThe6Chapter.h"
#include <iostream>

namespace Jiaoyan {
    static CPrimerThe6Chapter* s_SharedCPrimerThe6Chapter = NULL;
    
    CPrimerThe6Chapter::CPrimerThe6Chapter(){
        
    }
    
    CPrimerThe6Chapter::~CPrimerThe6Chapter(){
        
    }
    
    CPrimerThe6Chapter* CPrimerThe6Chapter::sharedCPrimerThe6Chapter(){
        if (s_SharedCPrimerThe6Chapter)
            return s_SharedCPrimerThe6Chapter;
        s_SharedCPrimerThe6Chapter = new CPrimerThe6Chapter();
        return s_SharedCPrimerThe6Chapter;
    }
    
    bool CPrimerThe6Chapter::init(){
        using namespace std;
        //逻辑表达式
        // ||, && 低于关系表达式，而且从左到右执行,！是高于关系表达式的
        int i = 10;
        cout << (i++ < 6|| i > 10) << endl;//true,从左到右，在执行右侧语句的时候i已经是11了
        
        //判断是否超过int类型
        //x <= INT_MAX && x >= INT_MIN
        
        //字符函数库cctype
        //isalpha('a');//判断是否是字母字符
        //ispunct(',');//判断是否是标点符号
        //isspace(' ');//判断是否是空格
        //isdigit('1');//判断是否是数字
        
        /*
        const int golds = 5;
        int counts[golds];
        for (int i = 0; i < golds; i++) {
            cout << " i = " << i << endl;
            while (!(cin >> counts[i])) {//cin >> counts[i]当用户输入数字的时候，该表达式返回的是true,如不是则返回false
                cout << "true" << endl;
                cin.clear();
                cout << "cin.get() = " << cin.get() << endl;
                while (cin.get() != '\n') {
                    cout << "cin.get()2222 = " << cin.get() << endl;
                    continue;
                }
                cout << "enter a number :" << endl;
            }
        }
         */
        
        /*
        char ch;
        cin.get(ch);
        while (ch != '\n') {
            cout << ch;
            cin.get(ch);
        }
        */
        //字符变量=cin.get();相当于cin.get(字符变量);
        
        /*
        char ch1,ch2;
        ch1 = cin.get();
        ch2 = cin.get();
        cout << "ch1 = " << ch1 << ",ch2 = " << ch2 << endl;//在mac下，当只输入一个字符的时候，不会停止，会直接打印这一句，只是ch2里没有值
        */
        
        char ch1,ch2;
        ch1 = cin.get();
        cin.get();
        ch2 = cin.get();
        cout << "ch1 = " << ch1 << ",ch2 = " << ch2 << endl;//在这里输入一个字符的时候会停止
        
        /*
        xcode是有自己的缓存的，相当于虚拟机（eclipse），所以你这样不用绝对路径；要到他缓存里面找，用了绝对路径就可以了。你换换地址
        如果你要看看你的hello.txt文件
        你打开finder 按command＋shift＋g，输入/Users/你的apple机名字/Library/Developer/Xcode
        然后进入DriverData
        你可以看到你所有做过的还在的和删掉的文件，找到你的目前的文件，然后点击进入Build -> Product -> Debug里面就是你创建的hello.txt
        http://blog.csdn.net/SearchLife/article/details/3491768
         */
        return true;
    }
}