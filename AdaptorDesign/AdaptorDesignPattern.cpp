#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
The Adapter Pattern converts the interface of a class into another interface the clients 
expect. Adapter lets classes work together that couldn’t otherwise because of incompatible 
interfaces.
*/

/*
A common real-world use case for the Adapter Pattern is integrating multiple payment 
gateways (like PayPal, Stripe, or a legacy bank system) into a single unified interface.
Scenario:
Your e-commerce app needs to support multiple payment methods, but each payment provider 
has a different interface. Instead of rewriting your code for each provider, you use 
Adapters to make them work uniformly.
*/

class IEcommercePaymentProcessingGateway
{
	// this is the interface our e-commerce app expects from all its payment gateways
	/*
	But each payment gateway will have its own methods implemented with a different 
	interface. Also 
	*/
public:
	virtual void processPayment(double amount)=0;
	virtual void refundPayment(double amount)=0;
};

class IPaypalGateway
{
public:
	virtual void pay(double amount)=0;
	virtual void refund(double amount)=0;
	virtual void notify(string user)=0;
};

class IStripeGateway
{
public:
	virtual void pay(double amount)=0;
	virtual void refund(double amount)=0;
	virtual void retry(string user)=0;
};

// concrete class implementing IPayPalGateway
class PaypalGateway : public IPaypalGateway
{
public:
	void pay(double amount)
	{
		cout<<"Paying amount from paypal:"<<amount<<endl;
	}
	void refund(double amount)
	{
		cout<<"refunding amount from paypal:"<<amount<<endl;
	}
	void notify(string user)
	{
		cout<<"notify user from paypal: "<<user<<endl;
	}
};

// concrete class implementing IStripeGateway
class StripeGateway : public IStripeGateway
{
public:
	void pay(double amount)
	{
		cout<<"Paying amount from stripe:"<<amount<<endl;
	}
	void refund(double amount)
	{
		cout<<"refunding amount from stripe:"<<amount<<endl;
	}
	void retry(string user)
	{
		cout<<"Retrying payment from stripe for user:"<<user<<endl;
	}
};


/*
how to use the above concrete classes which does not implement our expected interface ?
Option-1 : We change our interface to adhere to different gateway interfaces. This is a very 
bad approach since each gateway processor has different method naming for same underlying
functionality
Option-2 : We tell the gateways to adopt our expected interface. This is bad since the 
gateway classes are vendor classes and we cannot impose conditions on them.

Option-3 : Create Adaptors for each payment gateway which we can use to convert the payment
gateway interfaces to our expected payment processing interface. This is the best approach
*/


class PaypalGatewayAdaptor : public IEcommercePaymentProcessingGateway
{
	// converts the paypalgateway inerface to our expected interface 
	// Note that this implements our expected interface 
	// PaypalGatewayAdaptor "is a" IEcommercePaymentProcessingGateway
	// Adaptor classes implement the expected interface to which it converts
	/*
	Paypal gatway Adaptor takes a paypalgateway object and converts that into an object of 
	IEcommercePaymentProcessinggGatway interface which will have our expected interface 
	methods implemented.
	*/
	PaypalGateway* paypalgateway = NULL;
public:
	PaypalGatewayAdaptor(PaypalGateway* paypalgateway)
	{
		this->paypalgateway = paypalgateway;
	}
	
	void processPayment(double amount) 
	{
		this->paypalgateway->pay(amount);
	}
	
	void refundPayment(double amount) 
	{
		this->paypalgateway->refund(amount);
	}
};


class StripeGatewayAdaptor : public IEcommercePaymentProcessingGateway
{
	StripeGateway* stripegateway = NULL;
public:
	StripeGatewayAdaptor(StripeGateway* stripegateway)
	{
		this->stripegateway = stripegateway;
	}
	
	void processPayment(double amount) 
	{
		this->stripegateway->pay(amount);
	}
	
	void refundPayment(double amount) 
	{
		this->stripegateway->refund(amount);
	}
	
};



int main()
{
	/* 
	this is our e-commerce client code. We will make use of different gateway adaptors
	to process and refund payments 
	*/
	
	// create payment gateway classes
	StripeGateway* stripegateway = new StripeGateway();
	PaypalGateway* paypalgateway = new PaypalGateway();
	
	IEcommercePaymentProcessingGateway* pg = new PaypalGatewayAdaptor(paypalgateway);
	IEcommercePaymentProcessingGateway* sg = new StripeGatewayAdaptor(stripegateway);
	
	pg->processPayment(50.00);
	pg->refundPayment(90.00);
	
	sg->processPayment(60.00);
	sg->refundPayment(30.00);
	
	/*
	In this way , if a new PaymentGateway comes , we can easily create a new adaptor
	for that class implementing our expected interface without disturbing the already 
	existing classes and also the client code will not get disturbed. The client can use 
	the new PaymentGateway adaptor as and when it needs.
	*/
}
