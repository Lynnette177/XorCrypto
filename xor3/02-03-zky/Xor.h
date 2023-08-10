#pragma once
#include"include.h"             //包含自写的头文件
#ifndef  XOR_H                  //保证只包含一次
#define XOR_H
using namespace std;                         //确定命名空间
string XorEn(string key, string plaintext);   //声明要用到的函数
#endif // ! 