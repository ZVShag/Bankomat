#include <iostream>
#include <string.h>
using namespace std;
class Client
{
	double balance;
	string rezident;
	int password;
public:
	Client()
	{
		cout << "Укажите количество денег на карте:" << endl;
		cin >> this->balance;
		cout << "Укажите клиентом какого банка вы являетесь:" << endl;
		cin >> this->rezident;
		cout << "Придумайте пин-код карты:" << endl;
		cin>>this->password;
	}
	Client(int bal, string country, string rez, int pass)
	{
		this->balance = bal;
		this->rezident = rez;
		this->password = pass;
	}
	void Set_Balance(double a){this->balance += a;}
	double Get_Balacne(){return this->balance;}
	string Get_Rezident(){return this->rezident;}
	int Get_Password(){return this->password;}
	void Print()
	{
		cout << "Баланас карты " << this->balance << endl;
		cout << "Клиент банка " << this->rezident << endl;
		
	}
};
class bankomat
{
	string name;
	string model;
	double money;
	
public:
	bankomat()
	{
		cout << "Введите имя банка:" << endl;
		cin >> this->name;
		cout << "Введите модель банкомата:" << endl;
		cin >> this->model;
		cout << "Укажите количество денег в банкомате:" << endl;
		cin >> this->money;
		
	}
	void Out_money(Client &a, int summ)
	{
		if ((a.Get_Rezident() == this->name) && (summ <= a.Get_Balacne()) && (summ <= this->money))
		{
			cout << "Введите пин-код:" << endl;
			int pin = 0;
			cin >> pin;
			if (a.Get_Password() == pin)
			{
				a.Set_Balance(-summ);
				this->money -= summ;
				cout << "Возьмите деньги" << endl;
			}
			else
				cout << "Неверно введен пин-код" << endl;
		}
	}
	void Print()
	{
		cout << "Банкомат банка " <<this->name<< endl;
		cout << "Модель банкомата " << this->model << endl;
		cout << "Остаток денег в банкомате " << this->money << endl;
	}
	void Insert_money(Client &a,double c)
	{
		a.Set_Balance(c);
		cout << "Деньги успешно внесены!" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Client a;
	bankomat b;
	int sim=0;
	while (true)
	{
		cout << "Если вы хотите снять деньги введите 1:" << endl;
		cout << "Если вы хотите внести деньги введите 2:" << endl;
		cout << "Если вы хотите завершить обслуживание введите 3:" << endl;
		cin >> sim;
		if (sim == 1)
		{
			cout << "Введите сумму:" << endl;
			int c = 0;
			cin >> c;
			b.Out_money(a, c);
		}
		if (sim == 2)
		{
			cout << "Введите сумму:" << endl;
			double c = 0;
			cin >> c;
			b.Insert_money(a,c);
		}
		if (sim == 3)
			break;


	}
	a.Print();
	b.Print();
}