//
//  CPrimerThe11Chapter.cpp
//  testc
//  about 11和12章
//
//  Created by 椒盐 on 14-12-24.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include "CPrimerThe11Chapter.h"
namespace Jiaoyan {
    static CPrimerThe11Chapter* s_SharedCPrimerThe11Chapter = NULL;
    
    CPrimerThe11Chapter::CPrimerThe11Chapter()
    {
        
    }
    
    CPrimerThe11Chapter::~CPrimerThe11Chapter()
    {
        
    }
    
    CPrimerThe11Chapter *CPrimerThe11Chapter::sharedCPrimerThe11Chapter(){
        if (s_SharedCPrimerThe11Chapter) {
            return s_SharedCPrimerThe11Chapter;
        }
        s_SharedCPrimerThe11Chapter = new CPrimerThe11Chapter;
        return s_SharedCPrimerThe11Chapter;
    }
    
    bool CPrimerThe11Chapter::init(){
        //运算符重载是一种形式的C++多态
        //普通的时间加法方法应该这样写
        //Time Sum(const Time & t) const;
        //使用运算符重载，换成如下形式
        //Time operator+ (const Time& t) const;
        //两者实现方法一样，在调用时
        //total = codeing.operator+(fixing);
        //或者 total = codeing + fixing;//这里运算符左侧的对象是调用对象，运算符右边的对象是作为参数被传递的对象
        
        //当有三个数相加的时候
        //t4 = t1 + t2 + t3;这里的顺序跟内置类型不一样，相当于t1 + (t2 + t3)，因为t1是调用对象，(t2 + t3)是的结果是参数
        //与内置类型的顺序如 int4 = int1 + int2 + int3;的顺序不一样
        
        //重载的限制
        //重载后的运算符必须至少有一个操作数是用户定义的类型
        //使用运算符时不能违反运算符原来的句法规则，例如不能将求模运算符%重载成使用一个操作数，必须还是两个
        //不能创建新运算符
        //有些操作符是不允许重载的
        
        //友元
        //C++控制对类对象私有部分的访问，通常公有类方法提供唯一的访问途径，但是有时候这种限制太严格
        //在这种情况下，C++提供了另外一种形式的访问权限：友元
        //友元函数，友元类，友元成员函数
        
        //类的友元函数，不是成员函数，但是和成员函数拥有相同的权限，在类声明中的函数原型前加上关键字friend
        
        
        //类型转换
        
        
        
        return true;
    }
}