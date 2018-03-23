#pragma once
#include <atlstr.h>
namespace FScripter {
	namespace StringControl {
		/*
		* 문자열 조작 함수들
		* --------------------------------------------------------------------------------------------------
		* Pad = 입력받은 위치에서 빈공간을 추가한다
		* PadLeft = 왼쪽으로 빈공간 채우기
		* PadRight = 오른쪽으로 빈공간 채우기
		* --------------------------------------------------------------------------------------------------
		* Cut = 문자들을 입력 위치에서 방향대로 숫자만큼 짜른다
		* CutLeft = 왼쪽의 문자들을 숫자만큼 짜른다
		* CutRight = 오른쪽의 문자들을 숫자만큼 짜른다
		* CutKeyword = 입력받은 문자를 찾아서 없애준다
		* --------------------------------------------------------------------------------------------------
		* Extract = 문자를 추출한다
		* ExtractRange = 키워드를 가지고 끝나는 포인트까지의 문자를 추출한다
		* ExtractRangeKeep = 키워드를가지고 끝나닌 포인트까지의 문자를 추출한 후 유지한다
		*/

		//함수 전방 선언들
		enum class DIRECTION;
		CString Pad(CString str, int index, int size, char spaceChar);
		CString PadLeft(CString str, int size, char spaceChar);
		CString PadRight(CString str, int size, char spaceChar);
		CString Cut(CString str, int size, int index, DIRECTION direction);
		CString CutLeft(CString str, int size);
		CString CutRight(CString str, int size);
		CString CutKeyword(CString str, CString keyword);
		CString CutKeyword(CString str, char keyword);
		CString Extract(CString *str, CString startKeyword, CString endKeyword, BOOL keywordImport, BOOL keep);
		CString ExtractRangeKeep(CString str, CString startKeyword, CString endKeyword, BOOL keywordImport);
		CString ExtractRange(CString *str, CString startKeyword, CString endKeyword, BOOL keywordImport);

		enum class DIRECTION {
			NONE,
			LEFT,
			RIGHT,
		};

#pragma region Pad시리즈
		/*
		* 빈 공간을 채워주는 함수
		* 채워줄 값과 채워질 숫자, 입력받은 위치가 들어간다.
		*/
		CString Pad(CString str, int index, int size, char spaceChar = ' ') {
			int strSize = str.GetLength();

			while (size > strSize) {
				str.Insert(index, spaceChar);
				strSize++;
			}

			return str;
		}
		/*
		* 왼쪽으로 빈 공간을 채워주는 함수
		* 채워줄 값과 채워질 숫자가 들어간다.
		*/
		CString PadLeft(CString str, int size, char spaceChar = ' ') {
			int strSize = str.GetLength();

			while (size > strSize) {
				str.Insert(0, spaceChar);
				strSize++;
			}

			return str;
		}

		/*
		* 왼쪽으로 빈 공간을 채워주는 함수
		* 채워줄 값과 채워질 숫자가 들어간다.
		*/
		CString PadRight(CString str, int size, char spaceChar = ' ') {
			int strSize = str.GetLength();

			while (size > strSize) {
				str += spaceChar;
				strSize++;
			}

			return str;
		}
#pragma endregion

#pragma region Cut시리즈
		/*
		* 입력받은 숫자만큼 입력받은 방향에서 없애주는 함수
		* 문자열, 숫자, 위치, 방향이 들어간다
		*/
		CString Cut(CString str, int size, int index, DIRECTION direction) {
			if (direction == DIRECTION::LEFT) {
				int count = 0;
				while (index >= 0 && count < size) {
					str.Delete(index);
					count++;
				}
			}
			else if (direction == DIRECTION::RIGHT) {
				int count = 0;
				int length = str.GetLength();
				while (index <= length && count < size) {
					str.Delete(index);
					count++;
				}
			}
			return str;
		}

		/*
		* 입력받은 숫자만큼 왼쪽 문자열을 없애주는 함수
		* 문자열, 숫자가 들어간다
		*/
		CString CutLeft(CString str, int size) {
			int count = 0;
			int length = str.GetLength();
			while (length > 0 && count < size) {
				str.Delete(0);
				count++;
			}

			return str;
		}

		/*
		* 입력받은 숫자만큼 오른쪽 문자열을 없애주는 함수
		* 문자열, 숫자가 들어간다
		*/
		CString CutRight(CString str, int size) {
			int count = 0;
			int length = str.GetLength();

			while (length > 0 && count < size) {

				length = str.GetLength() - 1;

				str.Delete(length);
				count++;
			}
			return str;
		}

		/*
		* 입력받은 값을 찾아서 없앤다
		* 문자열, 값이 들어간다
		*/
		CString CutKeyword(CString str, CString keyword) {
			str.Replace(keyword, "");
			return str;
		}
		CString CutKeyword(CString str, char keyword) {
			str.Remove(keyword);
			return str;
		}



#pragma endregion

#pragma region Extract시리즈
		/*
		* 입력받은 숫자만큼 입력받은 방향에서 없애주는 함수
		* 문자열, 숫자, 위치, 방향이 들어간다
		*/
		CString Extract(CString *str, CString startKeyword, CString endKeyword, BOOL keywordImport = FALSE, BOOL keep = FALSE) { //문자를 추출한다
			return CString{ "" };
		}

		/*
		*
		*
		*/
		CString ExtractRange(CString *str, CString startKeyword, CString endKeyword, BOOL keywordImport = FALSE) {// 키워드를 가지고 끝나는 포인트까지의 문자를 추출한다
			CString result = ExtractRangeKeep(*str, startKeyword, endKeyword, keywordImport);
			str->Replace(result, "");

			return result;
		}
		CString ExtractRangeKeep(CString str, CString startKeyword, CString endKeyword, BOOL keywordImport = FALSE) { // 키워드를가지고 끝나닌 포인트까지의 문자를 추출한 후 유지한다
			CString result;
			int startPosition, endPosition;

			//시작 위치를 찾는다
			startPosition = str.Find(startKeyword);

			//못찾으면 리턴
			if (startPosition == -1) return CString{ "" };

			int i = 0;
			//끝 위치를 찾되, 맨 뒤에놈을 찾는다
			endPosition = str.Find(endKeyword, i++);
			while (str.Find(endKeyword, i) != -1) {
				endPosition = str.Find(endKeyword, i);
				i = endPosition + 1;
			}
			endPosition++;

			if (!keywordImport) {

				startPosition += startKeyword.GetLength();

				endPosition--;
			}

			result = str.Mid(startPosition, endPosition - startPosition);

			return result;
		}
#pragma endregion

	}

	/*
	* !를 변수, @을 함수, #을 예약어로 봤을때
	* $Add(@'abc' , @'abb') 이것은 함수명과 인자값들을 추출하는 함수를 만들면 된다.
	* (먼저 함수의 이름은 $뒤부터 (까지만 추출을 하면 되고, 변수들은 (부터 )까지
	*
	*/
}