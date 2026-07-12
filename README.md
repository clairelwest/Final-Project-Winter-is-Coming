# Final-Project-Winter-is-Coming

# CSCI 1300 Final Project

## Theme

My final Project is themed around Winterfell from the Game of Thrones universe. The main character will be Sansa Stark, and the game will also feature Brienne of Tarth, Arya Stark, Jon Snow, and Petyr Baelish. Sansa is the Queen of the North, and as winter approaches she will need to collect the necessary materials to care for her people.

## Goal

Sansa must complete a bundle of supplies before winter to keep her people safe and well fed. Sansa loses if she runs out of time before winter. Sansa will also lose if she runs out of respect, and in this scenario Petyr will arrive and take Winterfell. There is a special win scenario where Arya kills Petyr which wins Sansa additional respect.

## How to compile and run

The game complies with "g++ -Wall -Wpedantic -Werror -std=c++17 -g MainLoop.cpp Game.cpp Sansa.cpp ASCII.cpp Location.cpp Character.cpp Task.cpp" and runs with "./a.out". By putting using these commands in your terminal you should be able to play the game.

## How to play

This is a simple text based game which will prompt you to enter either "yes" or "no" or a number. You win the game by completing the nessesary tasks before time runs out.

## Classes

This game is comprised of several classes with their own unique functions and variables:
1. Game Class:
  This class hold many of the functions that run throughout the game including the win and loss conditions, intro, and taking a turn. The game is run in the main loop by creating a game object and running these functions. 
2. Character Class:
  This class is used for all the side characters and is the base class for the main character Sansa. It is a pretty simple class that includes a name and an index for each character. The side characters are created in the Game constructor as part of the vector "map".
3. Sansa Class:
  The main character of the game and has her own class derived from the Character class. Her class includes many functions which control her interactions with other characters and allow her to complete tasks.
4. Location Class:
  This class holds information about each of the four locations including a name, banner, and vectors for the characters and tasks found there. It features two main functions which find the availible characters and tasks from their vectors and print them in a list.
5. Task Class:
  This class is similar to the character class as it contains a name and index for each task. The tasks are created in the Game constructor as part of the vector "map".

## Extra credit

None
