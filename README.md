# raylib

This is a `build2` package repository for [raylib](https://www.raylib.com),
a simple and easy-to-use library to enjoy videogames programming.

Packages in this repository:

| Package | Description |
|---|---|
| [`libraylib`](libraylib/PACKAGE-README.md) | raylib C library (desktop GLFW backend) |
| [`raylib-tools`](raylib-tools/PACKAGE-README.md) | `rexm` (examples manager) and `rlparser` |

Upstream examples that only need raylib live under
`libraylib/tests/examples/` (built with `test = false`). Examples that require
vendored third-party windowing under `examples/others/external/`
(`rlgl_standalone`, `raylib_opengl_interop`) are not packaged yet.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. For consumer-facing
package docs see the package `PACKAGE-README.md` files linked above.

The development setup for `raylib` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules .../raylib.git
cd raylib

bdep init -C @msvc cc
bdep update
bdep test
```
