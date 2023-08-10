#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string xorEncryptDecrypt(string input, string key) {
    string output = input;
    int len = input.length();
    int len1 = key.length();
    int l = 0;
    for (int i = 0; i < len; i++) {
        if (l < len1) {
            output[i] = input[i] ^ key[l];
            l++;
        }
        else if (l == len1) {
            l = 0;
            output[i] = input[i] ^ key[l];
            l++;
        }
    }
    return output;
}

int main() {
    string input;
    cout << "输入明文：";
    getline(cin, input);
    cout << "输入密钥：";
    string key;
    getline(cin, key);
    string encrypted = xorEncryptDecrypt(input, key);
    string decrypted = xorEncryptDecrypt(encrypted, key);

    cout << "Original message: " << input << endl;
    for (char c : encrypted) {
        int value = static_cast<int>(c);
        std::cout << std::setw(2) << std::setfill('0') << std::hex << value;
        cout << " ";
    }
    cout << endl;
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
