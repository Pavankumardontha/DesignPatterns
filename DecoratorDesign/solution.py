from abc import ABC,abstractmethod

# abstract class for Burger
class Burger(ABC):
    @abstractmethod
    def getDescription(self):
        pass

    @abstractmethod
    def getCost(self):
        pass

# abstract class for Topplings
class Toppling(ABC):
    def __init__(self):
        self.__burger = None 
    
    def getDescription():
        pass
    def getCost():
        pass 


class ZingerBurger(Burger):
    def getDescription(self):
        return "Zinger Burger"
    
    def getCost(self):
        return 180.0

class TandoriBurger(Burger):
    def getDescription(self):
        return "Tandori Burger"
    
    def getCost(self):
        return 200.0 
    

class CheeseToppling(Toppling):
    def __init__(self,burger):
        self.__burger = burger #instance of burger object
    
    def getDescription(self):
        return self.__burger.getDescription() + " with extra cheese"

    def getCost(self):
        return self.__burger.getCost() + 10.0 


class MayoToppling(Toppling):
    def __init__(self,burger): 
        self.__burger = burger # instance of burger object

    def getDescription(self):
        return self.__burger.getDescription() + " with extra mayo"

    def getCost(self):
        return self.__burger.getCost() + 20.0

# Topplings have no meaning without burger. They can be sole only with burger 

# create zinger burger and add necessary topplings
zinger_burger = ZingerBurger()
print(zinger_burger.getDescription() + ":" + str(zinger_burger.getCost()))

# adding extra cheese
zinger_burger = CheeseToppling(zinger_burger)
print(zinger_burger.getDescription() + ":" + str(zinger_burger.getCost()))

# adding extra mayo
zinger_burger = MayoToppling(zinger_burger)
print(zinger_burger.getDescription() + ":" + str(zinger_burger.getCost()))


#create tandori burger and add necessary topplings
tandori_burger = TandoriBurger()
print(tandori_burger.getDescription() + ":" + str(tandori_burger.getCost()))

# adding extra cheese
tandori_burger = CheeseToppling(tandori_burger)
print(tandori_burger.getDescription() + ":" + str(tandori_burger.getCost()))

# adding extra mayo
tandori_burger = MayoToppling(tandori_burger)
print(tandori_burger.getDescription() + ":" + str(tandori_burger.getCost()))
