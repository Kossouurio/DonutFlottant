#pragma once
#include <vector>

class Settings;
class Mesh;
struct Vertex;
class Light;

class Screen
{
    public:
    Screen(Settings const& settings);
    void Display() const;
    void Display(Mesh const& mesh, Light const& light, float yOffset = 0.f, float zOffset = 0.f);

    private:
    void _ProjectMesh(Mesh const& mesh, Light const& light, float yOffset, float zOffset);
    void _ProjectInCenterScreenSpace(Vertex& vertex, float yOffset, float zOffset);
    void _ProjectInTopLeftScreenSpace(Vertex& vertex);
    bool _IsVertexInScreen(int u, int v);

    private:
    int m_width;
    int m_height;
    float m_zPosition;
    char m_background;
    char m_meshProjection;
    float m_meshZPosition;
    std::vector<char> m_pixels;
    std::vector<float> m_oozBuffer;
};