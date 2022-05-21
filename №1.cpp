#include <iostream>
#include <string>

using namespace std;

int x;
string s1 = "В караване ";
string s2 = "был";
string s3 = " верблюд"; 

int readDigit() {
    while (true) {
        cout << "Введите число в диапозоне от 1 до 100: ";
        cin >> x;
        if (x >= 1 && x <= 100) {
            return x;
        } 
        cout << "Введенное число должно быть в промежутке [1, 100]!\n";
    }
} 

int main()
{
    x = readDigit();
    for (int i = 0; i < 101; i++) {
        if (x % 10 == 1 && x != 11) {
            s2.push_back(' ');
            s3.push_back('.');
            break;
        }
        else if((x % 10 == 2 || x % 10 == 3 || x % 10 == 4 ) && x != 12 && x != 13 && x != 14) {
            s2.append("о ");
            s3.append("а.");
            break;
        }
        else {
            s2.append("о ");
            s3.append("ов.");
            break;
        }
    }
cout << s1 << s2 << x << s3;
}