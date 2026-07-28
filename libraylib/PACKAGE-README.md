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

`lib{raylib}` is the raylib library for the desktop GLFW backend. Optional
modules and feature flags are controlled with configuration variables below.

## Configuration variables

Defaults match upstream `src/config.h` and a full desktop GLFW + OpenGL 3.3
build. Set via `bdep config` / `config.libraylib.*=...` when creating a
configuration, or when building the package.

### Backend and graphics

| Variable | Type | Default | Maps to |
|---|---|---|---|
| `config.libraylib.graphics` | string | `opengl-3.3` | `GRAPHICS_API_*` |

`config.libraylib.graphics` values: `opengl-4.3`, `opengl-3.3`, `opengl-2.1`,
`opengl-1.1`, `opengl-es2`, `opengl-es3`, `software`.

Desktop windowing uses the `glfw` package dependency.

### Optional modules

When false, the corresponding `.c` is not compiled and
`SUPPORT_MODULE_*=0` is set.

| Variable | Default | Source / define |
|---|---|---|
| `config.libraylib.module_shapes` | `true` | `rshapes.c` / `SUPPORT_MODULE_RSHAPES` |
| `config.libraylib.module_textures` | `true` | `rtextures.c` / `SUPPORT_MODULE_RTEXTURES` |
| `config.libraylib.module_text` | `true` | `rtext.c` / `SUPPORT_MODULE_RTEXT` |
| `config.libraylib.module_models` | `true` | `rmodels.c` / `SUPPORT_MODULE_RMODELS` |
| `config.libraylib.module_audio` | `true` | `raudio.c` / `SUPPORT_MODULE_RAUDIO` |

### Feature flags (`SUPPORT_*` / `RLGL_*`)

All of these are `bool` and map to `-DNAME=0` or `-DNAME=1` with
`EXTERNAL_CONFIG_FLAGS` (so `config.h` defaults are not used). Defaults match
upstream `config.h`.

