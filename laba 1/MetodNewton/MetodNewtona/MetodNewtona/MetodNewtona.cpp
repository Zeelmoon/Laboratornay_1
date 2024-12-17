#include <iostream>
#include <clocale>
#include <cmath>
#include <limits>
#include <ctime>
using namespace std;
double F2(double x)
{
	x = -(-4 * pow(x, 5) + 20 * pow(x, 3) + (2 * sqrt(5) * sqrt(5 - 2 * pow(x, 2)) * (pow(x, 2) - 1)) - 25 * x) / (sqrt(1 - pow(x, 2)) * (4 * pow(x, 6) - 24 * pow(x, 4) + 45 * pow(x, 2) - 25));
	return x;
}
double f(double x)
{
	return sqrt(1 - 0.4 * x * x) - asin(x);
}
double deriF(double x)
{
	return (-0.4 * x / sqrt(1 - 0.4 * x * x)) - (1 / sqrt(1 - x * x));
}
int main()
{
	int st = clock();
	setlocale(LC_ALL, "Ru");
	double eps = 1e-6; // степень точности
	double a = 0.0;
	double b = 1.0; //a and b границы отрезка
	double x_rasn; // разница между корнями
	double x0, x1;
	int k = 0;
	int end;
	double Inf = numeric_limits<double>::infinity();
	if ((f(a) * F2(a)) >= 0)
	{
		if (abs(deriF(a)) != Inf)
		{
			if ((f(a) * F2(a)) == 0)
			{
				cout << "Корень уравнения: " << a << endl;
			}
			else {
				x0 = a;
				x1 = x0 - f(a) / deriF(a);
				x_rasn = abs(x0 - x1);
				while (x_rasn <= eps)
				{
					++k;
					x1 = x0 - f(x0) / deriF(x0);
					x_rasn = abs(x0 - x1);
					x0 = x1;
					cout << "Итерация: " << k << ". х1= " << x1 << endl;
				}
				end = clock();
				cout <<"Количество итераций: "<<k<<". Время выполнения: "<< end-st<< ". Корень уравнениея: " << x1;
			}
		}
		else {
			while (abs(deriF(a)) == Inf)
			{
				a -= 0.001;
			}
			if ((f(a) * F2(a)) == 0)
			{
				cout << "Корень уравнения: " << a << endl;
			}
			else
			{
				x0 = a;
				x1 = x0 - f(a) / deriF(a);
				x_rasn = abs(x0 - x1);
				while (x_rasn > eps)
				{
					x1 = x0 - f(x0) / deriF(x0);
					x_rasn = abs(x0 - x1);
					x0 = x1;
					cout << "Итерация: " << k << ". х1= " << x1 << endl;
				}
				end = clock();
				cout << "Количество итераций: " << k << ". Время выполнения: " << end - st << ". Корень уравнениея: " << x1;

			}

		}
	}
	else if ((f(b) * F2(a)) >= 0)
	{
		if (abs(deriF(b)) != (Inf))
		{
			if ((f(b) * F2(b)) == 0)
			{
				cout << "Корень уравнения: " << b;
			}
			else
			{
				x0 = b;
				x1 = (x0 - f(b) / deriF(b));
				x_rasn = abs(x0 - x1);
				while (x_rasn > eps)
				{
					x1 = x0 - f(b) / deriF(b);
					x0 = x1;
					x_rasn = abs(x0 - x1);
					cout << "Итерация: " << k << ". х1= " << x1 << endl;
				}
				end = clock();
				cout << "Количество итераций: " << k << ". Время выполнения: " << end - st << ". Корень уравнениея: " << x1;
			}
		}
		else {
			while (abs(deriF(b)) == Inf)
			{
				b -= 0.001;
			}
			if ((f(b) * F2(b)) == 0)
			{
				cout << "Корень уравнения: " << b;
			}
			else
			{
				x0 = b;
				x1 = (x0 - f(b) / deriF(b));
				x_rasn = abs(x0 - x1);
				
				while (x_rasn > eps) 
				{
					++k;
					x1 = x0 - (f(x0) / deriF(x0));
					
					x_rasn = abs(x0 - x1);
					x0 = x1;
					cout << "Итерация: " << k << ". х1= " << x1 << endl;
				}
				end = clock();
				cout << "Количество итераций: " << k << ". Время выполнения: " << end - st<<"мс" << ". Корень уравнениея: " << x1;
			}
		}
	}
	else {
		cout << "Корней нет";
	}
	
	return 0;
}