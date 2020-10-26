#pragma once
#include "core/standardUse.h"
#include "renderer/interface/VertexBuffer.h"
#include "renderer/OpenGL/OpenGLInclude.h"

namespace VIIL
{

	static int viilShaderDataTypeToGlfwDataType(ShaderDataType type)
	{
		switch (type)
		{
		case VIIL::ShaderDataType::FLOAT:
		case VIIL::ShaderDataType::FLOAT2:
		case VIIL::ShaderDataType::FLOAT3:
		case VIIL::ShaderDataType::FLOAT4:
		case VIIL::ShaderDataType::MTRX3:
		case VIIL::ShaderDataType::MTRX4:
			return GL_FLOAT;
			break;
		case VIIL::ShaderDataType::INT:
		case VIIL::ShaderDataType::INT2:
		case VIIL::ShaderDataType::INT3:
		case VIIL::ShaderDataType::INT4:
			return GL_INT;
			break;
		case VIIL::ShaderDataType::BOOL:
			return GL_BOOL;
			break;
		default:
			VL_APP_FATAL("Failed to return glfw data type of shader type: {0}", type);
			return -1;
			break;
		}
	}

	class OpenGLVertexBuffer : public VertexBuffer
	{
		BufferLayout buffLayout;
		uint32_t bufferId;

	public:

		OpenGLVertexBuffer(float* vertices, uint32_t size);

		virtual ~OpenGLVertexBuffer() override;

		virtual inline const BufferLayout& getLayout() const override { return buffLayout; }
		virtual inline void setLayout(const BufferLayout& layout) override { buffLayout = layout; }
		virtual void bind() const override;
		virtual void unbind() const override;
	};
}
