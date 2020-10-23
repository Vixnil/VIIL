#pragma once
#include "standardUse.h"
#include "VertexArray.h"

#include <glm/glm.hpp>

namespace VIIL
{

	class RendererLibrary
	{
	public:

		enum Type
		{
			None = -1,
			OpenGL
		};

		virtual void setClearColor(const glm::vec4& color) = 0;
		virtual void clear() = 0;

		virtual void drawVertexArray(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		inline static Type getType() { return libraryType; }
	private:
		static Type libraryType;
	};



}