// Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4). 
// IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно. 
// Числа не должны содержать ведущих нулей. 
// Других символов в строке, кроме вышеописанных, быть не должно.

// Пользователь вводит строку, задающую IP-адрес через стандартный ввод. 
// В результате программа должна вывести слово Valid, если адрес корректен, и слово Invalid, если это не так.

#include <iostream>
#include <vector>

std::vector<std::string> separation(std::string ip){
    std::vector<std::string> vecIp;
    std::string octet;
    for (int i = 0; i < ip.length(); i++) {
        if (ip[i] == '.' ) {
            vecIp.push_back(octet);
            octet = "";
        } else {
            octet += ip[i];
        }
    }
    vecIp.push_back(octet);
    return vecIp;
}

int conversion(std::string octet) {
    while (octet.length() != 3) {
        octet = '0' + octet;
    }
    return ((octet[0] - '0') * 100 + (octet[1] - '0') * 10 + (octet[2] - '0'));
}

bool checking(std::string ip) {
    std::vector<std::string> vecIp = separation(ip);
    if (vecIp.size() != 4) return false;
    for (std::string octet : vecIp) {
        if (octet.length() < 1 || octet.length() > 3 || (octet.length() > 1 && octet[0] == '0')) return false;
        for (char i : octet){
            if (i < '0' || i > '9') return false;
        }
        int octetInt = conversion(octet);
        if(octetInt < 0 || octetInt > 255) return false;
    }
    return true;
}


int main() {
    std::string ip;
    std::cout << "Enter the ip address:\n";
    std::getline(std::cin, ip);
    bool result = checking(ip);
    if (result) {
        std::cout << "\nValid." << std::endl;
    } else {
        std::cout << "\nInvalid." << std::endl;
    }
}