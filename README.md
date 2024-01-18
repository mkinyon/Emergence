# Emergence
Emergence is a simple C++ application that showcases different algorithms based on emergent behavior and cellular automation.  Currently, it supports:
- [Conway's Game Of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
- [Langton's Ant](https://en.wikipedia.org/wiki/Langton%27s_ant)
- [Falling Sand](https://en.wikipedia.org/wiki/Falling-sand_game) (Currently supports one type of sand.)

## Examples

## Controls
| Key | Description |
|-----------------------------|-----------------------------|
| **LEFT MOUSE** | Interact (usually by allowing you to place a pixel given the context of the simulation.) |
| **C**          | Cycles to the next simulation. |
| **R**          | Resets the current simulation. |

## Requirements
- Visual Studio (Not required, however the premake scripts only support VS.)
- Windows (Currently the premake scripts only support Windows.)

#### Compiling
Once you have cloned, run the `Setup-Windows.bat` script to generate solution/project files for Visual Studio.

## 3rd Party Libraries
- [OneLoneCoder olcPixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine) 
