#pragma once
#include <chrono>
#include "Vector3.h"

class Mesh;
class Settings;

class Animation
{
public:
    Animation(Mesh& mesh, Settings const& settings);

    void Update();

    void SetAmplitude(float amplitude);
    void SetSpeed(float speed);

    float GetAmplitude() const;
    float GetSpeed() const;
    float GetCurrentOffset() const;
    float GetOrbitOffset() const;
    float GetDeltaTime() const;

private:
    Mesh& m_mesh;
    float m_amplitude;
    float m_speed;
    float m_orbitAmplitude;
    float m_orbitSpeed;
    Vector3 m_basePosition;
    float m_currentOffset;
    float m_orbitOffset;
    std::chrono::high_resolution_clock::time_point m_lastUpdateTime;
    float m_lastDeltaTime;
};