#include <iostream>

int dist(int a[2], int b[2]);
int main(void) {
	int point[3][2];
	for (int i = 0; i < 3; i++)
		std::cin >> point[i][0] >> point[i][1];

	int dist1 = dist(point[0], point[1]);
	int dist2 = dist(point[1], point[2]);
	int dist3 = dist(point[2], point[0]);

	int x, y;
	if (dist1 > dist2 && dist1 > dist3) {
		x = point[0][0] + point[1][0] - point[2][0];
		y = point[0][1] + point[1][1] - point[2][1];
	}
	else if (dist2 > dist1 && dist2 > dist3) {
		x = point[1][0] + point[2][0] - point[0][0];
		y = point[1][1] + point[2][1] - point[0][1];
	}
	else {
		x = point[0][0] + point[2][0] - point[1][0];
		y = point[0][1] + point[2][1] - point[1][1];
	}

	std::cout << x << ' ' << y << std::endl;
	
	return 0;
}

int dist(int a[2], int b[2]) {
	return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}