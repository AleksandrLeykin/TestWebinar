#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");

	std::cout << "Шифр Цезаря!" << std::endl;
	
	while (true)
	{
		std::cout << "для кодированя текста нажмите - знак +,\nдля раскодирования текста нажмите - знак -" << std::endl;
		char simbol;
		std::cin >> simbol;
		int countChar = 0; //хранение колличества символов для ввода
		if (simbol == '+')
		{
			//int countChar = 0;
			std::cout << "Сколько символов Вы хотите ввести?" << std::endl;
			std::cin >> countChar;
			//выход при ложном вводе
			if (!countChar) {
				std::cout << "Введен не верный символ, программа будет закрыта!" << std::endl;
				return 0;
			}
			//массив для хранения текста
			char* arr = new char[countChar];
			std::cout << "Введите текст который вы хотите зашифровать:" << std::endl;
			std::cout << " знаки препинания, пробелы, цифры, — не вводятся!";
			for (int i = 0; i < countChar; ++i)
			{
				std::cin >> arr[i];
			}
			std::cin.ignore(1024, '\n');//подглядел в интернете!
			std::cout << "Вы ввели: ";
			for (int i = 0; i < countChar; i++)
			{
				std::cout << arr[i];
			}
			//целое число — сдвиг шифра
			int x = 1;	
			std::cout << std::endl;
			std::cout << "Введите  целое число — сдвиг шифра" << std::endl;
			std::cin >> x;			
			if (!x)
			{
				std::cout << "Введено не целое число! прграмма будет закрыта!" << std::endl;				
				return 0;
			}	
			//замена символов
			for (int i = 0; i < countChar; i++)
			{
				//Заглавныe
				if (arr[i] >= 'A' && arr[i] <= 'Z')
				{
					if (arr[i] >= 'A' && arr[i] <= ('Z' - x))
					{
						arr[i] += x;
					}
					else
					{
						int count = x - ('Z' - arr[i]);
						int num = 65;
						arr[i] = num;
						while (count)
						{
							arr[i] = num;
							--count;
							++num;
						}
					}
				}
				//строчные
				if (arr[i] >= 'a' && arr[i] <= 'z')
				{
					if (arr[i] >= 'a' && arr[i] <= 'z' - x)
					{
						arr[i] = arr[i] + x;
					}
					else
					{
						int count = x - ('z' - arr[i]);
						int num = 97;
						arr[i] = num;
						while (count)
						{
							arr[i] = num;
							--count;
							++num;
						}
					}
				}
			}
			std::cout << std::endl;
			std::cout << "получилось после шифровыния: ";
			for (int i = 0; i < countChar; i++)
			{
				std::cout << arr[i];

			}
			std::cout << std::endl;
			delete[] arr;
		}
		//дешифровка
		if (simbol == '-')
		{
			std::cout << "Сколько символов Вы хотите ввести для дешифровки?" << std::endl;
			std::cin >> countChar;
			//выход при ложном вводе
			if (!countChar) {
				std::cout << "Введен не верный символ, программа будет закрыта!" << std::endl;
				return 0;
			}
			//массив для хранения текста
			char* arr = new char[countChar];
			std::cout << "Введите текст который вы хотите зашифровать:" << std::endl;
			std::cout << " знаки препинания, пробелы, цифры, — не вводятся!";
			for (int i = 0; i < countChar; ++i)
			{
				std::cin >> arr[i];
			}
			std::cin.ignore(1024, '\n');//подглядел в интернете!
			std::cout << "Вы ввели: ";
			//целое число — сдвиг шифра
			int x = 1;
			std::cout << std::endl;
			std::cout << "Введите  целое число — сдвиг шифра" << std::endl;
			std::cin >> x;
			if (!x)
			{
				std::cout << "Введено не целое число! прграмма будет закрыта!" << std::endl;
				return 0;
			}
			//замена символов
			for (int i = 0; i < countChar; i++)
			{
				//Заглавныe
				if (arr[i] >= 'A' && arr[i] <= 'Z')
				{
					if (arr[i] >= ('A' + x) && arr[i] <= 'Z')
					{
						arr[i] -= x;
					}
					else
					{
						int count = x - (arr[i] - 'A');
						int num = 90;
						arr[i] = num;
						while (count)
						{
							arr[i] = num;
							--count;
							--num;
						}
					}
				}
				//строчные
				if (arr[i] >= 'a' && arr[i] <= 'z')
				{
					if (arr[i] >= ('a' + x) && arr[i] <= 'z')
					{
						arr[i] -= x;
					}
					else
					{
						int count = x - (arr[i] - 'a');
						int num = 122;
						arr[i] = num;
						while (count)
						{
							arr[i] = num;
							--count;
							--num;
						}
					}
				}
			}
			std::cout << std::endl;
			std::cout << "получилось после шифровыния: ";
			for (int i = 0; i < countChar; i++)
			{
				std::cout << arr[i];

			}
			std::cout << std::endl;

			delete[] arr;
		}
				
		//Повтор введения строки с возможностью закрыть программу
		std::cout << "Хотите поробывать еще?" << std::endl;
		std::cout << "Если да то нажмите - y, если нет то - n" << std::endl;
		char play;
		std::cin >> play;
		switch (play)
		{
		case 'n':
			return 0;
		case 'y':
			break;
		default:
			std::cout << "Введен не верный символ!" << std::endl;
			break;
		}
	}	
	return 0;
}
