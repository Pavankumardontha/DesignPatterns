import threading
import random


class TV:
    __singleton_instance = None # object of the TV class
    __channel = None # currently displaying channel no.

    @staticmethod
    def getInstance(): # method used to create and return TV object.
        if not TV.__singleton_instance: # check if no object of TV class exists
            with threading.Lock(): # Try to get the lock
                if not TV.__singleton_instance: # After getting lock also cross check if no object of TV class exists. IMPORTANT STEP 
                    TV.__singleton_instance = TV() # create TV object and assign it to the singleton_instance
        return TV.__singleton_instance # return the TV instance 

    def watch(self):
        print(f"Displaying channel:{TV.__channel}")

    def change_channel(self,new_channel):
        # Before changing the channel make sure that no other thread is changing the channel and Tv is free for channel a change. !!!
        with threading.Lock():
            TV.__channel = new_channel
            print(f"Channel changed to: {TV.__channel}")



def perform_TV_operations():
    obj = TV.getInstance()
    print(obj)
    obj.watch()
    obj.change_channel(random.randint(0,100))
    obj.watch()


#defining threads
thread1 = threading.Thread(target=perform_TV_operations)
thread2 = threading.Thread(target=perform_TV_operations)

#starting threads
thread1.start()
thread2.start()

#joining threads
thread1.join()
