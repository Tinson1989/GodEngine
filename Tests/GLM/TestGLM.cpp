#include<iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
int main(){

    glm::vec3 vec(1.0);
    glm::mat4 mat;
    glm::vec3 vec2(2.0);
    glm::vec3 vec3 = vec + vec2;
    std::cout << "vec3 = (" << vec3.x << "," << vec3.y << "," << vec3.z << ")" << std::endl;

    return 0;
}