from msilib.schema import Signature
from tabnanny import check
from turtle import pos, update
from typing import List, overload
from xml.etree.ElementTree import tostring
import numpy as np

# Chase Verbout
# Program 4
# CS202 Spring 2022
# Grade.py

# The purpose of this file is to contain the Grade base class and its three derivatives: Program, Exam, Demo
#
# Grade - A base class that contains the similar functions including edit capabilities for all variables, number to letter conversion, provide feedback,
#         altering due date, and more seen below. 
# Program - A program assignment that consists of various sub-compenents of a program and maintains their individual grading
# Exam - An exam that will consist of simple functionalities like add, and update, along with specific percent pass threshold functions
# Demo - A demo grade that varies from the other two because it is recorded initally as a string. The class will need to understand each character's representation and
#        convert it to a number corresponding with a pass and fail variable as well.

# Grade Constructor
class Grade:
    def __init__(self, aName = "NA", aNum = 1, aFloatGrade = 0.0, aPercent = 0.0, aMessage = "NA"):
        if (isinstance(aName, str) and aName != ""):
            self._name = aName
        else:
            self._name = "NA"

        if (isinstance(aNum, int) and aNum > 0):
            self._outOf = aNum
        else:
            self._outOf = 1
        
        if (isinstance(aFloatGrade, float) and aFloatGrade > 0.0):
            self._receivedGrade = aFloatGrade
        else:
            self._receivedGrade = 0.0
        
        if (isinstance(aPercent, float) and aPercent > 0.0):
            self._weight = aPercent
        else:
            self._weight = 0.0

        if (isinstance(aMessage, str) and aMessage != ""):
            self._feedback = aMessage
        else:
            self._feedback = "NA"



    # Sets a name if it is a string and not ""
    def name(self, aName):
        if (isinstance(aName, str) and aName != ""):
            self._name = aName
        


    # Sets outOf given an int > 0
    def outOf(self, aNum):
        if (isinstance(aNum, int) and aNum > 0):
            self._outOf = aNum



    # Sets a receievedGrade given a float > 0.0
    def receivedGrade(self, aFloatGrade):
        if (isinstance(aFloatGrade, float) and aFloatGrade > 0.0):
            self._receivedGrade = aFloatGrade
    


    # Sets a grade's weight given a float > 0.0
    def weight(self, aPercent):
        if (isinstance(aPercent, float) and aPercent > 0.0):
            self._weight = aPercent



    # Sets feedback given a string thats not ""
    def feedback(self, aMessage):
        if (isinstance(aMessage, str) and aMessage != ""):
            self._feedback = aMessage  



    # Fills out a Grade using setter functions given the correct inputs for the respective setters
    def fillOut(self, aName, aNum, aFloatGrade, aPercent, aMessage):
        self.name(aName)
        self.outOf(aNum)
        self.receivedGrade(aFloatGrade)
        self.weight(aPercent)
        self.feedback(aMessage)



    # User input receieved from SI for grade variables
    def promptFillOut(self):
        name = input("Name: ")
        outOf = int(input("Out of: "))
        receievedGrade = float(input("Points Earned: "))
        weight = float(input("Weight Percent(ex - 50): "))
        feedback = input("Feedback: ")
        self.fillOut(name, outOf, receievedGrade, weight, feedback)

        

    # Displays name
    def displayName(self):
        print("Name: ", self._name)



    # Displays weight
    def displayWeight(self):
        print("Weight: ", self._weight, "% of Total Grade")



    # displays grade
    def displayGrade(self):
        print("Grade: ", self._receivedGrade, " / ", self._outOf, " :: ", self.calculatePercentGrade(), " ", self.convertToLetter())



    # Displays feedback
    def displayFeedback(self):
        print("Feedback: ", self._feedback)



    # Calls all display functions
    def display(self):
        self.displayName()
        self.displayWeight()
        self.displayGrade()
        self.displayFeedback()
       


    # Given two ints > 0 returns the potential grade. Otherwise returns the grades actual value based on received / outOf
    def calculatePercentGrade(self, possibleReceived = None, possibleOutOf = None):
        if (possibleReceived == None) and (possibleOutOf == None):
            if self._outOf <= 0 or self._receivedGrade <= 0:
                return 0
            else:
                return np.round((self._receivedGrade / self._outOf), 2)
        else:
            if possibleOutOf <= 0 or possibleReceived <= 0:
                return 0
            else:
                return np.round((possibleReceived / possibleOutOf), 2)
        


    # Given a float, converts it into a Letter grade. Otherwise returns the current grade's letter value
    def convertToLetter(self, possiblePercent = 0.0):
        if possiblePercent != 0.0:
            grade = possiblePercent
        else:
            grade = self.calculatePercentGrade()

        letter = None
        if (grade >= .90):
            letter = 'A'
        elif (grade >= .80):
            letter = 'B'
        elif (grade >= .70):
            letter = 'C'
        elif (grade >= .60):
            letter = 'D'
        else:
            letter = 'F'
        return letter



    # Add a grade to another grade to get the weighted combination or given a float add a float to the current grades weighted grade value
    def __add__(self, aGrade):
        if isinstance(aGrade, Grade):
            return np.round(((self._receivedGrade / self._outOf) * self._weight) + ((aGrade._receivedGrade / aGrade._outOf) * aGrade._weight), 2)
        elif isinstance(aGrade, float):
            return np.round(((self._receivedGrade / self._outOf) * self._weight) + aGrade)
        else:
            return 0
         
    

    # Return true if this grade has the same name as the given string, otherwise return false
    def __eq__(self, aName):
        if isinstance(aName, str):
            return self._name == aName
        else:
            return False



