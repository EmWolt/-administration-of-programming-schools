#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>                            		
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <iomanip>



using namespace std;
class Proverka {
public:
	string PhoneNumber;

	bool proverkaSkidki() {
		int countGroups =0;
		if (PhoneNumber.find("Python") != -1)
		{
			countGroups++;
		}
		if (PhoneNumber.find("Scratch") !=-1)
		{
			countGroups++;
		}
		if (countGroups > 1)
		{
			return true;
		}
		else {
			return false;
		}
	}

	bool ProberkaNomera() {
		if (PhoneNumber.length() < 13)
		{
			return false;
		}
		else if (PhoneNumber[0] != '+')
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

class program {
public:
	string buff;
	string fillial;
	void setColor(unsigned int color) {
		std::cout << "\x1b[" << color << "m";
	}

	

	void vivodUchenikov() {
		bool skidka = false;
		setColor(36);
		cout << "===========================================================================" << endl;
		while (buff.find("##") != -1) {

			string IDuchenik = buff.substr(buff.find_first_of("##") + 2, 4);
			buff.erase(buff.find_first_of("##"), 6);
			ifstream Uchenik_Anketa(fillial + "/" + IDuchenik + ".txt");
			skidka = false;
			while (!Uchenik_Anketa.eof())
			{
				string uchenik;
				getline(Uchenik_Anketa, uchenik);
				Proverka ProverkaS{ uchenik };
				skidka = ProverkaS.proverkaSkidki();

				cout << "|" << uchenik << "|";
				for (int i = 0; i < 20 - uchenik.length(); i++)
				{
					cout << " ";
				}
				cout << "\t";
			}
			if (skidka)
			{
				string uchenik;
				Uchenik_Anketa.close();
				ifstream Uchenik_Anketa(fillial + "/" + IDuchenik + ".txt");
				getline(Uchenik_Anketa, uchenik);
				getline(Uchenik_Anketa, uchenik);
				setColor(31);
				cout << " \n|"<< uchenik<<"\t ученик входит в несколько групп и имеет 15 % скидку | \n ";
				setColor(36);
				skidka = false;
			}
			cout << endl;
			Uchenik_Anketa.close();
		}
		cout << "==========================================================================="<<endl;
		setColor(30);

	}
	void vivoDolzhnikov() {
		string IDuchenik, vivod;

		for (int j = 0; j < 10000; j++)
		{

			if (j < 10)
			{
				IDuchenik = "000" + to_string(j);
			}
			else if (j < 100)
			{
				IDuchenik = "00" + to_string(j);

			}
			else if (j < 100)
			{
				IDuchenik = "0" + to_string(j);

			}
			else {
				IDuchenik = to_string(j);
			}
			ifstream Uchenik_anketa("kiberone/" + IDuchenik + ".txt");
			if (Uchenik_anketa.is_open())
			{
				string balance;
				getline(Uchenik_anketa, balance);
				getline(Uchenik_anketa, balance);
				getline(Uchenik_anketa, balance);

				if (stoll(balance) < 0)
				{	
					Uchenik_anketa.close();
					ifstream Uchenik_anketa("kiberone/" + IDuchenik + ".txt");
					while (!Uchenik_anketa.eof()) {
						getline(Uchenik_anketa, vivod);
						cout << vivod << endl;
					}
					cout << endl;
					Uchenik_anketa.close();
				}
			}
		}
	}
	void vivodUchenika()
	{
		system("cls");
		bool skidka = false;

		for (int j = 0; j < 10000; j++)
		{
			string IDuchenik;
			if (j < 10)
			{
				IDuchenik = "000" + to_string(j);
			}
			else if (j < 100)
			{
				IDuchenik = "00" + to_string(j);

			}
			else if (j < 1000)
			{
				IDuchenik = "0" + to_string(j);

			}
			else {
				IDuchenik = to_string(j);
			}
			ifstream Uchenik_Anketa(fillial + "/" + IDuchenik + ".txt");
			if (Uchenik_Anketa.is_open())
			{
				string uchenik;
				while (!Uchenik_Anketa.eof()) {
					Uchenik_Anketa >> uchenik;
					if (uchenik == buff)
					{
						Uchenik_Anketa.close();
						ifstream Uchenik_Anketa(fillial + "/" + IDuchenik + ".txt");
						while (!Uchenik_Anketa.eof()) {
							getline(Uchenik_Anketa, uchenik);
							Proverka ProverkaS{ uchenik };
							skidka = ProverkaS.proverkaSkidki();
							cout << uchenik << endl;
						}
						if (skidka)
						{
							string uchenik;
							Uchenik_Anketa.close();
							ifstream Uchenik_Anketa(fillial + "/" + IDuchenik + ".txt");
							getline(Uchenik_Anketa, uchenik);
							getline(Uchenik_Anketa, uchenik);

							cout << " \n |" << uchenik << " ученик входит в несколько групп и имеет 15 % скидку | \n";
							skidka = false;
						}
					}
				}
				Uchenik_Anketa.close();
			}
		}
	}
		void VivodVsehUchenikov() {
			string IDuchenik,vivod;
			bool skidka = false;

			for (int j = 0; j < 10000; j++)
			{

				if (j < 10)
				{
					IDuchenik = "000" + to_string(j);
				}
				else if (j < 100)
				{
					IDuchenik = "00" + to_string(j);

				}
				else if (j < 100)
				{
					IDuchenik = "0" + to_string(j);

				}
				else {
					IDuchenik = to_string(j);
				}
				ifstream Uchenik_anketa("kiberone/" + IDuchenik + ".txt");
				if (Uchenik_anketa.is_open())
				{
					cout << "__________________________________" << endl;
					while (!Uchenik_anketa.eof()) {
						getline(Uchenik_anketa, vivod);
						Proverka ProverkaS{ vivod };
						skidka = ProverkaS.proverkaSkidki();
						cout << "|" << vivod << "|" << "    " << endl;
					}
					if (skidka)
					{
						string uchenik;
						Uchenik_anketa.close();
						ifstream Uchenik_anketa(fillial + "/" + IDuchenik + ".txt");
						getline(Uchenik_anketa, uchenik);
						getline(Uchenik_anketa, uchenik);

						cout << " \n |" << uchenik << " ученик входит в несколько групп и имеет 15 % скидку | \n";
						skidka = false;
					}
					cout << "__________________________________";
					Uchenik_anketa.close();
				}
			}

		}
	
	

		
	
};
class Substring{
public:
	void deleteSubstring(std::string fullFilePath, std::string substringToDelete) {
		std::ifstream fileIn(fullFilePath);
		std::stringstream buffer;
		buffer << fileIn.rdbuf();
		std::string content = buffer.str();
		fileIn.close();

		size_t pos = content.find(substringToDelete);
		while (pos != std::string::npos) {
			content.replace(pos, substringToDelete.length(), "");
			pos = content.find(substringToDelete, pos);
		}

		std::ofstream fileOut(fullFilePath);
		fileOut << content;
		fileOut.close();
	}
};

class Admin{
public:
	string fillial;
	string group;

	void Dobavka() {
		ofstream Group;
		Group.open(fillial + "/" + group + ".txt", ios_base::app);
		system("cls");
		cout << "Введите имя:";
		string name, surname,gruppa,balance;
		cin >> name;
		cout << "Введите фамилию:";
		cin >> surname;
		cout << "Введите группу ученика:";
		cin >> gruppa;
		cout << "Данный ученик оплатил курс?";
		cin >> balance;
		ifstream id("kiberone/id.txt");
		string Cifr;
		getline(id, Cifr);
		int idCifr = stoi(Cifr);
		idCifr += 1;

		string idCifrStroka;
		ofstream NewUchenik;
		id.close();
		ofstream idZapis("kiberone/id.txt");
		if (idCifr < 10)
		{
			NewUchenik.open("kiberone/000" + to_string(idCifr) + ".txt");
			NewUchenik << "000" + to_string(idCifr) << endl;
			NewUchenik << name << " " << surname << endl;
			if (balance == "yes" || balance == "да") 
			{
			NewUchenik << "650.000" << endl;
			}
			else { NewUchenik << "-650.000" << endl; }
			NewUchenik << gruppa;

			Group << "##000" + to_string(idCifr);
			
		}
		else if (idCifr < 100) {
			NewUchenik.open("kiberone/00" + to_string(idCifr) + ".txt");
			NewUchenik << "00" + to_string(idCifr) <<endl;
			NewUchenik << name << " " << surname << endl;
			if (balance == "yes" || balance == "да")
			{
				NewUchenik << "650.000" << endl;
			}
			else { NewUchenik << "-650.000" << endl; }
			NewUchenik << gruppa;

			Group << "##00" + to_string(idCifr);

		}
		else if (idCifr < 1000) {
			NewUchenik.open("kiberone/0" + to_string(idCifr) + ".txt");
			NewUchenik << "0" + to_string(idCifr) <<endl;
			NewUchenik << name << " " << surname << endl;
			if (balance == "yes" || balance == "да")
			{
				NewUchenik << "650.000" << endl;
			}
			else { NewUchenik << "-650.000" << endl; }
			NewUchenik << gruppa;
		
			Group << "##0" + to_string(idCifr);

		}
		else {
			NewUchenik.open("kiberone/" + to_string(idCifr) + ".txt");
			NewUchenik << idCifr<<endl;
			NewUchenik << name << " " << surname << endl;
			if (balance == "yes" || balance == "да")
			{
				NewUchenik << "650.000" << endl;
			}
			else { NewUchenik << "-650.000" << endl; }
			NewUchenik << gruppa;

			Group << "##" + to_string(idCifr);

		}
		idZapis << idCifr;
		NewUchenik.close();
		Group.close();
	}

	void Udalenie(string& putUdaleniya,string &idUdaleniya) {
		fstream Group;
		string GroupName = fillial + "/" + group + ".txt";
		Group.open(GroupName);
		system("cls");
		cout << "Введите ID ученика которого хотите удалить " << endl;
		cin >> idUdaleniya;
		string buff;

		while (!Group.eof())
		{
			getline(Group, buff);
			if (buff.find("##") != -1)
			{
				while (buff.find("##") != -1) {

					string IDuchenik = buff.substr(buff.find_first_of("##") + 2, 4);

					buff.erase(buff.find_first_of("##"), 6);
					if (idUdaleniya == IDuchenik)	
					{
						string Anketa_Udaleniya = fillial + "/" + IDuchenik + ".txt";
						remove(Anketa_Udaleniya.c_str());
						putUdaleniya = fillial + "/" + group + ".txt";
						idUdaleniya = "##" + IDuchenik;
						break;
					}
				}
			}
		}
	}
	
};
class Vhod {
public:
	string login;
	string password;
	string proverka;
	string buff;
	bool access = false;

	bool Autrization() {
		ifstream log("kiberone/login.txt");


		while (!log.eof())
		{
			getline(log, buff);
			if (buff.find(login) != -1)
			{
				proverka = buff.substr(buff.find(login) + login.length() + 1);

				if (password == proverka)
				{
					return true;
					
				}
				else {
					
					return false;
				}

			}
		
		}
		
		return false;

	}

};

void NomerProverka(string NameClient,int viborNapravleniya)
{
	time_t now;
	time(&now);
	tm ltm;
	localtime_s(&ltm, &now);

	string gruppa;
	if (viborNapravleniya == 1)
	{
		 gruppa = "Python 14:00-16:00";
	}
	else if (viborNapravleniya == 2) 
	{
		 gruppa = "C++ 18:00-19:30";
	}
	else if (viborNapravleniya == 3)
	{
		 gruppa = "Scratch 14:00-16:00";
	}
	else if (viborNapravleniya == 4)
	{
		 gruppa = "Мастер Класс Пак Даниил";
	}
	else if (viborNapravleniya == 5)
	{
		 gruppa = "Индивидуальные занятия";
	}
	else if (viborNapravleniya == 6)
	{
		 gruppa = "Онлайн обучение";
	}
	int month = 1 + ltm.tm_mon; // tm_mon начинается с 0
	int day = ltm.tm_mday;
	string days = to_string(day);
	string months = to_string(month);
	
	string PhoneClient;
	cout << NameClient << " введите пажалуйста ваш номер телефона в формате +99890000000\nТел: ";
	cin >> PhoneClient;
	Proverka  ProberkaNomera{ PhoneClient };
	if (ProberkaNomera.ProberkaNomera())
	{
		ofstream zapis;
		zapis.open(NameClient+ " " + days + "." + months + ".txt");
		if (zapis.is_open())
		{
			zapis << NameClient << endl;
			zapis << gruppa << endl;
			zapis << PhoneClient << endl;
		}
		zapis.close();
		cout << "Вы были записаны на пробный урок! Ждем вас" << endl;
	}
	else {
		NomerProverka(NameClient = "Klient", viborNapravleniya=1);
	}
}
	int main()
	{

		program colors{};
		colors.setColor(47);
		colors.setColor(30);
		system("cls");
		bool t = false;
		string buff = "jhgjgj";
		string putUdaleniya, idUdaleniya;
		
		M:if (t) {
		 Substring sub{};
			sub.deleteSubstring(putUdaleniya, idUdaleniya);
			t = false;

		}



		ifstream PythonGroup("kiberone/Python.txt");
		ifstream FigmaGroup("Figma.txt");
		ifstream PhotoshopGroup("Photoshop.txt");
		ifstream WebGroup("WEB.txt");
		ifstream ScratchGroup("kiberone/Scratch.txt");

		int vibor_v_menu;
		setlocale(LC_ALL, "rus");
		int admin;
		string login, password,proverka;
		bool access =false;
		cout << "Приветсвуем в программе ";
		colors.setColor(32);
		cout << "\'Обозреватель учебных центров \' \n";
		colors.setColor(30);
		cout << "1.Войти в аккаунт\n";
		cout << "2.Гость \n";
		cin >> admin;
		if (admin == 1)
		{
			
			
			cout << "Введите логин \n";
			cin >> login;
			cout << "Введите пароль \n";
			cin >> password;

			Vhod in{ login,password,proverka,buff,access };
			access = in.Autrization();

			if (access)
			{
				system("cls");
				
				//Выбор филиала 
				cout << "1.K1BERone\n";
				cout << "2.LvlUP education center\n";
				cout << "3.ProWEB\n";
				cout << "4.Поиск \n";
				cout << "Здравствуйте , выберите желаемый филлиал:";
				int viborFilliala;
				cin >> viborFilliala;

				//В зависимости от выбранной цифры происходит выбор филлиала и дальнейшие инструкции
				if (viborFilliala == 1)
				{
					system("cls");
					//выбор группы										   
					cout << "##  ##   ## #####  ##### #####   ####  ##  ## #####" << endl;
					cout << "## ##  #### ##  ## ##    ##  ## ##  ## ### ## ##   " << endl;
					cout << "####     ## #####  ####  #####  ##  ## ## ### #### " << endl;
					cout << "## ##    ## ##  ## ##    ##  ## ##  ## ##  ## ##   " << endl;
					cout << "##  ##   ## #####  ##### ##  ##  ####  ##  ## #####" << endl;
					cout << "Добро пожаловать в K1BERone лучшую школу программирования для детей\n Список курсов: \n";
					cout << "1.Визуальное прораммирование на Scratch \n";
					cout << "2.Язык программирования Python\n";

					//на каждом этапе должен быть возврат к началу
					cout << "3.Вернуться к филлиалам\n";
					cin >> vibor_v_menu;
					if (vibor_v_menu == 3)
					{
						return main();
					}
					else if (vibor_v_menu == 2) {
						system("cls");


						while (!PythonGroup.eof())
						{
							getline(PythonGroup, buff);

							if (buff.find("##") != -1)
								//условие находит строку где ученики
							{
								program vivod{ buff,"kiberone" };
								vivod.vivodUchenikov();
								cout << "1.Добавить ученика" << endl;
								cout << "2.Удалить ученика" << endl;
								cout << "3.Вернуться" << endl;
								int AdminChangeBD;
								cin>>AdminChangeBD;
								if (AdminChangeBD == 1)
								{
									Admin admin{ "kiberone","Python"};
									admin.Dobavka();
								}
								else if (AdminChangeBD == 2) {
									Admin admin{ "kiberone","Python" };
									admin.Udalenie(putUdaleniya,idUdaleniya);
									t = true;
									goto M;
								}
								else if (AdminChangeBD == 3) {
									return main();
								}
							}
							else {
								cout << buff << endl;
							}

						}
					}
					else if (vibor_v_menu == 1) {
						system("cls");

						while (!ScratchGroup.eof())
						{


							getline(ScratchGroup, buff);

							if (buff.find("##") != -1)

							{
								program vivod{ buff,"kiberone" };
								vivod.vivodUchenikov();
							}
							else {
								cout << buff << endl;
							}
						}
					}
				}
				else if (viborFilliala == 2)
				{
					cout << "Добро пожаловать в LVL up educaation center, айти курсы для всех!\n Список курсов: \n";
					cout << "1.Графический дизайн на Figma \n";
					cout << "2.Web программирование \n";
					cout << "3.Вернуться к филлиалам \n";
					cin >> vibor_v_menu;
					if (vibor_v_menu == 3)
					{
						return main();
					}


				}
				else if (viborFilliala == 3)
				{
					cout << "Добро пожаловать в ProWEB Худший учебный центр \n Список курсов: \n";
					cout << "1.Основы Photoshop\n";
					cout << "2.Вернуться к филлиалам\n";
					cin >> vibor_v_menu;
					if (vibor_v_menu == 2)
					{
						return main();
					}
				}
				else if (viborFilliala == 4) 
				{
					system("cls");
					int viborPoiska;
					cout << "Выберите опцию " << endl;
					cout << "1.Вывод всех учеников" << endl;
					cout << "2.Поиск определенного ученика" << endl;
					cout << "3.Вывод группы" << endl;
					cout << "4.Вывод должников" << endl;
					cin >> viborPoiska;
					if (viborPoiska == 2)
					{
						cout << "Введите имя или фамилию или айди желаемого ученика";
						cin >> buff;
						program vivod{ buff,"kiberone" };
						vivod.vivodUchenika();
					}
					else if (viborPoiska == 1) {
						system("cls");
						cout << "Все ученики нашей программы" << endl;
						program vivod{};
						vivod.VivodVsehUchenikov();
					}
					else if (viborPoiska == 3) {
						system("cls");
						string group;
						cout << "Введите название группы" << endl;
						cin >> group;
						ifstream Group("kiberone/" +group+ ".txt");
						
						while (!Group.eof())
						{


							getline(Group, buff);

							if (buff.find("##") != -1)

							{
								program vivod{ buff,"kiberone" };
								vivod.vivodUchenikov();
							}
							else {
								cout << buff << endl;
							}
						}
					}
					else if (viborPoiska == 4) {
						system("cls");
						program vivod{ buff,"kiberone" };
						vivod.vivoDolzhnikov();
						cout << "1.Вернуться";
						cin >> viborFilliala;
						if (viborFilliala == 1)
						{
							return main();
						}
					}
					

				}
			}
			else {
				system("cls");
				cout << "Ошибка входа \n";
				return main();

			}
			
			}
		else if (admin == 2) {
			system("cls");
			int viborNapravleniya;
			cout << "Где бы вы хотели учиться?\n";
			cout << "=========================================\n";
			cout << "Kiberone \n ул Катта хирмонтема дом 41 \n1.Язык Python \n преподаватель: Ходжаев Даян программист со стажем 5 лет " << endl;

			cout << " 14:00-16:00 \n пн-ср-пт \n цена курса:750 000" << endl;
			cout << "=========================================\n";

			cout << "2.Язык С++ \n преподаватель: доцент Абдуллаев Абдулборий\n 18:00-19:30\n вт-чт-сб\n цена курса:1 000 000" << endl;
			cout << "=========================================\n";

			cout << "3.Детское программирование на Scratch \n преподаватель:Шевцова Сусанна победитель междунарондых соревнований по программированию" << endl;

			cout << " 14:00-16:00 \n вт-чт-сб\n цена курса: 550 000" << endl;
			cout << "=========================================\n";

			cout << "4.Мастер-класс по 3д-моделлированию от Пака Даниила , гуру дизайна только 3,10 и 17 декабря !" << endl;
			cout << "=========================================\n";

			cout << "5.Индивидуальные занятия \n";
			cout << "=========================================\n";

			cout << "6.Онлайн группа\n";
			cout << "=========================================\n";

			cin >> viborNapravleniya;
			
			system("cls");
			
			
			
			
					
			if (viborNapravleniya == 5)
			{
				cout << "1.Python  1.100.000\n";
				cout << "2.C++  1.600.000\n";
				cout << "3.Full stack web-development 1.500.000\n";
				cout << "4.UI/UX Design  1.000.000\n";
				cout << "5.Олимпиадное программирование  1.900.000\n";
				int viborIndivid;
				cin>>viborIndivid;
				system("cls");
				cout << "1.Занятия онлайн\n";
				cout << "2.В одном из филлиалов +10%(к цене абонимента)\n";
				cout << "3.С выездом на дом +20%(к цене абонимента)\n";
				cin >> viborIndivid;


			}
			system("cls");
			cout << "Введите пажалуйста ваше имя: \n";
			string NameClient, PhoneClient;
			cin >> NameClient;
			NomerProverka(NameClient, viborNapravleniya);
			cout << "С вами свяжутся наши менеджеры и обсудят подходящий вам абонимент \n";
			if (!(cin >> viborNapravleniya))
			{
				cout << "Invalid input. Please enter a number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return main();
			}
				}
				if (!(cin>>admin))
				{
					cout << "Invalid input. Please enter a number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					return main();
				}
			}


		