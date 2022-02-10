11/27/2021
***This was a group project made with one partner***
***Project member's personal info has been removed for their privacy***

Made by:
Chris Caldwell C11526746 ccaldw3@clemson.edu
Zachary S. 

Compatibility:
##Warning##
This program is made for use within a Linux Operating environment. Any attempted use in another operating system cannot guarantee successful
execution of the program, and may have unintended consequences.

Functionality:
This program scans through a local file IN THE SAME FOLDER AS THE PROGRAM, and retrieves images stored in byte format, returning them 
in a named sequence starting from 0. EACH ITERATION OF THE PROGRAM OVERWRITES THE OUTPUT IMAGES WITH DEFAULT NAMES. This program reads
the designated source file in 512 bytes. 

Execution instructions: (default)
The included program is uncompiled, meaning in order to run it, you must first compile it. There is an attached makefile for use within
a Linux operating system, allowing the user to input "make", then "make run" to execute the program as intended using the default included
storage reference for image retrieval. When completed, the user can input "make clean" into the linux command prompt to removal all files
created by the program.

Execution instructions: (custom)
In order to customize a file for image scanning, the user can follow the above directions for default operation, with exception to inputting
"make run", the user must type "./driver.out " followed by the filename for the desired scanned file.
