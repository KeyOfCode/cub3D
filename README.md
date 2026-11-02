> *This project has been created as part of the 42 curriculum by darismen*

# *cub3D*

## Description

**cub3D** is a graphical project inspired by *Wolfenstein 3D*. It introduces raycasting to create a simple 3D perspective from a 2D map.

The program displays a navigable maze with textured walls and allows the player to move through the map in real time.

It uses a local implementation of Codam's MLX42 library for ease of cloning. (See: Resources)

## Features

- Raycasting-based 3D rendering
- Textured walls
- Player movement and camera rotation
- Collision detection
- Configurable map and textures
- Window management and keyboard input
- Map validation

## Requirements

- Linux
- `gcc` or `clang`
- `make`

## Installation

Clone the repository and build the project:

```bash
git clone git@github.com:KeyOfCode/cub3D.git Cub3D
cd Cub3D
make exe
```

## Usage

The maps follow a format of textures, colors for the ceiling and the floor, and an alphanumeric map.
*make exe* will execute using a predetermined map set in the makefile.

## Controls

| Key | Action |
|---|---|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Move left |
| `D` | Move right |
| `←` / `→` | Rotate camera |
| `ESC` | Exit the game |

## Cleanup

```bash
make fclean
```

## Resources
No AI was used in the creatin of this project.

* [Local implementation of the MLX42 library] (https://github.com/codam-coding-college/MLX42)
* https://harm-smits.github.io/42docs/projects/cub3d
* https://github.com/MichelleJiam/cub3D
* https://hackmd.io/@nszl/H1LXByIE2
