#pragma once
class Ticket
{
protected:
	int number;
	double price;

public:

	static int order;
	Ticket();
	Ticket(double price);
	~Ticket();
	int getNumber() const;
	double getPrice() const;
	void setPrice(const double& price);
	void show() const;
};