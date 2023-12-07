import LLL

# Chase Verbout
# CS 202 Spring 2022
# Prog 5
# BT.py

# This file contains the Bnode and BT class
# The Bnode class is a node specialized for an AVL tree containing a student's LLL of grades, a left and right child node, and a height indicator
# The BT class is an AVL tree that contains and maintains an alphabetically orgranized collection of students and their grades.
# It contains recursive functions for Add, Search and Display as well as helper functions for rotation, balance, and height assesment


# Bnode Class
# This is a node that is set up to contain a LLL from LLL.py which maintains a collection of grades for one student
# It has left and right node functionality and a height variable
class Bnode:
    # Constructor
    def __init__(self):
        self._glist = None
        self._left = None
        self._right = None
        self._height = 1



    # Set the left node
    def setLeft(self, Node):
        self._left = Node
    


    # Set the right node
    def setRight(self, Node):
        self._right = Node



    # get the left node
    def getLeft(self):
        return self._left
    


    # get the rigt node
    def getRight(self):
        return self._right



    # get the Students name from the LLL
    def getGlistName(self):
        return self._glist.getStudent()
    


    # Get the node's height
    def getHeight(self):
        return self._height



    # Set the node's height
    def setHeight(self, height):
        self._height = height



    # Set the Grade LLL in this node
    def setGlist(self, Glist):
        self._glist = Glist



    # Get the Grade LLL from in this node
    def GetGlist(self):
        return self._glist



    # Check if the node has a Grade LLL
    def hasGlist(self):
        if self._glist == None:
            return False
        else:
            return True
    


    # display the Grade LLL in the node
    def display(self):
        print(self.getGlistName())
        self._glist.displayGrades()


# AVL Balanced Tree 
class BT:
    # Constructor
    def __init__(self):
        self._root = None
        
    
    
    # Add a student by giving a Grade LLL as an argument
    def addStudent(self, Glist):
        self._root = self.addHelper(self._root, Glist)



    # Recursive helper function to insert a student
    def addHelper(self, curr, Glist):
        # Add the node if we reach a None value
        if curr == None:
            curr = Bnode()
            curr.setGlist(Glist)
            return curr
        #if the name we want to add is less than the current go left
        if Glist.getStudent() < curr.getGlistName():
            curr.setLeft(self.addHelper(curr.getLeft(), Glist))
        #if the name we want to add is greater or equal than the current go right
        elif Glist.getStudent() >= curr.getGlistName():
            curr.setRight(self.addHelper(curr.getRight(), Glist))

        # Adjust the current nodes height
        curr.setHeight(1 + max(self._calcHeight(curr.getLeft()), self._calcHeight(curr.getRight())))
        # Check the balance of this node by it's children
        bal = self._calcBal(curr.getLeft(), curr.getRight())
        if curr.getRight():
            # Case 1
            if bal < -1 and Glist.getStudent() > curr.getRight().getGlistName():
                return self._leftRotate(curr)
            # Case 2
            elif bal < -1 and Glist.getStudent() < curr.getRight().getGlistName():
                curr.setRight(self._rightRotate(curr.getRight()))
                return self._leftRotate(curr)
        if curr.getLeft():
            # Case 3
            if bal > 1 and Glist.getStudent() > curr.getLeft().getGlistName():
                curr.setLeft(self._leftRotate(curr.getLeft()))
                return self._rightRotate(curr)
            # Case 4
            elif bal > 1 and Glist.getStudent() < curr.getLeft().getGlistName():
                return self._rightRotate(curr)
        return curr



    
    # A private rotate function needed to keep the AVL tree balanced upon insertions
    # The left rotate moves the current node's right node's left child to its own right child
    # and takes the previously right node and sets its right node to the current node.
    # It returns the former right child, and not the beginning current node
    def _leftRotate(self, curr):
        rightChild = curr.getRight()
        leftChild = rightChild.getLeft()
        rightChild.setLeft(curr)
        curr.setRight(leftChild)
        curr.setHeight(1 + max(self._calcHeight(curr.getLeft()), self._calcHeight(curr.getRight())))
        rightChild.setHeight(1 + max(self._calcHeight(rightChild.getLeft()), self._calcHeight(rightChild.getRight())))
        return rightChild



    # Another private rotate function needed to keep balance in the AVL. See description of left rotate but swap 
    # rights with lefts and lefts with rights.
    def _rightRotate(self, curr):
        leftChild = curr.getLeft()
        rightChild = leftChild.getRight()
        leftChild.setRight(curr)
        curr.setLeft(rightChild)
        curr.setHeight(1 + max(self._calcHeight(curr.getLeft()), self._calcHeight(curr.getRight())))
        leftChild.setHeight(1 + max(self._calcHeight(leftChild.getLeft()), self._calcHeight(leftChild.getRight())))
        return leftChild




    # Calculates the balance by subtracting a given left childs height from a given right childs height
    def _calcBal(self, left, right):
        return self._calcHeight(left) - self._calcHeight(right)



    # Calculates height of a node. Checks if the node is a node or a None
    def _calcHeight(self, curr):
        if curr == None:
            return 0
        return curr.getHeight()
    


    # Display function that shows all students in the AVL tree
    def display(self):
        return self._display(self._root)



    # Recrusive helper function for display. In order traversal
    def _display(self, curr):
        if curr == None:
            return
        self._display(curr.getLeft())
        print()
        curr.display()
        print()
        self._display(curr.getRight())
        return



    # Search function to display a specific student's grades from a given name
    def search(self, student):
        return self._search(self._root, student)



    # Recrusinve helper function for search. Should have a logarithmic runtime because of balancing
    def _search(self, curr, student):
        if curr == None:
            return
        if curr.getGlistName() == student:
            print()
            curr.display()
        # Takes the path where the name should be if it exists in the tree
        if student < curr.getGlistName():
            self._search(curr.getLeft(), student)
        elif student >= curr.getGlistName():
            self._search(curr.getRight(), student)
        return

        
        




        

    

    
