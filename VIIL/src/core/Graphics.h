#pragma once

namespace VIIL
{
	class Graphics
	{
	protected:
		bool isInit;
	public:
		Graphics():
			isInit(false)
		{}
		Graphics(bool condition) :
			isInit(condition)
		{}

		inline bool getIsInit() { return isInit; }
	}; 

}