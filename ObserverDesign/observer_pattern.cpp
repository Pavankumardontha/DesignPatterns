#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class IObserver
{
public:
	virtual void notify()=0;
};

class IObservable
{
public:
	virtual void remove_observer(IObserver* ob)=0;
	virtual void add_observer(IObserver* ob)=0;
	virtual void notify_observers()=0;
};

class MessageGroup : public IObservable
{
	string name;
	vector<IObserver*> observers;
	public:
		MessageGroup(string name)
		{
			this->name = name;
		}
		void send_message(string message)
		{
			cout<<"sending message: "<<message<<" in group "<<this->name<<endl;
			notify_observers();
		}
		void add_observer(IObserver* ob)
		{
			observers.push_back(ob);
		}
		void remove_observer(IObserver* ob)
		{
			if(observers.size())
			observers.pop_back();
		}
		void notify_observers()
		{
			for(int i=0;i<observers.size();i++)
				observers[i]->notify();
		}
};

class Member : public IObserver
{
	string name;
	public:
		Member(string name)
		{
			this->name = name;
		}
		void notify()
		{
			cout<<"notifing member: "<<this->name<<endl;
		}
};

int main()
{
	IObserver* m1 = new Member("pavan");
	IObserver* m2 = new Member("vanitha");
	MessageGroup* message_group = new MessageGroup("CollegePlacements");
	message_group->add_observer(m1);
	message_group->add_observer(m2);
	message_group->send_message("hi everyone");
}
