'''
Imagine we are in a big family. We have only one tv object in our house. TV is one single entity and every family member has to use this one single object.
If member-1 of the family wishes to watch tv , he/she will get the same object as member-2. There is only one TV and so only one instance of TV is 
possible. We cannot instanciate the TV object again and again.
'''

# make the constructor of the TV class private so that it cant be accessed by all the clients. This cannot be done in python !!
# create GetInstance method which returns the instance of the class. But we need to keep this method as static if not the method should be called on object
# Make the process of creation of instance thread safe and use double checking. This is the most important part.


import threading
class TV:
    __singleton_instance = None

    @staticmethod
    def getInstance():
        if not TV.__singleton_instance:
            with threading.Lock():
                if not TV.__singleton_instance: # IMPORTANT STEP 
                    TV.__singleton_instance = TV()
        return TV.__singleton_instance


def get_TV():
    obj = TV.getInstance()
    print(obj)

object1 = TV.getInstance()
print(object1)
object2 = TV.getInstance()
print(object2)

#defining threads
thread1 = threading.Thread(target=get_TV)
thread2 = threading.Thread(target=get_TV)

#starting threads
thread1.start()
thread2.start()

#joining threads
thread1.join()
thread2.join()



