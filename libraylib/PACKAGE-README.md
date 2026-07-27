# libraylib

This is a `build2` package for the [raylib](https://www.raylib.com) C library.
It provides a simple API for windowing, 2D/3D graphics, audio, and input.

## Usage

Add the following `depends` value to your `manifest`, adjusting the version
constraint as appropriate:

```
depends: libraylib ^6.0.0
```

Then import the library in your `buildfile`:

```
import libs = libraylib%lib{raylib}
```

Include the public headers as upstream documents:

```c
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <rcamera.h>
```

## Importable targets

This package provides the following importable targets:

```
lib{raylib}
```

`lib{raylib}` is the full raylib library (rcore, rshapes, rtextures, rtext,
rmodels, raudio) built for the desktop GLFW backend with OpenGL 3.3 by default.

## Platform and dependencies

This package uses upstream's default **desktop GLFW** backend and compiles the
bundled GLFW amalgamation (`rglfw.c`, GLFW 3.4) together with raylib. System
libraries such as OpenGL, X11 (Linux), and Win32 multimedia libraries are
linked as needed.

Optional external GLFW (cppget `glfw`) is not used in this version because
upstream embeds GLFW 3.4 while the stable cppget package is still on 3.3.x.

## Configuration variables

This package currently exposes no package-specific configuration variables.
Platform and graphics API follow upstream defaults (`PLATFORM_DESKTOP_GLFW`,
`GRAPHICS_API_OPENGL_33`).

## Examples

Upstream desktop examples that depend only on raylib are compiled under
`tests/examples/` (categories: audio, core, models, shaders, shapes, text,
textures, and most of others). They are build-only targets (`test = false`)
so interactive windows are not launched by `bdep test`.

Not included (need extra vendored GLFW/glad under `examples/others/external/`):

- `rlgl_standalone`
- `raylib_opengl_interop`

Related tools (`rexm`, `rlparser`) ship in the sibling `raylib-tools` package.
