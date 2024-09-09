# 🐜 Langton's Ant Simulation

## 📝 Overview
This C program simulates **Langton's Ant**, a two-dimensional universal Turing machine that follows a simple set of rules to traverse a grid. The ant moves based on the color of the cell it is on: it turns left on a black cell and turns right on a white cell. Over time, this simple behavior leads to complex patterns.

The program reads the grid dimensions, number of iterations, and the ant's starting direction from command-line arguments. It prints the resulting grid after the specified number of iterations.

## 💡 Features
- **Ant Movement**: The ant moves based on grid color and changes direction accordingly.
- **Grid Generation**: Creates an `m x n` grid where each cell can either be black (1) or white (0).
- **Customizable Input**: The user specifies the grid size, number of iterations, and starting direction.
- **Graphical Console Output**: Displays the grid and ant's final state visually in the console using ASCII characters.

## 📁 Files
- **`main.c`**: The main program file that initializes the grid, simulates the ant's movement, and prints the final grid.
- **`antMotion.h`**: Header file that contains the function prototypes for moving the ant.

## 💻 Compilation
To compile the program, use the following command:
\`\`\`bash
gcc -o langtons_ant main.c antMotion.c
\`\`\`

## 🔨 Usage
To run the program, use the following command:
\`\`\`bash
./langtons_ant <rows> <cols> <iterations> <file_prefix> <starting_direction>
\`\`\`

Where:
- `<rows>`: Number of rows in the grid (e.g., 100)
- `<cols>`: Number of columns in the grid (e.g., 100)
- `<iterations>`: Number of iterations (e.g., 100000)
- `<file_prefix>`: Prefix for the output files (currently not used)
- `<starting_direction>`: Initial direction of the ant (0: up, 1: right, 2: down, 3: left)

### Example Usage:
\`\`\`bash
./langtons_ant 100 100 100000 file 0
\`\`\`
This will simulate the ant on a 100x100 grid for 100,000 iterations, starting in the upward direction (0).

## 📋 Output
The program prints a visual representation of the grid after the specified iterations. White cells are represented by spaces, and black cells are represented by `██`. The grid is surrounded by ASCII box-drawing characters to give it a neat appearance.

### Example Grid Output:
\`\`\`bash
──────────────────────
│                    │
│  ██  ██            │
│      ██  ██  ██    │
│  ██      ██        │
│  ██  ██            │
──────────────────────
\`\`\`

## 🙋‍♂️ Authors
- **Jakub Sztobryn** ~ Warsaw University of Technology student
