#pragma once

#include "standardUse.h"
#include "core/Graphics.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace VIIL
{
    /*
	* This needs to be on each thread GLFW will be on as GLFW will call the callback on the same thread only
	* NOTE: Error callback stays set after library has been terminated as well!?!?!??
	*/
	static void glfw_error_callback(int error, const char* description)
	{
		VL_ENGINE_ERROR(("GLFW: {0}: {1}", error, description));
	}

	class WindowsGraphics : public Graphics
	{
		
	public:
		WindowsGraphics()
		{
		}

		void initialize()
		{
			glfwSetErrorCallback(glfw_error_callback);
			isInit = glfwInit();

			VL_ENGINE_TRACE("Initialized windows graphics");
		}

		void prepareDelete()
		{
			glfwTerminate();
			VL_ENGINE_TRACE("Destroyed windows graphics");
		}
	};

	std::unique_ptr<Graphics, GraphicsDeleter> initializeGraphics()
	{
		std::unique_ptr<WindowsGraphics, GraphicsDeleter> gphs = std::unique_ptr<WindowsGraphics, GraphicsDeleter>(new WindowsGraphics());
		gphs->initialize();
		return gphs;
	}

	VIIL_MouseCode glfwToViilMouseButtonCode(int& glfwMouseButtonCode)
	{
		VIIL_MouseCode code;

		switch (glfwMouseButtonCode)
		{
		case GLFW_MOUSE_BUTTON_1:
			code = VIIL_MouseCode::BTN_1;
			break;
		case GLFW_MOUSE_BUTTON_2:
			code = VIIL_MouseCode::BTN_2;
			break;
		case GLFW_MOUSE_BUTTON_3:
			code = VIIL_MouseCode::BTN_3;
			break;
		case GLFW_MOUSE_BUTTON_4:
			code = VIIL_MouseCode::BTN_4;
			break;
		case GLFW_MOUSE_BUTTON_5:
			code = VIIL_MouseCode::BTN_5;
			break;
		case GLFW_MOUSE_BUTTON_6:
			code = VIIL_MouseCode::BTN_6;
			break;
		case GLFW_MOUSE_BUTTON_7:
			code = VIIL_MouseCode::BTN_7;
			break;
		case GLFW_MOUSE_BUTTON_8:
			code = VIIL_MouseCode::BTN_8;
			break;
		default:
			code = VIIL_MouseCode::BTN_UNKNOWN;
		}

		return code;
	}

	VIIL_KeyCode glfwToViilKeyCode(int& glfwKeyCode)
	{
		VIIL_KeyCode viilKeyCode;

		switch (glfwKeyCode)
		{
		case GLFW_KEY_0:
			viilKeyCode = VIIL_KeyCode::ZERO;
			break;
		case GLFW_KEY_1:
			viilKeyCode = VIIL_KeyCode::ONE;
			break;
		case GLFW_KEY_2:
			viilKeyCode = VIIL_KeyCode::TWO;
			break;
		case GLFW_KEY_3:
			viilKeyCode = VIIL_KeyCode::THREE;
			break;
		case GLFW_KEY_4:
			viilKeyCode = VIIL_KeyCode::FOUR;
			break;
		case GLFW_KEY_5:
			viilKeyCode = VIIL_KeyCode::FIVE;
			break;
		case GLFW_KEY_6:
			viilKeyCode = VIIL_KeyCode::SIX;
			break;
		case GLFW_KEY_7:
			viilKeyCode = VIIL_KeyCode::SEVEN;
			break;
		case GLFW_KEY_8:
			viilKeyCode = VIIL_KeyCode::EIGHT;
			break;
		case GLFW_KEY_9:
			viilKeyCode = VIIL_KeyCode::NINE;
			break;
		case GLFW_KEY_A:
			viilKeyCode = VIIL_KeyCode::A;
			break;
		case GLFW_KEY_B:
			viilKeyCode = VIIL_KeyCode::B;
			break;
		case GLFW_KEY_C:
			viilKeyCode = VIIL_KeyCode::C;
			break;
		case GLFW_KEY_D:
			viilKeyCode = VIIL_KeyCode::D;
			break;
		case GLFW_KEY_E:
			viilKeyCode = VIIL_KeyCode::E;
			break;
		case GLFW_KEY_F:
			viilKeyCode = VIIL_KeyCode::F;
			break;
		case GLFW_KEY_G:
			viilKeyCode = VIIL_KeyCode::G;
			break;
		case GLFW_KEY_H:
			viilKeyCode = VIIL_KeyCode::H;
			break;
		case GLFW_KEY_I:
			viilKeyCode = VIIL_KeyCode::I;
			break;
		case GLFW_KEY_J:
			viilKeyCode = VIIL_KeyCode::J;
			break;
		case GLFW_KEY_K:
			viilKeyCode = VIIL_KeyCode::K;
			break;
		case GLFW_KEY_L:
			viilKeyCode = VIIL_KeyCode::L;
			break;
		case GLFW_KEY_M:
			viilKeyCode = VIIL_KeyCode::M;
			break;
		case GLFW_KEY_N:
			viilKeyCode = VIIL_KeyCode::N;
			break;
		case GLFW_KEY_O:
			viilKeyCode = VIIL_KeyCode::O;
			break;
		case GLFW_KEY_P:
			viilKeyCode = VIIL_KeyCode::P;
			break;
		case GLFW_KEY_Q:
			viilKeyCode = VIIL_KeyCode::Q;
			break;
		case GLFW_KEY_R:
			viilKeyCode = VIIL_KeyCode::R;
			break;
		case GLFW_KEY_S:
			viilKeyCode = VIIL_KeyCode::S;
			break;
		case GLFW_KEY_T:
			viilKeyCode = VIIL_KeyCode::T;
			break;
		case GLFW_KEY_U:
			viilKeyCode = VIIL_KeyCode::U;
			break;
		case GLFW_KEY_V:
			viilKeyCode = VIIL_KeyCode::V;
			break;
		case GLFW_KEY_W:
			viilKeyCode = VIIL_KeyCode::W;
			break;
		case GLFW_KEY_X:
			viilKeyCode = VIIL_KeyCode::X;
			break;
		case GLFW_KEY_Y:
			viilKeyCode = VIIL_KeyCode::Y;
			break;
		case GLFW_KEY_Z:
			viilKeyCode = VIIL_KeyCode::Z;
			break;
		case GLFW_KEY_APOSTROPHE:
			viilKeyCode = VIIL_KeyCode::APOSTROPHE;
			break;
		case GLFW_KEY_BACKSLASH:
			viilKeyCode = VIIL_KeyCode::BACK_SLASH;
			break;
		case GLFW_KEY_BACKSPACE:
			viilKeyCode = VIIL_KeyCode::BACKSPACE;
			break;
		case GLFW_KEY_CAPS_LOCK:
			viilKeyCode = VIIL_KeyCode::CAPS_LOCK;
			break;
		case GLFW_KEY_COMMA:
			viilKeyCode = VIIL_KeyCode::COMMA;
			break;
		case GLFW_KEY_DELETE:
			viilKeyCode = VIIL_KeyCode::DELETE_KEY;
			break;
		case GLFW_KEY_DOWN:
			viilKeyCode = VIIL_KeyCode::DOWN_ARROW;
			break;
		case GLFW_KEY_END:
			viilKeyCode = VIIL_KeyCode::END;
			break;
		case GLFW_KEY_ENTER:
			viilKeyCode = VIIL_KeyCode::ENTER;
			break;
		case GLFW_KEY_EQUAL:
			viilKeyCode = VIIL_KeyCode::EQUAL;
			break;
		case GLFW_KEY_ESCAPE:
			viilKeyCode = VIIL_KeyCode::ESCAPE;
			break;
		case GLFW_KEY_F1:
			viilKeyCode = VIIL_KeyCode::F1;
			break;
		case GLFW_KEY_F2:
			viilKeyCode = VIIL_KeyCode::F2;
			break;
		case GLFW_KEY_F3:
			viilKeyCode = VIIL_KeyCode::F3;
			break;
		case GLFW_KEY_F4:
			viilKeyCode = VIIL_KeyCode::F4;
			break;
		case GLFW_KEY_F5:
			viilKeyCode = VIIL_KeyCode::F5;
			break;
		case GLFW_KEY_F6:
			viilKeyCode = VIIL_KeyCode::F6;
			break;
		case GLFW_KEY_F7:
			viilKeyCode = VIIL_KeyCode::F7;
			break;
		case GLFW_KEY_F8:
			viilKeyCode = VIIL_KeyCode::F8;
			break;
		case GLFW_KEY_F9:
			viilKeyCode = VIIL_KeyCode::F9;
			break;
		case GLFW_KEY_F10:
			viilKeyCode = VIIL_KeyCode::F10;
			break;
		case GLFW_KEY_F11:
			viilKeyCode = VIIL_KeyCode::F11;
			break;
		case GLFW_KEY_F12:
			viilKeyCode = VIIL_KeyCode::F12;
			break;
		case GLFW_KEY_F13:
			viilKeyCode = VIIL_KeyCode::F13;
			break;
		case GLFW_KEY_F14:
			viilKeyCode = VIIL_KeyCode::F14;
			break;
		case GLFW_KEY_F15:
			viilKeyCode = VIIL_KeyCode::F15;
			break;
		case GLFW_KEY_F16:
			viilKeyCode = VIIL_KeyCode::F16;
			break;
		case GLFW_KEY_F17:
			viilKeyCode = VIIL_KeyCode::F17;
			break;
		case GLFW_KEY_F18:
			viilKeyCode = VIIL_KeyCode::F18;
			break;
		case GLFW_KEY_F19:
			viilKeyCode = VIIL_KeyCode::F19;
			break;
		case GLFW_KEY_F20:
			viilKeyCode = VIIL_KeyCode::F20;
			break;
		case GLFW_KEY_F21:
			viilKeyCode = VIIL_KeyCode::F21;
			break;
		case GLFW_KEY_F22:
			viilKeyCode = VIIL_KeyCode::F22;
			break;
		case GLFW_KEY_F23:
			viilKeyCode = VIIL_KeyCode::F23;
			break;
		case GLFW_KEY_F24:
			viilKeyCode = VIIL_KeyCode::F24;
			break;
		case GLFW_KEY_F25:
			viilKeyCode = VIIL_KeyCode::F25;
			break;
		case GLFW_KEY_GRAVE_ACCENT:
			viilKeyCode = VIIL_KeyCode::GRAVE_ACCENT;
			break;
		case GLFW_KEY_HOME:
			viilKeyCode = VIIL_KeyCode::HOME;
			break;
		case GLFW_KEY_INSERT:
			viilKeyCode = VIIL_KeyCode::INSERT;
			break;
		case GLFW_KEY_KP_0:
			viilKeyCode = VIIL_KeyCode::KP_ZERO;
			break;
		case GLFW_KEY_KP_1:
			viilKeyCode = VIIL_KeyCode::KP_ONE;
			break;
		case GLFW_KEY_KP_2:
			viilKeyCode = VIIL_KeyCode::KP_TWO;
			break;
		case GLFW_KEY_KP_3:
			viilKeyCode = VIIL_KeyCode::KP_THREE;
			break;
		case GLFW_KEY_KP_4:
			viilKeyCode = VIIL_KeyCode::KP_FOUR;
			break;
		case GLFW_KEY_KP_5:
			viilKeyCode = VIIL_KeyCode::KP_FIVE;
			break;
		case GLFW_KEY_KP_6:
			viilKeyCode = VIIL_KeyCode::KP_SIX;
			break;
		case GLFW_KEY_KP_7:
			viilKeyCode = VIIL_KeyCode::KP_SEVEN;
			break;
		case GLFW_KEY_KP_8:
			viilKeyCode = VIIL_KeyCode::KP_EIGHT;
			break;
		case GLFW_KEY_KP_9:
			viilKeyCode = VIIL_KeyCode::KP_NINE;
			break;
		case GLFW_KEY_KP_ADD:
			viilKeyCode = VIIL_KeyCode::KP_ADD;
			break;
		case GLFW_KEY_KP_SUBTRACT:
			viilKeyCode = VIIL_KeyCode::KP_SUBTRACT;
			break;
		case GLFW_KEY_KP_MULTIPLY:
			viilKeyCode = VIIL_KeyCode::KP_MULTIPLY;
			break;
		case GLFW_KEY_KP_DIVIDE:
			viilKeyCode = VIIL_KeyCode::KP_DIVIDE;
			break;
		case GLFW_KEY_KP_DECIMAL:
			viilKeyCode = VIIL_KeyCode::KP_DECIMAL;
			break;
		case GLFW_KEY_KP_ENTER:
			viilKeyCode = VIIL_KeyCode::KP_ENTER;
			break;
		case GLFW_KEY_KP_EQUAL:
			viilKeyCode = VIIL_KeyCode::KP_EQUAL;
			break;
		case GLFW_KEY_LEFT:
			viilKeyCode = VIIL_KeyCode::LEFT_ARROW;
			break;
		case GLFW_KEY_LEFT_ALT:
			viilKeyCode = VIIL_KeyCode::LEFT_ALT;
			break;
		case GLFW_KEY_LEFT_SHIFT:
			viilKeyCode = VIIL_KeyCode::LEFT_SHIFT;
			break;
		case GLFW_KEY_LEFT_CONTROL:
			viilKeyCode = VIIL_KeyCode::LEFT_CONTROL;
			break;
		case GLFW_KEY_LEFT_SUPER:
			viilKeyCode = VIIL_KeyCode::LEFT_SUPER;
			break;
		case GLFW_KEY_LEFT_BRACKET:
			viilKeyCode = VIIL_KeyCode::LEFT_BRACKET;
			break;
		case GLFW_KEY_MINUS:
			viilKeyCode = VIIL_KeyCode::MINUS;
			break;
		case GLFW_KEY_MENU:
			viilKeyCode = VIIL_KeyCode::MENU;
			break;
		case GLFW_KEY_NUM_LOCK:
			viilKeyCode = VIIL_KeyCode::NUM_LOCK;
			break;
		case GLFW_KEY_PAGE_DOWN:
			viilKeyCode = VIIL_KeyCode::PAGE_DOWN;
			break;
		case GLFW_KEY_PAGE_UP:
			viilKeyCode = VIIL_KeyCode::PAGE_UP;
			break;
		case GLFW_KEY_PAUSE:
			viilKeyCode = VIIL_KeyCode::PAUSE_BREAK;
			break;
		case GLFW_KEY_PERIOD:
			viilKeyCode = VIIL_KeyCode::PERIOD;
			break;
		case GLFW_KEY_PRINT_SCREEN:
			viilKeyCode = VIIL_KeyCode::PRINT_SCREEN;
			break;
		case GLFW_KEY_RIGHT:
			viilKeyCode = VIIL_KeyCode::RIGHT_ARROW;
			break;
		case GLFW_KEY_RIGHT_SHIFT:
			viilKeyCode = VIIL_KeyCode::RIGHT_SHIFT;
			break;
		case GLFW_KEY_RIGHT_ALT:
			viilKeyCode = VIIL_KeyCode::RIGHT_ALT;
			break;
		case GLFW_KEY_RIGHT_CONTROL:
			viilKeyCode = VIIL_KeyCode::RIGHT_CONTROL;
			break;
		case GLFW_KEY_RIGHT_BRACKET:
			viilKeyCode = VIIL_KeyCode::RIGHT_BRACKET;
			break;
		case GLFW_KEY_RIGHT_SUPER:
			viilKeyCode = VIIL_KeyCode::RIGHT_SUPER;
			break;
		case GLFW_KEY_SCROLL_LOCK:
			viilKeyCode = VIIL_KeyCode::SCROLL_LOCK;
			break;
		case GLFW_KEY_SEMICOLON:
			viilKeyCode = VIIL_KeyCode::SEMICOLON;
			break;
		case GLFW_KEY_SLASH:
			viilKeyCode = VIIL_KeyCode::SLASH;
			break;
		case GLFW_KEY_SPACE:
			viilKeyCode = VIIL_KeyCode::SPACE;
			break;
		case GLFW_KEY_TAB:
			viilKeyCode = VIIL_KeyCode::TAB;
			break;
		case GLFW_KEY_UP:
			viilKeyCode = VIIL_KeyCode::UP_ARROW;
			break;
		default:
			viilKeyCode = VIIL_KeyCode::UNKNOWN;
		}

		return viilKeyCode;
	}

	void mouseCursorPositionCallback(GLFWwindow* windowHandel, double xPos, double yPos)
	{
		Window::WindowData& winData = *(Window::WindowData*)glfwGetWindowUserPointer(windowHandel);
		MouseMovedEvent event = VIIL::MouseMovedEvent((float)xPos, (float)yPos);

		winData.callBackFn(event);
	}

	void mouseScrollCallback(GLFWwindow* windowHandel, double xOffset, double yOffset)
	{
		Window::WindowData& winData = *(Window::WindowData*)glfwGetWindowUserPointer(windowHandel);

		VIIL::MouseScrolledEvent event = VIIL::MouseScrolledEvent((float)xOffset, (float)yOffset);
		winData.callBackFn(event);
	}

	void mouseButtonCallback(GLFWwindow* windowHandel, int buttonCode, int action, int modifiers)
	{
		Window::WindowData& winData = *(Window::WindowData*)glfwGetWindowUserPointer(windowHandel);
		VIIL_MouseCode btnCode = glfwToViilMouseButtonCode(buttonCode);

		switch (action)
		{
		case GLFW_PRESS:
		{
			VIIL::MouseButtonPressedEvent event = VIIL::MouseButtonPressedEvent(btnCode);
			winData.callBackFn(event);
		}
		break;
		case GLFW_RELEASE:
		{
			VIIL::MouseButtonReleasedEvent event = VIIL::MouseButtonReleasedEvent(btnCode);
			winData.callBackFn(event);
		}
		break;
		}

	}

	void keyCallback(GLFWwindow* windowHandel, int keyboardKeyCode, int keyScanCode, int action, int keyModifiers)
	{
		Window::WindowData& winData = *(Window::WindowData*)glfwGetWindowUserPointer(windowHandel);
		VIIL_KeyCode code = glfwToViilKeyCode(keyboardKeyCode);

		switch (action)
		{
		case GLFW_PRESS:
		{
			VIIL::KeyPressedEvent event = VIIL::KeyPressedEvent(code, 0);
			winData.callBackFn(event);
		}
		break;
		case GLFW_RELEASE:
		{
			VIIL::KeyReleasedEvent event = VIIL::KeyReleasedEvent(code);
			winData.callBackFn(event);
		}
		break;
		case GLFW_REPEAT:
		{
			VIIL::KeyPressedEvent event = VIIL::KeyPressedEvent(code, 1);
			winData.callBackFn(event);
		}
		break;
		}

	}

	void windowCloseCallback(GLFWwindow* windowHandel)
	{
		Window::WindowData& winData = *(Window::WindowData*)glfwGetWindowUserPointer(windowHandel);
		VIIL::WindowClose event;

		winData.callBackFn(event);
	}

	void windowResizeCallback(GLFWwindow* windowHandel, int newWidth, int newHeight)
	{
		Window::WindowData& winData = *(Window::WindowData*)glfwGetWindowUserPointer(windowHandel);
		VIIL::WindowResize event = VIIL::WindowResize(newWidth, newHeight);

		winData.width = newWidth;
		winData.height = newHeight;
		winData.callBackFn(event);
	}

}