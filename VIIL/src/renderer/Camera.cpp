#include "core/standardUse.h"
#include "renderer/Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace VIIL
{
	static const glm::vec3 upVector = {.0f, 1.0f, .0f };
	static const glm::vec3 rightVector = { 1.0f, .0f, .0f };
	static const glm::vec3 fowardVector = { .0f, .0f, 1.0f };

	CameraOrthographic::CameraOrthographic() :
		Camera()
	{}

	CameraOrthographic::CameraOrthographic(float aspectRt) :
		Camera(aspectRt)
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
		glm::mat4 r = glm::rotate(glm::mat4(1.0f), rotation.x, upVector) * glm::rotate(glm::mat4(1.0f), rotation.y, rightVector) * glm::rotate(glm::mat4(1.0f), rotation.z, fowardVector);
		glm::mat4 m = t * r;
		glm::mat4 view = glm::inverse(m);

		return view;
	}

	glm::mat4 CameraOrthographic::getProjectionMatrix() const
	{
		return glm::ortho(boundary.left,// * aspectRatio, 
			             boundary.right,// * aspectRatio, 
			            boundary.bottom,// * aspectRatio, 
			               boundary.top,// * aspectRatio, 
			          boundary.nearView,// * aspectRatio, 
			           boundary.farView // * aspectRatio
						);
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