#include "Xor.h"   //包含头文件
using namespace std;
int main() {
	int n;
	cout << "请输入要加密的字符串个数:" << endl;
	cin >> n;    //获取n
	string** p =NULL;         //定义一个指针数组，每个成员都是指向一个string类型的指针 并给它赋为NULL
	
	if (p == nullptr) {       //判断一下，如果是空的，就用new进行开辟
		p = new string * [n];//开辟空间的大小由n决定；
	}
	if (p == nullptr) {
		return -1;            //如果开辟失败，那么返回-1
	}
	if (p != nullptr) {
		goto Start;          //如果开辟成功，goto到start部分 开始执行
	}
End:                       //执行结束之后的跳转点
	if (p != nullptr) {      //执行结束之后 p应该不是空，那么释放空间，退出程序
		delete *p;
		p = nullptr;//删除完后立刻置空
		return 0;
	}
Start:                      //程序开始的跳转点
	cout << "请输入字符串，空格或回车表示结束一个，数量请不要超过n：" << endl;
	for (int i = 0; i < n; i++) {
		string temp;                  //创建一个用来存储的临时的string 输入到这里面之后，再根据这个给p[i]开辟空间并传入。
		cin >> temp;
		p[i] = new string(temp);     //开辟 赋值
	}
	int dec=2;                       //这是一个用来判断升序或降序的变量
	while (dec != 0 && dec != 1) {    //如果用户还没有输入，或者输入的不是0或者1，那么就让用户重新输入，避免继续执行而出错
		cout << "0.升序排序？1.降序排序？请输入0或1" << endl;
		cin >> dec;
	}
	for (int i = 0; i < n; i++) {                       //进行一个冒泡排序
		for (int k = 0; k < n - i-1; k++) {
			string a, b;                               //仍然定义两个临时的string 用来存储内容 并且转换成const char*格式，方便用strcmp进行比较
			a = *p[k];
			b = *p[k + 1];
			if (dec == 1) {
				if (strcmp(a.c_str(), b.c_str())) {                  //比较最先一个不同的字母的ascii大小 并且根据dec是1还是0选择不同的排序方式，升序降序
					string* tempp = p[k];                            //创建一个临时的指针，用来颠倒顺序
					p[k] = p[k + 1];
					p[k + 1] = tempp;
				}
			}
			else if (dec == 0) {                                 //同上 这是dec=0的情况
				if (!strcmp(a.c_str(), b.c_str())) {
					string* tempp = p[k];
					p[k] = p[k + 1];
					p[k + 1] = tempp;
				}
			}
		}
	}
	cout << "根据最先不同的字母的ASCII值排序后，结果如下："<<endl;
	for (int i = 0; i < n; i++) {                           //输出排序结果
		cout<< *p[i]<<endl;
	}
	string key;
	cout << "输入加密密钥：" << endl;
	cin >> key;                                                   //让用户输入密钥
	for (int i = 0; i < n; i++) {                          //对指针数组中的每个成员，进行相同操作
		string encrypted;                                 //定义一个密文string 后续会用到
		encrypted = XorEn(key, *p[i]);                    //调用加密函数 获得结果写入string密文
		cout << "加密后的密文" << i+1 << "是：";
		for (const char& c : encrypted) {                  //遍历密文中的每个单字。
			if (c == '\n') continue;
			cout << "0x"<<std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(c) << " ";//以16进制形式输出
		}
		cout << endl;
		encrypted = XorEn(key,encrypted);                 //对密文再进行解密 显然算法一样 只要调用相同的函数再一次就可以了
		cout << "对密文" << i + 1 << "进行解密是：";
		for (const char& c : encrypted) {                //同样进行遍历
			cout << c;                                  //现在只要简单的直接输出字符就可以了
		}
		cout << endl;
	}
	goto End;                                          //加密程序执行结束了，现在跳转到End 清理内存 并退出程序。
}