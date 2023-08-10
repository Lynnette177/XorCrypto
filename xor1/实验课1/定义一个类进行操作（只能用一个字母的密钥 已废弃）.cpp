#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class EnandDe {
private:string Origin, Destring, Enstring;
	   char key;
public:
	EnandDe(string c,char key1) {
		Origin = c;
		Destring = c;
		Enstring = c;
		key = key1;
	}
	int Encrypto() {
		int len = Origin.length();
		for (int i = 0; i < len; i++) {
			Enstring[i] = Origin[i] ^ key;
		}
		cout << "加密之后是：" << endl;
		for (char c : Enstring) {
			int value = static_cast<int>(c);
			std::cout << std::setw(2) << std::setfill('0') << std::hex << value;
			cout << " ";
		}
		cout << endl;
		return 0;
	}
	int Decrypto() {
		int len = Origin.length();
		for (int i = 0; i < len; i++) {
			Destring[i] = Enstring[i] ^ key;
		}
		cout <<"对上述再进行解密是："<< Destring << endl;
		return 0;
	}
};
int main() {
	string Origin;
	char key;
	cout << "本程序是对一串字符中的每个字母，针对一个key字母进行异或运算"<<endl<<"请输入需要加密的字符串：" << endl;
	getline(cin, Origin);
	cout<< "请输入Key，应该为一个字母：" << endl;
	cin >> key;
	EnandDe Enstring(Origin,key);
	Enstring.Encrypto();
	Enstring.Decrypto();
	return 0;
}