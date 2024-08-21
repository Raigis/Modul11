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