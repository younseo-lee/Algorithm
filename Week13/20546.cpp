#include <iostream>
using namespace std;

int main(void) {
	int money;
	cin >> money;

	int stock[14] = { 0, };
	for (int i = 0; i < 14; i++) cin >> stock[i];

	// ÁØÇö
	int left_money = money, stock_num = 0;
	for (int i = 0; i < 14; i++) {
		int buy = left_money / stock[i];
		left_money -= buy * stock[i];
		stock_num += buy;
	}
	int jun_profit = left_money + stock_num * stock[13];

	// ¼º¹Î
	left_money = money; stock_num = 0;
	int change = 0;
	for (int i = 1; i < 14; i++) {
		if (stock[i] - stock[i - 1] > 0) {
			if (change > 0) {
				change++;
				if (change >= 3) {
					left_money += stock_num * stock[i];
					stock_num = 0;
				}
			}
			else change = 1;
		}
		else if (stock[i] - stock[i - 1] < 0) {
			if (change < 0) {
				change--;
				if (change <= -3) {
					int buy = left_money / stock[i];
					left_money -= buy * stock[i];
					stock_num += buy;
				}
			}
			else change = -1;
		}
		else change = 0;
	}
	int sung_profit = left_money + stock_num * stock[13];

	if (jun_profit > sung_profit) cout << "BNP";
	else if (jun_profit < sung_profit) cout << "TIMING";
	else cout << "SAMESAME";

	return 0;
}