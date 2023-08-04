# pickME Color Picker

**Note: pickME is currently in its early development stages. Some features may be incomplete or subject to change. Your feedback and contributions are highly appreciated as I work towards a stable release.**

## Introduction

pickME is a lightweight and user-friendly color picker tool designed to help you effortlessly capture and analyze colors from your screen. By simply clicking on any point on your display, pickME instantly provides you with the selected color's RGB values, hexadecimal representation, and HSL values.


## Features

- **Color Information**: Retrieve RGB, hexadecimal, and HSL color values with a single click.
- **Ease of Use**: pickME's straightforward command-line interface makes it accessible to users of all levels.
- **Accurate Capture**: pickME ensures precise color capture by monitoring mouse interactions.
- **Colorful Terminal**: Utilize pickME with color-supportive terminals for an enhanced and visually engaging experience.

## Getting Started

### Prerequisites

To use pickME, make sure you have the following prerequisites:

- Windows operating system
- C++ compiler (such as g++)

### Installation

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/oddegen/pickME.git
   ```

2. Navigate to the project directory:

   ```bash
   cd pickME
   ```

3. Compile the source code using the provided Makefile:

   ```bash
   make
   ```

This will generate the `pickME.exe` executable in the project's `bin` directory.

## Usage

1. Open a terminal and navigate to the `bin` directory:

   ```bash
   cd path/to/pickME/bin
   ```

2. Run the `pickME.exe` executable:

   ```bash
   pickME.exe
   ```

3. Click anywhere on the screen to capture the color at that point.

4. To exit the tool, press `Ctrl+C` in the terminal.

## Color Terminal Compatibility

For optimal results, it's recommended to use pickME with terminals that offer robust color support. Terminals like [Windows Terminal](https://aka.ms/terminal) and [Hyper](https://hyper.is/) are known for their excellent color capabilities.

Ensure that your terminal's color settings are appropriately configured to fully appreciate the vivid color displays provided by pickME.

## Contributing

Contribute to pickME by following these steps:

1. Fork the repository.
2. Create a new branch for your enhancements.
3. Commit your changes with descriptive messages.
4. Push your changes to your fork.
5. Open a pull request to share your contributions.

## License

pickME is licensed under the [MIT License](LICENSE), allowing you to modify and distribute it as needed. Enjoy exploring colors with pickME!
