#include"Xor.h"

//这个文件中写Xor中声明过的加密函数，并被Main.cpp包含
string XorEn(string key, string plaintext) {
	string ciphertext = plaintext;
	int lengthofplain = plaintext.length();
	for (int i = 0; i < lengthofplain; i++) {
		ciphertext[i] = ciphertext[i] ^ key[i % key.length()];
	}
	return ciphertext;
}