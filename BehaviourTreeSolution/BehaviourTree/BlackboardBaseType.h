#pragma once
class BlackboardBaseType
{
public:
	BlackboardBaseType();
	~BlackboardBaseType();
};

class BlackboardBoolType :public BlackboardBaseType
{
public:
	BlackboardBoolType(bool val) : value (val){};
	bool GetValue() {return value;}
	void SetValue(bool val) {value = val;}

	private:
		bool value;
};

class BlackboardIntType :public BlackboardBaseType
{
public:
	BlackboardIntType(int val) : value(val) {};
	int GetValue() { return value; }
	void SetValue(int val) { value = val; }

private:
	int value;
};

class BlackboardCharType :public BlackboardBaseType
{
public:
	BlackboardCharType(char val) : value(val) {};
	char GetValue() { return value; }
	void SetValue(char val) { value = val; }

private:
	char value;
};

class BlackboardFloatType :public BlackboardBaseType
{
public:
	BlackboardFloatType(float val) : value(val) {};
	float GetValue() { return value; }
	void SetValue(float val) { value = val; }

private:
	float value;
};