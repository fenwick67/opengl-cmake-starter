# OpenGL CMake Example

This example uses CMake to build a simple openGL example [from the Red Book](www.glprogramming.com/red/chapter01.html).

1. clone and install deps

```
git clone <url>
sudo apt install freeglut3 freeglut3-dev libglew1.5 libglew1.5-dev libglu1-mesa libglu1-mesa-dev libgl1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev
```

2. build

```
mkdir build
cmake -G "Unix Makefiles" .. && make
```

3. run

```
./app
```