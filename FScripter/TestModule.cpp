#include "StringControl.hpp"
#include "Data.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	CString test = "ParsingStart;!Add(!Add(@'number1',@'number2'),@'number2')";


	printf("원본 : %s\r\n\r\n", test);

	CString result = FScripter::StringControl::ExtractRange(&test, "!Add(", ")", TRUE);

	printf("추출 후 원본 : %s\r\n\r\n추출 값 : %s\r\n", test, result);
	//여기까지 완료
	//이그노어까지 했는데 쉬불?
	return 0;
}