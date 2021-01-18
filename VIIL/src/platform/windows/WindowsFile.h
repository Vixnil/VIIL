#pragma once
#include "core/standardUse.h"
#include "platform/interface/File.h"

#include <fstream>

namespace VIIL
{

	/*
	* Microsoft Windows OS implementation of the File class
	*/
	class WindowsFile : public File
	{
		std::string filePath;
		mutable std::ifstream inStream;
		mutable bool endOfFile;

	public:
		WindowsFile(const std::string& newFilePath);

		virtual std::string getName() const override;
		virtual std::string getExt() const override;

		virtual std::string readFileToString() const override;
		virtual void open() const override;
		virtual void close() const override;
		virtual std::string getLine() const override;
		virtual inline bool isEndOfFile() const override { return endOfFile; }

	};

	std::shared_ptr<File> createFile(const std::string& filePath)
	{
		return std::make_shared<WindowsFile>(filePath);
	}
}