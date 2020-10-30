#pragma once
#include "core/standardUse.h"

namespace VIIL
{

	class File
	{
	public:
		virtual ~File()
		{}

		virtual std::string readFileToString() const = 0;
	};

	std::shared_ptr<File> createFile(const std::string& filePath);
}

