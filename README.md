# fdf
malapoug's fdf — a small 3D wireframe viewer project from 42-school

## Table of contents
- About
- Features
- Screenshots & GIFs
- Requirements
- Build
- Usage
- Controls (common / typical)
- Map file format
- Credits

## About
This repository contains an implementation of "fdf" — a program that reads a height-map (text file of integers) and renders a 3D wireframe projection (isometric) in a window.

## Features
- Parse plain-text map files (rows of integers)
- Render wireframe elevation maps
- Basic transformations: translate, scale (zoom), rotate
- Color support
- Minimal dependency set (C program, uses minilibx)

## Screenshots & GIFs

<img src="https://github.com/Loufok0/fdf/blob/main/ressources/gif.gif" width="500">
<img src="https://github.com/Loufok0/fdf/blob/main/ressources/t1.png" width="300">
<img src="https://github.com/Loufok0/fdf/blob/main/ressources/elem-fract.png" width="300">
<img src="https://github.com/Loufok0/fdf/blob/main/ressources/mars.png" width="300">

## Requirements
- C compiler (gcc or clang)
- make
- On Linux: X11 dev libs (libx11-dev, libxext-dev)
- On macOS: Xcode command line tools and the macOS-compatible MinilibX

## Build
- make          # build the binary (default target)
- make clean    # remove object files
- make fclean   # remove object files and binary
- make re       # fclean + make

Example:
```
make
./fdf maps/42.fdf
```

## Usage
Run the compiled binary with a map file path:

Example:
```
./fdf maps/42.fdf
```

## Controls
- Arrow keys: move view
- +/- zoom in/out
- W/S Modify height
- C: toggle color projection
- R: reset view
- Esc: exit

## Map file format
- Plain text
- Each line is a row of integers separated by spaces
- Example:
0 0 0 0
0 1 2 0
0 0 0 0

- You can also add colors like this: "3,0xFF0000".

## Credits
- Author / Maintainer: Loufok0
- Libraries: minilibx
