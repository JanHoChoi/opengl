#pragma once

#include <cmath>

namespace LearnOpenGL
{
	class Vector2
	{
	public:
		float x = 0.f;
		float y = 0.f;

		// 默认构造函数
		Vector2() {}
		// 复制构造函数
		Vector2(const Vector2& a) : x(a.x), y(a.y) {}
		// 带参数的构造函数
		Vector2(float _x, float _y) : x(_x), y(_y) {}

		// 返回自身的引用，方便连续赋值
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

		// 重载一元的"-"运算符，用于取负向量
		Vector2 operator-() const {
			return Vector2(-x, -y);
		}

		// 重载二元的运算符"+"
		Vector2 operator+(const Vector2& a) const {
			return Vector2(x + a.x, y + a.y);
		}

		// 重载二元的运算符"-"
		Vector2 operator-(const Vector2& a) const {
			return Vector2(x - a.x, y - a.y);
		}

		// 标量乘法、标量除法
		Vector2 operator*(const float& a) {
			return Vector2(x * a, y * a);
		}

		Vector2 operator/(const float& a) {
			float oneDivideA = 1.0f / a;	// 不判断除0，让系统做
			return Vector2(x * oneDivideA, y * oneDivideA);
		}

		// 重载自反运算符
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

		// 置为零向量
		void zero() {
			x = y = 0.0f;
		}

		// 向量标准化
		void normalize(void) {
			float magnitudeSq = x * x + y * y;
			if (magnitudeSq > 0.0f) {
				float oneDivideMag = 1.0f / std::sqrt(magnitudeSq);
				x *= oneDivideMag;
				y *= oneDivideMag;
			}
		}

		// 向量点乘
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
