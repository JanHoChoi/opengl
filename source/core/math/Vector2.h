#pragma once

#include <cmath>

namespace LearnOpenGL
{
	class Vector2
	{
	public:
		float x = 0.f;
		float y = 0.f;

		// Ĭ�Ϲ��캯��
		Vector2() {}
		// ���ƹ��캯��
		Vector2(const Vector2& a) : x(a.x), y(a.y) {}
		// �������Ĺ��캯��
		Vector2(float _x, float _y) : x(_x), y(_y) {}

		// ������������ã�����������ֵ
		Vector2& operator=(const Vector2& a) {
			x = a.x;
			y = a.y;
			return *this;
		}

		bool operator==(const Vector2& a) const {
			return x == a.x && y == a.y;
		}

		bool operator!=(const Vector2& a) const {
			return x != a.x || y != a.y;
		}

		// ����һԪ��"-"�����������ȡ������
		Vector2 operator-() const {
			return Vector2(-x, -y);
		}

		// ���ض�Ԫ�������"+"
		Vector2 operator+(const Vector2& a) const {
			return Vector2(x + a.x, y + a.y);
		}

		// ���ض�Ԫ�������"-"
		Vector2 operator-(const Vector2& a) const {
			return Vector2(x - a.x, y - a.y);
		}

		// �����˷�����������
		Vector2 operator*(const float& a) {
			return Vector2(x * a, y * a);
		}

		Vector2 operator/(const float& a) {
			float oneDivideA = 1.0f / a;	// ���жϳ�0����ϵͳ��
			return Vector2(x * oneDivideA, y * oneDivideA);
		}

		// �����Է������
		Vector2& operator+=(const Vector2& a) {
			x += a.x;
			y += a.y;
			return *this;
		}

		Vector2& operator-=(const Vector2& a) {
			x -= a.x;
			y -= a.y;
			return *this;
		}

		Vector2& operator*=(const float& a) {
			x *= a;
			y *= a;
			return *this;
		}

		Vector2& operator/=(const float& a) {
			float oneDivideA = 1.0f / a;
			x *= oneDivideA;
			y *= oneDivideA;
			return *this;
		}

		// ��Ϊ������
		void zero() {
			x = y = 0.0f;
		}

		// ������׼��
		void normalize(void) {
			float magnitudeSq = x * x + y * y;
			if (magnitudeSq > 0.0f) {
				float oneDivideMag = 1.0f / std::sqrt(magnitudeSq);
				x *= oneDivideMag;
				y *= oneDivideMag;
			}
		}

		// �������
		float operator*(const Vector2& a) const {
			return x * a.x + y * a.y;
		}

		inline float magnitude() {
			return std::sqrt(x * x + y * y);
		}

		inline float crossProduct(const Vector2& a) const {
			return x * a.y - y * a.x;
		}

		inline float distance(const Vector2& a) {
			return (*this - a).magnitude();
		}

		static const Vector2 ZERO;
	};
}
