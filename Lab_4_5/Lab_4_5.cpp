#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	srand((unsigned)time(NULL));

	double x, y, R;
	cout << "Введіть параметр R: ";
	cin >> R;

	cout << "Спосіб 1 (введення координат вручну):" << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << "Постріл " << i << ":" << endl;
		cout << "Введіть значення x (x є [" << -2 * R << "; " << 2 * R << "]): ";
		cin >> x;
		cout << "Введіть значення y (y є [" << -2 * R << "; " << 2 * R << "]): ";
		cin >> y;

		if (x < -2 * R || x > 2 * R || y < -2 * R || y > 2 * R)
		{
			cout << "Некоректні координати!" << endl;
			break;
		}

		if (((x <= 0) && (y >= 0) && (x * x + y * y <= R * R)) ||
			((y <= 0) && (y >= -2 * x) && (y >= 2 * x - 2 * R)))
			cout << "Влучання!" << endl;
		else
			cout << "Промах!" << endl;
	}

	cout << endl << "Спосіб 2 (випадкові координати):" << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << "Постріл " << i << ":" << endl;
		x = -2 * R + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (2 * R - (-2 * R))));
		cout << "Випадкове значення x: " << x << endl;
		y = -2 * R + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (2 * R - (-2 * R))));
		cout << "Випадкове значення y: " << y << endl;

		if (x < -2 * R || x > 2 * R || y < -2 * R || y > 2 * R)
		{
			cout << "Некоректні координати!" << endl;
			continue;
		}

		if (((x <= 0) && (y >= 0) && (x * x + y * y <= R * R)) ||
			((y <= 0) && (y >= -2 * x) && (y >= 2 * x - 2 * R)))
			cout << "Влучання!" << endl;
		else
			cout << "Промах!" << endl;
	}

	return 0;
}