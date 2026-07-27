# raylib

This is a `build2` package repository for [raylib](https://www.raylib.com),
a simple and easy-to-use library to enjoy videogames programming.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`raylib` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libraylib/PACKAGE-README.md) file.

The development setup for `raylib` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules .../raylib.git
cd raylib

bdep init -C @msvc cc
bdep update
bdep test
```
