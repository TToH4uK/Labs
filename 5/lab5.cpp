// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

int main()
{
	setlocale(LC_ALL, "Rus");
	bool latin = true;
	std::string text = "si-x One Три tWo четыре hello пяТь si-x сеven ";
	int count = 1, startIndex = 0, endIndex = 0, wordNumber = 0;
	std::string word = "";
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ')
			count++;
	}
	std::string* words = new std::string[count];
	for (int i = 0; i < text.length(); i++) {
		startIndex = i;
		word = "";
		latin = true; // ДОПУСТИМ, СЛОВО  ЛАТИНСКОЕ
		while (text[i] != ' ') {
			if (i == text.length())
				break;
			word += text[i];
			i++;
		}
		for (int j = 0; j < word.length(); j++)
			if (word[j] < 65 || (word[j] > 90 && word[j] < 97) || word[j] > 123)
				latin = false;                                               
		if (word != "" && latin) {                                                              //ПРОВЕРКА И ВЫВОД ЛАТИНИЦЫ
			words[wordNumber] = word;
			wordNumber++;
		}
	}

	for (int i = 0; i < text.length(); i++) {
		startIndex = i;
		word = "";
		latin = false; // ДОПУСТИМ, СЛОВО НЕ ЛАТИНСКОЕ
		while (text[i] != ' ') {
			if (i == text.length())
				break;
			word += text[i];
			i++;
		}
		for (int j = 0; j < word.length(); j++)
			if ((word[j] >= 65 && word[j] <= 90) || (word[j] >= 97 && word[j] <= 123))
				latin = true;
			else {
				latin = false;
				break;
			}

		if (word != "" && !latin) {                                                                    // ПРОВЕРКА И ВЫВОД КИРИЛИЦЫ
			words[wordNumber] = word;
			wordNumber++;
		}
	}
	for (int i = 0; i < count; i++) {
		std::cout << words[i] << ' ';
	}
}

//сеven не выводится - разные диапазоны для латинского и кирилицы

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
