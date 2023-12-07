import numpy as np
import Grade

# Chase Verbout
# CS 202 Spring 2022
# Prog 4
# LLL.py

'''
This is the testing suite for the Grade Class and derivatives: Program, Demo, Exam
Testing design is in progress and will be completed through the next week.
'''

'''
-----Grade Testing-----
1. Test initialization for correct inputs and incorrect inputs
    - strings are strings
    - floats are floats
    - ints are ints
    - Check for zero values
2. Same as above for fillOut method
3. Make sure calculateGradePercent method deals with zero value denominators and non number inputs
4. Check that convertToLetter works with edge values and deals with non numerical inputs
5. Check that __add__ and __eq__ returns expected results and deals with non grade variables
'''

def test_Grade(aGoodGrade, aFaultyGrade):
    assert aGoodGrade._name == "Program 1"
    assert aGoodGrade._outOf == 10
    assert aGoodGrade._receivedGrade == 8.34
    assert aGoodGrade._weight == 50.0
    assert aGoodGrade._feedback == "Goodjob"
    assert aFaultyGrade._name == "NA"
    assert aFaultyGrade._outOf == 1
    assert aFaultyGrade._receivedGrade == 0
    assert aFaultyGrade._weight == 0.0
    assert aFaultyGrade._feedback == "NA"

def test_name(aFaultyGrade):
    options = ["Homework", 4, -4, 5.8, -5.8, True]
    for option in options:
        aFaultyGrade.name(option)
        assert aFaultyGrade._name == "Homework"

def test_outOf(aFaultyGrade):
    options = [10, -10, 20.5, -20.5, "5", False]
    for option in options:
        aFaultyGrade.outOf(option)
        assert aFaultyGrade._outOf == 10

def test_receivedGrade(aFaultyGrade):
    options = [10.34, -10.34, 30, -30, "20", False]
    for option in options:
        aFaultyGrade.receivedGrade(option)
        assert aFaultyGrade._receivedGrade == 10.34

def test_weight(aFaultyGrade):
    options = [25.0, -25.0, 30, -30, "45", False]
    for option in options:
        aFaultyGrade.weight(option)
        assert aFaultyGrade._weight == 25.0

def test_feedback(aFaultyGrade):
    options = ["GoodJob", 4, -4, 5.8, -5.8, True]
    for option in options:
        aFaultyGrade.feedback(option)
        assert aFaultyGrade._feedback == "GoodJob"

def test_calculatePercentGrade(aGoodGrade, aFaultyGrade):
    options = [[8.0, 10, .80], [8.0, 0, 0], [0, 8, 0], [-8.0, 10, 0], [8.0, -10, 0]]
    for option in options:
        assert aFaultyGrade.calculatePercentGrade(option[0], option[1]) == option[2]
    assert aGoodGrade.calculatePercentGrade() == .83

def test_convertToLetter(aGoodGrade):
    options1 = [[.90, 'A'], [.80, 'B'], [.70, 'C'], [.60, 'D'], [.50, 'F'], [-.50, 'F']]
    options2 = [[9.0, 'A'], [8.0, 'B'], [7.0, 'C'], [6.0, 'D'], [5.0, 'F']]
    for option in options1:
        assert aGoodGrade.convertToLetter(option[0]) == option[1]
    aGoodGrade.outOf(10)
    for option in options2:
        aGoodGrade.receivedGrade(option[0])
        assert aGoodGrade.convertToLetter() == option[1]
    
def test___add__(aGoodGrade):
    grade = Grade.Grade("Program 2", 10, 5.54, 50.0, "Goodjob")
    assert (aGoodGrade + grade) == 69.40
    assert aGoodGrade + 5 == 0

def test___eq__(aGoodGrade):
    assert aGoodGrade == "Program 1"

'''
-----Program Testing-----
1. addSection
    - Check that it takes string int int in that order
    - Check for blank string
    - Check for negative numbers
    - Check for zeros
2. removeSection
    - Check that it finds the matching section
    - Check that match is removed successsfully
    - Check that nothing is removed on no match
3. calculateGrade
    - Check that _receivedGrade is correct after
    - Check that _outOf is correct after
    - Check that total being 0 does not crash it
    - Check that it works after removal
'''

