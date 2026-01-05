#define _USE_MATH_DEFINES
#include "Animation.h"
#include "Mesh.h"
#include "Settings.h"
#include <cmath>

Animation::Animation(Mesh& mesh, Settings const& settings)
    : m_mesh(mesh)
    , m_amplitude(settings.GetAnimationAmplitude())
    , m_speed(settings.GetAnimationSpeed())
    , m_orbitAmplitude(settings.GetOrbitAmplitude())
    , m_orbitSpeed(settings.GetOrbitSpeed())
    , m_basePosition(Vector3::Zero())
    , m_currentOffset(0.f)
    , m_orbitOffset(0.f)
    , m_lastUpdateTime(std::chrono::high_resolution_clock::now())
    , m_lastDeltaTime(0.f)
{
}

void Animation::Update()
{
    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = now - m_lastUpdateTime;
    m_lastDeltaTime = elapsed.count();
    m_lastUpdateTime = now;

    static float totalTime = 0.f;
    totalTime += m_lastDeltaTime;

    m_currentOffset = m_amplitude * std::cos(totalTime * m_speed);
    m_orbitOffset = m_orbitAmplitude * std::sin(totalTime * m_orbitSpeed);
}

float Animation::GetCurrentOffset() const
{
    return m_currentOffset;
}

float Animation::GetOrbitOffset() const
{
    return m_orbitOffset;
}

void Animation::SetAmplitude(float amplitude)
{
    m_amplitude = amplitude;
}

void Animation::SetSpeed(float speed)
{
    m_speed = speed;
}

float Animation::GetAmplitude() const
{
    return m_amplitude;
}

float Animation::GetSpeed() const
{
    return m_speed;
}

float Animation::GetDeltaTime() const
{
    return m_lastDeltaTime;
}