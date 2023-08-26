#include<bits/stdc++.h>
using namespace std;

string convertToTitle(int n) {
	if(n < 27) {
		return string(1,'A' + (n-1)%26);
	}

	string s = "";

	while(n > 0) {
		if(n % 26 == 0) {
			s = char('A' + 25) + s;
			n = n-1;
		}
		else {
			s = char('A' + (n%26) - 1) + s;
		}

		n /= 26;
	}

	return s;
}

int main() {
	int n;
	cin>>n;
	cout<<convertToTitle(n);
}