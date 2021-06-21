##############################################################################
#  Author: Alexandrea Teigeler
#  Starter Code Provided by: Professor Linda Noss
#  Date Last Modified: June 17th, 2021
#  Program Details:
#				This program will communicate with C++ code
#				----------------------------------------------
#				Reads a file, counts the amount of products were purchased
#               And prints the information to the console
#				----------------------------------------------
#               Reads a file, counts the amount of a specific product
#               Specified by user, then sends frequency to C++
#				----------------------------------------------
#               Reads a file, sorts and counts product and frequency
#               Writes this data to a .dat file
#               Uses .dat file to create a visual Histogram
#
#
#############################################################################

import re
import string
from collections import Counter # imported to count frequency of words in file                              



def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v

def read_File():

    # This function will read a file
    # It will count the total amount of each product
    # Then it will print it to the console
    

    ticket = open("project_three_input_file.txt") #creates object that opens text file
    products = ticket.read().split() #creates object that holds each line info from ticket object
    
    unique_Product = sorted(set(products))

    for word in unique_Product:
        print("------------------------------------")
        print("\n")
        print(products.count(word), " : ",  word)
        print("\n")
        print("------------------------------------")
    

    ticket.close() #closes ticket object to prevent memory issues

    

def locate_Total_Product_Amount(v):
    # Takes a string from C++ user input
    # will search through text file to count the total occurance of item
    # will print to console

    
    ticket = open("project_three_input_file.txt")
    products = ticket.read().split() #creates object that holds each line info from ticket object
    unique_Product = sorted(set(products)) #sorts the items
    ticket.close() #closes ticket object to prevent memory issues


    tot = 0 #number to be sent back to C++
    tot_inventory = 0 #counts amount of times loop iterates --  used to determine if item not 
    tot_inventory_count = 0 # meant to hold total inventory in document file

    for word in unique_Product: # get total amount of items in list -- works better then len(list) due to how set is sorted
        tot_inventory_count += 1

    for word in unique_Product: #finds the element in unique_Product that is the requested string from user
        temp_String = word
        tot_inventory += 1
        if (temp_String == v):
            tot = products.count(word)
            tot_inventory -= 1 # this determines that the item was accessed at least once during iteration --  used to determine if user input actually in file
        if (temp_String != v and tot_inventory == tot_inventory_count):
            return -1 # this determined that item from user input was not present in file

    
    
    return tot


def read_AND_Write_File():

    # takes information from text file
    # counts product and sorts/counts items
    # Takes the sorted and counted items and writes to a dat file
    # will then call histogram function to print to console

    ticket = open("project_three_input_file.txt")
    data = open("frequency.dat", "w")
    products = ticket.read().split() #creates object that holds each line info from ticket object
    unique_Product = sorted(set(products)) #sorts the items


    #writes the data to the .dat file
    for word in unique_Product:
        data.write(word)
        data.write(" ")
        data.write(str(products.count(word))) #convert to string to write to .dat file
        data.write("\n")
    
    data.close() #close file -- will be reopened in next line to read from it

    histo_data = open("frequency.dat", "r") # read .dat file
    product_data = histo_data.readlines() # read lines so each product is matches with frequency amount


    #temp variables used for nested for loops
    temp_freq = 0
    temp_product = ""

    #reads and prepares data from .dat file for histogram
    for line in product_data:
        temp_int = 0
        temp_string = line.split() #splits product name and frequency
        for word in temp_string:
            temp_int += 1
            if (temp_int == 1):
                temp_product = word #product
                print(temp_product, end = " ")
            if (temp_int == 2):
                temp_freq = int(word) #frequency of product
        

        #creates Histogram -- EXAMPLE: Onions ****
        for i in range(temp_freq):
            print("+", end = "")
        print("\n")
        print("------------------------------------")
        print("\n")
        
    