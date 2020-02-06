# Image Upscaler

A really, really simple image upscaler, intended for perfect integer upscaling (good for pixelart)

I don't claim this to be good code (it's slow...), but it works, and that's all I need

## Getting Started

* GCC Recommended (you're going to compile the source yourself)
* might provide a built executable for Windows later

## Prerequisites

* A C++ compiler (Makefile is for GCC)
* C++11
* Magick++ installed

## Installation

* install Magick++
* download this repository
* build

### Installing Magick++

#### Linux

Enter these commands in the terminal:

```
wget https://www.imagemagick.org/download/ImageMagick.tar.gz
tar xvzf ImageMagick.tar.gz
cd ImageMagick-[version]
./configure
make
make install
ldconfig /usr/local/lib
```

And you're good to go!

#### Windows

(has not been tested)

* Install [ImageMagick](https://imagemagick.org/script/download.php)

### Building

Simply run `make` to get your executable, then run that when desired

Running: `./upscaler`

Outputs to the folder where the executable was run from. I haven't done much testing but I'm pretty sure the original image can be located anywhere.

If you're on Windows or not using GCC, good luck

### A demo

Run `make mario` to get 16x16 8-bit Mario upscaled to 512x512 8-bit Mario

## Built With

* [Magick++](http://www.graphicsmagick.org/Magick++/) - Image library to edit the images
* the power of open-source software

## Contributing

it's pretty much done so if you want to contribute you're better off making your own project, either starting from this one or from scratch

## License

This project is licensed under the MIT license

## Other copyright notice

I DO NOT OWN 8-BIT MARIO (OR ANY MARIO). THE IMAGE WAS ONLY PROVIDED FOR A DEMO, AND LITERALLY ANY NON-BROKEN IMAGE WOULD SUFFICE (pixel art works best though). PLEASE DON'T SUE ME, NINTENDO.

## Acknowledgments

* StackOverflow
* helpful documentation (good job Magick++)
