#pragma once

#include <list>

class Fps
{
public:
	Fps();
	~Fps() = default;
	void wait();
	void draw() const;
private:
	std::list<int> timeList;
	float fps;
	unsigned int counter;

	void updateAverage();
	void regist();
	unsigned int getWaitTime() const;
};
