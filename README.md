# cub3d
![gif](https://github.com/retakashi/cub3d/blob/rtakashi_home/cub3D.gif)

## Overview
This is a program that uses ray casting to render a maze in "realistic" 3D graphics from a first-person perspective.

## Implementation Environment

- **Programming Language**: C
- **Operating Systems**: macOS
- **Compiler**: Apple Clang 15.0.0 (clang-1500.3.9.4), Target: arm64-apple-darwin23.6.0

## Usage
### Mandatory
``` bash
git clone ...
cd cub3d
make
./cub3d <map_path>
```
### Bonus
``` bash
make bonus
./cub3d_bonus <map_path>
```
## Features
### Mandatory
- left arrow key, right arrow key: Look left and right in the maze.
- W key, S key: Move forward and backward.
- A key, D key: Move left and right.
### Bonus
In addition to the mandatory features, the following functionalities are available:
- rotate the point of view with the mouse.
- Notify about the collision with the wall.
  
