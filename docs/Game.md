[go back](../README.md)

# Game

Knowledge about game programming is collected here.






### Game Loop

The Game loop is the loop within the game logic and graphics get updated. Different to other applications, a game have to run a loop where the game gets updated until the game ends. 

The famous **FPS** comes right from here. The game loop can run multiple times per second and the FPS (frames per second) says how often the game loop runs in one second. Therefore one iteration of the game loop is called **frame**.

On a high-level this can be splitted into:
- **Input Processing**<br>
	Which can be the input from a controller, keyboard, GPS, ... These can be from one player or for an server with multiple players there would be multiple inputs every frame.
- **Game World Update**<br>
	Updates every object in the game (if needed). For example to apply gravity or updating the position when the player pressed 'w'.
- **Output generation**<br>
	The output is the rendering (graphics), audio (->music, dialogue, effects), controller feedback (like shaking) or sending data to players (in multiplayer games...).

Note that the game loop is paused during 'pause' (if existing) for example by pressing the settings or the menu and the game loop not even started if the game is in the start menu. Sometimes some parts of the game still  loops when pasuing the game. For example some games still let update some graphics or sounds.






### Game Engine

...






### Ressources

Probably best ressource:


<img src="../res/img/game_engine_cover.jpg" width=0.5></img>

**Game Engine Architecture, Third Edition** by Jason Gregory (2018/2019)
- [amazon link](https://www.amazon.de/Engine-Architecture-Third-Jason-Gregory/dp/1138035459/ref=sr_1_1)
- [thalia link](https://www.thalia.de/shop/home/artikeldetails/A1048142533)

<br><br>

<img src="../res/img/cpp_game_dev_cover.jpg" width=0.5></img>

**Game Programming in C++: Creating 3D Games** by Sanjay Madhav (2018)
- [amazon link](https://www.amazon.de/Game-Programming-Creating-Addison-Wesley-Development/dp/0134597206/ref=sr_1_1)
- [thalia link](https://www.thalia.de/shop/home/artikeldetails/A1045611597)

<br><br>

<img src="../res/img/components_game_engine_cover.jpg" width=0.5></img>

**Components of a Game Engine** by Harold Serrano
- [Gumroad link](https://haroldserrano.gumroad.com/l/componentsofagameengine)

<br>

---






