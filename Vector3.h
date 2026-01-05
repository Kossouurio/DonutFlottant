#pragma once
#include <cmath>

struct Vector3
{
    float x = 0.f;
    float y = 0.f;
    float z = 0.f;

    Vector3() = default;
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    // Operators
    Vector3 operator+(const Vector3& other) const { return Vector3(x + other.x, y + other.y, z + other.z); }
    Vector3 operator-(const Vector3& other) const { return Vector3(x - other.x, y - other.y, z - other.z); }
    Vector3 operator*(float scalar) const { return Vector3(x * scalar, y * scalar, z * scalar); }
    Vector3 operator/(float scalar) const { return Vector3(x / scalar, y / scalar, z / scalar); }

    Vector3& operator+=(const Vector3& other) { x += other.x; y += other.y; z += other.z; return *this; }
    Vector3& operator-=(const Vector3& other) { x -= other.x; y -= other.y; z -= other.z; return *this; }
    Vector3& operator*=(float scalar) { x *= scalar; y *= scalar; z *= scalar; return *this; }

    // Dot product
    float Dot(const Vector3& other) const { return x * other.x + y * other.y + z * other.z; }

    // Cross product
    Vector3 Cross(const Vector3& other) const
    {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Magnitude
    float Length() const { return std::sqrt(x * x + y * y + z * z); }
    float LengthSquared() const { return x * x + y * y + z * z; }

    // Normalize
    Vector3 Normalized() const
    {
        float len = Length();
        if (len > 0.f) return *this / len;
        return Vector3();
    }

    void Normalize()
    {
        float len = Length();
        if (len > 0.f) { x /= len; y /= len; z /= len; }
    }

    // Static helpers
    static Vector3 Zero() { return Vector3(0.f, 0.f, 0.f); }
    static Vector3 Up() { return Vector3(0.f, 1.f, 0.f); }
    static Vector3 Right() { return Vector3(1.f, 0.f, 0.f); }
    static Vector3 Forward() { return Vector3(0.f, 0.f, 1.f); }
};

// Scalar * Vector
inline Vector3 operator*(float scalar, const Vector3& vec) { return vec * scalar; }
