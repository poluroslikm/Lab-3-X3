#include <iostream>
#include <locale>
#include <string>
#include <fstream>

using namespace std;

struct AEROFLOT
{
	int NUMR;
	double COST;
	string NASN;
	string TIP;
};

void zad1()
{
	int i=0, k;
	string str1;
	for (;;)
	{ 
		i = 0;
		getline(cin, str1);
		for (;i != -1;)
		{
			i = str1.find(' ');
			if (i!= -1)
			str1.replace(i, 1, "!");
		}
		cout << str1 << "\n\n";
		k = str1.find("quit");
		if (k != -1)
			break;
		cout << "Введите строку\n";
	}
}

void zad2()
{
	int z = 0;
	ifstream text1("text1.txt");
	ofstream text2;
	text2.open("text2.txt");
	string str0;
		while (getline(text1, str0))
		{
			z = str0.length();
			text2 << str0 << " - " << z << " symbols\n";
		}
	text1.close();
	text2.close();
}

void zad3()
{
	AEROFLOT AIROPORT[7];
	string str0;
	int z=0;
	for (int i = 0; i < 7; i++)
	{
		cout << "Введите номер рейса, стоимость билета, название пункта назначения и тип самолета\n";
		cin >> AIROPORT[i].NUMR >> AIROPORT[i].COST >> AIROPORT[i].NASN >> AIROPORT[i].TIP;
		//cout << '\n' << AIROPORT[i].NUMR << AIROPORT[i].COST << AIROPORT[i].NASN << AIROPORT[i].TIP;
	}
	cout << "Введите название пункта назначения\n";
	cin >> str0;
	for (int i = 0; i < 7; i++)
	{
		if (AIROPORT[i].NASN == str0)
		{
			z = 1;
			cout << "\nНомер рейса - " << AIROPORT[i].NUMR << " Тип самолета - " << AIROPORT[i].TIP;
		}
	}
	if (z == 0)
		cout << "\nРейсов с таким пунктом назначения нет";
}

// 13 54545.32 voronezh ultra
// 32 8766.44 rostov ultra
// 12 757.434 voronezh mega
// 4 545445 moskva mega
// 34 33434 moskva mega
// 43 3434.554 piter giga
// 12 4334.5678 voronezh giga

int main()
{
	setlocale(LC_ALL, "RUS");
	char sw;
	cout << "Выберите задание (1, 2 или 3) \n";
	cin >> sw;
	switch (sw)
	{
	case '1': zad1();
		break;
	case '2': zad2();
		break;
	case '3': zad3();
		break;
	default: cout << "Неизвестная операция";
	}

}
