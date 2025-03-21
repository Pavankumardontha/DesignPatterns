#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class AbstractBurger
{
public:
	virtual double getCost()=0;
	virtual string getDescription()=0;
};

class ZingerBurger : public AbstractBurger
{
public:
	double getCost() override
	{
		return 80.00;
	}
	
	string getDescription() override
	{
		return "Zinger Burger ";
	}
};

class TandooriBurger : public AbstractBurger
{
public:
	double getCost() override
	{
		return 90.00;
	}
	
	string getDescription() override
	{
		return "Tandoori Burger ";
	}
};


class AbstractTopplingDecorator : public AbstractBurger
{
	/*
	- TopplingDecorator class must inherit from the decorated class (here the burger class)
	- Every decorator will have a reference to burger object
	*/
public:
	AbstractBurger* burger;
	virtual double getCost() = 0;
	virtual string getDescription() = 0;
};

class CheeseToppling : public AbstractTopplingDecorator
{
public:
	CheeseToppling(AbstractBurger* burger)
	{
		this->burger = burger;
	}
	
	string getDescription() override
	{
		return this->burger->getDescription() + " with extra cheese";
	}
	
	double getCost() override
	{
		return this->burger->getCost() + 10.00;
	}
};


class MayoToppling : public AbstractTopplingDecorator
{
public:
	MayoToppling(AbstractBurger* burger)
	{
		this->burger = burger;
	}
	string getDescription() override
	{
		return this->burger->getDescription() + " with extra mayo";
	}
	double getCost() override
	{
		return (this->burger->getCost() + 20.00);
	}	
};

int main()
{
	AbstractBurger* zinger_burger = new ZingerBurger();
	AbstractBurger* tandoori_burger = new TandooriBurger();
	cout<<zinger_burger->getDescription()<<": "<<zinger_burger->getCost()<<endl;
	cout<<tandoori_burger->getDescription()<<": "<<tandoori_burger->getCost()<<endl;
	
	// Add cheese toppling cost = 10
	zinger_burger = new CheeseToppling(zinger_burger);
	tandoori_burger = new CheeseToppling(tandoori_burger);
	cout<<zinger_burger->getDescription()<<": "<<zinger_burger->getCost()<<endl;
	cout<<tandoori_burger->getDescription()<<": "<<tandoori_burger->getCost()<<endl;
	
	// Add mayo toppling cost = 20
	zinger_burger = new MayoToppling(zinger_burger);
	tandoori_burger = new MayoToppling(tandoori_burger);
	cout<<zinger_burger->getDescription()<<": "<<zinger_burger->getCost()<<endl;
	cout<<tandoori_burger->getDescription()<<": "<<tandoori_burger->getCost()<<endl;
	
}