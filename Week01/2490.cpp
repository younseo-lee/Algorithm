#include <iostream>

int main(void) {
	int a[4];
	char result[3];

	for (int i = 0; i < 3; i++) {
		std::cin >> a[0] >> a[1] >> a[2] >> a[3];
		int sum = a[0] + a[1] + a[2] + a[3];

		switch (sum) {
		case 0:
			result[i] = 'D';
			break;
		case 1:
			result[i] = 'C';
			break;
		case 2:
			result[i] = 'B';
			break;
		case 3: 
			result[i] = 'A';			
			break;
		case 4: 
			result[i] = 'E';
			break;
		}
	}
	for (int i = 0; i < 3; i++) std::cout << result[i] << std::endl;
	return 0;
}