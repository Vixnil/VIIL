#include "standardUse.h"
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace VIIL
{
	static const glm::vec3 upVector = {.0f, 1.0f, .0f };
	static const glm::vec3 rightVector = { 1.0f, .0f, .0f };
	static const glm::vec3 fowardVector = { .0f, .0f, 1.0f };

	Camera2D::Camera2D() :
		Camera()
	{}

	Camera2D::Camera2D(ViewBoundary bounds, glm::vec3 loc, glm::vec3 rot, float asptRt, float fov):
		Camera(bounds, loc, rot, asptRt, fov)
	{}

	Camera2D::~Camera2D()
	{

	}

	glm::mat4 Camera2D::getViewMatrix() const
	{
		glm::mat4 t = glm::translate(glm::mat4(1.0f), location);
		glm::mat4 r = glm::rotate(glm::mat4(1.0f), rotation.z, fowardVector);
		glm::mat4 m = t * r;
		glm::mat4 view = glm::inverse(m);

		return view;
	}

	glm::mat4 Camera2D::getProjectionMatrix() const
	{
		return glm::ortho(boundary.left, boundary.right, boundary.bottom, boundary.top, boundary.nearView, boundary.farView);
	}

	void Camera2D::setLocation(glm::vec3 loc)
	{
		location = loc;
	}

	void Camera2D::setRotation(glm::vec3 rot)
	{
		rotation = rot;
	}

	void Camera2D::setAspectRatio(float asptRt)
	{
		aspectRatio = asptRt;
	}

	void Camera2D::setFieldOfView(float fov)
	{
		fieldOfView = fov;
	}

}