| Variable | Default | Upstream define |
|---|---|---|
| `config.libraylib.tracelog` | `true` | `SUPPORT_TRACELOG` |
| `config.libraylib.camera_system` | `true` | `SUPPORT_CAMERA_SYSTEM` |
| `config.libraylib.gestures_system` | `true` | `SUPPORT_GESTURES_SYSTEM` |
| `config.libraylib.rprand_generator` | `true` | `SUPPORT_RPRAND_GENERATOR` |
| `config.libraylib.mouse_gestures` | `true` | `SUPPORT_MOUSE_GESTURES` |
| `config.libraylib.ssh_keyboard_rpi` | `true` | `SUPPORT_SSH_KEYBOARD_RPI` |
| `config.libraylib.winmm_highres_timer` | `true` | `SUPPORT_WINMM_HIGHRES_TIMER` |
| `config.libraylib.busy_wait_loop` | `false` | `SUPPORT_BUSY_WAIT_LOOP` |
| `config.libraylib.partialbusy_wait_loop` | `true` | `SUPPORT_PARTIALBUSY_WAIT_LOOP` |
| `config.libraylib.screen_capture` | `true` | `SUPPORT_SCREEN_CAPTURE` |
| `config.libraylib.compression_api` | `true` | `SUPPORT_COMPRESSION_API` |
| `config.libraylib.automation_events` | `true` | `SUPPORT_AUTOMATION_EVENTS` |
| `config.libraylib.custom_frame_control` | `false` | `SUPPORT_CUSTOM_FRAME_CONTROL` |
| `config.libraylib.clipboard_image` | `true` | `SUPPORT_CLIPBOARD_IMAGE` |
| `config.libraylib.opengl_debug_context` | `false` | `RLGL_ENABLE_OPENGL_DEBUG_CONTEXT` |
| `config.libraylib.show_gl_details_info` | `false` | `RLGL_SHOW_GL_DETAILS_INFO` |
| `config.libraylib.quads_draw_mode` | `true` | `SUPPORT_QUADS_DRAW_MODE` |
| `config.libraylib.fileformat_png` | `true` | `SUPPORT_FILEFORMAT_PNG` |
| `config.libraylib.fileformat_bmp` | `true` | `SUPPORT_FILEFORMAT_BMP` |
| `config.libraylib.fileformat_tga` | `false` | `SUPPORT_FILEFORMAT_TGA` |
| `config.libraylib.fileformat_jpg` | `false` | `SUPPORT_FILEFORMAT_JPG` |
| `config.libraylib.fileformat_gif` | `true` | `SUPPORT_FILEFORMAT_GIF` |
| `config.libraylib.fileformat_qoi` | `true` | `SUPPORT_FILEFORMAT_QOI` |
| `config.libraylib.fileformat_psd` | `false` | `SUPPORT_FILEFORMAT_PSD` |
| `config.libraylib.fileformat_dds` | `true` | `SUPPORT_FILEFORMAT_DDS` |
| `config.libraylib.fileformat_hdr` | `false` | `SUPPORT_FILEFORMAT_HDR` |
| `config.libraylib.fileformat_pic` | `false` | `SUPPORT_FILEFORMAT_PIC` |
| `config.libraylib.fileformat_pnm` | `false` | `SUPPORT_FILEFORMAT_PNM` |
| `config.libraylib.fileformat_ktx` | `false` | `SUPPORT_FILEFORMAT_KTX` |
| `config.libraylib.fileformat_astc` | `false` | `SUPPORT_FILEFORMAT_ASTC` |
| `config.libraylib.fileformat_pkm` | `false` | `SUPPORT_FILEFORMAT_PKM` |
| `config.libraylib.fileformat_pvr` | `false` | `SUPPORT_FILEFORMAT_PVR` |
| `config.libraylib.image_export` | `true` | `SUPPORT_IMAGE_EXPORT` |
| `config.libraylib.image_generation` | `true` | `SUPPORT_IMAGE_GENERATION` |
| `config.libraylib.fileformat_ttf` | `true` | `SUPPORT_FILEFORMAT_TTF` |
| `config.libraylib.fileformat_fnt` | `true` | `SUPPORT_FILEFORMAT_FNT` |
| `config.libraylib.fileformat_bdf` | `false` | `SUPPORT_FILEFORMAT_BDF` |
| `config.libraylib.fileformat_obj` | `true` | `SUPPORT_FILEFORMAT_OBJ` |
| `config.libraylib.fileformat_mtl` | `true` | `SUPPORT_FILEFORMAT_MTL` |
| `config.libraylib.fileformat_iqm` | `true` | `SUPPORT_FILEFORMAT_IQM` |
| `config.libraylib.fileformat_gltf` | `true` | `SUPPORT_FILEFORMAT_GLTF` |
| `config.libraylib.fileformat_vox` | `true` | `SUPPORT_FILEFORMAT_VOX` |
| `config.libraylib.fileformat_m3d` | `true` | `SUPPORT_FILEFORMAT_M3D` |
| `config.libraylib.mesh_generation` | `true` | `SUPPORT_MESH_GENERATION` |
| `config.libraylib.gpu_skinning` | `false` | `SUPPORT_GPU_SKINNING` |
| `config.libraylib.fileformat_wav` | `true` | `SUPPORT_FILEFORMAT_WAV` |
| `config.libraylib.fileformat_ogg` | `true` | `SUPPORT_FILEFORMAT_OGG` |
| `config.libraylib.fileformat_mp3` | `true` | `SUPPORT_FILEFORMAT_MP3` |
| `config.libraylib.fileformat_qoa` | `true` | `SUPPORT_FILEFORMAT_QOA` |
| `config.libraylib.fileformat_flac` | `false` | `SUPPORT_FILEFORMAT_FLAC` |
| `config.libraylib.fileformat_xm` | `true` | `SUPPORT_FILEFORMAT_XM` |
| `config.libraylib.fileformat_mod` | `true` | `SUPPORT_FILEFORMAT_MOD` |

Example (disable audio and models, keep default graphics):

```
bdep config create @msvc-cc cc \
  config.libraylib.module_audio=false \
  config.libraylib.module_models=false
```

## Target metadata

`lib{raylib}` exports metadata (prefix `libraylib`) for:

- `libraylib.graphics`
- `libraylib.module_shapes` / `module_textures` / `module_text` /
  `module_models` / `module_audio`

## Examples

Upstream desktop examples that depend only on raylib are compiled under
`tests/examples/` (categories gated by the module config variables). They are
build-only targets (`test = false`) so interactive windows are not launched by
`bdep test`.

Not included (need extra vendored GLFW/glad under `examples/others/external/`):

- `rlgl_standalone`
- `raylib_opengl_interop`

Related tools (`rexm`, `rlparser`) ship in the sibling `raylib-tools` package.

## Not configurable here (yet)

Other platforms (Web, Android, DRM, SDL, RGFW, Memory), numeric `MAX_*`
buffer sizes, and audio device tuning macros remain at upstream code defaults.
Those need extra backends or generated headers beyond the current desktop
GLFW package.
