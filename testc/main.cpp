//
//  main.cpp
//  testc
//
//  Created by 椒盐 on 14-11-13.
//  Copyright (c) 2014年 椒盐. All rights reserved.
//

#include <iostream>
#include <vector>
#include <array>
#include "CPrimerThe4Chapter.h"

//struct things{
//    int good;
//    int bad;
//};
//
//struct inflatable{
//    char name[20];
//    float volume;
//    double price;
//};
//
//char * getname(void);
//
//struct antarctica{
//    int year;
//};

int main(int argc, const char * argv[]) {
    using namespace Jiaoyan;
    CPrimerThe4Chapter* chapter4 = CPrimerThe4Chapter::sharedCPrimerThe4Chapter();
    chapter4->init();
    return 0;
}

//char * getname(void)
//{
//    using namespace std;
//    char temp[80];
//    cout << "enter your name :" << endl;
//    cin >> temp;
//    char * pn = new char[strlen(temp) +1];
//    strcpy(pn,temp);
//    return pn;
//}