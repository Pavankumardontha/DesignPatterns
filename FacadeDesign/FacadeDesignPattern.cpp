#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
We’re going to look at a pattern now that alters an interface, but for a different reason: 
to simplify the interface. It’s aptly named the Facade Pattern because this pattern hides 
all the complexity of one or more classes behind a clean, well-lit facade.
A Facade is just what you need: with the Facade Pattern you can take a complex subsystem 
and make it easier to use by implementing a Facade class that provides one, more reasonable
interface. Don’t worry; if you need the power of the complex subsystem, it’s still there 
for you to use, but if all you need is a straightforward interface, the Facade is there 
for you.
To use the Facade Pattern, we create a class that simplifi es and unifi es a set of more
complex classes that belong to some subsystem. Unlike a lot of patterns, Facade is fairly
straightforward; there are no mind bending abstractions to get your head around. But that
doesn’t make it any less powerful: the Facade Pattern allows us to avoid tight coupling 
between clients and subsystems.
There isn’t a lot here that you don’t already know, but one of the most important things
to remember about a pattern is its intent. This defi nition tells us loud and clear that 
the purpose of the facade it to make a subsystem easier to use through a simplifi ed 
interface.

Example:
In real-world payment systems, multiple steps and services are involved, such as:
1)User authentication
2)Fraud detection
3)Transaction logging
4)Multiple payment gateways (PayPal, Stripe, etc.)
5)Email/SMS notifications

Instead of exposing all these services directly to the client, we'll use a PaymentFacade 
to simplify interactions.
*/

class AuthenticationService
{
public:
	static bool authenticateUser(string user)
	{	
		cout<<"authenticating user: "<<user<<endl;
		return true;	
	}
};


class PaypalGateway
{
	string user;
	string card_no;
	bool is_authenticated;
public:
	PaypalGateway(string user, string card_no)
	{
		this->user = user;
		this->card_no = card_no;
		this->is_authenticated = false;
	}
	
	bool AuthenticateUser()
	{
		this->is_authenticated = AuthenticationService::authenticateUser(this->user);
		return this->is_authenticated;
	}
	
	bool pay(double amount,string to_user)
	{
		if(this->is_authenticated)
		{
			cout<<"paying amount: "<<amount<<"from user: "<<this->user<< " to user:"<<to_user<<endl;
			return true;
		}
		return false;
	}
};


class NotificationService
{
public:
	static void sendEmail(string user,string content)
	{
		cout<<"Sending email to user: "<<user<<" with content: "<<content<<endl;
	}
	static void sendSMS(string user, string content)
	{
		cout<<"Sending SMS to user: "<<user<<" with content: "<<content<<endl;
	}
};




class Transactionlogging
{
public:
	static void logTransaction(string from_user, string to_user, string gateway, double amount)
	{
		cout<<"amount: "<<amount<<" transferred from user: "<<from_user<<" to user: "<<to_user<<"from gateway: "<<gateway<<endl;
	}
};


class PaymentFacade
{
	PaypalGateway* pg;
	string user;
	string card_no;
	public:
	PaymentFacade(string user, string card_no)
	{
		this->user = user;
		this->card_no = card_no;
		this->pg = new PaypalGateway(user,card_no);
	}
	bool processPayment(string to_user, double amount)
	{
		pg->AuthenticateUser();
		pg->pay(amount,to_user);
		Transactionlogging::logTransaction(this->user,to_user,"paypal",amount);
		string notification_body = "payment to user: " + to_user + " successful";
		NotificationService::sendSMS(this->user,notification_body);
		NotificationService::sendEmail(this->user,notification_body);
		return true;
	}
};

int main()
{
	// this is how the client code looks to process payment without PaymentProcessFacade class
	PaypalGateway* pg = new PaypalGateway("pavan","csy12323");
	pg->AuthenticateUser();
	pg->pay(345.56,"pradeep");
	Transactionlogging::logTransaction("pavan","pradeep","paypal",345.56);
	NotificationService::sendSMS("pavan","payment to pradeep successful");
	NotificationService::sendEmail("paven","payment to pradeep successful");
	
	// with PaymentProcessorFacade class
	cout<<"---using PaymentFacade interface----"<<endl;
	PaymentFacade* pf = new PaymentFacade("pavan1", "erw345");
	pf->processPayment("pradeep1",546);
	/*
	So the payment facade class , makes the job of the client easier to process
	payment. The client interacts only with facade class to process the payment
	instead of multiple other classes. The client if wants , can also interact
	with the underlying classes to complete the payment. 
	*/
}
