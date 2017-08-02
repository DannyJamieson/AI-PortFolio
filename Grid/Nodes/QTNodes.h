#pragma once
class QTNodes
{
public:
	QTNodes();
	~QTNodes();
	int depth;
	double x, y;
	double width, height;
	QTNodes *a, *b, *c, *d;

	void Add();
	void Split();
};

