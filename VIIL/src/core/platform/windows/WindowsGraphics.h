#pragma once

#include "standardUse.h"
#include "core/Graphics.h"
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

	MouseBtnCode glfwToViilMouseButtonCode(int& glfwMouseButtonCode)
	{
		MouseBtnCode code;

		switch (glfwMouseButtonCode)
		{
		case GLFW_MOUSE_BUTTON_1:
			code = MouseBtnCode::BTN_1;
			break;
		case GLFW_MOUSE_BUTTON_2:
			code = MouseBtnCode::BTN_2;
			break;
		case GLFW_MOUSE_BUTTON_3:
			code = MouseBtnCode::BTN_3;
			break;
		case GLFW_MOUSE_BUTTON_4:
			code = MouseBtnCode::BTN_4;
			break;
		case GLFW_MOUSE_BUTTON_5:
			code = MouseBtnCode::BTN_5;
			break;
		case GLFW_MOUSE_BUTTON_6:
			code = MouseBtnCode::BTN_6;
			break;
		case GLFW_MOUSE_BUTTON_7:
			code = MouseBtnCode::BTN_7;
			break;
		case GLFW_MOUSE_BUTTON_8:
			code = MouseBtnCode::BTN_8;
			break;
		default:
			code = MouseBtnCode::BTN_UNSUPPORTED;
		}

		return code;
	}

	KeyCode glfwToViilKeyCode(int& glfwKeyCode)
	{
		KeyCode viilKeyCode;

		switch (glfwKeyCode)
		{
		case GLFW_KEY_0:
			viilKeyCode = KeyCode::ZERO;
			break;
		case GLFW_KEY_1:
			viilKeyCode = KeyCode::ONE;
			break;
		case GLFW_KEY_2:
			viilKeyCode = KeyCode::TWO;
			break;
		case GLFW_KEY_3:
			viilKeyCode = KeyCode::THREE;
			break;
		case GLFW_KEY_4:
			viilKeyCode = KeyCode::FOUR;
			break;
		case GLFW_KEY_5:
			viilKeyCode = KeyCode::FIVE;
			break;
		case GLFW_KEY_6:
			viilKeyCode = KeyCode::SIX;
			break;
		case GLFW_KEY_7:
			viilKeyCode = KeyCode::SEVEN;
			break;
		case GLFW_KEY_8:
			viilKeyCode = KeyCode::EIGHT;
			break;
		case GLFW_KEY_9:
			viilKeyCode = KeyCode::NINE;
			break;
		case GLFW_KEY_A:
			viilKeyCode = KeyCode::A;
			break;
		case GLFW_KEY_B:
			viilKeyCode = KeyCode::B;
			break;
		case GLFW_KEY_C:
			viilKeyCode = KeyCode::C;
			break;
		case GLFW_KEY_D:
			viilKeyCode = KeyCode::D;
			break;
		case GLFW_KEY_E:
			viilKeyCode = KeyCode::E;
			break;
		case GLFW_KEY_F:
			viilKeyCode = KeyCode::F;
			break;
		case GLFW_KEY_G:
			viilKeyCode = KeyCode::G;
			break;
		case GLFW_KEY_H:
			viilKeyCode = KeyCode::H;
			break;
		case GLFW_KEY_I:
			viilKeyCode = KeyCode::I;
			break;
		case GLFW_KEY_J:
			viilKeyCode = KeyCode::J;
			break;
		case GLFW_KEY_K:
			viilKeyCode = KeyCode::K;
			break;
		case GLFW_KEY_L:
			viilKeyCode = KeyCode::L;
			break;
		case GLFW_KEY_M:
			viilKeyCode = KeyCode::M;
			break;
		case GLFW_KEY_N:
			viilKeyCode = KeyCode::N;
			break;
		case GLFW_KEY_O:
			viilKeyCode = KeyCode::O;
			break;
		case GLFW_KEY_P:
			viilKeyCode = KeyCode::P;
			break;
		case GLFW_KEY_Q:
			viilKeyCode = KeyCode::Q;
			break;
		case GLFW_KEY_R:
			viilKeyCode = KeyCode::R;
			break;
		case GLFW_KEY_S:
			viilKeyCode = KeyCode::S;
			break;
		case GLFW_KEY_T:
			viilKeyCode = KeyCode::T;
			break;
		case GLFW_KEY_U:
			viilKeyCode = KeyCode::U;
			break;
		case GLFW_KEY_V:
			viilKeyCode = KeyCode::V;
			break;
		case GLFW_KEY_W:
			viilKeyCode = KeyCode::W;
			break;
		case GLFW_KEY_X:
			viilKeyCode = KeyCode::X;
			break;
		case GLFW_KEY_Y:
			viilKeyCode = KeyCode::Y;
			break;
		case GLFW_KEY_Z:
			viilKeyCode = KeyCode::Z;
			break;
		case GLFW_KEY_APOSTROPHE:
			viilKeyCode = KeyCode::APOSTROPHE;
			break;
		case GLFW_KEY_BACKSLASH:
			viilKeyCode = KeyCode::BACK_SLASH;
			break;
		case GLFW_KEY_BACKSPACE:
			viilKeyCode = KeyCode::BACKSPACE;
			break;
		case GLFW_KEY_CAPS_LOCK:
			viilKeyCode = KeyCode::CAPS_LOCK;
			break;
		case GLFW_KEY_COMMA:
			viilKeyCode = KeyCode::COMMA;
			break;
		case GLFW_KEY_DELETE:
			viilKeyCode = KeyCode::DELETE_KEY;
			break;
		case GLFW_KEY_DOWN:
			viilKeyCode = KeyCode::DOWN_ARROW;
			break;
		case GLFW_KEY_END:
			viilKeyCode = KeyCode::END;
			break;
		case GLFW_KEY_ENTER:
			viilKeyCode = KeyCode::ENTER;
			break;
		case GLFW_KEY_EQUAL:
			viilKeyCode = KeyCode::EQUAL;
			break;
		case GLFW_KEY_ESCAPE:
			viilKeyCode = KeyCode::ESCAPE;
			break;
		case GLFW_KEY_F1:
			viilKeyCode = KeyCode::F1;
			break;
		case GLFW_KEY_F2:
			viilKeyCode = KeyCode::F2;
			break;
		case GLFW_KEY_F3:
			viilKeyCode = KeyCode::F3;
			break;
		case GLFW_KEY_F4:
			viilKeyCode = KeyCode::F4;
			break;
		case GLFW_KEY_F5:
			viilKeyCode = KeyCode::F5;
			break;
		case GLFW_KEY_F6:
			viilKeyCode = KeyCode::F6;
			break;
		case GLFW_KEY_F7:
			viilKeyCode = KeyCode::F7;
			break;
		case GLFW_KEY_F8:
			viilKeyCode = KeyCode::F8;
			break;
		case GLFW_KEY_F9:
			viilKeyCode = KeyCode::F9;
			break;
		case GLFW_KEY_F10:
			viilKeyCode = KeyCode::F10;
			break;
		case GLFW_KEY_F11:
			viilKeyCode = KeyCode::F11;
			break;
		case GLFW_KEY_F12:
			viilKeyCode = KeyCode::F12;
			break;
		case GLFW_KEY_F13:
			viilKeyCode = KeyCode::F13;
			break;
		case GLFW_KEY_F14:
			viilKeyCode = KeyCode::F14;
			break;
		case GLFW_KEY_F15:
			viilKeyCode = KeyCode::F15;
			break;
		case GLFW_KEY_F16:
			viilKeyCode = KeyCode::F16;
			break;
		case GLFW_KEY_F17:
			viilKeyCode = KeyCode::F17;
			break;
		case GLFW_KEY_F18:
			viilKeyCode = KeyCode::F18;
			break;
		case GLFW_KEY_F19:
			viilKeyCode = KeyCode::F19;
			break;
		case GLFW_KEY_F20:
			viilKeyCode = KeyCode::F20;
			break;
		case GLFW_KEY_F21:
			viilKeyCode = KeyCode::F21;
			break;
		case GLFW_KEY_F22:
			viilKeyCode = KeyCode::F22;
			break;
		case GLFW_KEY_F23:
			viilKeyCode = KeyCode::F23;
			break;
		case GLFW_KEY_F24:
			viilKeyCode = KeyCode::F24;
			break;
		case GLFW_KEY_F25:
			viilKeyCode = KeyCode::F25;
			break;
		case GLFW_KEY_GRAVE_ACCENT:
			viilKeyCode = KeyCode::GRAVE_ACCENT;
			break;
		case GLFW_KEY_HOME:
			viilKeyCode = KeyCode::HOME;
			break;
		case GLFW_KEY_INSERT:
			viilKeyCode = KeyCode::INSERT;
			break;
		case GLFW_KEY_KP_0:
			viilKeyCode = KeyCode::KP_ZERO;
			break;
		case GLFW_KEY_KP_1:
			viilKeyCode = KeyCode::KP_ONE;
			break;
		case GLFW_KEY_KP_2:
			viilKeyCode = KeyCode::KP_TWO;
			break;
		case GLFW_KEY_KP_3:
			viilKeyCode = KeyCode::KP_THREE;
			break;
		case GLFW_KEY_KP_4:
			viilKeyCode = KeyCode::KP_FOUR;
			break;
		case GLFW_KEY_KP_5:
			viilKeyCode = KeyCode::KP_FIVE;
			break;
		case GLFW_KEY_KP_6:
			viilKeyCode = KeyCode::KP_SIX;
			break;
		case GLFW_KEY_KP_7:
			viilKeyCode = KeyCode::KP_SEVEN;
			break;
		case GLFW_KEY_KP_8:
			viilKeyCode = KeyCode::KP_EIGHT;
			break;
		case GLFW_KEY_KP_9:
			viilKeyCode = KeyCode::KP_NINE;
			break;
		case GLFW_KEY_KP_ADD:
			viilKeyCode = KeyCode::KP_ADD;
			break;
		case GLFW_KEY_KP_SUBTRACT:
			viilKeyCode = KeyCode::KP_SUBTRACT;
			break;
		case GLFW_KEY_KP_MULTIPLY:
			viilKeyCode = KeyCode::KP_MULTIPLY;
			break;
		case GLFW_KEY_KP_DIVIDE:
			viilKeyCode = KeyCode::KP_DIVIDE;
			break;
		case GLFW_KEY_KP_DECIMAL:
			viilKeyCode = KeyCode::KP_DECIMAL;
			break;
		case GLFW_KEY_KP_ENTER:
			viilKeyCode = KeyCode::KP_ENTER;
			break;
		case GLFW_KEY_KP_EQUAL:
			viilKeyCode = KeyCode::KP_EQUAL;
			break;
		case GLFW_KEY_LEFT:
			viilKeyCode = KeyCode::LEFT_ARROW;
			break;
		case GLFW_KEY_LEFT_ALT:
			viilKeyCode = KeyCode::LEFT_ALT;
			break;
		case GLFW_KEY_LEFT_SHIFT:
			viilKeyCode = KeyCode::LEFT_SHIFT;
			break;
		case GLFW_KEY_LEFT_CONTROL:
			viilKeyCode = KeyCode::LEFT_CONTROL;
			break;
		case GLFW_KEY_LEFT_SUPER:
			viilKeyCode = KeyCode::LEFT_SUPER;
			break;
		case GLFW_KEY_LEFT_BRACKET:
			viilKeyCode = KeyCode::LEFT_BRACKET;
			break;
		case GLFW_KEY_MINUS:
			viilKeyCode = KeyCode::MINUS;
			break;
		case GLFW_KEY_MENU:
			viilKeyCode = KeyCode::MENU;
			break;
		case GLFW_KEY_NUM_LOCK:
			viilKeyCode = KeyCode::NUM_LOCK;
			break;
		case GLFW_KEY_PAGE_DOWN:
			viilKeyCode = KeyCode::PAGE_DOWN;
			break;
		case GLFW_KEY_PAGE_UP:
			viilKeyCode = KeyCode::PAGE_UP;
			break;
		case GLFW_KEY_PAUSE:
			viilKeyCode = KeyCode::PAUSE_BREAK;
			break;
		case GLFW_KEY_PERIOD:
			viilKeyCode = KeyCode::PERIOD;
			break;
		case GLFW_KEY_PRINT_SCREEN:
			viilKeyCode = KeyCode::PRINT_SCREEN;
			break;
		case GLFW_KEY_RIGHT:
			viilKeyCode = KeyCode::RIGHT_ARROW;
			break;
		case GLFW_KEY_RIGHT_SHIFT:
			viilKeyCode = KeyCode::RIGHT_SHIFT;
			break;
		case GLFW_KEY_RIGHT_ALT:
			viilKeyCode = KeyCode::RIGHT_ALT;
			break;
		case GLFW_KEY_RIGHT_CONTROL:
			viilKeyCode = KeyCode::RIGHT_CONTROL;
			break;
		case GLFW_KEY_RIGHT_BRACKET:
			viilKeyCode = KeyCode::RIGHT_BRACKET;
			break;
		case GLFW_KEY_RIGHT_SUPER:
			viilKeyCode = KeyCode::RIGHT_SUPER;
			break;
		case GLFW_KEY_SCROLL_LOCK:
			viilKeyCode = KeyCode::SCROLL_LOCK;
			break;
		case GLFW_KEY_SEMICOLON:
			viilKeyCode = KeyCode::SEMICOLON;
			break;
		case GLFW_KEY_SLASH:
			viilKeyCode = KeyCode::SLASH;
			break;
		case GLFW_KEY_SPACE:
			viilKeyCode = KeyCode::SPACE;
			break;
		case GLFW_KEY_TAB:
			viilKeyCode = KeyCode::TAB;
			break;
		case GLFW_KEY_UP:
			viilKeyCode = KeyCode::UP_ARROW;
			break;
		default:
			viilKeyCode = KeyCode::UNKNOWN;
		}

		return viilKeyCode;
	}

	void mouseCursorPositionCallback(GLFWwindow* windowHandel, double xPos, double yPos)
	{
		Window::WindowData& winData = *(Window::WindowData*)glfwGetWindowUserPointer(windowHandel);
		MouseMovedEvent event = VIIL::MouseMovedEvent(xPos, yPos);

		winData.callBackFn(event);
	}

	void mouseScrollCallback(GLFWwindow* windowHandel, double xOffset, double yOffset)
	{
		Window::WindowData& winData = *(Window::WindowData*)glfwGetWindowUserPointer(windowHandel);

		VIIL::MouseScrolledEvent event = VIIL::MouseScrolledEvent(xOffset, yOffset);
		winData.callBackFn(event);
	}

	void mouseButtonCallback(GLFWwindow* windowHandel, int buttonCode, int action, int modifiers)
	{
		Window::WindowData& winData = *(Window::WindowData*)glfwGetWindowUserPointer(windowHandel);
		int btnCode = glfwToViilMouseButtonCode(buttonCode);

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
		int code = glfwToViilKeyCode(keyboardKeyCode);

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