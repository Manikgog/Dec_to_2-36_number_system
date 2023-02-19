#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

// ������� ��� �������������� ����� � ������
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


// ������� ����������� ������� �� ���������� ������� ��������� � ������� �� 2-��� �� 36-����
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
	SetConsoleCP(1251); // ��������� ������� �������� �� ���� ������
	srand(time(NULL));
	int n, m;
	std::cout << "������� ����� -> ";
	std::cin >> n;
	std::cout << "������� ��������� ������� ��������� -> ";
	std::cin >> m;
	Dec_to_another_num_sys(n, m);
	


	return 0;
}
