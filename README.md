# Fract-ol

This project was developed as part of the 42 curriculum by **tagliarini-m**.

## 📖 Description

**Fract-ol** is a graphical project focused on creating a real-time fractal viewer. The goal is to explore the beauty of mathematical sets like **Mandelbrot** and **Julia**, rendering them using the **MinilibX** (MLX) library.

The project involves complex number mathematics and optimization techniques to handle pixel-by-pixel rendering and interactive features:
* **Fractals:** Dynamic rendering of the Mandelbrot set and various Julia sets.
* **Interactivity:** Smooth zooming at the mouse position and color shifting.
* **Performance:** Efficient use of hooks and images to ensure fluid navigation.

## 🛠️ Installation Instructions

### Prerequisites

* **GCC** or **Clang**
* **Make**
* **MinilibX** (The project expects the MLX library and its dependencies like X11 and zlib).

### Compilation

Clone the repository and compile the project then use `make`


## 🚀 Execution

To run the program, you must provide the name of the fractal you want to see as an argument.

./fractol [mandelbrot | julia x y]

obs: in julia, change x and y for coordinates

### Examples

`./fractol mandelbrot`

or

`./fractol julia -0.4 0.6`

### Controls

Mouse Wheel: Zoom in and out at the cursor position.

Arrows: Pan/Move through the fractal.

ESC / Close window: Exit the program safely.
