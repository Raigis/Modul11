// Задание 2. Проверка корректности email-адреса
// Что нужно сделать
// Напишите программу, которая проверяет корректность email-адреса, введённого пользователем.

// Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделённых знаком @. 
// Первая часть должна иметь длину не менее одного и не более 64 символов, вторая часть — не менее одного и не более 63 символов. 
// Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. 
// Точка не может быть первым или последним символом, две точки не могут идти подряд. 
// В первой части (перед символом @), кроме вышеперечисленных, разрешены ещё следующие символы:

// !#$%&'*+-/=?^_`{|}~
// Пользователь вводит строку, задающую email-адрес. 
//Программа должна вывести слово Yes, если адрес корректен, а в противном случае — слово No.

#include <iostream>
#include <vector>

std::string filling(){
    std::string dictionary;
    for (char i = 'a'; i <= 'z'; i++) dictionary += i;
    for (char i = 'A'; i <= 'Z'; i++) dictionary += i;
    for (char i = '0'; i <= '9'; i++) dictionary += i;
    return dictionary;
}

bool comparison(std::string half, std::string dictionary){
    bool match;
    for(int i = 0; i < half.length(); i++){
        match = false;
        for(int y = 0; y < dictionary.length(); i++){
            if(half[i] == dictionary[y]){
                match = true;
                break;
            }
        }
        if(!match) return match;
    }
    return match;
}

std::vector<int> is_correct_level4(std::vector<std::string> email){
    std::vector<bool> isCorrect;
    for (int i = 0; i < email.size(); i++) {
        std::string dictionary = filling();
        if (i == 0) {
            dictionary += "!#$%&'*+-/=?^_`{|}~.";
        } else {
            dictionary += "-.";
        }
        isCorrect[i] = comparison(email[i], dictionary);
    }
    if (isCorrect[0] && isCorrect[1]) {
        return {1};
    } else {
        return {0, };
    }
}

std::vector<std::string> separation(std::string email){
    std::string leftHalf, rightHalf;
    bool isAt = false;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@' && !isAt) {
            isAt = true;
        } else if (!isAt) {
            leftHalf += email[i];
        } else if (isAt) {
            rightHalf += email[i];
        }
    }
    return {leftHalf, rightHalf};
}

std::vector<int> is_correct_level3(std::vector<std::string> email){
    for (int i = 0; i < email.size(); i++) {
        if (email[i].length() > 64 - i) {
            
        }
    }
}

std::vector<int> is_correct_level2 (std::string email){
    bool prevPoint = false;
    bool isAt = false;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@' && !isAt) {
            isAt = true;
        } else if (email[i] == '@' && isAt) {
            return {0, 2};
        }
        if (email[i] == '.' && !prevPoint) {
            prevPoint = true;
        } else if (email[i] == '.' && prevPoint) {
            return {0, 3};
        } else if (email[i] != '.' && prevPoint) {
            prevPoint == false;
        }
    }
    std::vector<std::string> separatedEmail = separation(email);
    return is_correct_level3(separatedEmail);
}

std::vector<int> is_correct_level1 (std::string email){
    if (email.length() >= 3 && email.length() <= 128 && email[0] != '.' && email[email.length()-1] != '.') {
        return is_correct_level2(email);
    }
}

int main() {
    std::string email;
    std::cout << "Enter an email:\n";
    std::getline(std::cin, email);
    std::vector<int> result = is_correct_level1(email);
    if (result[0]) {
        std::cout << "Email is correct." << std::endl;
    }


    return 0;
}