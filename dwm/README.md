# Kris's build of dwm

My build of dwm, now using [dwm-flexipatch](https://github.com/bakkeby/dwm-flexipatch) for easier patch management via preprocessor directives.

---

## Bindings

The MOD key is set to the Super (Windows) key.

### Essential

| Keybinding | Action |
|------------|--------|
| `MOD+Return` | Spawn terminal (st) |
| `MOD+d` | App launcher (dlaunch) |
| `MOD+q` | Kill focused window |
| `MOD+j/k` | Focus next/previous window |
| `MOD+h/l` | Decrease/increase master area size |
| `MOD+Tab` | Switch to last viewed tag |
| `MOD+1-9` | View tag 1-9 |
| `MOD+Shift+1-9` | Move window to tag 1-9 |
| `MOD+0` | View all tags |
| `MOD+Shift+0` | Make window sticky to all tags |

### Applications

| Keybinding | Action |
|------------|--------|
| `MOD+b` | Browser selector (dbrowse) |
| `MOD+w` | Content writer (dwrite) |
| `MOD+r` | Library browser (dread) |
| `MOD+n` | Notes browser (dnotes) |
| `MOD+e` | Metadata editor (dedit) |
| `MOD+c` | Content creator (dcreate) |
| `MOD+p` | Password manager (passmenu) |
| `MOD+y` | World clock (dtime) |
| `MOD+m` | System monitor (btop) |
| `MOD+Shift+c` | Clipboard manager (dclip) |
| `MOD+Shift+n` | RSS reader (newsboat) |
| `MOD+Shift+m` | Toggle mute |
| `MOD+BackSpace` | System actions menu (sysact) |
| `MOD+Shift+q` | System actions menu (sysact) |

### Scratchpads

| Keybinding | Action |
|------------|--------|
| `MOD+Shift+Return` | Toggle scratchpad terminal |
| `MOD+'` | Toggle scratchpad calculator (bc) |

### Window Management

| Keybinding | Action |
|------------|--------|
| `MOD+Shift+j/k` | Move window down/up in stack |
| `MOD+Shift+Space` | Toggle floating |
| `MOD+Shift+f` | Toggle fullscreen |
| `MOD+s` | Toggle sticky |
| `MOD+o` | Increase number of masters |
| `MOD+Shift+o` | Decrease number of masters |
| `MOD+Ctrl+e` | Hide window |
| `MOD+Ctrl+Shift+e` | Restore hidden window |

### Layouts

| Keybinding | Action |
|------------|--------|
| `MOD+t` | Tile layout |
| `MOD+f` | Floating layout |
| `MOD+Shift+r` | Reading mode (3 vertical panes) |
| `MOD+Shift+t` | Bstack layout |
| `MOD+u` | Deck layout |
| `MOD+Shift+u` | Monocle layout |
| `MOD+i` | Centered master layout |
| `MOD+Shift+i` | Centered floating master |
| `MOD+Ctrl+g` | Gapless grid |
| `MOD+Space` | Toggle last layout |
| `MOD+Ctrl+,/.` | Cycle layouts prev/next |

### Gaps

| Keybinding | Action |
|------------|--------|
| `MOD+a` | Toggle gaps |
| `MOD+Shift+a` | Reset gaps to default |
| `MOD+Ctrl+i/d` | Increase/decrease all gaps |
| `MOD+Shift+i` | Increase inner gaps |
| `MOD+Ctrl+Shift+i` | Decrease inner gaps |
| `MOD+Ctrl+o` | Increase outer gaps |
| `MOD+Ctrl+Shift+o` | Decrease outer gaps |

### Resize (cfact)

| Keybinding | Action |
|------------|--------|
| `MOD+Shift+h` | Increase cfact |
| `MOD+Shift+l` | Decrease cfact |
| `MOD+Ctrl+Return` | Reset cfact |

### Multi-Monitor

| Keybinding | Action |
|------------|--------|
| `MOD+,/.` | Focus prev/next monitor |
| `MOD+Shift+,/.` | Move window to prev/next monitor |
| `MOD+Left/Right` | Shift view to prev/next tag |

### Border

| Keybinding | Action |
|------------|--------|
| `MOD+Shift+-` | Decrease border size |
| `MOD+Shift+p` | Increase border size |

### Screenshots

| Keybinding | Action |
|------------|--------|
| `Print` | Full screenshot |
| `Shift+Print` | Selection screenshot (maimpick) |
| `MOD+Print` | Record screen (dmenurecord) |
| `MOD+Shift+Print` | Kill recording |

### Media Keys

| Keybinding | Action |
|------------|--------|
| `XF86AudioRaiseVolume` | Volume up |
| `XF86AudioLowerVolume` | Volume down |
| `XF86AudioMute` | Toggle mute |
| `XF86MonBrightnessUp` | Brightness up |
| `XF86MonBrightnessDown` | Brightness down |

### System

| Keybinding | Action |
|------------|--------|
| `MOD+Ctrl+r` | Restart dwm |
| `MOD+Ctrl+w` | Toggle tab mode |

### Mouse

| Click | Action |
|-------|--------|
| `MOD+Left Click` | Move or place window |
| `MOD+Middle Click` | Toggle floating |
| `MOD+Right Click` | Resize window |
| `Ctrl+Left Click` | Drag mfact |
| `Ctrl+Right Click` | Drag cfact |

---

## Patches and Features

This build uses **dwm-flexipatch** for patch management. Toggle patches in `patches.h`:

```c
#define VANITYGAPS_PATCH 1   // enabled
#define SYSTRAY_PATCH 0      // disabled
```

### Enabled Patches

| Patch | Description |
|-------|-------------|
| vanitygaps | Gaps across all layouts with configurable inner/outer gaps |
| swallow | Terminals swallow windows spawned by child processes |
| scratchpads | Dropdown terminal and calculator accessible via keybind |
| sticky | Make windows visible on all tags |
| xresources | Read colors and config from ~/.Xresources at startup |
| stacker | Move windows up/down in the stack (focusstack/pushstack) |
| shiftview | Cycle through tags with arrow keys |
| shifttag | Move windows to adjacent tags |
| dwmblocks | Clickable status bar with signal support |
| cfacts | Resize individual windows in the stack |
| cyclelayouts | Cycle through layouts with keybind |
| restartsig | Restart dwm in place without losing windows |
| pertag | Each tag remembers its own layout settings |
| togglefullscreen | Toggle fullscreen on focused window |
| cool_autostart | Run commands on dwm startup (starts dwmblocks) |

### Layouts

- tile, floating, monocle, bstack
- centeredmaster, centeredfloatingmaster
- deck, spiral, dwindle
- reading mode (3 equal vertical panes)

---

## Installation

```bash
git clone https://github.com/krisyotam/dwm.git
cd dwm
sudo make install
```

There is also a `PKGBUILD` usable on distributions with pacman. Run `makepkg -si` instead of `sudo make install`.

### Dependencies

```bash
# Required for swallow patch
pacman -S libxcb xcb-util
```

---

## My Other Suckless Repos

- [st](https://github.com/krisyotam/st) - simple terminal (st-flexipatch with sixel)
- [dmenu](https://github.com/krisyotam/dmenu) - application launcher (dmenu-flexipatch)
- [dwmblocks](https://github.com/krisyotam/dwmblocks) - modular status bar
