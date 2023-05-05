// DZ 27.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

//Задание
//Создайте структуру movies, которая обладает
//следующим набором полей :
//string title – название фильма;
//int year – год выхода фильма;
//string genre – жанр фильма;
//unsigned int duration – продолжительность
//фильма в минутах;
//unsigned int price – цена за диск фильма.

struct movies {
	std::string title;
	int year;
	std::string genre;
	unsigned int duration;
	unsigned int price;
};

/*Задача 1
Создайте функцию show_movie, которая принимает
объект структуры и выводит всю информацию о нём
(т.е.выводятся значения полей объекта).*/

 void show_movie(const movies& PM) {
	std::cout << "Название: " << PM.title << std::endl;
	std::cout << "Год: " << PM.year << std::endl;
	std::cout << "Жанр: " << PM.genre << std::endl;
	std::cout << "Продолжительность: " << PM.duration << std::endl;
	std::cout << "Цена: " << PM.price << std::endl;
}

//Задача 2
//Создайте функцию expensive, которая принимает
//три объекта структуры и возвращает объект с самой
//высокой ценой за диск.Для решения данной задачи
//необходимо при создании функции использовать тип
//данных movies для возвращаемого значения.


 const movies& expensive(const movies& p1, const movies& p2, const movies& p3) {
	const movies* max = &p1;
	if (p1.price > max->price)
		max = &p1;
	if (p2.price > max->price)
		max = &p2;
	if (p3.price > max->price)
		max = &p3;
	return *max;
}

//Задача 3
//Создайте функцию update_info, которая принимает
//объект структуры и позволяет поменять какую - нибудь
//информацию об этом объекте.Для решения данной
//задачи необходимо в качестве параметра функции
//использовать указатель или ссылку на объект.

 void update_info(movies& PM) {
	std::cout << "Выберите, какую информацию о фильме хотите обновить: " << std::endl;
	std::cout << "1: Название" << std::endl;
	std::cout << "2: Год выхода" << std::endl;
	std::cout << "3: Жанр" << std::endl;
	std::cout << "4: Продолжительность" << std::endl;
	std::cout << "5: Цена за диск" << std::endl;

	int number;
	std::cout << "number: ";
	std::cin >> number;

	switch (number)
	{
	case 1:
		std::cin.ignore(256, '\n');
		getline(std::cin, PM.title);
		break;
	case 2:
		std::cin >> PM.year;
		break;
	case 3:
		std::cin.ignore(256, '\n');
		getline(std::cin, PM.genre);
		break;
	case 4:
		std::cin >> PM.duration;
		break;
	case 5:
		std::cin >> PM.price;
		break;
	}
}


int main() {
	setlocale(LC_ALL, "rus");

	movies PM1;
	PM1.title = "Терминатор";
	PM1.year = 1984;
	PM1.genre = "боевик";
	PM1.duration = 107;
	PM1.price = 750;

	movies PM2;
	PM2.title = "Чужой";
	PM2.year = 1979;
	PM2.genre = "ужасы";
	PM2.duration = 116;
	PM2.price = 500;

	movies PM3;
	PM3.title = "Индиана Джонс";
	PM3.year = 1986;
	PM3.genre = "приключения";
	PM3.duration = 120;
	PM3.price = 600;

	show_movie(PM1);
	std::cout << std::endl;
	show_movie(PM2);
	std::cout << std::endl;
	show_movie(PM3);
	std::cout << std::endl;

	const movies& most_exp = expensive(PM1, PM2, PM3);
	std::cout << "Самая высокая цена за диск: " << std::endl;
	show_movie(most_exp);

	std::cout << std::endl;

	std::cout << "Editing: m3" << std::endl;
	update_info(PM3);

	std::cout << std::endl;
	show_movie(PM3);

	return 0;
}

