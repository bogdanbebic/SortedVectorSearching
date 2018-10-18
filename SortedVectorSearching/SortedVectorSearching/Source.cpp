#include <iostream>
#include <vector>

std::vector<int> generate_binomial_coefficents(int n) {
	std::vector<int> vec;
	int binomial_coef = 1;
	vec.push_back(binomial_coef);
	for (int i = 1; i < 1 + n / 2; i++) {
		binomial_coef *= n - i + 1;
		binomial_coef /= i;
		vec.push_back(binomial_coef);
	}
	return vec;
}

void output_vector_to_cout(std::vector<int> a) {
	for (int elem : a) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

int main() {
	bool is_running = true;
	int menu_option;
	int n, key;

	std::cout << "Hello, World!" << std::endl;

	for (int i = 0; i < 10; i++) {
		const std::vector<int> a = generate_binomial_coefficents(i);
		output_vector_to_cout(a);
	}

	while (is_running) {
		std::cout << "1. Input n for binomial coefficent generation" << std::endl;
		std::cout << "2. Input key for search" << std::endl;
		std::cout << "3. Run simulation" << std::endl;
		std::cout << "0. Exit program" << std::endl;

		std::cin >> menu_option;

		switch (menu_option) {
		case 1:
			std::cout << "Input n: ";
			std::cin >> n;
			break;
		case 2:
			std::cout << "Input key for search: ";
			std::cin >> key;
			break;
		case 3:
			if (n >= 0) {
				const std::vector<int> a = generate_binomial_coefficents(n);
				std::cout << "Generated vector for n = " << n << " is:" << std::endl;
				output_vector_to_cout(a);
				// TODO: implement ternary and interpolation searching
				
			}
			break;
		case 0:
			is_running = false;
			break;
		default: 
			break;
		}
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}
