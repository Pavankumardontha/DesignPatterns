from abc import ABC,abstractmethod

class ObserverInterface(ABC):
    @abstractmethod
    def update(self,temperatur,humidity):
        pass

class ObservableInterface(ABC):
    # abstract class with only abstract methods(no concrete methods should be present) is an interface in python
    @abstractmethod
    def register_observer(self,observer):
        pass
    @abstractmethod
    def remove_observer(self,observer):
        pass 
    @abstractmethod
    def notify_observers(self):
        pass 

class WeatherStation(ObservableInterface):
    def __init__(self):
        self.__temperature = self.__humidity = None
        self.__observers = list() 
    
    def register_observer(self,observer):
        if observer not in self.__observers:
            self.__observers.append(observer)

    def remove_observer(self, observer):
        if observer in self.__observers:
            self.__observers.remove(observer)

    def notify_observers(self):
        for observer in self.__observers:
            observer.update(self.__temperature,self.__humidity)

    def set_parameters(self,temperature,humidity):
        self.__temperature = temperature
        self.__humidity = humidity
        self.notify_observers()


class AverageTemperaturDisplay(ObserverInterface):

    def __init__(self,observable):
        self.__sum_of_temperatures = self.__total_temperatures = 0
        observable.register_observer(self)

    def display(self):
        if self.__total_temperatures:
            print(f"Average Temperature: {self.__sum_of_temperatures/self.__total_temperatures}")
        else:
            print("Average Temperatur: 0.0")

    def update(self,temperature,humidity):
        self.__sum_of_temperatures = self.__sum_of_temperatures + temperature
        self.__total_temperatures = self.__total_temperatures + 1 
        self.display()


class CurrentWeatherConditionsDisplay(ObserverInterface):

    def __init__(self,observable):
        self.__temperature = self.__humidity = None
        observable.register_observer(self)
    
    def display(self):
        print(f"Current Temperature: {self.__temperature}. Current Humidity: {self.__humidity}")

    def update(self, temperature, humidity):
        self.__temperature = temperature
        self.__humidity = humidity
        self.display()


weather_station = WeatherStation()
average_temperature_display = AverageTemperaturDisplay(weather_station)
current_weather_display = CurrentWeatherConditionsDisplay(weather_station)
weather_station.set_parameters(20,10)

weather_station.set_parameters(10,20)




