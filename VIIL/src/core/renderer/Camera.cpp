#include "standardUse.h"
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace VIIL
{
	static const glm::vec3 upVector = {.0f, 1.0f, .0f };
	static const glm::vec3 rightVector = { 1.0f, .0f, .0f };
	static const glm::vec3 fowardVector = { .0f, .0f, 1.0f };

	CameraOrthographic::CameraOrthographic() :
		Camera()
	{}

	CameraOrthographic::CameraOrthographic(ViewBoundary bounds, glm::vec3 loc, glm::vec3 rot, float asptRt, float fov):
		Camera(bounds, loc, rot, asptRt, fov)
	{}

	CameraOrthographic::~CameraOrthographic()
	{

	}

	glm::mat4 CameraOrthographic::getViewMatrix() const
	{
		glm::mat4 t = glm::translate(glm::mat4(1.0f), location);
		glm::mat4 r = glm::rotate(glm::mat4(1.0f), rotation.z, fowardVector);
		glm::mat4 m = t * r;
		glm::mat4 view = glm::inverse(m);

		return view;
	}

	glm::mat4 CameraOrthographic::getProjectionMatrix() const
	{
		return glm::ortho(boundary.left, boundary.right, boundary.bottom, boundary.top, boundary.nearView, boundary.farView);
	}

	void CameraOrthographic::setLocation(glm::vec3 loc)
	{
		location = loc;
	}

	void CameraOrthographic::setRotation(glm::vec3 rot)
	{
		rotation = rot;
	}

	void CameraOrthographic::setAspectRatio(float asptRt)
	{
		aspectRatio = asptRt;
	}

	void CameraOrthographic::setFieldOfView(float fov)
	{
		fieldOfView = fov;
	}

}