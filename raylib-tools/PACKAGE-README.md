# raylib-tools

This is a `build2` package for raylib support tools from the
[raylib](https://www.raylib.com) project.

## Usage

```
depends: raylib-tools ^6.0.0
```

Importable targets:

```
exe{rexm}
exe{rlparser}
```

### rexm

Raylib examples manager. Links against `libraylib` and is intended for
maintaining the upstream examples collection. Not run as an automated test.

### rlparser

Standalone C header parser tuned for raylib-style headers (`raylib.h`,
`rlgl.h`, etc.). Depends only on the C standard library for linking.

## Import example

```
import! rexm = raylib-tools%exe{rexm}
import! rlparser = raylib-tools%exe{rlparser}
```
