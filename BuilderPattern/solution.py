'''
1.We first remove all the setter methods for attributes we do not want to change after the object is initiated.So we will remove setter methods for gender
attribute and breed attribute from our Dog class.
2.We will create another class Builder which has all the attributes as that of class Dog with all setter and getter methods. Client first creates this 
Builder class object , uses few setters to change the attributes and when finally done, passes on this object to the constructor of class Dog. 
'''
class Builder:
    def __init__(self):
        self.name = self.breed = self.gender = ""
        self.age = 0

class Dog:
    def __init__(self,x):
        self.__name = x.name
        self.__age = x.age
        self.__breed = x.breed
        self.__gender = x.gender 

    def set_name(self,name):
        self.__name = name

    def set_age(self,age):
        self.__age = age

    # remove setters of both breed and gender since we do not want to set them once object has been initialised
    # def set_breed(self,breed):
    #     self.__breed = breed
    
    # def set_gender(self,gender):
    #     self.__gender = gender
    
    def get_name(self):
        return self.__name
    
    def get_age(self):
        return self.__age 
    
    def get_breed(self):
        return self.__breed
    
    def get_gender(self):
        return self.__gender


# client needs to first create Builder object
builder = Builder()
builder.name = "puppy"
builder.gender = "male"
builder.breed = "pug"

# create Dog object with this builder object
dog = Dog(builder)
print(dog.get_name())
print(dog.get_breed())
print(dog.get_gender())
print(dog.get_age())
