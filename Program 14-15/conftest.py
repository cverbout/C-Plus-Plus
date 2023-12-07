import Grade
import pytest

# Chase Verbout
# CS 202 Spring 2022
# Prog 4
# conftest.py

# This file holds the pytest fixtures for the test_Grade.py file

@pytest.fixture
def aGoodGrade():
    grade = Grade.Grade("Program 1", 10, 8.34, 50.0, "Goodjob")
    return grade

@pytest.fixture
def aFaultyGrade():
    grade = Grade.Grade(0, 0, 0, 0, 0)
    return grade

@pytest.fixture
def aGoodProgram():
    program = Grade.Program("Program 1", 10, 8.34, 50.0, "Goodjob")
    return program

@pytest.fixture
def aFaultyProgram():
    program = Grade.Program()
    return program

@pytest.fixture
def aGoodDemo():
    demo = Grade.Demo("Midterm Demo", 'P', 20, "Goodjob")
    return demo

@pytest.fixture
def aFaultyDemo():
    demo = Grade.Demo()
    return demo

@pytest.fixture
def aGoodExam():
    exam = Grade.Exam("Midterm 1", 50, 45.3, 25.0, "Goodjob")
    return exam

@pytest.fixture
def aFaultyExam():
    exam = Grade.Exam()
    return exam