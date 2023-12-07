import Grade
import LLL
import BT

# Chase Verbout
# CS 202 Spring 2022
# Prog 4/5
# Main.py

# This is the Main file where we can see a demostration of the Grade Derivative classes, LLL class functionality and BT class functionality combined

def main():
    hw = Grade.Program("Program 1", 100, 56.75, 10.00, "Great Job on this!")
    hw.addSection("Submission 1 -", 10, 6.00)
    hw.addSection("Submission 2 -", 10, 10.00)
    hw.addSection("Submission 3 -", 10, 8.00)
    hw.calculateGrade()

    #This section is commented out to make display less lengthy
    
    hw2 = Grade.Program("Program 2", 100, 70.5, 10.00, "Great Job on this!")
    hw3 = Grade.Program("Program 3", 100, 90.35, 10.00, "Great Job on this!")
    """
    mpdemo = Grade.Demo("Midterm Demo", 'U', 0.0, "See me")
    mpdemo.updateDemo('PW')
    fdemo = Grade.Demo("Final Demo", 'Z', 0.0, "well done")
    fdemo.letter('PW')
    fdemo.updateDemo()

    mExam = Grade.Exam("Midterm Exam", 40, 38.8, 20.0, "Cool!")
    mExam.addTopic("ARR, LLL")
    mExam.percentToPass(75.0)
    m2Exam = Grade.Exam("Midterm2 Exam", 40, 36.1, 20.0, "Okay")
    m2Exam.addTopic("Dynamic Binding")
    m2Exam.percentToPass(75.0)
    fExam = Grade.Exam("Final Exam", 40, 35.4, 30.0, "Not bad")
    fExam.addTopic("Everything")
    fExam.percentToPass(80.0)
    """

    myGrades = LLL.LLL("Chase")
    #for grade in [hw, hw2, hw3, mpdemo, fdemo, mExam, m2Exam, fExam]:
    for grade in [hw]:
        myGrades.addGrade(grade)

    steve = LLL.LLL("Steve")
    for grade in [hw, hw2]:
        steve.addGrade(grade)

    robin = LLL.LLL("Robin")
    for grade in [hw]:
        robin.addGrade(grade)

    billy = LLL.LLL("Billy")
    for grade in [hw, hw3]:
        billy.addGrade(grade)

    will = LLL.LLL("Will")
    for grade in [hw2]:
        will.addGrade(grade)

    mike = LLL.LLL("Mike")
    for grade in [hw3]:
        mike.addGrade(grade)

    el = LLL.LLL("El")
    for grade in [hw]:
        el.addGrade(grade)

    ourClass = BT.BT()
    for person in [myGrades, robin, steve, mike, el, will, billy]:
        ourClass.addStudent(person)

    print("Display:")
    ourClass.display()
    print("Search:")
    print()
    ourClass.search("Billy")
    ourClass.search("Robin")
    ourClass.search("Steve")

    # This was LLL functionality from Prog 4
    '''
    myGrades.displayGrades()

    totalGrade = hw + hw2
    for grade in [hw3, mpdemo, fdemo, mExam, m2Exam, fExam]:
        totalGrade = grade + totalGrade
    print()
    print("Total Grade:", totalGrade, hw.convertToLetter(totalGrade / 100))
    print()
    print()

    myGrades.removeGrade("Program 1")
    myGrades.findGrade("Midterm Demo")
    myGrades.removeGrade("Midterm Demo")
    myGrades.findGrade("Midterm Demo")
    myGrades.removeGrade("Final Exam")

    myGrades.displayGrades()
'''
if __name__ == "__main__":
    main()