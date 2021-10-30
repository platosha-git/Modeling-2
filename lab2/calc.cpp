#include <iostream>
#include <vector>

using namespace std;

const double eps = 0.00001;  // точность

vector<float> gauss(float (*a)[3], vector<float> y, int n) 
{
	vector<float> x(n); 
	
	int k = 0;
	while (k < n) {
		float max = abs(a[k][k]);
		int index = k;
	
		for (int i = k + 1; i < n; i++) {
	  		if (abs(a[i][k]) > max) {
				max = abs(a[i][k]);
				index = i;
	  		}
		}
		
		for (int j = 0; j < n; j++) {
	  		float temp = a[k][j];
	  		a[k][j] = a[index][j];
	  		a[index][j] = temp;
		}
	
		float temp = y[k];
		y[k] = y[index];
		y[index] = temp;
		
		for (int i = k; i < n; i++) {
	  		double temp = a[i][k];
	  		if (abs(temp) < eps) continue;
	  		
	  		for (int j = 0; j < n; j++) {
				a[i][j] = a[i][j] / temp;
			}
	  		
	  		y[i] = y[i] / temp;
	  		if (i == k)  continue;
	  		
	  		for (int j = 0; j < n; j++) {
				a[i][j] = a[i][j] - a[k][j];
	  		}
	  		
	  		y[i] = y[i] - y[k];
		}
		k++;
  	}
  	
  	for (k = n - 1; k >= 0; k--) {
		x[k] = y[k];
		for (int i = 0; i < k; i++) {
	  		y[i] = y[i] - a[i][k] * x[k];
		}
  	}

  	return x;
}

int main()
{
	int size = 3;
	int matr[size][size];
	matr[0][0] = 0; matr[0][1] = 1; matr[0][2] = 2;
	matr[1][0] = 3; matr[1][1] = 0; matr[1][2] = 4;
	matr[2][0] = 5; matr[2][1] = 6; matr[2][2] = 0;

	vector<int> sum(size);
	for (int i = 0; i < size; i++) {
		sum[i] = 0;
		for (int j = 0; j < size; j++) {
			sum[i] += matr[i][j];
		}
	}

	float res[3][3];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				res[i][j] = -sum[i];
			}
			else {
				res[i][j] = matr[j][i];
			}
		}
	}

	//нормировка
	for (int j = 0; j < size; j++) {
		res[size - 1][j] = 1;
	}

	vector<float> states(size - 1, 0);
	states.push_back(1);

	vector<float> x = gauss(res, states, size);
	for (int i = 0; i < size; i++) {
		cout << x[i] << " ";
	}
	cout << endl;

	vector<float> time(size);
	for (int i = 0; i < size; i++) {
		time[i] = (1 - x[i]) / (x[i] * sum[i]);
		cout << time[i] << " ";
	}
	cout << endl;


	return 0;
}