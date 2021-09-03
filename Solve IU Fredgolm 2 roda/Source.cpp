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


double Intergal()
{

	double I;
	for (int i = 0; i < n-1; i++)
	{
		I += f(a + (i + 0.5)*(X[i + 1] - X[i] / n));
	}


}


int main()
{


	return 1;
}