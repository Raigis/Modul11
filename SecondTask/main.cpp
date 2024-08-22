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

bool comparison(std::string part, std::string dictionary){
    bool match;
    for(int i = 0; i < part.length(); i++){
        match = false;
        for(int y = 0; y < dictionary.length(); y++){
            if(part[i] == dictionary[y]){
                match = true;
                break;
            }
        }
        if(!match) return match;
    }
    return match;
}

std::vector<int> is_correct_level4(std::vector<std::string> email){
    std::vector<bool> isCorrect (2, false);
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
        return {1, 0};
    } else if (!isCorrect[0] && isCorrect[1]){
        return {0, 7};
    } else {
        return {0, 8};
    }
}

std::vector<std::string> separation(std::string email){
    std::vector<std::string> separatedEmail {"", ""};
    bool isAt = false;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@' && !isAt) {
            isAt = true;
        } else if (!isAt) {
            separatedEmail[0] += email[i];
        } else if (isAt) {
            separatedEmail[1] += email[i];
        }
    }
    return separatedEmail;
}

std::vector<int> is_correct_level3(std::vector<std::string> email){
    for (int i = 0; i < email.size(); i++) {
        if (email[i].length() > 64 - i || email[i].length() == 0) {
            if (i == 0) {
                return {0, 1};
            } else {
                return {0, 2};
            }
        }
    }
    return is_correct_level4(email);
}

std::vector<int> is_correct_level2 (std::string email){
    bool prevDot = false;
    bool isAt = false;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@' && !isAt) {
            isAt = true;
        } else if (email[i] == '@' && isAt) {
            return {0, 4};
        }
        if (email[i] == '.' && !prevDot) {
            prevDot = true;
        } else if (email[i] == '.' && prevDot) {
            return {0, 6};
        } else {
            prevDot = false;
        }
    }
    if (!isAt) return {0, 3};
    std::vector<std::string> separatedEmail = separation(email);
    return is_correct_level3(separatedEmail);
}

std::vector<int> is_correct_level1 (std::string email){
    if (!(email.length() >= 3 && email.length() <= 128)) {
        return {0, 0};
    } else if (!(email[0] != '.' && email[email.length()-1] != '.')) {
        return {0, 5};
    } else {
        return is_correct_level2(email);
    }
}

void print_error_code (int code){
    switch (code) {
    case 0:
        std::cout << "Error code: " << code << ".\nIncorrect total length." << std::endl; 
        break;
    case 1:
        std::cout << "Error code: " << code << ".\nIncorrect length of the left part." << std::endl; 
        break;
    case 2:
        std::cout << "Error code: " << code << ".\nIncorrect length of the right part." << std::endl; 
        break;
    case 3:
        std::cout << "Error code: " << code << ".\nThe '@' symbol is missing." << std::endl; 
        break;
    case 4:
        std::cout << "Error code: " << code << ".\nMore than one '@' character." << std::endl; 
        break;
    case 5:
        std::cout << "Error code: " << code << ".\nThe dot is at the beginning or end." << std::endl; 
        break;
    case 6:
        std::cout << "Error code: " << code << ".\nThere are two dots in a row." << std::endl; 
        break;
    case 7:
        std::cout << "Error code: " << code << ".\nThere is a forbidden symbol in the left part." << std::endl; 
        break;
    case 8:
        std::cout << "Error code: " << code << ".\nThere is a forbidden symbol in the right part." << std::endl; 
        break;
    default:
        std::cout << "Error code: -1.\nUnknown error." << std::endl;
        break;
    }
}

int main() {
    std::string email;
    std::cout << "Enter an email:\n";
    std::getline(std::cin, email);
    std::vector<int> result = is_correct_level1(email);
    if (result[0]) {
        std::cout << "\nEmail is correct." << std::endl;
    } else {
        std::cout << "\nEmail is incorrect.\n";
        print_error_code(result[1]);
    }


    return 0;
}