#include <iostream>

using namespace std;
const int n = 10;

double a = 0, b = 1, lambda = 1;
double h = (b - a) / n;

double X[n + 1], Xi[n], A[n][n + 1], C[n];

double ker(double x,double y) {

	return x - y;

}

double u(double x) {

	return pow(x, 2);
}

double f(double x)
{
	return x * x - lambda * (x * 3 - (1 / 4));
}

void MakeGrid(){

	for (int i = 0; i <= n; i++)
	{
		X[i] = a + i * h;
	}
	for (int i = 0; i < n; i++)
	{
		Xi[i] = X[i] + h / 2;
	}
}


double Integral(int i, int k)
{
	int N = 100;
	double I = 0, l, alfa = X[i], beta = X[i + 1], xi = Xi[k];
	l = ((beta - alfa) / N);
	for (int i = 0; i < N-1; i++)
	{
		I += l*ker(xi, alfa + (i + 0.5)*l);
	}

	return I;
}

double delta(int i, int k) {
	return (i == k);
}

void AAA() {

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{


			A[i][j] = delta(i, j) - lambda * Integral(j, i);
		}
	}

}



int main()
{
	for (int i = 0; i < n; i++)
	{ 
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j];
		}
		cout << endl;
	}
	//cout << delta(1, 2);
	return 1;
}