'''
We will define 3 classes for cars
a) InnovaCar Class
b) FortunerCar Class
c) CarFactory Class
'''
class InnovaCar():
    def drive(self):
        print("Driving Innova car")

class FortunerCar():
    def drive(self):
        print("Driving Fortuner car")

class CarFactory():
    def getVehicle(self,car):
        if ( car == "Innova" ):
            return InnovaCar()
        elif ( car == "Fortuner" ):
            return FortunerCar()
        else:
            return None

'''
We will define 3 classes for bikes
a) ActivaBike Class
b) DukeBike Class
c) BikeFactory Class
'''


class ActivaBike():
    def drive(self):
        print("Driving Activa Bike")

class DukeBike():
    def drive(self):
        print("Driving Duke Bike")

class BikeFactory():
    def getVehicle(self,bike):
        if ( bike == "Activa" ):
            return ActivaBike()
        elif ( bike == "Duke" ):
            return DukeBike()
        else:
            return None

# if there is no abstract factory class, the client needs to deal with car factory as well as bike factory class in his code

# use bike factory to create bike objects
bike_factory = BikeFactory()
bike = bike_factory.getVehicle("Activa")
bike.drive()

# use car factory to create car objects
car_factory = CarFactory()
car = car_factory.getVehicle("Fortuner")
car.drive()


# If there is an abstract factory class , client does not have to deal with bike as well as car factory classes.
class AbstractVehicleFactory():
    def getVehicle(self,vehicle):
        if vehicle in ["Active","Duke"]:
            return BikeFactory().getVehicle(vehicle)
        elif vehicle in ["Fortuner","Innova"]:
            return CarFactory().getVehicle(vehicle)
        else:
            return None

# use abstract vehicle factory to create a bike and car objects
abstract_factory = AbstractVehicleFactory()
bike = abstract_factory.getVehicle("Duke")
bike.drive()
car = abstract_factory.getVehicle("Innova")
car.drive()

# The client now has to deal ONLY with abstract vehicle factory class and not with Car factory and bike factory classes.
