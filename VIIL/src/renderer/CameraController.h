#pragma once
#include "core/standardUse.h"
#include "event/app.h"
#include "event/mouse.h"
#include "input/inputValues.h"
#include "renderer/Camera.h"


namespace VIIL
{

	/*
	* Default keys used to manually control a camera.
	*/
	struct CameraControllerKeys
	{
		//Translation
		VIIL_KeyCode keyUp = VIIL_KeyCode::W;
		VIIL_KeyCode keyDown = VIIL_KeyCode::S;
		VIIL_KeyCode keyLeft = VIIL_KeyCode::A;
		VIIL_KeyCode keyRight = VIIL_KeyCode::D;

		//Rotation
		VIIL_KeyCode keyRotLeft = VIIL_KeyCode::Q;
		VIIL_KeyCode keyRotRight = VIIL_KeyCode::E;
	};

	/*
	* Base controller class to provide functionality for commonly needed camera features.
	*/
	class CameraController
	{
	protected:
		float aspectRatio;

		CameraControllerKeys inputKeys;

		CameraController(float aspRto) : aspectRatio(aspRto)
		{}

	public:
		virtual void inline setCameraControllerKeys(CameraControllerKeys keyInputs) { inputKeys = keyInputs; }

		virtual inline float getAspectRatio() { return aspectRatio; }
		virtual glm::mat4 getViewProjectionMatrix() = 0;

		virtual void OnUpdate(float timeStep) = 0;
		virtual void OnEvent(Event& e) = 0;
	};

	/*
	* Orthographic camera controller, provides functionality normally needed to control
	* an orthographic type camera.
	*/
	class CameraOrthographicController : public CameraController
	{
		const float BASE_MOVE_SPEED = 1.0f;
		float zoomLevel = BASE_MOVE_SPEED;
		float camMovementSpeed = BASE_MOVE_SPEED;
		float camRotationSpeed = BASE_MOVE_SPEED;
		bool isRotationAllowed;

		CameraOrthographic camera;

	public:
		CameraOrthographicController(float aspectRatio, bool rotation = false);

		virtual glm::mat4 getViewProjectionMatrix();

		virtual void OnUpdate(float timeStep);
		virtual void OnEvent(Event& e);

	private:

		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResize(WindowResize& e);
	};

}