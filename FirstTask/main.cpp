// Задание 1. Шифр Цезаря
// Что нужно сделать
// Юлий Цезарь использовал свой способ шифрования текста. 
// Каждая буква заменялась на следующую по алфавиту через K позиций по кругу. 
// Если взять английский алфавит и K = 3, то в слове, которое мы хотим зашифровать, буква A станет буквой D, B станет E и так далее. 
// Если для сдвига на данное число позиций алфавита не хватает, то он зацикливается, то есть последняя буква алфавита Z, сдвинутая на одну позицию, будет преобразовываться в A. 

// Напишите функцию encrypt_caesar, в которую передаётся текст и сдвиг и которая возвращает зашифрованный текст. 
// Считаем, что входные строки состоят лишь из английских букв. 
// Если там содержатся и другие символы, то их надо выдать без шифрования. 
// Регистр букв (заглавные и строчные) меняться не должен.

#include <iostream>

char shifting (char start, int shift){
    return start >= 'a' && start <= 'z' ? ((start - 'a' + shift)%26)+'a' : (start >= 'A' && start <= 'Z' ? ((start - 'A' + shift)%26)+'A' : start);
}

std::string encrypt_caesar(std::string text, int shift){
    std::string result;
    for(int i = 0; i< text.length(); i++){
        result += shifting(text[i], shift);
    }
    return result;
}

int main(){
    std::string text;
    int shift;
    std::cout << "Enter the text:\n";
    std::getline(std::cin, text);
    std::cout << "Enter the shift: ";
    std::cin >> shift;
    std::cout << "\nEncryp123ted text:\n" << encrypt_caesar(text, shift);
    return 0;
}