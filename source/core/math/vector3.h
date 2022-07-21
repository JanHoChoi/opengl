#pragma once

#include <cmath>

namespace LearnOpenGL
{
	class Vector3
	{
	public:
		float x = 0.f;
		float y = 0.f;
		float z = 0.f;

		// 默认构造函数
		Vector3() {}
		// 复制构造函数
		Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}
		// 带参数的构造函数
		Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

		// 返回自身的引用，方便连续赋值
		Vector3& operator=(const Vector3& a) {
			x = a.x;
			y = a.y;
			z = a.z;
			return *this;
		}

		bool operator==(const Vector3& a) const {
			return x == a.x && y == a.y && z == a.z;
		}

		bool operator!=(const Vector3& a) const {
			return x != a.x || y != a.y || z != a.z;
		}

		// 重载一元的"-"运算符，用于取负向量
		Vector3 operator-() const {
			return Vector3(-x, -y, -z);
		}

		// 重载二元的运算符"+"
		Vector3 operator+(const Vector3& a) const {
			return Vector3(x + a.x, y + a.y, z + a.z);
		}

		// 重载二元的运算符"-"
		Vector3 operator-(const Vector3& a) const {
			return Vector3(x - a.x, y - a.y, z - a.z);
		}

		// 标量乘法、标量除法
		Vector3 operator*(const float& a) {
			return Vector3(x * a, y * a, z * a);
		}

		Vector3 operator/(const float& a) {
			float oneDivideA = 1.0f / a;	// 不判断除0，让系统做
			return Vector3(x * oneDivideA, y * oneDivideA, z * oneDivideA);
		}

		// 重载自反运算符
		Vector3& operator+=(const Vector3& a) {
			x += a.x;
			y += a.y;
			z += a.z;
			return *this;
		}

		Vector3& operator-=(const Vector3& a) {
			x -= a.x;
			y -= a.y;
			z -= a.z;
			return *this;
		}

		Vector3& operator*=(const float& a) {
			x *= a;
			y *= a;
			z *= a;
			return *this;
		}

		Vector3& operator/=(const float& a) {
			float oneDivideA = 1.0f / a;
			x *= oneDivideA;
			y *= oneDivideA;
			z *= oneDivideA;
			return *this;
		}

		// 置为零向量
		void zero() {
			x = y = z = 0.0f;
		}

		// 向量标准化
		void normalize(void) {
			float magnitudeSq = x * x + y * y + z * z;
			if (magnitudeSq > 0.0f) {
				float oneDivideMag = 1.0f / std::sqrt(magnitudeSq);
				x *= oneDivideMag;
				y *= oneDivideMag;
				z *= oneDivideMag;
			}
		}

		// 向量点乘
		float operator*(const Vector3& a) const {
			return x * a.x + y * a.y + z * a.z;
		}

		inline float magnitude() {
			return std::sqrt(x * x + y * y + z * z);
		}

		inline Vector3 crossProduct(const Vector3& a) const {
			return Vector3(
				y * a.z - z * a.y,
				z * a.x - x * a.z,
				x * a.y - y * a.x
			);
		}

		inline float distance(const Vector3& a) {
			return (*this - a).magnitude();
		}

		static const Vector3 ZERO;
	};
}
