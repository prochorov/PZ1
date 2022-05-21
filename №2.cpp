#include <iostream>
#include <fstream>
#include <string>


using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    string line;

    ofstream out;
    out.open("D:/ЯП/PZ1/text_reseult.txt");

    ifstream in("D:/ЯП/PZ1/text.txt");
    while (getline(in, line)) {
        if (line.find("mephi") != -1) {
            line.replace(line.find("mephi"), 5, "yandex");
        }
        out << line << endl;
    }
    in.close();
    out.close();

    cout << "Выполнение завершено!" << endl;
    return 0;
}