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
		virtual void open() const = 0;
		virtual void close() const = 0;
		virtual std::string getLine() const = 0;
		virtual bool isEndOfFile() const = 0;
	};

	std::shared_ptr<File> createFile(const std::string& filePath);
}

