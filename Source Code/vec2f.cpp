#include "vec2f.h"

vec2f::vec2f() {
	x = 0;
	y = 0;
}

#ifdef USE_SSE 
vec2f::vec2f(__m128 Vec) {
	SimdReals = Vec;
}
#else
vec2f::vec2f(float x, float y) {
	this->x = x;
	this->y = y;
}
#endif

float vec2f::length() const {
#ifdef USE_SSE
	return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(SimdReals, SimdReals, 0x71)));
#else
	return sqrt(x * x + y * y);
#endif
}

void vec2f::normalize() {
	float length = this->length();

	if (length != 0) {
		x = x / length;
		y = y / length;
	}
}

float vec2f::dot(const vec2f& other) {
	return (x * other.x) + (y * other.y);
}

vec2f& vec2f::add(const vec2f& other) {
	x += other.x;
	y += other.y;

	return *this;
}

vec2f& vec2f::subtract(const vec2f& other) {
	x -= other.x;
	y -= other.y;

	return *this;
}

vec2f& vec2f::multiply(const vec2f& other) {
	x *= other.x;
	y *= other.y;

	return *this;
}

vec2f& vec2f::divide(const vec2f& other) {
	x /= other.x;
	y /= other.y;

	return *this;
}

vec2f operator+(vec2f left, const vec2f& right) {
	left.add(right);
	return left;
}

vec2f operator-(vec2f left, const vec2f& right) {
	left.subtract(right);
	return left;
}

vec2f operator*(vec2f left, const vec2f& right) {
	left.multiply(right);
	return left;
}

vec2f operator/(vec2f left, const vec2f& right) {
	left.divide(right);
	return left;
}

//float operations
vec2f& vec2f::operator+=(const float other) {
	x += other;
	y += other;

	return vec2f(x, y);
}

vec2f& vec2f::operator-=(const float other) {
	x -= other;
	y -= other;

	return vec2f(x, y);
}

vec2f& vec2f::operator*=(const float other) {
	x *= other;
	y *= other;

	return vec2f(x, y);
}

vec2f& vec2f::operator/=(const float other) {
	x /= other;
	y /= other;

	return vec2f(x, y);
}

//vec2f operations
vec2f& vec2f::operator+=(const vec2f& other) {
	return add(other);
}

vec2f& vec2f::operator-=(const vec2f& other) {
	return subtract(other);
}

vec2f& vec2f::operator*=(const vec2f& other) {
	return multiply(other);
}

vec2f& vec2f::operator/=(const vec2f& other) {
	return divide(other);
}

bool vec2f::operator==(const vec2f& other) {
	return x == other.x && y == other.y;
}

bool vec2f::operator!=(const vec2f& other) {
	return !(*this == other);
}

bool vec2f::operator<(const vec2f& other) {
	return (length() > other.length());
}

bool vec2f::operator>(const vec2f& other) {
	return !(*this > other);
}

std::ostream& operator<<(std::ostream& stream, const vec2f& vector) {
	stream << "(" << vector.x << ", " << vector.y << ")";
	return stream;
}