#include <iostream>

using namespace std;

int main() {
	int a = 23;
	
	printf("%d\n", a--);
	printf("%f\n", (double)a--);
	printf("%d\n", sizeof(a));
	printf("%f\n", a--);
	
	return 0;
}
 
