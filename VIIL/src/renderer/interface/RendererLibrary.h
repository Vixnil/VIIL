#pragma once
#include "core/standardUse.h"
#include "renderer/interface/VertexArray.h"

#include <glm/glm.hpp>

namespace VIIL
{
	/*
	* Platform/Rendering API independent rendering library. 
	*/
	class RendererLibrary
	{
	public:

		enum Type
		{
			None = -1,
			OpenGL
		};

		virtual void setClearColor(const glm::vec4& color) = 0;
		virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void clear() = 0;

		virtual void drawVertexArray(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		inline static Type getType() { return libraryType; }
	private:
		static Type libraryType;
	};



}