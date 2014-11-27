//
//  CPrimerThe6Chapter.cpp
//  testc
//
//  Created by 椒盐 on 14-11-24.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include "CPrimerThe6Chapter.h"
#include <iostream>
#include <fstream>

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
        //cin.get(ch);
        ch = cin.get();
        while (ch != '\n') {
            cout << ch;//cout 每次输出一个字符，直到ch == '\n',结果就像输入一个字符串，然后输出字符串
            //cin.get(ch);
            ch = cin.get();
        }
        // (字符变量=cin.get()) == (相当于cin.get(字符变量));两种写法是一个意思
        */
        
        
        /*
        char ch1,ch2;
        ch1 = cin.get();
        ch2 = cin.get();
        cout << "ch1 = " << ch1 << ",ch2 = " << ch2 << endl;
         //在mac下，当只输入一个字符的时候，不会停止，会直接打印这一句，只是ch2里没有值
         //在cin这个对象里,有一个储存字符的流,可以想象成缓冲区
        */
        
        
        /*
        char ch1,ch2;
        ch1 = cin.get();
        cin.get();
        ch2 = cin.get();
        cout << "ch1 = " << ch1 << ",ch2 = " << ch2 << endl;
         //在这里输入一个字符的时候会停止
         //当空回调cin.get();时,cin.get便自动在cin中的流数据中删除一个字母,起了一个删除作用.
        */
        
        
        //cin.getline的原型是getline(char *line,int size,char='/n')，第三个参数默认为回车
        /*
        char ch1[200];
        cin.getline(ch1, sizeof(ch1)/sizeof(char));
        cout << ch1 << endl;
        */
        
        /*
        char ch1[200];
        cin.getline(ch1, sizeof(ch1)/sizeof(char),'X');
        cout << ch1 << endl;
        //在cin.getline的第三个参数设置为x, 那么只有遇到X的字符的时候，才会停止输入，包括回车也不会停止输入，并且回车会被打印出来
        */
        
        /*
        int a;
        cin >> a;
        if (cin.rdstate() == ios::goodbit) {
            cout<<"输入数据的类型正确，无错误！"<<endl;
        }
        if (cin.rdstate() == ios::failbit) {
            cout<<"输入数据类型错误，非致命错误，可清除输入缓冲区挽回！"<<endl;
        }
        //当cin.rdstate()返回0(即ios::goodbit)时表示无错误,可以继续输入或者操作,
        //若返回4则发生非致命错误即ios::failbit,则不能继续输入或操作.
        //而cin.clear则可以控制我们此时cin里对这个问题的一个标识
        //cin.clear(标识符);
        //标识符号为:
        //goodbit 无错误
        //Eofbit 已到达文件尾
        //failbit 非致命的输入/输出错误，可挽回
        //badbit　致命的输入/输出错误,无法挽回
        //若在输入输出类里.需要加ios::标识符号
         */
        
        /*在mac上运行有问题，好像
        int a;
        while(1)
        {
            cin>>a;
            if(!cin)            //条件可改写为cin.fail()
            {
                cout<<"输入有错!请重新输入"<<endl;
                cin.clear();
                cin.sync();   //清空流
            }
            else
            {
                cout<<a;
                break;
            }
        }
        */
        
        
        /*
        int a,b;
        cin >> a;
        cout << a <<endl;//在mac上如果输入的类型的不对，输出的a是0
        cin.clear();//而且在mac上，cin里的数据如果是错误的，无法清空
        cin.sync();
        cin >> b;
        cout << b << endl;
        */
        
        /*
        int x;
        string dummy;
        while (true) {
            cin>>x;
            if (cin.fail()) {
                //cin如果读取的类型不匹配，是会存在缓冲区里等待下次读取的
                cout<< "fail, and dummy is ";
                cin.clear();
                cin >> dummy;
                cout << dummy << endl;
            } else {
                cout << "input number is " << x << endl;
            }
        }
        */
        
        //文件的I/O处理
        //首先xcode工程里的文件路径问题
        //xcode是有自己的缓存的，相当于虚拟机（eclipse），所以你这样不用绝对路径；要到他缓存里面找，用了绝对路径就可以了。你换换地址
        //如果你要看看你的hello.txt文件
        //你打开finder 按command＋shift＋g，输入/Users/你的apple机名字/Library/Developer/Xcode
        //然后进入DriverData
        //你可以看到你所有做过的还在的和删掉的文件，找到你的目前的文件，然后点击进入Build -> Product -> Debug里面就是你创建的hello.txt
        
        /*
        ofstream fileStream;
        //open函数在没有该文件的时候会创建该文件,
        //但是如果本身有这个文件，open函数默认情况下会丢弃原有的内容，然后将新的输出加入到文件中
        fileStream.open("aaa.txt");
        fileStream << "aaaa";//简单的写入内容
        fileStream.close();
        
        ifstream infileStream;
        infileStream.open("aaa.txt");
        char infile[80];
        infileStream >> infile;
        cout << infile << endl;
        infileStream.close();
        
        //打开文件用于接收输入时有可能会失败，例如指定的文件确实存在，但是禁止对其进行访问，因此必须检查文件打开是否成功
        ifstream inf;
        inf.open("aaa.txt");
        if (!inf.is_open()) {
            exit(EXIT_FAILURE);
        }
        */
        
        /*
        char a;
        ifstream inf;
        inf.open("aaa.txt");
        inf >> a;
        while (inf.good()) {//good()函数用来检查是否EOF:inf.eof(),是否类型匹配:inf.fail()，是否文件损坏:inf.bad()
            cout << a << endl;
            inf >> a;
        }
         */
        
        /*
        //上面的代码可以精简
        char a ;
        ifstream inf;
        inf.open("aaa.txt");
        while (inf >> a) {//表达式inf >> a的结果为inf,而在需要一个bool值得情况下，inf的结果为inf.good()，所以可以对上述代码精简
            cout << a << endl;
        }
        */
        
        
        return true;
    }
}