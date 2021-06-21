# Corner-Grocer-Product-Sorter
A simple program that takes in a word document, counts the frequency, and given the choice of the user from the menu, will output information about it.

-----------------------------------------------------------------------------------------------------------------------------------------------
Summarize the project and what problem it was solving:
This Program was created to help organize the products purchased from "Corner Grocer", a fictional store, that were saved to a text file. The Python code read from this file, counted the frequency of these words, and created a visual histogram. The C++ code handled the UI and gave the user a menu and prompt to interact with the menu.
They had 4 options, to print out the total frequency of each word, to select a product and it would retrieve how many times that product appeared only, to print a visual text histogram, or to exit the program

------------------------------------------------------------------------------------------------------------------------------------------------
What did you do particularly well:
What was most successful in this project was creating the Python code that read the text file, wrote to a .dat file, read the .dat file. TThe error was well executed.

------------------------------------------------------------------------------------------------------------------------------------------------
Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on:
To improve the program, I would have employed a learning algorithm that is available with certain imported Python Modules that can be used to find trends from data and report to the user which are the most popular items. This would require more files and data entries from the store, but the concept is applicable in real scenerios. This would also help the store recognize which products are not as popular, so they can understand how much to purchase to reduce waste and reduce cost of over purchasing.

------------------------------------------------------------------------------------------------------------------------------------------------
Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network:
The most difficult portion of code to write was counting the frequency of the words within the Python code. Issues that arose, was that it was counting the frequency, but missed items, and per example, it would print "Onions 3, Onions 1". There are 4 onions, but it would cause this issue. Once the correct algorithm was in place, everything worked smoothly.
Also, creating the text histogram proved a challenge initally as I was attempting to use Matplotlib and numpy to create a visual histogram and visual studio was not recognizing these imports. I still have to trouble shoot this issue, however, using a simple algorithm, a text histogram was printed to the console where the frequency was print out such as "Onions ++++".

------------------------------------------------------------------------------------------------------------------------------------------------
What skills from this project will be particularly transferable to other projects or course work:
The error handling are portions of code that can be used in any program and only have minor changes to correctly corrospond with that specific document. Specific skills that are transferable to other projects would be learning how to communicate between two langauges.
Trouble shooting issues with library directories will also prove useful.

------------------------------------------------------------------------------------------------------------------------------------------------
How did you make this program maintainable, readable, and adaptable:
Proper comments and explanation is at the beginning of each function as well as specific pieces of code to explain how it is expected to work.
Organization of the functions and spacing help the readability.
Proper maintained formatting ensures that it is visually appealing and easy to follow.
The program is structured in a way that could be easily changed to add more functionality in both the C++ and Python file due to how the error handling and function calls are created.

------------------------------------------------------------------------------------------------------------------------------------------------
