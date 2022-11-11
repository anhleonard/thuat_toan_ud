#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

int n;
int M[MAX][MAX];
int A[MAX];

int I[MAX];
int J[MAX];

int m;

void input() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> I[i] >> J[i];
 	}
}

void initM() {
	for(int j = 0; (1<<j) < n; j++) {
		for(int i = 0; i < n; i++) {
			M[j][i] = -1;
		}
	}
}

void preprocessing() { // tao bang gom 0 -> j cot va 0 -> i hang
	
	for(int i = 0; i < n; i++) {
		M[0][i] = i;
	}
	
	for(int j = 1; (1 << j) <= n; j++) {
		for(int i = 0; (i + (1 << j) -1) < n; i++) {
			if(A[M[j-1][i]] < A[M[j-1][i + (1 << (j-1))]]) {
				M[j][i] = M[j-1][i];
			}
			else {
				M[j][i] = M[j-1][i + (1 << (j-1))];
			}
		}
	}
}

int log2(int x) {
	int result;
		for(int i = 0; (1 << i) <= x ; i++) {
			result = i;
			}
	return result;
}

int rmq(int i, int j) {
	int k = log2(j-i+1);
	int p2k = pow(2,k);
	if(A[M[k][i]] < A[M[k][j-p2k+1]]) {
		return A[M[k][i]];
	}
	else return A[M[k][j-p2k+1]];
}

int solve() {
	preprocessing();
	int sum = 0;
	for(int i = 0; i < m; i++) {
		sum = sum + rmq(I[i], J[i]);
	}
	return sum;
}

int main() {
	input();
	initM();
	cout << "===========" << endl;
	cout << solve();
	cout << "Anh is very beautiful";
}
