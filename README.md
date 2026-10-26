# 32Blit Boilerplate

![Build](https://github.com/32blit/32blit-boilerplate/workflows/Build/badge.svg)

This is a basic template for starting 32blit projects. It shows the basic
code layout and asset pipeline, hopefully giving folk a starting point for
any new projects.

It's based on the original `template` project from the 
[32Blit SDK](https://github.com/32blit/32blit-sdk), with added asset
handling, and some tidying up to fit in with how I do things.

## Usage

[Use this template](https://github.com/32blit/32blit-boilerplate/generate) to
generate your own project (creates a new repository for you to keep your code tracked on GitHub).

* **Edit the CMakeList.txt file to set the name of your project! (LINE 5 - no spaces allowed in the name)**
* **Edit the metadata.yml file to set the information for your project!**
* Edit the LICENSE file to set your name on the license
* Write lots of super cool code!

You should then be able to follow the usual build instructions.

For local builds this is:
```
mkdir build
cd build
cmake -D32BLIT_DIR=/path/to/32blit-sdk/ .. # The SDK path might be detected automatically in some cases
```

After that, the Makefile in `build` will have a target for your game name (whatever you set in line 5 of `CMakeLists.txt`)
```
make my-game-name
```

After that your executable will be in the build directory. You can just run it through the command line

Platform/Editor specific instructions [can be found in the main 32blit repo](https://github.com/32blit/32blit-sdk#you-will-need)
(For Visual Studio, you should follow the "Option 2" instructions, as the boilerplate does not contain a solution file)


## Troubleshooting

### Keyboard inputs failing on Linux

On certain Linux machines, there might be issues with 32blit's SDL2 backend. On my setup (Fedora + KDE Plasma), running the executable using Wayland caused issues with registering my keyboard inputs (despite controller working fine). To fix this you can try adding the `SDL_VIDEODRIVER=x11` environment variable when running:

```
SDL_VIDEODRIVER=x11 <your-executable-path>
```

### Intellisense failing to find header files (C/C++ Extension Pack VSCode Extension)

When you first start a 32blit project, it is likely that you will see errors at the `#include <header>` lines of code in both your .cpp and .hpp files. This is because there is a dependency on the 32blit SDK which lives outside of this repository. The fix here is to simply tell the extension where these header files live by making a `.vscode/c_cpp_properties.json` file in this repository and defining the `includePath`.

(Google/ask AI to help format this file and supply other useful fields in this file)
```
"includePath": [
    "${workspaceFolder}",
    "${workspaceFolder}/../32blit-sdk/32blit",
    "${workspaceFolder}/../32blit-sdk/32blit-sdl"
]
```
