- OOP244
- Final Project
- winter of 2016
- Aid Management Application (AMA)


Aid Management Application  (AMA) 
 
When disaster hits an area, the most important thing is to be able provide the people affected with what they need as quickly and as efficiently possible. 
Your job for this project is to prepare an application that manages the list of goods needed to be shipped to the area. The application should be able to keep track of the quantity of items needed and quantity in hand, and store them in a file for future use.  
The types of goods needed to be shipped in this situation are divided into two categories;   Non-Perishable products, such as blankets and tents, that have no expiry date, we refer to these type of products as AMA_product.  Perishable products, such as food and medicine, that have an expiry date, we refer to these products as AMA_Perishable.  
To accomplish this task you need to create several classes to encapsulate the problem and provide a solution for this application.  CLASSES TO BE DEVELOPED The classes needed for this application are: 
Date  A class to be used to hold the expiry date of the perishable items. 
ErrorMessage  A class to keep track of the errors occurring during data entry and user interaction. 
Streamable  This interface (a class with “only” pure virtual functions) enforces the classes that inherit from it to be streamable. Any class derived from “Streamable” can read from or write to the console, or can be saved to or loaded from a text file.    
Using this class the list of items can be saved into a file and retrieved later, and individual item specifications can be displayed on screen or read from keyboard.  
Product  A class inherited form Streamable, containing general information about an item, like the name, Stock Keeping Unit (SKU), price etc. 
2 
 
AMA_Product  A class for non-perishable items that is inherited from the “Product” class and implements the requirements of the “Streamable” class (i.e. implements the pure virtual methods of the Streamable class) 
AMA_Perishable  A class inherited from the “AMA_Product” that provides expiry date for Perishable items. 
AidApp  The main application class that is essentially the manager class for the NFI and Perishable items. This class provides the user with a user-interface to list, add and update the items saved in a data file. PROJECT CLASS DIAGRAM 
 
 
