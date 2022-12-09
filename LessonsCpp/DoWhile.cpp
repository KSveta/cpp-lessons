#include <cmath>

inline int CalculateDoWhile(int n, double epsion, double& value_An) {
	int result_fact = 1; // �������� ���������� � �����������
	int numerator_to_exponent = -1; // ��������� � ��������� �������
	double A_previous = 0; // ���������� ��������
	double A_current = 1 - 1 / 6; // ������� ��������

	int i = 2; // ������
	do {
		// ���� ������ ��������, �� -1 ����� 1
		numerator_to_exponent = i % 2 ? -1 : 1;

		// ����������� ������ �������� ����������
		int value_fact = 2 * i + 1; // �����������
		result_fact *= value_fact - 1;
		result_fact *= value_fact;

		// �������� �� ������� ������ �� �����
		if (std::abs(A_current - A_previous) < epsion) {
			value_An = A_current;
			return i;
		}

		// ���������� ����������
		A_previous = A_current;
		A_current = 1 + numerator_to_exponent / static_cast<double>(result_fact);
		++i;
	} while (i <= n);
	return -1; // ��� ������, ���� �� ��� ������ ������ �������
}