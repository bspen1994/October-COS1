
Features added: 

-Added system to view creatures in a "stable".
-Added the ability to create multiple creatures and switch between them at will.
-Added save system to allow you to save creatures and load them up later.

Updates to system design:
-Moved most all ui facing elements to the display class

Refactoring:
-Simplified a bunch of code and separated out code from the mainLoop::Run method so it is easier to add things to it without it being massive.
-Fixed the personality switch code to be more in line with the enum class.

What I changed and why:
-Moving the menus to the display class keeps all visual elements together and just makes more sense as the game itself gets bigger.
-Pulling out code from the Run method in mainLoop allows for better visibility of the Run method and allows for more scalability with more methods into that method.