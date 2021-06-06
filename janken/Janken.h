#pragma once

#include "Task.h"

class Janken : public Task
{
public:
	Janken();
	virtual ~Janken() = default;
	bool update() override;
	void draw() const override;
private:
	void initialize();
	void inputJanken();
	void calcJanken();
	int player, com, state;
	int image[3];
};
