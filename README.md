# Cub3D

*This project has been created as part of the 42 curriculum by msokolov.*

## Description

Cub3D is a 3D graphical project inspired by the legendary Wolfenstein 3D game, which was the first FPS (First Person Shooter) ever created. The goal of this project is to create a dynamic view inside a maze using raycasting principles, similar to those used in the classic Wolfenstein 3D.

The project provides a first-person perspective view of a maze defined in a `.cub` configuration file. Players can navigate through the maze using keyboard controls, with textured walls, floor and ceiling colors, and smooth rendering.

**Key Features:**
- Raycasting engine for 3D rendering
- Textured walls (North, South, East, West)
- Floor and ceiling color customization
- Player movement (W, A, S, D keys)
- Camera rotation (arrow keys or mouse)
- Door mechanics (open/close with E key)
- Minimap display
- Map validation and error handling

## Instructions
- a make command with the options of re fclean clean and standard make

### Prerequisites

- **Linux** operating system
- **GCC** compiler
- **Make** build system
- **MLX42** graphics library (included in the project)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/trojanforyou/Cub3D.git
cd Cub3D
```

2. Build the project:
```bash
make
```

This will compile the project and create the `cub3D` executable.

### Usage

Run the program with a valid `.cub` map file:

```bash
./cub3D maps/classic.cub
```

**Map file format:**

The `.cub` file must contain:
- Texture paths for each wall direction (NO, SO, WE, EA)
- Floor color (F) in RGB format (0-255)
- Ceiling color (C) in RGB format (0-255)
- Map layout using:
  - `1` for walls
  - `0` for empty space
  - `N`, `S`, `E`, or `W` for player starting position and orientation
  - `D` for doors (optional)
  - ` ` (space) for void areas

### Controls

- **W/A/S/D** - Move forward/left/backward/right
- **Left/Right Arrow** or **Mouse** - Rotate camera
- **E** - Open/close doors
- **ESC** - Exit the game

### Cleaning

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Rebuild the project
```

## Resources

### Documentation & Tutorials

- **Raycasting Tutorial** - [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
  - Comprehensive guide on raycasting principles and implementation
- **MLX42 Documentation** - [Codam MLX42](https://github.com/codam-coding-college/MLX42)
  - Graphics library documentation and examples
- **Wolfenstein 3D** - [Wikipedia](https://en.wikipedia.org/wiki/Wolfenstein_3D)
  - Historical context and game mechanics
- **DDA Algorithm** - [Digital Differential Analyzer](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))
  - Line drawing algorithm used in raycasting
