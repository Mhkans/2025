#pragma once
class Vector
{
public:
	Vector() : x(0.0f), y(0.0f) {}
	Vector(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	~Vector() {}

	Vector operator+(const Vector& other) const
	{
		Vector result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;

		return Vector(this->x + other.x, this->y + other.y);
	}
	Vector operator-(const Vector& other) const
	{
		Vector result;
		result.x = x - other.x;
		result.y = y - other.y;

		return result;
	}
	Vector operator*(float value) const
	{
		Vector result;
		result.x = this->x * value;
		result.y = this->y * value;

		return result;
	}
	Vector& operator=(const Vector& other)
	{
		this->x = other.x;
		this->y = other.y;

		return *this;
	}
	Vector& operator+=(const Vector& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}
	Vector& operator-=(const Vector& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	float Length() const
	{
		return sqrtf(this->x * this->x + this->y * this->y);
	}
	void Noraml()
	{
		float length = Length();
		x /= length;
		y /= length;
	}

	Vector Nomalize() const
	{
		Vector result = *this;
		result.Noraml();
		return result;
	}

	float Dot(const Vector& other) const
	{
		return x * other.x + y * other.y;
	}
	float Cross(const Vector& other) const
	{
		return x * other.y - y * other.x;
	}

	bool IsBetween(const Vector& v1, const Vector& v2)
	{
		float cross1 = this->Cross(v1);
		float cross2 = this->Cross(v2);

		return cross1 * cross2 < 0;
	}
	void Rotate(float angle) {

		x = x * cosf(angle) - y * sinf(angle);
		y = x * sinf(angle) + y * cosf(angle);
	}
	bool operator==(const Vector& other) const {
		if (x == other.x && y == other.y) {
			return true;
		}
		return false;
	}
	bool operator!=(const Vector& other) const {
		return !this->operator==(other);
	}
	float Manhattan_distance(Vector pos) {
		Vector temp = pos - *this;
		return abs(temp.x) + abs(temp.y);
	}
	float x;
	float y;
};