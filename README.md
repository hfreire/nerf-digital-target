# A digital :pager: target :dart: for Nerf gun :gun: darts

> Uses an [Adafruit Trinket](https://www.adafruit.com/product/1501) with a [Velostat](https://en.wikipedia.org/wiki/Velostat) pressure sensor circuit to show dart hits on a [4-Digit 7-Segment Display](https://www.adafruit.com/product/880).

<p align="center">
  <a href="http://www.youtube.com/watch?v=FRkOJmAujnU"><img src="share/github/overview.png" width="620"></a>
</p>

### Features
* Detect, :muscle: measure and display :dart: dart hit impacts on the target :white_check_mark:

### How to build
Clone the GitHub repo
```
git clone https://github.com/hfreire/nerf-digital-target.git
```

Change current directory
```
cd nerf-digital-target
```

Create build directory
```
mkdir build
```

Change current directory
```
cd build
```

Generate Makefile with Arduino toolchain
```
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/platforms/arduino/arduino.cmake ..
```

Package image
```
make 
```

Upload image
```
make upload
```

<p align="center">
  <img src="share/github/breadboard.png" width="400"/>
</p>
