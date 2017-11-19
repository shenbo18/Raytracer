#include "common/Scene/Lights/Point/PointLight.h"
#include <random>
#include <cmath>

void PointLight::ComputeSampleRays(std::vector<Ray>& output, glm::vec3 origin, glm::vec3 normal) const
{
    origin += normal * LARGE_EPSILON;
    const glm::vec3 lightPosition = glm::vec3(GetPosition());
    const glm::vec3 rayDirection = glm::normalize(lightPosition - origin);
    const float distanceToOrigin = glm::distance(origin, lightPosition);
    output.emplace_back(origin, rayDirection, distanceToOrigin);
}

float PointLight::ComputeLightAttenuation(glm::vec3 origin) const
{
    return 1.f;
}

void PointLight::GenerateRandomPhotonRay(Ray& ray) const
{
    // Assignment 8 TODO: Fill in the random point light samples here.
	float x = 1.0, y =1.0, z =1.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);
	while (std::pow(x,2) + std::pow(y,2) + std::pow(z,2) >1)
	{	
		x = distribution(generator);
		y = distribution(generator);
		z = distribution(generator);
	}
	//std::cout << x << std::endl;
	//std::cout << y << std::endl;

	const glm::vec3 rayDirection = glm::normalize(glm::vec3(x, y, z));
	ray.SetRayDirection(rayDirection);
	//std::cout << position.x << " " << position.y <<" "<< position.z << std::endl;
	ray.SetRayPosition(glm::vec3(position.x, position.y, position.z));

}
