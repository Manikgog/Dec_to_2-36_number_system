#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

// функци€ дл€ преобразовани€ числа в символ
char number_to_symbol(int n) {
	char s;
	if(n >= 0 && n <= 9){
		s = 48 + n;
	}
	else if (n >= 10 && n <= 36) {
		s = 65 - 10 + n;
	}


	return s;
}


// функци€ выполн€юща€ перевод из дес€тичной системы счислени€ в систему от 2-ной до 36-чной
void Dec_to_another_num_sys(int N, int M) {
	char arr[100]{};
	int ost;
	int i = 0;
	while(N > 0) {
		ost = N;
		ost %= M;
		
		arr[i] = number_to_symbol(ost);
		
		N /= M;
		i++;
	}
	i--;
	for (i; i >= 0; --i) {
		std::cout << arr[i];
	}
	std::cout << '\n';
}


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));
	int n, m;
	std::cout << "¬ведите число -> ";
	std::cin >> n;
	std::cout << "¬ведите основание системы счислени€ -> ";
	std::cin >> m;
	Dec_to_another_num_sys(n, m);
	


	return 0;
}
