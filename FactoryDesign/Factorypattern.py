class Circle():
    def draw(self):
        print("Circle is drawn")

class Square():
    def draw(self):
        print("Square is drawn")

class Triangle():
    def draw(self):
        print("Triangle is drawn")


client_input = "circle"

# if there is no factory class 
if (client_input == "circle" ):
    client_object = Circle()
elif (client_input == "square"):
    client_object = Square()
elif (client_input == "triangle"):
    client_object = Triangle()
else:
    client_object = None

client_object.draw()



# Implementing factory class for creating different shapes based on user input.
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
client_object = shapefactory.getShape(client_input)
client_object.draw()

