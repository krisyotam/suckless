# dwm-flexipatch

My personal build of dwm using [dwm-flexipatch](https://github.com/bakkeby/dwm-flexipatch). This uses preprocessor directives to decide whether or not to include a patch during build time, making patch management clean and maintainable.

## Configuration

All patch toggles are in `patches.h`. To enable or disable a patch, change the value from 0 to 1 (or vice versa):

```c
#define VANITYGAPS_PATCH 1  // Enabled
#define SYSTRAY_PATCH 0     // Disabled
```

## Enabled Patches

### Functionality
- **BAR_DWMBLOCKS_PATCH** - Clickable status bar integration with dwmblocks
- **COOL_AUTOSTART_PATCH** - Run commands on dwm startup (starts dwmblocks)
- **CYCLELAYOUTS_PATCH** - Cycle through all layouts
- **PERTAG_PATCH** - Per-tag layouts, nmaster, and mfact
- **RESTARTSIG_PATCH** - Restart dwm in place with kill -HUP
- **SCRATCHPADS_PATCH** - Multiple scratchpad windows (spterm, spcalc)
- **SHIFTVIEW_PATCH** - Circular shift through tags
- **SHIFTTAG_PATCH** - Move clients to adjacent tags
- **STACKER_PATCH** - Comprehensive stack management (focusstack/pushstack)
- **STICKY_PATCH** - Make windows visible on all tags
- **SWALLOW_PATCH** - Terminal window swallowing
- **TOGGLEFULLSCREEN_PATCH** - Toggle fullscreen with single key
- **VANITYGAPS_PATCH** - Configurable inner/outer gaps
- **XRESOURCES_PATCH** - Load colors and settings from Xresources
- **CFACTS_PATCH** - Resize clients in stack with different weights

### Layouts
- **TILE_LAYOUT** - Default master/stack
- **MONOCLE_LAYOUT** - Single window fullscreen
- **BSTACK_LAYOUT** - Master on top, stack below
- **CENTEREDMASTER_LAYOUT** - Master centered
- **CENTEREDFLOATINGMASTER_LAYOUT** - Floating centered master
- **DECK_LAYOUT** - Stack as monocle
- **FIBONACCI_SPIRAL_LAYOUT** - Spiral arrangement
- **FIBONACCI_DWINDLE_LAYOUT** - Dwindle arrangement

## Custom Settings

- **Border:** 3px, red selection (#770000)
- **Gaps:** 20h/10v inner, 10h/30v outer
- **Font:** monospace:size=11 + NotoColorEmoji
- **Autostart:** dwmblocks
- **Scratchpads:** spterm (terminal), spcalc (bc calculator)

## Dependencies

```bash
# Required for swallow patch
pacman -S libxcb xcb-util
```

## Installation

```bash
make clean install
```

## My Other Suckless Repos

- [st](https://github.com/krisyotam/st) - Simple Terminal (st-flexipatch with sixel)
- [dmenu](https://github.com/krisyotam/dmenu) - Dynamic Menu (dmenu-flexipatch)
- [dwmblocks](https://github.com/krisyotam/dwmblocks) - Status bar blocks
