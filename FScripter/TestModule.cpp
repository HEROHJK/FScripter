#include "StringControl.hpp"
#include "Data.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	CString test = "ParsingStart;!Add(!Add(@'number1',@'number2'),@'number2')";


	printf("���� : %s\r\n\r\n", test);

	CString result = FScripter::StringControl::ExtractRange(&test, "!Add(", ")", TRUE);

	printf("���� �� ���� : %s\r\n\r\n���� �� : %s\r\n", test, result);
	//������� �Ϸ�
	//�̱׳����� �ߴµ� ����?
	return 0;
}