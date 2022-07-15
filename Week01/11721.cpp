#include <iostream>
#include <string.h>

int main(void) {
	char word[100];
	std::cin >> word;

	for (int i = 0; i < strlen(word); i++) {
		if (i > 0 && i % 10 == 0) std::cout << std::endl;
		std::cout << word[i];
	}
	return 0;
}