#pragma once
#include <atlstr.h>
namespace FScripter {
	namespace StringControl {
		/*
		* ���ڿ� ���� �Լ���
		* --------------------------------------------------------------------------------------------------
		* Pad = �Է¹��� ��ġ���� ������� �߰��Ѵ�
		* PadLeft = �������� ����� ä���
		* PadRight = ���������� ����� ä���
		* --------------------------------------------------------------------------------------------------
		* Cut = ���ڵ��� �Է� ��ġ���� ������ ���ڸ�ŭ ¥����
		* CutLeft = ������ ���ڵ��� ���ڸ�ŭ ¥����
		* CutRight = �������� ���ڵ��� ���ڸ�ŭ ¥����
		* CutKeyword = �Է¹��� ���ڸ� ã�Ƽ� �����ش�
		* --------------------------------------------------------------------------------------------------
		* Extract = ���ڸ� �����Ѵ�
		* ExtractRange = Ű���带 ������ ������ ����Ʈ������ ���ڸ� �����Ѵ�
		* ExtractRangeKeep = Ű���带������ ������ ����Ʈ������ ���ڸ� ������ �� �����Ѵ�
		*/

		//�Լ� ���� �����
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

#pragma region Pad�ø���
		/*
		* �� ������ ä���ִ� �Լ�
		* ä���� ���� ä���� ����, �Է¹��� ��ġ�� ����.
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
		* �������� �� ������ ä���ִ� �Լ�
		* ä���� ���� ä���� ���ڰ� ����.
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
		* �������� �� ������ ä���ִ� �Լ�
		* ä���� ���� ä���� ���ڰ� ����.
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

#pragma region Cut�ø���
		/*
		* �Է¹��� ���ڸ�ŭ �Է¹��� ���⿡�� �����ִ� �Լ�
		* ���ڿ�, ����, ��ġ, ������ ����
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
		* �Է¹��� ���ڸ�ŭ ���� ���ڿ��� �����ִ� �Լ�
		* ���ڿ�, ���ڰ� ����
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
		* �Է¹��� ���ڸ�ŭ ������ ���ڿ��� �����ִ� �Լ�
		* ���ڿ�, ���ڰ� ����
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
		* �Է¹��� ���� ã�Ƽ� ���ش�
		* ���ڿ�, ���� ����
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

#pragma region Extract�ø���
		/*
		* �Է¹��� ���ڸ�ŭ �Է¹��� ���⿡�� �����ִ� �Լ�
		* ���ڿ�, ����, ��ġ, ������ ����
		*/
		CString Extract(CString *str, CString startKeyword, CString endKeyword, BOOL keywordImport = FALSE, BOOL keep = FALSE) { //���ڸ� �����Ѵ�
			return CString{ "" };
		}

		/*
		*
		*
		*/
		CString ExtractRange(CString *str, CString startKeyword, CString endKeyword, BOOL keywordImport = FALSE) {// Ű���带 ������ ������ ����Ʈ������ ���ڸ� �����Ѵ�
			CString result = ExtractRangeKeep(*str, startKeyword, endKeyword, keywordImport);
			str->Replace(result, "");

			return result;
		}
		CString ExtractRangeKeep(CString str, CString startKeyword, CString endKeyword, BOOL keywordImport = FALSE) { // Ű���带������ ������ ����Ʈ������ ���ڸ� ������ �� �����Ѵ�
			CString result;
			int startPosition, endPosition;

			//���� ��ġ�� ã�´�
			startPosition = str.Find(startKeyword);

			//��ã���� ����
			if (startPosition == -1) return CString{ "" };

			int i = 0;
			//�� ��ġ�� ã��, �� �ڿ����� ã�´�
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
	* !�� ����, @�� �Լ�, #�� ������ ������
	* $Add(@'abc' , @'abb') �̰��� �Լ���� ���ڰ����� �����ϴ� �Լ��� ����� �ȴ�.
	* (���� �Լ��� �̸��� $�ں��� (������ ������ �ϸ� �ǰ�, �������� (���� )����
	*
	*/
}