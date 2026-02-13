# Kris's build of dmenu (flexipatch)

My build of [dmenu](https://tools.suckless.org/dmenu/), the dynamic menu for X.

This build is based on [dmenu-flexipatch](https://github.com/bakkeby/dmenu-flexipatch), which uses preprocessor directives to manage patches. This allows easy toggling of features without manual patching.

---

## How Patches Work (Preprocessor Directives)

Unlike traditional dmenu patching, this build uses C preprocessor directives to include/exclude patches at compile time. To enable or disable a patch, edit `patches.h` and set the value to `1` (enabled) or `0` (disabled):

```c
#define CENTER_PATCH 1      /* enabled */
#define VI_MODE_PATCH 0     /* disabled */
```

Then rebuild:
```bash
sudo make clean install
```

All patch options are documented in `patches.h`.

---

## Features

| Feature | Description |
|---------|-------------|
| **Centered** | dmenu appears centered on screen (enabled by default) |
| **Fuzzy matching** | Type non-consecutive portions to match |
| **Highlight** | Matched characters are highlighted |
| **Mouse support** | Click to select options |
| **Password mode** | `-P` flag hides input with dots |
| **Transparency** | Alpha support with compositor |
| **Xresources** | Read colors from `~/.Xresources` (pywal compatible) |
| **Numbers** | Shows match count in top right |
| **Border** | Visible border when centered |

---

## Usage

```bash
# Run dmenu (centered by default)
dmenu_run

# Vertical list
echo -e "option1\noption2\noption3" | dmenu -l 5

# Password mode
echo -e "option1\noption2" | dmenu -P

# Reject non-matching input
echo -e "yes\nno" | dmenu -r

# With prompt
dmenu -l 5 -p "Select:" < options.txt

# Case-sensitive (default is insensitive)
dmenu -s
```

---

## Enabled Patches

Configured in `patches.h`:

| Patch | Description |
|-------|-------------|
| alpha | Transparency support |
| border | Visible border around dmenu |
| caseinsensitive | Case-insensitive by default |
| center | Centered on screen |
| ctrl_v_to_paste | Ctrl+V paste support |
| fuzzymatch | Fuzzy matching |
| highlight | Highlight matched characters |
| line_height | Configurable line height |
| mouse_support | Click to select |
| numbers | Show match count |
| password | Hide input with -P |
| rejectnomatch | Reject non-matching input |
| xresources | Read from Xresources |

---

## Installation

```bash
git clone https://github.com/krisyotam/dmenu
cd dmenu
sudo make clean install
```

> Requires a compositor (`xcompmgr`, `picom`, etc.) for transparency.

---

## Configuration

### Enabling/Disabling Patches

Edit `patches.h` to toggle patches:

```c
#define FUZZYMATCH_PATCH 1   /* Enable fuzzy matching */
#define VI_MODE_PATCH 0      /* Disable vi mode */
```

### Customizing Settings

Edit `config.def.h` for:
- Font settings
- Colors
- Default behavior (centered, etc.)
- Border width

After editing, rebuild:
```bash
rm config.h && sudo make clean install
```

### Xresources

This build reads settings from `~/.Xresources`. Example:

```
dmenu.font: JetBrainsMono Nerd Font:size=14
dmenu.background: #9CC2EC
dmenu.foreground: #2a4055
dmenu.selbackground: #DEC292
dmenu.selforeground: #2a4055
```

Apply with:
```bash
xrdb merge ~/.Xresources
```

---

## My Other Suckless Repos

- [dwm](https://github.com/krisyotam/dwm) - dynamic window manager
- [st](https://github.com/krisyotam/st) - simple terminal
- [dwmblocks](https://github.com/krisyotam/dwmblocks) - modular status bar
- [surf](https://github.com/krisyotam/surf) - simple web browser

---

## Credits

- Based on [dmenu-flexipatch](https://github.com/bakkeby/dmenu-flexipatch) by bakkeby
- [suckless.org](https://tools.suckless.org/dmenu/) for the original dmenu

---

## Contact

- Kris Yotam <krisyotam@protonmail.com>
- [https://krisyotam.com](https://krisyotam.com)
