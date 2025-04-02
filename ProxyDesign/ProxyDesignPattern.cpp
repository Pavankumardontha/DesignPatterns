/*
The Proxy design pattern is a structural pattern that provides a surrogate or 
placeholder for another object to control access to it. In the context of a payment 
gateway, a proxy can be useful for several purposes like security, caching, or lazy 
initialization.

Payment Gateway Scenario :-
Imagine you're integrating multiple payment gateways (like Stripe, PayPal, etc.) into 
your e-commerce system. Directly calling these external services for every payment 
operation can be inefficient and potentially insecure. A payment gateway proxy can 
help by:
1) Caching frequent requests
2) Validating inputs before forwarding
3) Logging transactions
4) Providing a fallback mechanism if the real gateway is down
5)Adding security layers

The client interacts with the proxy just as it would with the real payment gateway, 
but gets these additional benefits transparently.
This pattern is particularly useful when working with external services where you want 
to minimize actual calls, add safety checks, or maintain better control over the 
interaction.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class IPaymentGateway
{
public:
	virtual void processPayment()=0;
	virtual void refundPayment()=0;
};

class StripePaymentGateway : public IPaymentGateway
{
public:
	void processPayment()
	{
		cout<<"Processing payment using stripe"<<endl;
	}
	void refundPayment()
	{
		cout<<"refunding payment using stripe"<<endl;
	}
};

class PaymentGatewayProxy : public IPaymentGateway
{
	IPaymentGateway* pg;
public:
	PaymentGatewayProxy()
	{
		this->pg = new StripePaymentGateway(); // we can take input from user if we have more paymentgateways
	}
	void processPayment()
	{
		// log transaction
		// add security layers
		cout<<"Start transaction"<<endl;
		this->pg->processPayment();
		cout<<"End transaction"<<endl;
	}
	
	void refundPayment()
	{
		// log transaction
		// add security layers
		cout<<"Refund transaction"<<endl;
		this->pg->refundPayment();
		cout<<"Refund successful"<<endl;
	}
};

int main()
{
	IPaymentGateway* pg = new PaymentGatewayProxy();
	// the client interacts with the proxy object only 
	pg->processPayment();
	pg->refundPayment();
}