def test_Program(aGoodProgram, aFaultyProgram):
    assert aGoodProgram._name == "Program 1"
    assert aGoodProgram._outOf == 10
    assert aGoodProgram._receivedGrade == 8.34
    assert aGoodProgram._weight == 50.0
    assert aGoodProgram._feedback == "Goodjob"
    assert aFaultyProgram._name == "NA"
    assert aFaultyProgram._outOf == 1
    assert aFaultyProgram._receivedGrade == 0
    assert aFaultyProgram._weight == 0.0
    assert aFaultyProgram._feedback == "NA"

def test_addSection(aGoodProgram, aFaultyProgram):
    options = [["Submission 1 -", 10.00, 6.00], ["Submission 2 -", 10.00, 10.00], ["Submission 3 -", 10.00, 8.00]]
    for option in options:
        aGoodProgram.addSection(option[0], option[1], option[2])
    for i in range(len(aGoodProgram._sections)):
        assert aGoodProgram._sections[i][0] == options[i][0]
        assert aGoodProgram._sections[i][1] == options[i][1]
        assert aGoodProgram._sections[i][2] == options[i][2]
    aFaultyProgram.addSection(0, 10.00, 6.00)
    aFaultyProgram.addSection("Sub 1", "10.00", 6.00)
    aFaultyProgram.addSection("Sub 1", 10.00, "6.00")
    aFaultyProgram.addSection("Sub 1", -10.00, 6.00)
    aFaultyProgram.addSection("Sub 1", -10.00, -6.00)
    assert len(aFaultyProgram._sections) == 0

def test_removeSection(aGoodProgram):
    options = [["Submission 1 -", 10.00, 6.00], ["Submission 2 -", 10.00, 10.00], ["Submission 3 -", 10.00, 8.00]]
    for option in options:
        aGoodProgram.addSection(option[0], option[1], option[2])
    size = len(aGoodProgram._sections)
    
    aGoodProgram.removeSection("Sub 2")
    aGoodProgram.removeSection("")
    aGoodProgram.removeSection(34)
    assert len(aGoodProgram._sections) == size
    
    for i in range(len(aGoodProgram._sections)):
        aGoodProgram.removeSection(option[i][0])
        assert len(aGoodProgram._sections) == size - (i + 1)

def test_calculateGrade(aGoodProgram):
    assert aGoodProgram._receivedGrade == 8.34
    assert aGoodProgram._outOf == 10
    aGoodProgram.calculateGrade()
    assert aGoodProgram._receivedGrade == 0.0
    assert aGoodProgram._outOf == 1
    aGoodProgram.addSection("Submission 1 -", 10, 6.00)
    aGoodProgram.calculateGrade()
    assert aGoodProgram._receivedGrade == 6.0
    assert aGoodProgram._outOf == 10
    aGoodProgram.addSection("Submission 2 -", 10, 10.00)
    aGoodProgram.calculateGrade()
    assert aGoodProgram._receivedGrade == 16.0
    assert aGoodProgram._outOf == 20
    aGoodProgram.addSection("Submission 3 -", 10, 8.00)
    aGoodProgram.calculateGrade()
    assert aGoodProgram._receivedGrade == 24.0
    assert aGoodProgram._outOf == 30

    aGoodProgram.removeSection("Submission 1 -")
    aGoodProgram.calculateGrade()
    assert aGoodProgram._receivedGrade == 18.00
    assert aGoodProgram._outOf == 20

'''
-----Demo Testing-----
1. addDemo
    - Check that given input is a string
    - check that if given a different data type nothing happens
    - Check that _letter changes to correct letter if its one of the options
    - Check that it does not change if the given letter is not an option
2. updateDemo
    - Same checks as addDemo
    - Check that it adds the appropriate score to _receieved grade for each letter option
    - Check that _outOf is correct with each letter
3. checkPassed
    - Assert that _passed is True when receieved is 1
    - Assert that _passed is False when received is 0
'''

def test_Demo(aGoodDemo, aFaultyDemo):
    assert aGoodDemo._name == "Midterm Demo"
    assert aGoodDemo._outOf == 1
    assert aGoodDemo._receivedGrade == 1.0
    assert aGoodDemo._weight == 0.0
    assert aGoodDemo._feedback == "Goodjob"
    assert aGoodDemo._aLetter == 'P'
    assert aGoodDemo._passed == True
    assert aFaultyDemo._name == "NA"
    assert aFaultyDemo._outOf == 1
    assert aFaultyDemo._receivedGrade == 0.0
    assert aFaultyDemo._weight == 0.0
    assert aFaultyDemo._feedback == "NA"
    assert aFaultyDemo._aLetter == 'Z'
    assert aFaultyDemo._passed == None

