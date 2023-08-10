#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class EnandDe {
private:string Origin, Destring, Enstring, key;
public:
	EnandDe(string c, string key1) {
		Origin = c;
		Destring = c;
		Enstring = c;
		key = key1;
	}
	int Encrypto() {
		int len = Origin.length();
		int l = 0;
		int len1 = key.length();
		for (int i = 0; i < len; i++) {
			if (l < len1) {
				Enstring[i] = Origin[i] ^ key[l];
				l++;
			}
			else if (l == len1) {
				l = 0;
				Enstring[i] = Origin[i] ^ key[l];
				l++;
			}
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
		int l = 0;
		int len1 = key.length();
		for (int i = 0; i < len; i++) {
			if (l < len1) {
				Destring[i] = Enstring[i] ^ key[l];
				l++;
			}
			else if (l == len1) {
				l = 0;
				Enstring[i] = Origin[i] ^ key[l];
				l++;
			}
		}
		cout << "对上述再进行解密是：" << Destring << endl;
		return 0;
	}
};
int main() {
	string Origin;
	string key;
	cout << "请输入需要加密的字符串：" << endl;
	getline(cin, Origin);
	cout << "请输入Key,可以为任意长度的字符串：" << endl;
	getline(cin, key);
	EnandDe Enstring(Origin, key);
	Enstring.Encrypto();
	Enstring.Decrypto();
	return 0;
}