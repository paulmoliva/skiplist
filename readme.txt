Hybrid linked list implementation in C++. Created for Data Structures and Algorithms course at University of Alaska-Anchorage.

Assignment Specs were as follows:
The second assignments is due only in C++. For this assignment you (the programmer) were contacted
by one of the online car retail stores with a request to create a car inventory management system.
Unfortunately, the app will be running on a propriety mobile hardware, so the conventional database
systems as a back end is out. Instead you are asked to create an object oriented inventory system for a
very large inventory of vehicles. The presentation layer (that you are not responsible for implementing)
will be a browser that the customer and managers use to search for different types of vehicles by make,
by engine type, and by carrying capacity. In addition to these search features, your app will have to
support deletion and addition of vehicle inventory. The initial data load will be from a tab delimited text
file – this is the only section of the code that you are allowed to use tokenizer to parse individual lines of text to create objects.
Methodology:
Each vehicle will be an object of Vehicle type with the following slots: int::id, string::make,
string::model, char::engineType (D:diesel, G:gas, H:hybrid,E:electric), int::carryingCapacity, 0-
5::customerRating. To keep track of the vehicles and support the search functionality of your
application, you need to create 4 linked lists. The first one will keep track of all vehicles (allVehicles)
and will be search-able by id, the reminder 3 lists will be skip-lists where objects will be inserted in
order and search-able byMake, byEngineType, byCarryingCapacity (in 100 lbs increment steps – input
example 735 means search for all engines 735-835lbs). The add function will contain 5 values for each
object, and the delete command will be followed by an id of an object to be deleted. The final command
is t for terminate the application.
Design note: You might consider each vehicle object to have an internal linked list to the SkipListNode
objects for the ease of implementing the delete function. The problem is if you delete a vehicle object,
first locate the vehicle using the allVehicles LList, but if you delete the object, it is still being pointed to by the other SkipListNodes. One option, is to search all other link lists to delete the individual
SkipListNodes in byMake, byEngineType, byCarryingCapacity OR have a doubly linked lists in each
vehicle object that point to the individual SkipListNodes to be deleted.
Commands to the API:
byMake string
byEngineType (D|G|H|E)
byCarryingCapacity int
add int::id \t string::make \t string::model \t char::engineType \t int::carryingCapacity\t 0-
5::customerRating
delete int
Example:
example.txt
1 ford escort G 750 2
2 ford mustang G 920 4
3 ford scorpion G 710 3
4 subaru outback G 950 5
5 subaru impreza D 875 4
6 subaru forrester G 980 3
7 ford T G 510 5
8 ford F-150 D 1250 4
9 ford F-350 D 1500 3
10 ford F-150 G 1050 2
11 ford F-350 G 1200 4
12 ford F-150 H 950 5
13 ford F-350 H 1100 4
>> byMake subaru
<<4 subaru outback G 950 5
<<5 subaru impreza G 875 4
<<6 subaru forrester G 980 3
>> byEngineType D
<<8 ford F-150 D 1250 4
<<9 ford F-350 D 1500 3
<<5 subaru impreza D 875 4
>> byCarryingCapacity 910
<<2 ford mustang G 920 4
<<4 subaru outback G 950 5
<<6 subaru forrester G 980 3
<<13 ford F-350 H 1100 4
>>delete 10
<<deleted: 10 ford F-150 G 1050 2
>> delete: 12
<< not found id 12
>> add 16 subaru baha h 972 2
<< added 16 subaru baha h 972 2
>> add 9 ford F-350 D 1500 3
<< could not add: duplicate id
Design:
Implement the following functionality of the UJS:
• Implementation in C++
• You cannot use built-in libraries, only tokenizer for parsing in the input
• Read-in unlimited number of vehicles (NO ARRAYS)
• Implement all necessary setter, getter, and manipulation methods
• Allocate all data-structures on the heap (not the stack)
• Graceful termination: deallocate all allocated memory before exiting the application
Evaluation Criteria:
(1) Correctness: In the true spirit of software engineering, you are required to implement the above
described project specifications and no more and no less features than required by the 
assignment. Implement the project in a minimum of two (2) files for each language. The first file
is a driver and it contains the “main” routine to illustrates the operation of your project and does
not include any “business logic” - name this file driver.cpp. The second (or any additional) files
have the code for the objects and the business logic. Your C++ assignment must compile and run
under MS VisualStudio 2010/2012 or GNU c++ v 4.6. or later. Please no project files, .o objects
or .exe file.
(2) The proper programming practices must be followed. I'm not explicitly setting the programming
style guidelines, but I will dock you points if the code is not commented, the variable and
method names are not descriptive, the code is not structured in methods or indented.
(3) Memory management in C++ is a must! 