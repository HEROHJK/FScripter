#include "StringControl.hpp"
#include "Data.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	CString test = "ParsingStart;!Add(!Add(@'number1',@'number2'),@'number2')";


	printf("원본 : %s\r\n\r\n", test);

	CString result = FScripter::StringControl::ExtractRange(&test, "!Add(", ")", TRUE);

	printf("추출 후 원본 : %s\r\n\r\n추출 값 : %s\r\n", test, result);

	return 0;
}