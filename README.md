# Image Crafter

## Overview

**Image Crafter** is a C-based image processing tool designed to read image data in '.ipi' format, process it using a machine model, and output the results in the PPM (Portable Pixmap) format. This project leverages a modular design, utilizing multiple header files that encapsulate functionality for layers, pixels, and the underlying machine architecture.


## Features

- **Image Processing**: Efficiently reads and processes image data to generate PPM files.
- **Modular Architecture**: Utilizes separate header files for layers, pixels, and machine logic, promoting maintainability and code organization.


## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/aryan-bansal/Image-Crafter.git
   cd Image-Crafter
   ```

2. Compile the project:

   ```bash
   make
   ```

## Usage

The `image_crafter` executable can be run in several modes based on the number of arguments:

- **Standard Input Mode**: Reads size from stdin and processes input until EOF.

  ```bash
  ./image_craft
  ```

- **File Input Mode**: Reads size from a specified input file.

  ```bash
  ./image_craft input_file.ipi
  ```

- **File Input & Output Mode**: Reads from a specified input file and writes the output to a specified output file.

  ```bash
  ./image_craft input_file.ipi output.ppm
  ```


## Contributing

Feel free to fork the project and submit pull requests. Ensure your changes pass all tests and maintain the structure of the project.
