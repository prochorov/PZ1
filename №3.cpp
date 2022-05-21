#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <algorithm>

using namespace std;
 

wstring crypt(const wstring& text, const int k) {
    int key = k % 33;
    wstring answer;
    wstring alpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            answer += L" ";
            continue;
        }
        for (int j = 0; j < alpha.length(); j++) {
        
            if (text[i] == alpha[j]) {
                int newIndex = j + key;
                if (j > 32) { // this rule is used to fix uppercase problem
                    newIndex -= 33;
                }
                
                if (newIndex >= 33) {
                    newIndex -= 33;
                } else if (newIndex < 0) {
                    newIndex = 33 + newIndex;
                }
                answer += alpha[newIndex];
            }
            
        }
    }
    return answer;
}



int main() {
    int k;
    string text;
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    cout << "Введите строку: ";
    getline(cin, text);
    cout << "Введите ключ: "; cin >> k;
    wstring wsText = codec.from_bytes(text);
    wstring res = crypt(wsText, k);
    cout << codec.to_bytes(res) << endl;
    cout << codec.to_bytes(crypt(res, -k)) << endl;
    return 0;
}