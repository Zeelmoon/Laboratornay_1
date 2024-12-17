#include <iostream>
#include <clocale>
#include <ctime>
#include <cmath>
using namespace std;

double f(double x)
{
	return 	x = sin(sqrt(1 - 0.4 * pow(x, 2)));
}
int main()
{
	int s = clock();
	setlocale(LC_ALL, "Ru");
	double eps = 1e-6; // степень точности
	double a = 0.0;
	double b = 1.0; //a and b границы отрезка
	double x0,x1;
	int k = 0;
	x0 = (b-a)/2;
	x1 = f(x0);
	while (abs(x0-x1) > eps)
	{
		++k;	
		x0 = x1;
		x1 = f(x0);
		cout << "Значение х0= "<< x1<<" при "<< k<<" итераций" << endl;
			
		
	}
	
	int end = clock();
	cout << "Времени затрачено: " << end - s << "мс, " << "кол-во итераций: " << k << ", Значение x = " << x0;
	return 0;
}
