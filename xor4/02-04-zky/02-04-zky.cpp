#include <iostream>
#include<string>
#include<algorithm>
#include<sstream>    

std::string key;         //定义一个全局变量key方便加密时调用

class StringText {     //定义字符类,用作派生用途。protect之内存储text，public内写一个构造函数
protected:
    std::string text = "";
public:
    StringText(std::string t)
    {
        text = t;
    }
};

class xorclass :public StringText{              //定义异或加密类，继承字符类
public:
    xorclass(std::string t) :StringText(t){}
    void xorcrypt() {                //定义异或加密函数
        std::string ciphertext = text;
        int lengthofplain = ciphertext.length();
        for (int i = 0; i < lengthofplain; i++) {
            ciphertext[i] = ciphertext[i] ^ key[i % key.length()];    //简单的异或加密 第i个字符与i % key.length()字符异或
        }
        text = ciphertext;                             //把加密后的内容再赋回去，不返回内容，只修改text
    }
    std::string showstring() {                        //这是一个用来输出字符串的函数
        return text;
    }
};

int main()
{
    std::string line;                                       //定义一个string，用来存储输入的内容
    std::cout << "请输入要加密的明文，可以包含空格，回车自动结束" << std::endl;  
    std::getline(std::cin, line);                             //把第一行内容全部写到line里面去，包括空格
    std::string word;
    xorclass xor1(line);                                      //创建一个xorclass类名为xor1，并把line的内容写到text内
    std::cout << "输入加密密钥（可以包含空格，回车结束,空格会作为密钥的一部分）：\n";
    std::getline(std::cin, key);
    std::cout << "加密后的密文是（16进制）：\n";
    xor1.xorcrypt();                                            //加密函数调用
    for (const char& c : xor1.showstring()) {                      //遍历一下
        printf("0x%llx ", unsigned __int64(c));             //llx直接打印出16进制 转换了一下uint64，比较简便。如果有警告可以忽略
    }
    std::cout << std::endl;
    std::cout << "对密文重新进行解密是：\n";
    xor1.xorcrypt();                                            //再次进行异或，加密解密算法相同，一样的调用
    for (const char& c : xor1.showstring()) {                   //遍历一下
        printf("0x%llx ", unsigned __int64(c));             //llx直接打印出16进制 转换了一下uint64，比较简便。如果有警告可以忽略
    }
    std::cout << std::endl;
    std::cout << xor1.showstring();                        //这时候再打印一下text的内容看一下是不是变回来了一样的明文
    return 0;
}
