#define _USE_MATH_DEFINES
#include "Settings.h"
#include <string>
#include <cmath>

Settings::Settings(int argc, char** argv)
// Screen
: m_screenWidth(100)
, m_screenHeight(20)
, m_screenBackground(' ')
, m_screenMeshProjection('X')
, m_screenPosition(50.f)

// Mesh
, m_meshResolution(128)
, m_meshPosition(18.f)
, m_meshRotationXPerFrame(0.03f)
, m_meshRotationYPerFrame(0.05f)
, m_meshRotationZPerFrame(0.0f)

// Light
, m_lightDirectionX(-1.f)
, m_lightDirectionY(-1.f)
, m_lightDirectionZ(-1.f)

// Animation
, m_frameDuration(16000)
, m_animationAmplitude(6.0f)
, m_animationSpeed(0.8f)
, m_orbitAmplitude(10.f)
, m_orbitSpeed(0.5f)

// Initial rotations
, m_initialRotationX(static_cast<float>(M_PI / 4.0))
, m_initialRotationY(static_cast<float>(M_PI / 4.0))
, m_initialRotationZ(0.f)

// Torus geometry
, m_torusMajorRadius(4.f)
, m_torusMinorRadius(2.5f)
{
    _ParseArguments(argc, argv);
}

void Settings::_ParseArguments(int argc, char** argv)
{
    // Elegant solution from @T.Rosselet
    for (int i = 1; i < argc; i++) //i starts at 1 because command line arguments start with argv[1] (argv[0] is the name of the exe)
    {
        std::string arg = argv[i];
        if (arg == "-w" && i + 1 < argc)
        {
            m_screenWidth = std::atoi(argv[i+1]);
            i++;
        }
        else if (arg == "-h" && i + 1 < argc)
        {
            m_screenHeight = std::atoi(argv[i+1]);
            i++;
        }
        else if (arg == "-b" && i + 1 < argc)
        {
            m_screenBackground = argv[i+1][0];
            i++;
        }
        else if (arg == "-p" && i + 1 < argc)
        {
            m_screenMeshProjection = argv[i+1][0];
            i++;
        }
        else if (arg == "-s" && i + 1 < argc)
        {
            m_screenPosition = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-r" && i + 1 < argc)
        {
            m_meshResolution = std::atoi(argv[i+1]);
            i++;
        }
        else if (arg == "-m" && i + 1 < argc)
        {
            m_meshPosition = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-x" && i + 1 < argc)
        {
            m_meshRotationXPerFrame = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-y" && i + 1 < argc)
        {
            m_meshRotationYPerFrame = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-z" && i + 1 < argc)
        {
            m_meshRotationZPerFrame = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-lx" && i + 1 < argc)
        {
            m_lightDirectionX = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-ly" && i + 1 < argc)
        {
            m_lightDirectionY = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-lz" && i + 1 < argc)
        {
            m_lightDirectionZ = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-f" && i + 1 < argc)
        {
            m_frameDuration = std::atoi(argv[i+1]);
            i++;
        }
        else if (arg == "-aa" && i + 1 < argc)
        {
            m_animationAmplitude = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-as" && i + 1 < argc)
        {
            m_animationSpeed = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-oa" && i + 1 < argc)
        {
            m_orbitAmplitude = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-os" && i + 1 < argc)
        {
            m_orbitSpeed = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-ix" && i + 1 < argc)
        {
            m_initialRotationX = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-iy" && i + 1 < argc)
        {
            m_initialRotationY = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-iz" && i + 1 < argc)
        {
            m_initialRotationZ = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-tM" && i + 1 < argc)
        {
            m_torusMajorRadius = std::atof(argv[i+1]);
            i++;
        }
        else if (arg == "-tm" && i + 1 < argc)
        {
            m_torusMinorRadius = std::atof(argv[i+1]);
            i++;
        }
    }
}