
#include <clocale>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
double f(double x)
{
	return sqrt(1 - 0.4 * x * x) - asin(x);
}
int main()
{
	int st = clock();
	setlocale(LC_ALL, "Ru");
	double eps = 1e-6; // степень точности
	double a = 0.0;
	double b = 1.0; //a and b границы отрезка
	double x_rasn; // разница между корнями
	double x0;
	int x1 = 0;// счетчик итераций
	int end;
	x_rasn = abs(b - a);
	while (x_rasn > eps)
	{
		++x1;
		x0 = ((b + a) / 2);
		;
		if ((f(a) * f(x0)) < 0)
		{
			b = x0;
			x_rasn = abs(b - a);
			end =clock();
			cout << "Итерация: " << x1 << "\t" << "Границы отрезка: (" << a << "; " << b << ")" << endl;
		}
		else if ((f(x0) * f(b)) < 0)
		{
			a = x0;
			x_rasn = abs(b - a);

			cout << "Итерация: " << x1 << "\t" << "Границы отрезка: (" << a << "; " << b << ")" << endl;
		}
		else
		{
			cout << "Корней нет" << endl;
		}
	}
	end = clock();

	cout << "Всего итераций: "<< x1<<". Время действия программы: "<< end-st<<"мс"<<". Корень равен = "<<a<<endl;
	return 0;
}
