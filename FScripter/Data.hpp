#pragma once
#include <AtlStr.h>
/*
* 자료형의 범위 : Int, Unsignde Int, Long(64빗), Double(실수), String(문자열)
* DataV2, CString, int, Long, ULong, double
*/
namespace Data {
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
		​
#pragma region 대입연산자들
			​
			Data& operator=(const Data& value) { return Operate(value); };
		Data& operator=(const CString& value) { return Operate(value); };
		Data& operator=(const int& value) { return Operate(value); };
		Data& operator=(const Long& value) { return Operate(value); };
		Data& operator=(const ULong& value) { return Operate(value); };
		Data& operator=(const double& value) { return Operate(value); };
		​
#pragma endregion
			​
#pragma region ==연산자
			BOOL operator==(const Data& other) const { return IsEqual(other); };
		BOOL operator!=(const Data& other) const { return IsNotEqual(other); };
		BOOL operator==(const CString& other) const { return IsEqual(other); };
		BOOL operator!=(const CString& other) const { return IsNotEqual(other); };
		BOOL operator==(const int& other) const { return IsEqual(other); };
		BOOL operator!=(const int& other) const { return IsNotEqual(other); };
		BOOL operator==(const Long& other) const { return IsEqual(other); };
		BOOL operator!=(const Long& other) const { return IsNotEqual(other); };
		BOOL operator==(const ULong& other) const { return IsEqual(other); };
		BOOL operator!=(const ULong& other) const { return IsNotEqual(other); };
		BOOL operator==(const double& other) const { return IsEqual(other); };
		BOOL operator!=(const double& other) const { return IsNotEqual(other); };
#pragma endregion
		​
#pragma region 대소비교 연산자
			​
			bool operator<(const Data& other) const { return data < other.data; };
		bool operator<=(const Data& other) const { return data <= other.data; };
		bool operator>(const Data& other) const { return data > other.data; };
		bool operator>=(const Data& other) const { return data >= other.data; };
		​
#pragma endregion
			​
#pragma region 형변환 연산자
			operator const CString&() const { return data; };
		operator const int() const { return _ttoi(data); };
		operator const Long() const { return (Long)_ttoi64(data); };
		operator const ULong() const { return (ULong)_ttoi64(data); };
		operator const double() const { return _ttof(data); };
#pragma endregion 
		​
	private:
#pragma region data를 바꿔주는 연산들
		Data() {};
		Data& Operate(const Data& value) {
			data = value.data;
			​
				return *this;
		};
		Data& Operate(const CString& value) {
			data = value;
			​
				return *this;
		};
		Data& Operate(const int& value) {
			data.Format("%d", value);
			​
				return *this;
		}
		Data& Operate(const Long& value) {
			data.Format("%lld", value);
			​
				return *this;
		};
		Data& Operate(const ULong& value) {
			data.Format("%u", value);
			​
				return *this;
		}
		​
			Data& Operate(const double& value) {
			data.Format("%lf", value);
			​
				return *this;
		}
#pragma endregion
#pragma region 같은지 비교하는 연산자들
		BOOL IsEqual(const Data& other) const { return data == other.data; };
		BOOL IsNotEqual(const Data& other) const { return data != other.data; };
		BOOL IsEqual(const CString& other) const { return data == other; };
		BOOL IsNotEqual(const CString& other) const { return data != other; };
		BOOL IsEqual(const int& other) const { return data == Data(other).data; };
		BOOL IsNotEqual(const int& other) const { return data != Data(other).data; };
		BOOL IsEqual(const Long& other) const { return data == Data(other).data; };
		BOOL IsNotEqual(const Long& other) const { return data != Data(other).data; };
		BOOL IsEqual(const ULong& other) const { return data == Data(other).data; };
		BOOL IsNotEqual(const ULong& other) const { return data != Data(other).data; };
		BOOL IsEqual(const double& other) const { return data == Data(other).data; };
		BOOL IsNotEqual(const double& other) const { return data != Data(other).data; };
#pragma endregion
		​
		CString data;
	};
};