#pragma once
#include <AtlStr.h>
/*
* 자료형의 범위 : Int, Unsignde Int, Long(64빗), Double(실수), String(문자열)
* DataV2, CString, int, Long, ULong, double
*/
namespace FScripter {
	class Data {
		typedef long long Long;
		typedef unsigned long ULong;
	public:
#pragma region 생성자들
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

#pragma region 대입연산자들
		/*IsEqual(cons)*/
#pragma endregion

	private:
#pragma region data를 바꿔주는 연산들
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