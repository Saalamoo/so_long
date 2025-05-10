# so_long

<p align="center">
  <img src="imgs/so_longvid.gif" alt="so_long demo" width="800"/>
</p>

## About

**so_long** is a small 2D graphical game developed using the MiniLibX graphics library.  
The objective of the game is for the player to navigate through a simple map, collect all the collectibles, and reach the exit to win.

This project was designed to help understand:

- Basic graphics programming in C.
- Map file parsing and validation.
- User input handling via the keyboard.
- Game state management (e.g., player position, collectibles, and movement count).

Each map is provided as a `.ber` file and must follow specific rules:

- The map must be rectangular and surrounded by walls.
- It must contain at least one player start position, one exit, and one collectible.
- Invalid maps are properly detected and rejected with an error message.

The game renders a top-down view of the map using sprites (XPM images), and prints the number of movements in the terminal as the player moves.

### Compilation

To compile the project, simply run:

```bash
make
```

This will compile the necessary files and generate the executable.

### Running the game

After compiling, you can run the game with:

```bash
./so_long so_long.ber
```
Replace so_long.ber with the path to any valid .ber map file you want to play.

### Controls

The game is controlled using the arrow keys:

- `↑` – Move Up  
- `←` – Move Left  
- `↓` – Move Down  
- `→` – Move Right  
- `ESC` – Exit the game
