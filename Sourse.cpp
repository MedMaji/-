Sourse.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include "Sourse.h"

using namespace std;

template <typename T>
enable_if_t<is_arithmetic_v<T>, vector<uint8_t>> to_digits(const vector<T>& numbers)
{
	vector<uint8_t> digits;
	digits.reserve(numbers.size() * numeric_limits<T>::digits10);
	for_each(numbers.begin(), numbers.end(), [&digits](auto n) {
		uint8_t d[numeric_limits<T>::digits10];
		if (n < 0) n = -n;
		uint8_t l = n != 0 ? 0 : (d[0] = 0, 1);
		for (; n; n /= 10, ++l) d[l] = n % 10;
		do digits.push_back(d[l - 1]); while (--l);
		});
	return digits;
}

int main() {
	vector<int> v{ 1, 2, 6, 7, 9, 0 };
	cout << "Original vector: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	auto v_digits = to_digits(v);
	cout << "Modified vector: ";
	transform(v.begin(), v.end(), v.begin(), [](int x) {return x + 10; }); // n = 10
	for (auto e : v)
	{
		cout << e << " ";	
	}
    cout << endl;
	return 0;
}
