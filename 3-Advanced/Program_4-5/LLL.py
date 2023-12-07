from asyncio.windows_events import NULL

# Chase Verbout
# CS 202 Spring 2022
# Prog 4
# LLL.py

# This file contains a Node class and LLL class that function togeter to maintain a collection of grades for a student
# The LLL functions are implemented recursively

# Node Class
class Node:
    # Node Constructor
    def __init__(self, aGrade = None):
        self._grade = aGrade
        self._next = NULL



    # Set a Node's grade to the given aGrade
    def setGrade(self, aGrade):
        self._grade = aGrade



    # Set this Node's next field to a given aNode
    def setNext(self, aNode):
        self._next = aNode



    # Return this Node's next field value
    def getNext(self):
        return self._next



    # Display this Node's Grade
    def displayGrade(self):
        self._grade.display()



    # Return true if this Node's name is the same as the given string aName
    def compareName(self, aName):
        return self._grade == aName



# LLL Class
class LLL:
    # LLL Constructor
    def __init__(self, aName = None):
        if aName != None:
            self._student = aName
        self._head = NULL
    


    # Return Student Name
    def getStudent(self):
        return self._student



    # Add a Grade to the List at the end
    def addGrade(self, aGrade):
        if self._head == NULL:
            self._head = Node()
            self._head.setGrade(aGrade)
        else:
            self.__addGrade(aGrade, self._head)



    # Recursive add helper
    def __addGrade(self, aGrade, curr):
        if curr.getNext() == NULL:
            curr.setNext(Node(aGrade))
            return
        
        return self.__addGrade(aGrade, curr.getNext())



    # Remove a Grade from the LLL if it exists in the LLL. Name must match aName
    def removeGrade(self, aName):
        if self._head.compareName(aName):
            self._head = self._head.getNext()
            return
        return self.__removeGrade(aName, self._head.getNext(), self._head)



    # Recursive remove helper
    def __removeGrade(self, aName, curr, prev):
        if curr == NULL:
            return
        if curr.compareName(aName):
            prev.setNext(curr.getNext())
            return
        return self.__removeGrade(aName, curr.getNext(), curr)



    # Display all Grade objects in the LLL
    def displayGrades(self):
        self.__displayGrades(self._head)



    # Recursive display helper
    def __displayGrades(self, curr):
        if curr == NULL:
            return
        
        curr.displayGrade()
        return self.__displayGrades(curr.getNext())
    


    # Display a Grade if it's name matches aName
    def findGrade(self, aName = ""):
        if isinstance(aName, str) and aName != "":
            self.__findGrade(self._head, aName)



    # Recursive findGrade helper
    def __findGrade(self, curr, aName):
        if curr == NULL:
            return
        
        if curr.compareName(aName):
            curr.displayGrade()

        return self.__findGrade(curr.getNext(), aName)
