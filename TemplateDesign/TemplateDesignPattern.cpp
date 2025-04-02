/*
The Template Method Pattern defi nes the skeleton
of an algorithm in a method, deferring some steps to
subclasses. Template Method lets subclasses redefi ne
certain steps of an algorithm without changing the
algorithm’s structure.

This pattern is all about creating a template for an algorithm. What’s a template?
As you’ve seen it’s just a method; more specifi cally, it’s a method that defines 
an algorithm as a set of steps. One or more of these steps is defi ned to be 
abstract and implemented by a subclass. This ensures the algorithm’s structure 
stays unchanged,while subclasses provide some part of the implementation.
The ConcreteClass implements the abstract operations, which are called when the 
templateMethod() needs them.
There may be many ConcreteClasses, each implementing the full set of operations 
required by the template method.

Abstract base class
{
	void templateMethod()
	{
		Dostep1();
		Dostep2();
		Dostep3();
		Dostep4();
	}
	
	void Dostep1()
	{
		
	}
	void Dostep4()
	{
		
	}
};

from the above , the template method will define an algorithm following a sequence
of steps. Some of the steps inside the template method can be concrete and are 
defined inside the abstract class itself like Dostep1 and Dostep4 methods. We also 
have methods which are abstract and need to be defined by the subclasses. Here 
Dostep2() and Dostep3() are the abstract methods. Subclasses should provide the 
implementations to these methods.

Example:

For a payment gateway to process payment, different steps must be done in order
to process the payment. There are multiple payment gateways and each gateway will
have different implementations of these steps. 

Lets say we have 2 different payment gateways CreditCardPaymentGateway and 
UPIPaymentGateway
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class AbstractPaymentGateway
{
public:
	void processPayment() // this is the template method
	{
		authenticateUser();
		IntiateTransaction();
		capturePayment();
		if(!confirmPayment())
		{
			handlePaymentFailure();
		}
	}
	virtual void authenticateUser() = 0; // implementation provided by subclasses
	virtual void capturePayment() = 0; // implementation provided by subclasses
	virtual bool confirmPayment() = 0; // implementation provided by the subclasses
	void IntiateTransaction()
	{
		cout<<"Initiating transaction...."<<endl;
	}
	
	void handlePaymentFailure()
	{
		cout<<"Handle payment failure...."<<endl;
	}
	
};

class UPIPaymentGateway : public AbstractPaymentGateway
{
public:
	UPIPaymentGateway() : AbstractPaymentGateway()
	{
		
	}
	void authenticateUser() 
	{
		cout<<"Authenticating user with UPIPaymentGateway"<<endl;
	}
	
	void capturePayment()
	{
		cout<<"Capturing payment through UPIPaymentGateway"<<endl;
	}
	
	bool confirmPayment()
	{
		cout<<"Payment confirmed through UPIPaymentGateway"<<endl;
		return true;
	}
};



class CreditCardPaymentGateway : public AbstractPaymentGateway
{
public:
	CreditCardPaymentGateway() : AbstractPaymentGateway()
	{
		
	}
	void authenticateUser() 
	{
		cout<<"Authenticating user with CreditCardPaymentGateway"<<endl;
	}
	
	void capturePayment()
	{
		cout<<"Capturing payment through CreditCardPaymentGateway"<<endl;
	}
	
	bool confirmPayment()
	{
		cout<<"Payment confirmed through CreditCardPaymentGateway"<<endl;
		return true;
	}
};


int main()
{
	AbstractPaymentGateway* pg1 = new UPIPaymentGateway();
	AbstractPaymentGateway* pg2 = new CreditCardPaymentGateway();
	pg1->processPayment();
	pg2->processPayment(); 
	
}
