 # Hotel_Management-GUI
 
 The project above you is a partly done GUI management interface meant to be used in hotel management system application. It is developed in C++ 11 programming language with the help of SDL2.0 library.
 
 The project design patterns were greatly influenced by the book I was reading at the time of development -"Game programming patterns" by Robert Nystorm. Few of the concepts mentioned in the that book I had accommodated to my program including: The Flyweight, Prototype, Singleton and State patterns and the update method sequencing pattern.
 
 ## If you want to run the application and test it on your machine (assuming that it runs Windows) download the .zip file here - [Application_Executable.zip](https://github.com/1000p/Hotel_Management-GUI/blob/master/Application_Executable.zip)
 
 * The source code is available in the Hotel-Management folder in the repository.
 
 ```
 Please keep in mind that I am publishing unfinished work and that this project was just for the purpose
 of interacting with SDL 2.0, developing GUI application design skills and practicing my C++ skills,
 I really like the idea that I have in mind and I will be continuing the project with a different
 C++ framework you can read more about that below.
 ```
 
 In this current version I had successfully developed the main window for the project.
 The window is composed of these components:
 
 * A sidebar which purpose will be as of a "toolbox" for the program
 
 * The "task" area of the program
 
 * A create new "room" button, located in the sidebar which creates a new RoomButtonComponent and displays it sequentially on the 
 task area of the program until there is enough space
 
 * If any Rooms are "created" there will be X amount of buttons for each displayed in the task area
 
   * Each room button can open a separate window for it's room. If the "room window" is open pressing again on the "room button" 
   will close that window. 
   
   * The buttons are titled accordingly by a name saved in Files/Rooms/RoomButtons.txt or if it's a new room it's titled with "Room X"
   (X representing the current amount of rooms created)
   
 * The initialization of the main window is done by reading .txt files and that makes the program quite easy to be serialized in the future;
 
 * The buttons for the rooms are also read from a file.
 
 ## I am discontinuing the development for this project, SDL2.0 library is not well suited for GUI interfaces.
 
 The project will be transitioned to Qt5 framework as it is supporting all the trivial features which take most of the developing time for
 the project. That way I can focus on features and not be worried to "reinvent the wheel" in the process.
 
 The initial intentions for that projects where to be able to create new rooms which should be displayed as push buttons onto the task area (right of the sidebar). Pressing a button should loaded all the details for the corresponding room from a simple .txt file and create a separate window for the room. Upon exiting the data should of been serialized in according .txt files. On the next initialization of the program it should read from those files and initialize the saved work from the last session.
 
 * Each window should contained:
 
   * Modifiable name for the room - which should changed the text displayed on it's corresponding button to the typed text.
  
   * Modifiable occupants area if the room is taken.
  
   * A checkbox if the room is occupied that should color modulate the texture of its corresponding button to be red for occupied.
  
   * Modifiable "Notes" area for any notes for the room.
  
 ### Note to self:
 * I am satisfied with the work I have done for this project over a week, considering that it is my first project that was not entirely represented by the console IO and my first attempt to use SDL 2.0 outside my learning curve.
  
 
 
