//
//  CPrimerThe10Chapter.cpp
//  about 对象和类
//  testc
//
//  Created by 椒盐 on 14-12-23.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include "CPrimerThe10Chapter.h"

namespace Jiaoyan {
    static CPrimerThe10Chapter* s_SharedCPrimerThe10Chapter = NULL;
    
    CPrimerThe10Chapter::CPrimerThe10Chapter()
    {
        
    }
    
    CPrimerThe10Chapter::~CPrimerThe10Chapter()
    {
        
    }
    
    CPrimerThe10Chapter *CPrimerThe10Chapter::sharedCPrimerThe10Chapter(){
        if (s_SharedCPrimerThe10Chapter) {
            return s_SharedCPrimerThe10Chapter;
        }
        s_SharedCPrimerThe10Chapter = new CPrimerThe10Chapter;
        return s_SharedCPrimerThe10Chapter;
    }
    
    bool CPrimerThe10Chapter::init(){
        //指定基本类型完成了三项工作:
        //1.决定数据对象需要的内存数量
        //2.决定如何解释内存中的位(long和float在内存中占用的位数相同，但将他们转换为数值的方法不同)
        //3.决定可使用数据对象执行的操作方法
        //对于内置类型来说，有关操作的信息被内置到编译器中，但在C++中定义用户自定义类型的时候，
        //必须自己提供这些信息
        
        //类和结构
        //类描述看上去很像是包含成员函数以及public和private可见性标签的结构声明，实际上，
        //C++对结构进行了扩展，使之具有与类相同的特性
        //他们之间唯一的区别是，结构的默认访问类型是public，而类是private
        //C++程序员通常使用类来实现类描述，而把结构限制为只表示纯粹的数据对象
        
        //默认构造函数
        //默认构造函数是在未提供显式的初始值时，用来创建对象的构造函数。
        //也就是说，它是用于下面这种声明的构造函数
        //jiaoyanClass aaa;//uses the default constructor，记住在隐式调用默认构造函数的时候不能写成这样
        //jiaoyanClass aaa();//error,这是定义了一个方法。。。
        
        //当且仅当没有定义任何构造函数时，编译器才会提供默认构造函数，为类定义了构造函数后，程序员就必须为它提供默认构造函数。
        //如果提供了非默认构造函数(如：jianyanClass(int , int))，但没有提供默认构造函数，那么下面的声明将出错
        //jiaoyanClass bbb;//not possible with current constructor
        //这样做的原因可能是想禁止创建未初始化的对象，然而如果要创建对象，而不显式地初始化，则必须定义一个不接受任何参数的默认构造函数
        //定义默认构造函数的方式有两种。一种是给已有构造函数的所有参数提供默认值
        //另一种方式是通过函数重载来定义另一个构造函数--一个没有参数的构造函数
        //由于只能有一个默认构造函数，因此不要同时采用这两种
        
        //析构函数
        //析构函数一般用来完成清理工作，如果构造函数中有new的分配内存操作，那么析构函数可以使用delete来释放这些内存
        //什么时候调用析构函数，是由编译器决定的，
        //如果创建的是静态存储类对象，则其析构函数将在程序结束时自动被调用
        //如果创建的是自动存储类对象，则其析构函数将在程序执行完代码块时自动被调用
        //如果对象是通过new创建的，则它将驻留在栈内存或自由存储区中，当是用delete来释放内存时，其析构函数将自动被调用
        
        //const成员函数
        //const jianyanClass cc = jianyanClass("123");
        //cc.show();//对于当前的C+++来说，编译器将拒绝第二行，因为show()代码无法确保调用对象不被修改
        //这里需要一种新语法，保证函数不会修改调用对象
        //C++的解决方法是将const关键字放在函数的括号后面。也就是说，show()声明应像这样
        //void show() const;
        //void jiaoyanClass::show() const{}
        //这种方式声明和定义的类函数称为const成员函数，就像应尽可能将const引用和指针用作函数参数一样，只要类方法不修改调用对象
        //就应将其声明为const
        
        //作用域内枚举(C++11)
        //传统的枚举存在一个问题
        //enum egg {Small,Medium,Large,Jumbo};
        //enum shirt {Small,Medium,Large,Jumbo};
        //如上定义两个枚举，这将无法通过编译，因为egg Small和shirt Small位于相同的作用域内，他们将发生冲突
        //C++11提供了一种新枚举，其枚举变量的作用域为类
        //enum class egg {Small,Medium,Large,};
        //enum class shirt {Small,Medium,Large,};
        //egg a = egg::Small这样使用
        
        
        return true;
    }
    
    
}