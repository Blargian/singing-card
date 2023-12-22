This project is using CMake to compile and program the Arduino pro mini. I decided to do it this way because I don't like too much the limitations of the Arduino IDE, I'd much rather program in C++. 

CMake setup for this project comes from [here](https://github.com/tttapa/Arduino-AVR-CMake)

## To run 

from the root directory of the repository run:

git clone https://github.com/Microsoft/vcpkg.git

Once done, cd to the vcpkg folder and run:

`./bootstrap-vcpkg.sh`

Finally, run:

`./vcpkg integrate install`

Configure the project using CMake by running the following command:
```
cmake -S. -Bbuild \
    -D ARDUINO_PORT=COM4 \
    -D CMAKE_TOOLCHAIN_FILE=cmake/toolchain/promini.toolchain.cmake \
    -D CMAKE_BUILD_TYPE=MinSizeRel
```

Finally, build and upload the example “blink” program:

`cmake --build build -j -t upload-sing`

To compile the program without uploading, you can use

`cmake --build build -j -t sing`