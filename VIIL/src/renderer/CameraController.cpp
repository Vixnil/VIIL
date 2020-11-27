#include "core/standardUse.h"
#include "renderer/CameraController.h"

namespace VIIL
{

	CameraOrthographicController::CameraOrthographicController(float aspRato, bool rotation):
		CameraController(aspRato), isRotationAllowed(rotation),
		camera({ -aspectRatio * zoomLevel, aspectRatio * zoomLevel, -zoomLevel, zoomLevel}, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, .45f, 1)
	{
	}

	void CameraOrthographicController::OnUpdate(float timeStep)
	{
		InputCache& input = InputCache::get();
		float camMovSpeed = camMovementSpeed * timeStep;
		glm::vec3 modLoc = camera.getLocation();

		if (input.isKeyPressed(inputKeys.keyUp))
		{
			modLoc = { modLoc.x, modLoc.y + camMovSpeed, modLoc.z };
		}
		else if (input.isKeyPressed(inputKeys.keyDown))
		{
			modLoc = { modLoc.x, modLoc.y - camMovSpeed, modLoc.z };
		}

		if (input.isKeyPressed(inputKeys.keyLeft))
		{
			modLoc = { modLoc.x - camMovSpeed, modLoc.y, modLoc.z };
		}
		else if (input.isKeyPressed(inputKeys.keyRight))
		{
			modLoc = { modLoc.x + camMovSpeed, modLoc.y, modLoc.z };
		}

		camera.setLocation(modLoc);

		if (isRotationAllowed)
		{
			float camRotSpeed = camRotationSpeed * timeStep;
			glm::vec3 modRot = camera.getRotation();

			if (input.isKeyPressed(inputKeys.keyRotLeft))
			{
				modRot = { modRot.x, modRot.y, modRot.z - camRotSpeed };
			}
			else if (input.isKeyPressed(inputKeys.keyRotRight))
			{
				modRot = { modRot.x, modRot.y, modRot.z + camRotSpeed };
			}

			camera.setRotation(modRot);
		}
	}

	glm::mat4 CameraOrthographicController::getViewProjectionMatrix()
	{
		return camera.getViewMatrix() * camera.getProjectionMatrix();
	}

	void CameraOrthographicController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<MouseScrolledEvent>(bindEventHandler(CameraOrthographicController::OnMouseScrolled));
		dispatcher.dispatch<WindowResize>(bindEventHandler(CameraOrthographicController::OnWindowResize));
	}

	bool CameraOrthographicController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		//TODO: make zoom speed variable
		zoomLevel -= e.getYOffset() * .025;

		if (zoomLevel < 0.1)
		{
			zoomLevel = 0.1;
		}

		camMovementSpeed = zoomLevel;

		camera.setBoundary({ -aspectRatio * zoomLevel, aspectRatio * zoomLevel, -zoomLevel, zoomLevel });

		return true;
	}

	bool CameraOrthographicController::OnWindowResize(WindowResize& e)
	{
		aspectRatio = (float) e.getWdith() / (float) e.getHeight();

		camera.setBoundary({ -aspectRatio * zoomLevel, aspectRatio * zoomLevel, -zoomLevel, zoomLevel });

		return true;
	}

}