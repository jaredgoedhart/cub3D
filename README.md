# Cub3D: Ray Casting Game Engine

## 🎮 Project Overview

Cub3D is a ray-casting game engine inspired by the classic Wolfenstein 3D, implemented in C using the MLX42 graphics library. This project demonstrates low-level graphics rendering techniques, specifically ray-casting, to create a pseudo-3D environment from a 2D map.

## 🖥️ Features

- Smooth first-person perspective rendering
- Ray-casting algorithm for wall rendering
- Textured walls and sprites
- Player movement and rotation
- Custom map parsing and validation
- Multiple map configurations with unique themes

## 🎨 Themes Included

This project comes with several pre-configured map themes:
- Aphex Twin Canny
- Aphex Twin Uncanny
- Bella Reanimation
- Digital Nature (Windows XP)

## 🛠️ Technical Details

### Rendering Technique
- Uses ray-casting to create a 3D-like perspective from a 2D map
- Calculates wall distances and textures in real-time
- Supports sprite rendering with depth sorting

### Movement
- WASD keys for movement
- Arrow keys for camera rotation
- Collision detection with walls

## 📦 Dependencies

- MLX42 Graphics Library
- libft (Custom C library)
- Standard C libraries

## 🚀 Compilation

```bash
# Clone the repository
git clone https://github.com/yourusername/cub3d.git
cd cub3d

# Compile the project
make
```

## 🎮 Running the Game

```bash
# Basic syntax
./cub3D <map_file.cub>

# Example
./cub3D maps/digitalNature.cub
```

## 🕹️ Controls

- `W`: Move Forward
- `S`: Move Backward
- `A`: Strafe Left
- `D`: Strafe Right
- `←`: Rotate Camera Left
- `→`: Rotate Camera Right
- `ESC`: Exit Game

## 🗺️ Map Configuration

The game uses `.cub` files for map configuration. Each map file defines:
- Resolution
- Texture paths for walls and sprites
- Floor and ceiling colors
- 2D map layout

### Map Symbols
- `0`: Empty space
- `1`: Wall
- `2`: Sprite
- `N`, `S`, `E`, `W`: Player starting position and direction

## 🎥 Demonstration

[![Cub3D Gameplay](https://img.youtube.com/vi/ZYLt-T0zv7U/0.jpg)](https://www.youtube.com/watch?v=ZYLt-T0zv7U)

Click the image above to watch a gameplay demonstration.

## 📄 License

Distributed under the MIT License. See `LICENSE` for more information.

## 👥 Authors

- [Jared Goedhart](https://github.com/jaredgoedhart)
- [Luca Goddijn](https://github.com/DontCallMeLuca)

## 🙏 Acknowledgments

- 42 Network for the project inspiration
- MLX42 Graphics Library
- Wolfenstein 3D for the ray-casting concept
