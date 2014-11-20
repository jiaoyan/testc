//
//  CPrimerThe4Chapter.cpp
//  testc
//
//  Created by 椒盐 on 14-11-20.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include "CPrimerThe4Chapter.h"
#include <iostream>
#include <vector>
#include <array>

char * getname(void);

struct antarctica{
    int year;
};

namespace Jiaoyan {
    static CPrimerThe4Chapter *s_SharedCPrimerThe4Chapter = NULL;
    
    CPrimerThe4Chapter::CPrimerThe4Chapter(){
        
    };
    
    CPrimerThe4Chapter::~CPrimerThe4Chapter(){
        
    };
    
    CPrimerThe4Chapter* CPrimerThe4Chapter::sharedCPrimerThe4Chapter(){
        if (s_SharedCPrimerThe4Chapter)
            delete s_SharedCPrimerThe4Chapter;
        s_SharedCPrimerThe4Chapter = new CPrimerThe4Chapter();
        return s_SharedCPrimerThe4Chapter;
    };
    
    bool CPrimerThe4Chapter::init(){
        using namespace std;
        /*
         double wages[3] = {10000.0,20000.0,30000.0};
         short stacks[3] = {1,2,3};
         
         //here are two ways to get the address of array
         double *pw = wages;
         short *st = &stacks[0];
         cout << "pw = " << pw << ", *pw = " << *pw << endl;
         pw = pw + 1;
         cout << "pw = " << pw << ", *pw = " << *pw << endl;
         
         cout << "st = " << st << ", *st = " << *st << endl;
         st = st + 1;
         cout << "st = " << st << ", *st = " << *st << endl;
         
         cout << "stacks = " << stacks << ", *&stacks[0] = " << &stacks[0] << endl;
         cout << "*stacks = " << *stacks << ", *(stacks + 1) = "  << *(stacks + 1) << endl;
         
         cout << "sizeof(wages) = " << sizeof(wages) << endl; //对数组应用sizeof,得到的是数组的长度
         cout << "sizeof(pw) = " << sizeof(pw) << endl; //对指针应用sizeof，得到的是指针的长度
         cout << "sizeof(st) = " << sizeof(st) << endl; //在mac下sizeof(指针)，得到的是8
         
         //stacks 和 &stacks[0] 等价 stacks display &stacks[0]
         //但是&stacks 表示的是整个数组的地址，虽然从数字上说两个地址相同
         //&stacks[0] 即 stakcs ， + 1是将地址加2
         //&stacks + 1 是将地址加上整个数组的长度，即6
         cout << "stacks = " << stacks << ", stacks + 1 = " << stacks + 1 <<endl;
         cout << "&stacks = " << &stacks << ", &stacks + 1 = " << &stacks + 1 <<endl;
         
         //stacks是一个short类型的指针，而&stacks是一个这样的指针，即指向包含3个元素的short数组
         short (*ss)[3] = &stacks; // ss points to array of 3 short
         //这里的括号不能缺少，如果没有括号，short *ss[3],ss就变成了一个short指针数组
         cout << "(*ss)[0] = " << (*ss)[0] << endl;// *ss与stacks等价，所以(*ss)[0]就是stacks的第一个元素
         
         //注：指针数组和数组指针,需要复习下
         
         int tacos[10] = {5,4,3,5,6,7,89,2,1,0};
         int *pt = tacos;
         pt = pt + 1;
         int *pe = &tacos[9];
         pe = pe - 1;
         //    int diff = pe - pt;
         long diff = pe - pt;//在mac下地址对地址操作，得到的long型，不是int
         cout << "diff = " << diff << endl;
         
         //数组的动态联编和静态联编
         int staticarray[10];
         //使用数组声明来创建数组时，将采用静态联编，即数组的长度在编译时设置
         int dynamicsize = 10;
         int* dynamicarray = new int[dynamicsize];
         delete []dynamicarray;
         //使用new[]运算符创建数组时,将采用动态联编，即，将在运行时为数组分配空间,其长度也将在运行时设置，记得这样的数组需要在使用完后用delete去释放
         */
        
        /*
         //在C++中,cout 和多数表达式，char数组名，char指针，和用引号括起的字符串常量都被解释为字符串第一个字符的地址
         char animal[20] = "bear";
         const char *bird = "wren"; //将"wren"的地址赋值给了bird指针
         char *pp;//cout << pp << endl; !!!may display garbage,may cause a crash
         
         cout << animal << " and " << bird << endl;
         cout << "enter a kind of animal : " << endl;
         cin >> animal;
         //这里如果使用cin >> bird,并不合适,原因如下
         //有些编译器将字符串字面量视为只读常量,如果试图修改他们，会导致运行阶段错误
         //有些编译器只使用字符串字面量的一个副本来表示程序中所有的该字面量，将值读入一个字符串可能会影响被认为是独立的，位于其他地方的字符串
         //所以将bird申明为const,编译器将禁止改变bird所指向的位置中的内容
         
         pp = animal;//pp会复制animal的地址，两个指针指向相同的内存单元和字符串，这里不会复制字符串
         cout << "pp = " << pp << endl;
         
         cout << animal << " at " << (int *)animal << endl;
         cout << pp << " at " << (int *)pp << endl;
         
         //为了获取字符串的副本,需要new出内存空间，并使用strcpy函数来复制
         pp = new char[strlen(animal) + 1];
         strcpy(pp, animal);
         
         cout << animal << " at " << (int *)animal << endl;
         cout << pp << " at " << (int *)pp << endl;
         
         //使用strcpy有可能出现这种情况，待复制的字符串如果超过目标数组的长度，那么字符串中剩余的的部分会复制到数组后面的内存字节中
         //这可能会覆盖程序正在使用的其他内存，要避免这个问题，要使用strncpy()
         char food[10] = "shaokao";
         //strcpy(food, "malatangxianglaxia");//error
         strncpy(food, "malatangxianglaxia", 9);
         food[9] = '\0';
         cout << "food = " << food << endl;
         
         delete []pp;
         
         //一般来说,给cout提供一个指针，它将打印地址，但如果指针类型是char*，则cout将显示指向的字符串
         //如果要显示字符串的地址，则必须将指针强行转化为另一种指针类型，如int*
         */
        
        /*
        struct things{
            int good;
            int bad;
        };
        
        struct inflatable{
            char name[20];
            float volume;
            double price;
        };
        
        cout << "Hello, World!\n";
        things thing = {1,1};
        cout << thing.bad << "," << thing.good << endl;
        things *ps = &thing;
        cout << ps->bad << "," << ps->good << endl;
        cout << (*ps).bad << "," << (*ps).good << endl;
        
        
        inflatable *in = new inflatable;
        cin.get(in->name,20);
        cout << in->name << endl;
        cout << (*in).name << endl;
        delete in;// !!!free memory used by structure
        */
        
        /*
         char * name = NULL;
         name = getname();
         cout << name << "," << &name << endl;
         cout << name << "," << (int *)name << endl;
         delete [] name; // 将new 和 delete放到两个函数中的做法不是太好，很容易忘记delete
         
         name = getname();
         cout << name << "," << &name << endl;
         cout << name << "," << (int *)name << endl;
         delete [] name;
         */
        
        //c++的3种管理数据内存的方式，自动存储，静态存储，动态存储
        //自动变量是局部变量，通常存储在栈中，在程序执行过程中，栈在不断的增大和缩小
        //使变量成为静态变量有两种方式：在函数外面定义他，或者使用关键字static,静态变量存在于程序的整个生命周期
        //new 和 delete提供了自由存储空间，称为堆
        
        /*
         //指向指针数组的指针
         antarctica s01,s02,s03;
         s01.year = 1988;
         s02.year = 1989;
         antarctica *an = &s01;
         antarctica ans[3];
         ans[0].year = 2014;
         (ans + 1)->year = 2015;
         //指针数组
         const antarctica * anp[3] = {&s01,&s02,&s03};
         cout << anp[0]->year << endl;
         //可创建指向上述数组的指针(创建一个指向指针数组的指针)
         const antarctica ** anpp = anp;
         //c++11可以 auto anpp = anp;编译器可以推断类型
         cout << (*anpp)->year << endl;
         cout << (*anpp + 1)->year << endl;
         //cout << (*anpp)[0]->year << endl;error *anpp的结果不是数组名，不能使用[]符号
         
         
         //模板类vector,模板类array(C++11),代替数组
         //使用vector需要引入<vector>
         vector<int> vi; //craete a zero-size array of int
         vector<double> vii(1);//create a one-size array of double
         vector<int> viii = {1,2,3};
         
         //C++11新增的模板类array,array对象的长度是固定的，与数组一样使用栈存储，不使用堆
         //使用array需要引入<array>
         array<int, 5> ai;
         array<double, 3> aii = {1.0,2.0,3.0};
         
         double a1[4] = {1.2,2.4,3.6,4.8};
         vector<double> a2(4);
         a2[0] = 0.1;
         a2[1] = 0.2;
         a2[2] = 0.3;
         a2[3] = 0.4;
         array<double, 4> a3 = {1.1,2.2,3.3,4.4};
         array<double, 4> a4;
         a4 = a3;//valid for array objects of same size
         cout << "a1[2] : " << a1[2] << " at &a1[2] : " << &a1[2] << endl;
         cout << "a2[2] : " << a2[2] << " at &a2[2] : " << &a2[2] << endl;
         cout << "a3[2] : " << a3[2] << " at &a3[2] : " << &a3[2] << endl;
         cout << "a4[2] : " << a4[2] << " at &a4[2] : " << &a4[2] << endl;
         //a1[-2] = 20.0;//C++不会判断这种危险的做法，这会将a1的地址向前移动2个double元素，将20.0存入目的地，也就是说存储到数组外面了，
         //很有可能覆盖掉程序正在使用的内存
         //cout << "a1[-2] : " << a1[-2] << " at &a1[-2] : " << &a1[-2] << endl;
         //所以vector和array提供了at()函数，会在运行期间提供非法索引的捕获
         //a4.at(1);
         //a2.at(1);
         */
        
        /******************************************************************************/
        //关于const的修饰对象总结
        //    const int *A; //const修饰指向的对象，A可变，A指向的对象不可变
        //    int const *A; //const修饰指向的对象，A可变，A指向的对象不可变
        //    int *const A; //const修饰指针A， A不可变，A指向的对象可变
        //    const int *const A;//指针A和A指向的对象都不可变
        /******************************************************************************/
        return true;
    };
    
}