#include "core/standardUse.h"
#include "platform/windows/WindowsFile.h"

namespace VIIL
{
	static const int fileReadBufferSize = 2048;

	WindowsFile::WindowsFile(const std::string& newFilePath):
		endOfFile(true)
	{
		filePath = newFilePath;
	}

	void WindowsFile::open() const
	{
		inStream.open(filePath);
		endOfFile = false;
	}

	void WindowsFile::close() const
	{
		inStream.close();
		endOfFile = true;
	}

	std::string WindowsFile::getLine() const
	{
		std::string contents;
		char buffer[fileReadBufferSize];

		endOfFile = inStream.getline(buffer, fileReadBufferSize).eof();
		contents.append(buffer);
		contents.append("\n");

		return contents;
	}

	std::string WindowsFile::readFileToString() const
	{
		std::string contents;
		char buffer[fileReadBufferSize];

		inStream.open(filePath);

		while (inStream.getline(buffer, fileReadBufferSize))
		{
			contents.append(buffer);
			contents.append("\n");
		}

		return contents;
	}
}
