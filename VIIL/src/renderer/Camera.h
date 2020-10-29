#pragma once
#include "core/standardUse.h"

#include <glm/glm.hpp>

namespace VIIL
{

	struct ViewBoundary
	{
		float left, right, bottom, top, nearView, farView;
	};

	class Camera
	{
	protected:
		ViewBoundary boundary;
		glm::vec3 location;
		glm::vec3 rotation;
		float aspectRatio;
		float fieldOfView;
	public:
		Camera() :
			boundary({ .0f, 1.0f, .0f, 1.0f, -1.0f, 1.0f }), location({ .0f, .0f, .0f }), rotation({ .0f, .0f, .0f }), aspectRatio(1), fieldOfView(45.0f)
		{}
		Camera(float asptRt) :
			boundary({ .0f, 1.0f, .0f, 1.0f, -1.0f, 1.0f }), location({ .0f, .0f, .0f }), rotation({ .0f, .0f, .0f }), aspectRatio(asptRt), fieldOfView(45.0f)
		{}
		Camera(ViewBoundary bounds, glm::vec3 loc, glm::vec3 rot, float asptRt, float fov) :
			boundary(bounds), location(loc), rotation(rot), aspectRatio(asptRt), fieldOfView(fov)
		{}

		virtual void setLocation(glm::vec3 loc) = 0;
		virtual void setRotation(glm::vec3 rot) = 0;
		virtual void setAspectRatio(float asptRt) = 0;
		virtual void setFieldOfView(float fov) = 0;

		virtual glm::mat4 getViewMatrix() const = 0;
		virtual glm::mat4 getProjectionMatrix() const = 0;
		virtual float getAspectRatio() const { return aspectRatio; }

		virtual glm::vec3& getLocation() { return location; }
		virtual glm::vec3& getRotation() { return rotation; }

		virtual ~Camera()
		{};
	};

	class CameraOrthographic : public Camera
	{
	public:
		CameraOrthographic();
		CameraOrthographic(float aspectRt);
		CameraOrthographic(ViewBoundary bounds, glm::vec3 loc, glm::vec3 rot, float asptRt, float fov);

		virtual void setLocation(glm::vec3 loc);
		virtual void setRotation(glm::vec3 rot);
		virtual void setAspectRatio(float asptRt);
		virtual void setFieldOfView(float fov);

		virtual glm::mat4 getViewMatrix() const;
		virtual glm::mat4 getProjectionMatrix() const;

		virtual ~CameraOrthographic();
	};

}