def test_letter(aGoodDemo):
    assert aGoodDemo._aLetter == 'P'
    for option in ['E', 'e', 'P', 'p', 'PW', 'pw', 'IP', 'ip', 'U', 'u']:
        aGoodDemo.letter(option)
        assert aGoodDemo._aLetter == option.upper()
    for option in [1, '', 5.5, True]:
        aGoodDemo.letter(option)
        assert aGoodDemo._aLetter == 'U'

def test_updateDemo(aGoodDemo):
    assert aGoodDemo._aLetter == 'P'
    assert aGoodDemo._receivedGrade == 1
    for option in ['E', 'e', 'P', 'p', 'PW', 'pw']:
        aGoodDemo.updateDemo(option)
        assert aGoodDemo._aLetter == option.upper()
        assert aGoodDemo._receivedGrade  == 1.0
    for option in ['IP', 'ip', 'U', 'u', 'DNE', "OOGaBOOGa"]:
        aGoodDemo.updateDemo(option)
        assert aGoodDemo._aLetter == option.upper()
        assert aGoodDemo._receivedGrade  == 0.0


def test_checkPassed(aGoodDemo):
    assert aGoodDemo._passed == True
    for option in ['IP', 'ip', 'U', 'u', 'DNE', "OOGaBOOGa"]:
        aGoodDemo.updateDemo(option)
        aGoodDemo.checkPassed()
        assert aGoodDemo._passed == False
    for option in ['E', 'e', 'P', 'p', 'PW', 'pw']:
        aGoodDemo.updateDemo(option)
        aGoodDemo.checkPassed()
        assert aGoodDemo._passed == True

'''
-----Exam Testing-----
    1. Constrcutor
        - Works with same inputs as Grade
    2. addTopic
        - Make sure topics are added to the array
    3. percentToPass
        - Check that it only accepts a float and that a float updates the value
        - a non float changes value to 0.0
    4. updatePassed
        - check that combinations of received grade , out of, and percent to pass end as correct true or false
    3. checkPassed
        - Check that passed return is correct based on percent grade and percentToPass

'''

def test_Exam(aGoodExam, aFaultyExam):
    assert aGoodExam._name == "Midterm 1"
    assert aGoodExam._outOf == 50
    assert aGoodExam._receivedGrade == 45.3
    assert aGoodExam._weight == 25.0
    assert aGoodExam._feedback == "Goodjob"
    assert aFaultyExam._name == "NA"
    assert aFaultyExam._outOf == 1
    assert aFaultyExam._receivedGrade == 0
    assert aFaultyExam._weight == 0.0
    assert aFaultyExam._feedback == "NA"

def test_addTopic(aGoodExam):
    assert aGoodExam._topics.size == 0
    options = ["LLL", "Array", "Graph", "BST"]
    for option in options:
        aGoodExam.addTopic(option)
        ind = np.isin(aGoodExam._topics, option)
        assert np.any(ind) == True
    assert aGoodExam._topics.size == 4
    ind = np.isin(aGoodExam._topics, "LLL")
    assert np.all(ind) == False
  
def test_percentToPass(aGoodExam):
    assert aGoodExam._percentToPass == None
    aGoodExam.percentToPass(95.5)
    assert aGoodExam._percentToPass == 95.5
    for option in [5, True, "pass", -54.3]:
        aGoodExam.percentToPass(option)
        assert aGoodExam._percentToPass == 0.0

def test_updatePassed(aGoodExam):
    assert aGoodExam._percentToPass == None
    assert aGoodExam._passed == None
    assert aGoodExam._outOf == 50

    aGoodExam.percentToPass(82.0)
    aGoodExam.updatePassed()
    assert aGoodExam._passed == True

    aGoodExam.percentToPass(100.0)
    aGoodExam.updatePassed()
    assert aGoodExam._passed == False

def test_updateExam(aGoodExam):
    assert aGoodExam._percentToPass == None
    assert aGoodExam._receivedGrade == 45.3
    assert aGoodExam._outOf == 50
    assert aGoodExam._passed == None
    aGoodExam.updateExam(80.0, 45.8)
    assert aGoodExam._percentToPass == 80.0
    assert aGoodExam._receivedGrade == 45.8
    assert aGoodExam._passed == True
    aGoodExam.updateExam(80.0, 45.8)
