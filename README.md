# Kris's build of st

The [suckless terminal (st)](https://st.suckless.org/) with additional features that make it the best terminal emulator.

---

## Features

### Clipboard

| Keybinding | Action |
|------------|--------|
| `Ctrl+Shift+c` | Copy selection |
| `Ctrl+Shift+v` | Paste |
| `Right Click` | Paste from clipboard |

### Scrollback

| Keybinding | Action |
|------------|--------|
| `Alt+k` | Scroll up |
| `Alt+j` | Scroll down |

### Font & Zoom

| Keybinding | Action |
|------------|--------|
| `Alt+,` | Zoom in |
| `Alt+.` | Zoom out |
| `Alt+g` | Reset to default size |

### Transparency

| Keybinding | Action |
|------------|--------|
| `Alt+s` | Increase transparency |
| `Alt+a` | Decrease transparency |
| `Alt+m` | Reset transparency |

### Other

| Keybinding | Action |
|------------|--------|
| `Mod+Shift+Enter` | Spawn new terminal in current directory |

---

## Patches

| Patch | Description |
|-------|-------------|
| ligatures | HarfBuzz ligature support |
| sixel | Sixel graphics support (check sixel branch) |
| scrollback | Scroll history |
| clipboard | Clipboard integration |
| alpha | Transparency support with configurable opacity |
| boxdraw | Render box-drawing characters without font glyphs |
| patch_column | Doesn't cut text while resizing |
| font2 | Secondary font support (emoji fallback) |
| right click paste | Paste with right click |
| newterm | Spawn new terminal in current directory |
| anygeometry | Dynamic geometry/borders |
| xresources | Live reload colors/settings from Xresources |
| sync | Better draw timing to reduce flicker/tearing |
| live reload | Change colors/fonts on the fly |
| swapmouse | Swap mouse buttons |

---

## Appearance

- **Default font:** JetBrainsMono Nerd Font
- **Xresources:** Supports dynamic colors via `~/.Xdefaults` or `~/.Xresources`
- **Live reload:** `xrdb merge ~/.Xresources && kill -USR1 $(pidof st)`

---

## Installation

### Dependencies

```bash
# Arch
pacman -S gd

# Debian/Ubuntu
apt install build-essential libxft-dev libharfbuzz-dev libgd-dev

# Fedora
dnf install gd-devel libXft-devel

# Void
xbps-install libXft-devel libX11-devel harfbuzz-devel libXext-devel libXrender-devel libXinerama-devel gd-devel
```

### Build

```bash
git clone https://github.com/krisyotam/st
cd st
sudo make install
xrdb merge ~/.Xresources
```

> Add the `xrdb merge` command to your WM's autostart.

> Requires a compositor (`xcompmgr`, `picom`, etc.) for transparency.

---

## Configuration

### Xresources

This build reads settings from `~/.Xdefaults` or `~/.Xresources`. Changes reload live with:

```bash
xrdb merge ~/.Xresources && kill -USR1 $(pidof st)
```

---

## Other Suckless Repos

- [dwm](https://github.com/krisyotam/dwm) - dynamic window manager
- [dwmblocks](https://github.com/krisyotam/dwmblocks) - modular status bar
- [surf](https://github.com/krisyotam/surf) - simple web browser

---

## Contact

- Kris Yotam <krisyotam@protonmail.com>
- [https://krisyotam.com](https://krisyotam.com)
