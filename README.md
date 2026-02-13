# Kris's build of st (flexipatch)

The [suckless terminal (st)](https://st.suckless.org/) with additional features that make it the best terminal emulator.

This build is based on [st-flexipatch](https://github.com/bakkeby/st-flexipatch), which uses preprocessor directives to manage patches. This allows easy toggling of features without manual patching.

---

## How Patches Work (Preprocessor Directives)

Unlike traditional st patching, this build uses C preprocessor directives to include/exclude patches at compile time. To enable or disable a patch, edit `patches.h` and set the value to `1` (enabled) or `0` (disabled):

```c
#define ALPHA_PATCH 1      /* enabled */
#define FULLSCREEN_PATCH 0 /* disabled */
```

Then rebuild:
```bash
sudo make clean install
```

All patch options are documented in `patches.h`. The actual code for each patch lives in the source files, wrapped in `#if PATCH_NAME ... #endif` blocks.

---

## Features

### Clipboard

| Keybinding | Action |
|------------|--------|
| `Ctrl+c` or `Ctrl+Shift+c` | Copy selection |
| `Ctrl+v` or `Ctrl+Shift+v` | Paste |
| `Right Click` | Paste from clipboard |

### Scrollback

| Keybinding | Action |
|------------|--------|
| `Alt+k` / `Alt+Up` | Scroll up (1 line) |
| `Alt+j` / `Alt+Down` | Scroll down (1 line) |
| `Alt+u` / `Alt+PageUp` | Scroll up (page) |
| `Alt+d` / `Alt+PageDown` | Scroll down (page) |

### Font & Zoom

| Keybinding | Action |
|------------|--------|
| `Alt+,` | Zoom in |
| `Alt+.` | Zoom out |
| `Alt+g` | Reset to default size |
| `Super+Shift+K/J` | Zoom in/out |
| `Super+Shift+U/D` | Zoom in/out (2x) |

### Transparency

| Keybinding | Action |
|------------|--------|
| `Alt+s` | Increase transparency |
| `Alt+a` | Decrease transparency |
| `Alt+m` | Reset transparency (opaque) |

### External Pipe

| Keybinding | Action |
|------------|--------|
| `Alt+l` | Open URL handler |
| `Alt+y` | Copy URL to clipboard |
| `Alt+o` | Copy terminal output |

### Other

| Keybinding | Action |
|------------|--------|
| `Super+Shift+Enter` | Spawn new terminal in current directory |
| `Ctrl+Shift+U` | Unicode input (ISO 14755) |

---

## Enabled Patches

Configured in `patches.h`:

| Patch | Description |
|-------|-------------|
| alpha | Transparency support with configurable opacity |
| anygeometry | Dynamic geometry/borders |
| anysize | Resize to any pixel size |
| blinking_cursor | Cursor blinking support |
| boxdraw | Render box-drawing characters without font glyphs |
| clipboard | Clipboard integration (CLIPBOARD on selection) |
| columns | Doesn't cut text while resizing |
| copyurl | Select and copy URLs |
| externalpipe | Pipe terminal content to external commands |
| font2 | Secondary font support (emoji fallback) |
| iso14755 | Unicode input via dmenu |
| ligatures | HarfBuzz ligature support |
| newterm | Spawn new terminal in current directory |
| scrollback | Scroll history |
| scrollback_mouse | Scroll with mouse wheel + Shift |
| scrollback_mouse_altscreen | Mouse scroll in alternate screen |
| **sixel** | **Sixel graphics support (for manga-tui, etc.)** |
| swapmouse | Swap mouse buttons |
| sync | Synchronized updates to reduce flicker |
| xresources | Load settings from Xresources |
| xresources_reload | Live reload on SIGUSR1 |

---

## Appearance

- **Default font:** JetBrainsMono Nerd Font
- **Color scheme:** Gruvbox Dark
- **Transparency:** 85% (configurable)
- **Xresources:** Supports dynamic colors via `~/.Xdefaults` or `~/.Xresources`
- **Live reload:** `xrdb merge ~/.Xresources && kill -USR1 $(pidof st)`

---

## Installation

### Dependencies

```bash
# Arch
pacman -S harfbuzz imlib2 libxft fontconfig freetype2

# Debian/Ubuntu
apt install build-essential libxft-dev libharfbuzz-dev libimlib2-dev

# Fedora
dnf install harfbuzz-devel imlib2-devel libXft-devel

# Void
xbps-install libXft-devel libX11-devel harfbuzz-devel imlib2-devel
```

### Build

```bash
git clone https://github.com/krisyotam/st
cd st
sudo make clean install
xrdb merge ~/.Xresources
```

> Add the `xrdb merge` command to your WM's autostart.

> Requires a compositor (`xcompmgr`, `picom`, etc.) for transparency.

---

## Configuration

### Enabling/Disabling Patches

Edit `patches.h` to toggle patches:

```c
#define SIXEL_PATCH 1        /* Enable sixel graphics */
#define FULLSCREEN_PATCH 0   /* Disable fullscreen */
```

### Customizing Settings

Edit `config.def.h` for:
- Font settings
- Colors (Gruvbox by default)
- Keyboard shortcuts
- Transparency level
- External pipe commands

After editing, rebuild:
```bash
rm config.h && sudo make clean install
```

### Xresources

This build reads settings from `~/.Xdefaults` or `~/.Xresources`. Changes reload live with:

```bash
xrdb merge ~/.Xresources && kill -USR1 $(pidof st)
```

Example Xresources:
```
st.font: JetBrainsMono Nerd Font:pixelsize=15
st.alpha: 0.85
st.color0: #282828
st.background: #282828
st.foreground: #ffffff
```

---

## Sixel Graphics

This build includes sixel support for displaying images in the terminal. Applications like `manga-tui` can render images directly in st.

To verify sixel support:
```bash
# If you have libsixel installed
img2sixel /path/to/image.png
```

---

## Other Suckless Repos

- [dwm](https://github.com/krisyotam/dwm) - dynamic window manager
- [dwmblocks](https://github.com/krisyotam/dwmblocks) - modular status bar
- [surf](https://github.com/krisyotam/surf) - simple web browser
- [dmenu](https://github.com/krisyotam/dmenu) - application launcher

---

## Credits

- Based on [st-flexipatch](https://github.com/bakkeby/st-flexipatch) by bakkeby
- [suckless.org](https://st.suckless.org/) for the original st

---

## Contact

- Kris Yotam <krisyotam@protonmail.com>
- [https://krisyotam.com](https://krisyotam.com)
