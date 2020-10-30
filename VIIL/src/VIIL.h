#pragma once
#define STB_IMAGE_IMPLEMENTATION

//VIIL project headers that should be accessaible by other applications
#include "core/Application.h"
#include "core/Logger.h"
#include "core/Entry.h"
#include "core/Layer.h"
#include "core/LayerStack.h"

#include "event/event.h"
#include "event/app.h"
#include "event/key.h"
#include "event/mouse.h"

#include "input/inputValues.h"

#include "platform/interface/File.h"

#include "renderer/Renderer.h"
#include "renderer/Camera.h"
#include "renderer/Scene.h"
#include "renderer/interface/IndexBuffer.h"
#include "renderer/interface/Shader.h"
#include "renderer/interface/Texture.h"
#include "renderer/interface/VertexBuffer.h"
#include "renderer/interface/VertexArray.h"

#include "UserInterface/imguiLayer.h"
