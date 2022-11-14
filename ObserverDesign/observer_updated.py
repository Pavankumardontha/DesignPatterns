from datetime import datetime

'''
We will have 3 classes 
a) PlacementMessageGroup class - 1 object
b) PlacementAdmin class - 1 object
c) Student class - Many objects 
'''

class PlacementMessageGroup:
    def __init__(self,name):
        self.name = name
        self.__messages_list = list() # contains list of all messages published in the message group
        self.__students_list = list() # list of student objects present in the message group 

    def publish_message(self,admin,message):
        print(f"Admin: {admin.name} at {datetime.now()} published message : {message}")
        self.__messages_list.append(message)
        self.notify_all_students(admin,message) #notify all students present in the message group about the message being published by placement admin

    def notify_all_students(self,admin,message):
        for student in self.__students_list:
            student.notify(admin,message)
        print(f"-----All students notified about the message published by admin: {admin.name}------")
    
    def add_student(self,student): # add student into the message group
        self.__students_list.append(student)
    
    def remove_student(self,student): # remove student from the message group
        if student in self.__students_list:
            self.__students_list.remove(student)

    def __str__(self):
        return f"{self.name}"


class PlacementAdmin:
    def __init__(self,name):
        self.name = name

    def __str__(self):
        return f"{self.name}"


class Student:
    def __init__(self,name):
        self.name = name

    def notify(self,admin,message):
        print(f"user: {self.name} received message published by admin: {admin.name}. message : {message}")

    def __str__(self):
        return f"{self.name}"


# Create student objects 
student_1 = Student("Student-1")
student_2 = Student("Student-2")
student_3 = Student("Student-3")

# Create a placement group
message_group = PlacementMessageGroup("IIT-KHARAGPUR PLACEMENT GROUP")

# Add students into the placement message group for placement updates
message_group.add_student(student_1)
message_group.add_student(student_2)
message_group.add_student(student_3)

# create a Placementadmin object 
pavan = PlacementAdmin("Pavan")

# publish a message in the group
message = "Attentive is visiting our campus for on 12-12-2022 for Full time SDE roles"
message_group.publish_message(pavan,message)
message = "Google is visiting our campus for on 12-12-2022 for Full time SDE roles"
message_group.publish_message(pavan,message)

