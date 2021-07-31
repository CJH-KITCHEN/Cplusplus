#pragma once
class Ticket
{
protected:
	int number;
	double price;
	double finalprice;
public:

	static int order;
	Ticket();
	Ticket(double price);
	virtual ~Ticket();
	int getNumber() const;
	virtual	double getPrice() const=0;
	void setPrice(const double& price);
	virtual void show() const;
	virtual double setFinalPrice()=0;
};