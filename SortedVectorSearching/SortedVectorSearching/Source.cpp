#include <iostream>
#include <vector>

struct SearchResult {
	bool is_succesful;
	int number_of_iterations;
	SearchResult();
};

SearchResult::SearchResult() {
	is_succesful = false;
	number_of_iterations = 0;
}

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

SearchResult ternary_search(std::vector<int> a, int key) {
	SearchResult res;
	int low = 0, high = a.size() - 1;
	while (low <= high) {
		res.number_of_iterations++;
		const int first_third = low + (high - low) / 3;
		const int second_third = low + 2 * (high - low) / 3;
		if (key == a[first_third] || key == a[second_third]) {
			res.is_succesful = true;
			break;
		}
		if (key < a[first_third]) {
			high = first_third - 1;
		}
		else if (key > a[second_third]) {
			low = second_third + 1;
		}
		else {
			low = first_third + 1;
			high = second_third - 1;
		}
	}
	return res;
}

SearchResult interpolation_search(std::vector<int> a, int key) {
	SearchResult res;
	int low = 0, high = a.size() - 1;
	while (low <= high) {
		res.number_of_iterations++;
		const int search_index = low + (high - low) * (key - a[low]) / (a[high] - a[low]);
		if (key < a[low] || key > a[high]) {
			break;
		}
		if (key == a[search_index]) {
			res.is_succesful = true;
			break;
		}
		if (key < a[search_index]) {
			high = search_index - 1;
		}
		else {
			low = search_index + 1;
		}
	}
	return res;
}

SearchResult hybrid_search(std::vector<int> a, int key) {
	SearchResult res;
	// TODO: implementation
	return res;
}

int main() {
	bool is_running = true;
	int menu_option;
	int n = 0, key = 0;

	std::cout << "Hello, World!" << std::endl;

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
				std::cout << "Searching for key " << key << std::endl;
				const SearchResult ternary_result = ternary_search(a, key);
				std::cout << "Ternary search " << ternary_result.is_succesful << " with " << ternary_result.number_of_iterations << " iterations" << std::endl;
				const SearchResult interpolation_result = interpolation_search(a, key);
				std::cout << "Interpolation search " << interpolation_result.is_succesful << " with " << interpolation_result.number_of_iterations << " iterations" << std::endl;
				const SearchResult hybrid_result = hybrid_search(a, key);	// TODO: implement hybrid search
				std::cout << "Hybrid search " << hybrid_result.is_succesful << " with " << hybrid_result.number_of_iterations << " iterations" << std::endl;
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
