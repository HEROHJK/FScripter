#pragma once
#include <AtlStr.h>
/*
* �ڷ����� ���� : Int, Unsignde Int, Long(64��), Double(�Ǽ�), String(���ڿ�)
* DataV2, CString, int, Long, ULong, double
*/
namespace FScripter {
	class Data {
		typedef long long Long;
		typedef unsigned long ULong;
	public:
#pragma region �����ڵ�
		Data(const Data& value) {
			Operate(value);
		}
		Data(const CString& value) {
			Operate(value);
		}
		Data(const int& value) {
			Operate(value);
		}
		Data(const ULong& value) {
			Operate(value);
		}
		Data(const Long& value) {
			Operate(value);
		}
		Data(const double& value) {
			Operate(value);
		}
#pragma endregion

#pragma region ���Կ����ڵ�
		/*IsEqual(cons)*/
#pragma endregion

	private:
#pragma region data�� �ٲ��ִ� �����
		Data() {};
		Data& Operate(const Data& value) {
			data = value.data;

			return *this;
		};
		Data& Operate(const CString& value) {
			data = value;

			return *this;
		};
		Data& Operate(const int& value) {
			data.Format("%d", value);

			return *this;
		}
		Data& Operate(const Long& value) {
			data.Format("%lld", value);

			return *this;
		};
		Data& Operate(const ULong& value) {
			data.Format("%u", value);

			return *this;
		}

		Data& Operate(const double& value) {
			data.Format("%lf", value);

			return *this;
		}
#pragma endregion

		CString data;
	};
}