/*
A mutex allows only one thread at a time to access a section of 
code (called a critical section) that manipulates shared data.
A mutex (short for mutual exclusion) is a synchronization primitive 
used to protect shared resources from being accessed simultaneously 
by multiple threads, which can cause race conditions or undefined 
behavior.
In C++, the std::mutex class (from the <mutex> header) is used for locking.

Best practice for locking : use std::lock_guard
SYNTAX: std::lock_guard<std::mutex> lock(mtx);
The above syntax does the following things for you
->Automatically locks the mutex on creation
->Automatically unlocks the mutex when `lock` goes out of scope (RAII)

A lock guard (or mutex guard) ensures that only one thread can 
execute the critical section of code at a time. This is the 
fundamental purpose of synchronization primitives like mutexes and 
their guard wrappers.

How Lock Guards Work:
Exclusive Access: When a thread acquires the lock (through the 
lock guard), no other thread can acquire the same lock until it's 
released.

Automatic Management: The lock guard typically follows RAII (Resource Acquisition Is Initialization) principles:
1)The lock is acquired when the guard is constructed
2)The lock is automatically released when the guard goes out of 
scope
3)Thread Safety: This ensures thread-safe access to shared resources 
within the critical section.
*/

#include<bits/stdc++.h>
#include<iostream>
#include<mutex>
using namespace std;


class Singleton
{
private:
	Singleton(){}
	~Singleton(){}
	// Delete copy constructor and assignment operator    
    /*
    Singleton(const Singleton&) = delete; This tells the compiler: “Do not allow copying an object with the copy constructor.”
    Singleton& operator=(const Singleton&) = delete; This tells the compiler: “Do not allow copying an object via assignment.”
    Any attempt to copy or assign a singleton instance will cause a compilation error
    for a Singleton, you only want ONE instance. If someone copies it, that breaks the whole idea of a singleton.
    */
	Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    // static singleton and mutex
	static Singleton* instance;
	static mutex mtx;
	/* In C++, only static data members (variables) need to be defined outside the class (in addition to their declaration inside the class).
	So we define both of the variables outside the class too.
	*/
	 
public:
	static Singleton* getInstance()
	{
		if(instance == NULL) // first check
		{
			lock_guard<mutex> lock(mtx); // locking :- only one thread can execute the statements below in the critical section
			// check again after acquiring lock
			if(instance == NULL)
			instance = new Singleton();
			//lock will be automatically released after all the statements inside the if condition are executed since the lock scope is limited 
		}
		return instance;
	}
};

// VERY VERY IMPORTANT STEP TO DEFINE THE STATIC VARIABLES INSIDE AND OUTSIDE OF THE SINGLETON CLASS
Singleton* Singleton::instance = NULL;
mutex Singleton::mtx;

int main()
{
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();
	cout<<s1<<endl;
	cout<<s2<<endl;
}