# Program Class
class Program(Grade):
    # Program Constructor
    def __init__(self, aName = "NA", aNum = 1, aFloatGrade = 0.0, aPercent = 0.0, aMessage = "NA"):
        super().__init__(aName, aNum, aFloatGrade, aPercent, aMessage)
        self._sections = list()



    # Adds a section to the Program given a string, int, and float
    def addSection(self, aName, aTotal, aGrade):
        if isinstance(aName, str) and aName != "":
            if isinstance(aTotal, int) and aTotal > 0:
                if isinstance(aGrade, float) and aGrade > 0.0:
                    self._sections.append([aName, aTotal, aGrade])
                    self.calculateGrade()



    # Removes a section given a string. If the given string is not in the list of sections nothing is removed
    def removeSection(self, aName):
        if isinstance(aName, str) and aName != "":
            for section in self._sections:
                if section[0] == aName:
                    self._sections.remove(section)
                    self.calculateGrade()



    # Displays Program and all sections in a Program
    def displayAll(self):
        super().display()
        self.displaySections()


    
    # Displays a section
    def displaySections(self):
        for section in self._sections:
            print("\tName: ", section[0], section[2], " / ", section[1])



    # Caclulates a Programs total grade based on the cumulation of sections grades
    def calculateGrade(self):
        pts_received = 0
        pts_total = 0
        for section in self._sections:
            pts_received += section[2]
            pts_total += section[1]
        if pts_total <= 0:
            self._outOf = 1
        else:
            self._outOf = pts_total
        self._receivedGrade = pts_received




# Demo Class
class Demo(Grade):
    # Demo Constructor
    def __init__(self, aName = "NA", aLetter = 'Z', aPercent = 0.0, aMessage = "NA"):
        super().__init__(aName, 1, 0.0, aPercent, aMessage)
        self._passed = None
        self._aLetter = aLetter
        self._options = [['E', 1.0], ['P', 1.0], ['PW', 1.0], ['IP', 0.0,], ['U', 0.0]]
        if aLetter != 'Z':
            self.updateDemo(aLetter)



    # Sets a letter grade given a str
    def letter(self, aLetter):
        if isinstance(aLetter, str) and aLetter != "":
            self._aLetter = aLetter.upper()



    # Add a demos base information by user SI and given a letter
    def addDemo(self, aLetter):
        self.promptFillOut()
        self.updateDemo(aLetter)



    # Given a string update the Demo's receieved grade based on the letter's corresponding value in options. 
    # If not present set to 0.0. Update Passed based on new grade
    def updateDemo(self, aLetter = None):
        if aLetter != None:
            self.letter(aLetter)
        else:
            aLetter = self._aLetter
        found = False
        for option in self._options:
            if (option[0] == aLetter.upper()):
                found = True
                self._receivedGrade = option[1]
                self._outOf = 1
        if not found:
            self._receivedGrade = 0.0
        self.checkPassed()



    # Return True if demo was passed else return false
    def checkPassed(self):
        if self._receivedGrade == 1.0:
            self._passed = True
        else:
            self._passed = False
        return self._passed



    # Display if the Demo was passed
    def displayDemo(self):
        message = ""
        if (self._passed):
            message = "Passed"
        else:
            message = "DNP"
        print("Status:", self._aLetter, message)



# Exam Class
class Exam(Grade):
    # Exam Constructor
    def __init__(self,  aName = "NA", outOf = 1, aFloatGrade = 0.0, aPercent = 0.0, aMessage = "NA"):
        super().__init__(aName, outOf, aFloatGrade, aPercent, aMessage)
        self._topics = np.array([],dtype=str)
        self._passed = None
        self._percentToPass = None

    

    # Given a string, adds it to the Exam's topic array
    def addTopic(self, someTopic):
         if isinstance(someTopic, str) and someTopic != "":
            self._topics = np.append(self._topics, someTopic)



    # Given a float, Changes the Exam's percentToPass field
    def percentToPass(self, aPercent):
        if isinstance(aPercent, float) and aPercent > 0.0:
            self._percentToPass = aPercent
        else:
            self._percentToPass = 0.0



    # Add Exam info by UI and given a string, float, and float
    def addExam(self, topics, aPercent, aGrade):
        self.promptFillOut()
        self.updateExam(topics, aPercent, aGrade)



    # Update Exam info by giving a float for percent to pass and optionally a float for a new grade. Updates exam's passed field based on new input
    def updateExam(self, aPercent, aGrade = None):
        self.percentToPass(aPercent)
        if aGrade == None:
            aGrade = self._receivedGrade
        else:
            self.receivedGrade(aGrade)

        self.updatePassed()
    


    # Update Exam's Passed field based on current fields
    def updatePassed(self):
        if (self._receivedGrade / self._outOf) * 100 > self._percentToPass:
            self._passed = True
        else:
            self._passed = False

    

    # return Exam's passed field
    def checkPassed(self):
        return self._passed
            
