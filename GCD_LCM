#include <iostream>
#include <vector>

int gcd(int number1, int number2) { //assume number1 is greather than number2
	int gcd{ 0 };
	if (number1 == 0 && number2 != 0) {
		return number2;
	}
	if (number1 != 0 && number2 == 0) {
		return number1;
	}
	int temporary;
	while (number2 != 0) {
		temporary = number2;
		number2 = number1 % number2;
		number1 = temporary;
	}
	return number1;
}

int lcm(int number1, int number2) {
	return (number1 * number2 ) / gcd(number1, number2);
}

int main()
{
	int number1, number2;
	std::cout << "Input 2 integers:\n";
	std::cin >> number1 >> number2;
	if (number2 > number1) {
		number1 += number2;
		number2 = number1 - number2;
		number1 -= number2;
	}
	std::cout << "Greatest common divisor of " << number1 << " and "
		 << number2 << " is:   " << gcd(number1, number2) << std::endl;
	std::cout << "Least common multiple of " << number1 << " and "
		<< number2 << " is:   " << lcm(number1, number2);
}

/*
int main() {
	int size;
	int sum{ 0 };
	std::vector<int> vec;
	std::cout << "Input size of an array:\n";
	std::cin >> size; // size == n, if count starts from 1.
	std::cout << "Input elements in of the array:" << std::endl;
	int element{0};
	for (int i = 1; i <= size; i++) {
		std::cin >> element;
		vec.push_back(element);
		sum += element;
	}
	int missing_el = (1 + size+1) * (size+1) / 2 - sum;
	std::cout << "Missing element is:   " << missing_el;
}
*/

