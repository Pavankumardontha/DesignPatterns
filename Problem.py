
'''
Imagine we have a dog class with few attributes and methods. With this below setup we face certain problems.Lets suppose that we give this class to the 
client. Lets understand what difficulties client faces in using this class that we have created.
- Client must always remember the order of parameters that he/she needs to give while initiating the object of the class. 
- Client must send all the required parameters without missing even one while initiating the object of the class.Different client using our same Dog class
might have different requirements and thus the initialisation should change for different clients.
Design issues that we need to take care of
- Once a dog has been initiated , by design its gender and breed should not change.So these should not change after initialisation.
- Lets say in the future , some new client comes and asks for our Dog class we need to provide them with all the functionalities. In this case , the 
client can ask for extra attributes or extra methods which are not required by client 1. 
These are some of the problems which builder design pattern solves. 
'''

class Dog:
    def __init__(self,name,age,breed,gender):
        self.__name = name
        self.__age = age
        self.__breed = breed
        self.__gender = gender 

    def set_name(self,name):
        self.__name = name

    def set_age(self,age):
        self.__age = age

    def set_breed(self,breed):
        self.__breed = breed
    
    def set_gender(self,gender):
        self.__gender = gender
    
    def get_name(self):
        return self.__name
    
    def get_age(self):
        return self.__age 
    
    def get_breed(self):
        return self.__breed
    
    def get_gender(self):
        return self.__gender

b = Dog("d1",12,"pug","male")
print(b)
b.set_name("k1")
print(b.get_name())
