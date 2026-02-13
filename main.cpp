#include <iostream>
#include <string>

using namespace std;

string to_two_digits(int i) {
	if (i < 10) {
		return "0" + to_string(i);
	}
	else {
		return to_string(i);
	}
}

bool is_prime(string str_mmdd) {
	int mmdd = stoi(str_mmdd);
	if (mmdd < 2) return false;

	for (int i = 2; i < mmdd; i++) {
		if (mmdd / i * i == mmdd) return false; // int / intは切り捨てだから、割り切れたら約数ってことになる！
	}

	return true;
}

int main() {
	string max_days = "121010110101"; // 0が30日、1が31日、2が29日まで！
	int result = 0;

	for (int i = 0; i < max_days.length(); i++) {
		int month = i + 1;
		string str_month = to_two_digits(month);

		int max_day;
		if (max_days[i] == '0') max_day = 30;
		if (max_days[i] == '1') max_day = 31;
		if (max_days[i] == '2') max_day = 29;

		for (int j = 0; j < max_day; j++) {
			int day = j + 1;
			string str_day = to_two_digits(day);

			if (is_prime(str_month + str_day)) {
				result++;

				cout << result << ": " << str_month << "/" << str_day << endl;
			}
		}
	}

	cout << "result: " << result << endl;
}