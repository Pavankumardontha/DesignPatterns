'''
We will define 3 shape classes 
a) Circle 
b) Square
c) Triangle
'''
class Circle():
    def draw(self):
        print("Circle is drawn")

class Square():
    def draw(self):
        print("Square is drawn")

class Triangle():
    def draw(self):
        print("Triangle is drawn")


# This is how the shape object creation code looks at client end without Shapefactory class
circle_object = Circle()
circle_object.draw()
square_object = Square()
square_object.draw()
triangle_object = Triangle()
triangle_object.draw()
# Notice here that the client needs to interact and remember all the 3 classes to create any shape object

# Implementing factory class for creating different shape objects.
class ShapeFactory():
    def getShape(self,shape):
        if ( shape == "circle" ):
            return Circle()
        elif ( shape == "square" ):
            return Square()
        elif ( shape == "triangle" ):
            return Triangle()
        else:
            return None
        

# using shapefactory class to create shape object
shapefactory = ShapeFactory()
circle_object = shapefactory.getShape("circle")
circle_object.draw()
square_object = shapefactory.getShape("square")
square_object.draw()
triangle_object = shapefactory.getShape("triangle")
triangle_object.draw()
# Look how simple the shape object creation looks !!! Client will be very much happy since he/she has to deal with ONLY one class and NOT 3 as before.


