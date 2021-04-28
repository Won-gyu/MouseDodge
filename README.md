# MouseDodge
- The player moves Hero and dodges monsters using the mouse
- Hero starts with 10 HP and loses one every time it runs into a monster
- Over time Hero will level up and gain HP, however the monsters will also get harder

## Game Play
- Use the arrow keys to select options in the Menu
- Use Esc to return from any window to the Menu
- In the game use your mouse to move Hero away from monsters
- If implemented, use the left mouse button to trigger Hero's invincibility

## Testing Network (Currently Unstable)
- Open two instances of MouseDodge in different windows
- Run the game in server mode from one window
- After a few seconds open the game from client mode in the second window
- You should be able to play on the cient window and view the game in the server window with a slight delay

## Programmers
Won-gyu Hwang
- Design the program framework
- Implement Hero(has hp and movable by mouse), base Monster(has simple move patterns)
- Combine others' code
- Rough diagram of in-game objects https://docs.google.com/drawings/d/1bak9Jg4cMHtfxeA9ubuS-2ohl1nBc-tMi1ohaXNzhO4/edit?usp=sharing

Scott Van Laar
- Design the Menu
- Implement Score Rank system (save & load "rank.txt")
- Implement extra features of Hero like invincibility for 10 seconds (on left mouse button press), etc.

Zachary Harrington
- Implement complicated types of Monster like TargetMonster (follows the player for n seconds), DynamicMonster (radius grows/shrinks), etc.
- Implement Credits page
- Add sounds

## 04-17-2021
Set up project for SFML watching https://youtu.be/YfMQyOw1zik

## 04-18-2021
Implemented Menu & Hero
