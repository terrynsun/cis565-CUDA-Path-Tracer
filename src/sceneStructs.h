#pragma once

#include <string>
#include <vector>
#include <cuda_runtime.h>
#include "glm/glm.hpp"

enum GeomType {
    SPHERE,
    CUBE,
};

struct Ray {
    glm::vec3 origin;
    glm::vec3 direction;
};

struct Geom {
    enum GeomType type;
    int materialid;
    glm::vec3 translation;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::mat4 transform;
    glm::mat4 inverseTransform;
    glm::mat4 invTranspose;
};

struct Texture {
    int width;
    int height;
    int channels;
    unsigned char *data;
};

struct Material {
    glm::vec3 color;
    struct {
        float exponent;
        glm::vec3 color;
    } specular;
    int textureid;
    Texture texture;
    int normalid;
    Texture normalMap;
    float indexOfRefraction;
    float emittance;
};

struct Camera {
    glm::ivec2 resolution;
    glm::vec3 position;
    glm::vec3 view;
    glm::vec3 up;
    glm::vec2 fov;
    glm::vec2 dof; // (focal length, aperture radius)
};

struct RenderState {
    Camera camera;
    unsigned int iterations;
    int traceDepth;
    std::vector<glm::vec3> image;
    std::string imageName;
};

struct Pixel {
    Ray ray;
    glm::vec3 color;
    bool terminated;
    int index;
};
