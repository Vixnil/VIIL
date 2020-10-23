#pragma once

#include "standardUse.h"

namespace VIIL
{
	enum class ShaderDataType
	{
		TYPE_UNKNOWN = -1
		,FLOAT ,FLOAT2 ,FLOAT3 ,FLOAT4
		,INT ,INT2 ,INT3 ,INT4
		,MTRX3, MTRX4
		,BOOL
	};

	static uint32_t shaderDataTypeCount(ShaderDataType type)
	{
		switch (type)
		{
		case VIIL::ShaderDataType::FLOAT:
		case VIIL::ShaderDataType::INT:
		case VIIL::ShaderDataType::BOOL:
			return 1;
			break;
		case VIIL::ShaderDataType::FLOAT2:
		case VIIL::ShaderDataType::INT2:
			return 2;
			break;
		case VIIL::ShaderDataType::FLOAT3:
		case VIIL::ShaderDataType::INT3:
			return 3;
			break;
		case VIIL::ShaderDataType::FLOAT4:
		case VIIL::ShaderDataType::INT4:
			return 4;
			break;
		case VIIL::ShaderDataType::MTRX3:
			return 3 * 3;
			break;
		case VIIL::ShaderDataType::MTRX4:
			return 4 * 4;
			break;
		default:
			VL_APP_FATAL("Failed to return count of shader type: {0}", type);
			return -1;
			break;
		}
	}

	static uint32_t shaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case VIIL::ShaderDataType::FLOAT:
		case VIIL::ShaderDataType::FLOAT2:
		case VIIL::ShaderDataType::FLOAT3:
		case VIIL::ShaderDataType::FLOAT4:
		case VIIL::ShaderDataType::MTRX3:
		case VIIL::ShaderDataType::MTRX4:
			return sizeof(float) * shaderDataTypeCount(type);
			break;
		case VIIL::ShaderDataType::INT:
		case VIIL::ShaderDataType::INT2:
		case VIIL::ShaderDataType::INT3:
		case VIIL::ShaderDataType::INT4:
			return sizeof(int) * shaderDataTypeCount(type);
			break;
		case VIIL::ShaderDataType::BOOL:
			return sizeof(bool);
			break;
		default:
			VL_APP_FATAL("Failed to return size of shader type: {0}", type);
			return -1;
			break;
		}
	}

	struct BufferElement
	{
		std::string name;
		ShaderDataType type;
		uint32_t size;
		uint32_t offset;
		bool isNormalized;

		BufferElement():
			name("defaultVal"), type(ShaderDataType::FLOAT), size(shaderDataTypeSize(ShaderDataType::FLOAT)), offset(0), isNormalized(false)
		{}

		BufferElement(ShaderDataType newType, const std::string& newName, bool setIsNormalized = false):
			name(newName), type(newType), size(shaderDataTypeSize(newType)), offset(0), isNormalized(setIsNormalized)
		{

		}

		uint32_t getTypeCount() const
		{
			return shaderDataTypeCount(type);
		}
	};

	class BufferLayout
	{
		using BufferElementsVec = std::vector<BufferElement>;
		BufferElementsVec elements;
		uint32_t stride;

		void calculateOffsetAndStride()
		{
			uint32_t currOffset = 0;
			stride = -1;

			for (auto& element : elements)
			{
				element.offset = currOffset;
				currOffset += element.size;
			}

			stride = currOffset;
		}

	public:
		BufferLayout():
			elements(), stride(0)
		{}

		BufferLayout(const std::initializer_list<BufferElement>& elementList):
			elements(elementList)
		{
			calculateOffsetAndStride();
		}

		inline uint32_t getStride() const { return stride; }

		const BufferElementsVec::const_iterator begin() const { return elements.begin(); }
		const BufferElementsVec::const_iterator end() const { return elements.end(); }

		inline const std::vector<BufferElement>& getElements() const { return elements; }
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() 
		{
			VL_ENGINE_TRACE("Default vertext buffer destructor.");
		};
		
		virtual void setLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& getLayout() const = 0;
		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		static std::shared_ptr<VertexBuffer> Create(float* vertices, uint32_t size);

	};

}
