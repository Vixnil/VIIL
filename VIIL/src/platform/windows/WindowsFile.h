#pragma once
#include "core/standardUse.h"
#include "platform/interface/File.h"

namespace VIIL
{

	class WindowsFile : public File
	{
		std::string filePath;

	public:
		WindowsFile(const std::string& newFilePath);

		virtual std::string readFileToString() const;
	};

	std::shared_ptr<File> createFile(const std::string& filePath)
	{
		return std::make_shared<WindowsFile>(filePath);
	}
}