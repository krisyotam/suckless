# Kris's build of dmenu

My build of [dmenu](https://tools.suckless.org/dmenu/), the dynamic menu for X.

Based on [BreadOnPenguins' dmenu](https://github.com/BreadOnPenguins/dmenu) with center and xresources patches.

---

## Features

- **Center patch**: dmenu appears centered on screen (`-c` flag)
- **Vertical listing**: Show options in a vertical list (`-l` flag)
- **Xresources**: Read colors from `~/.Xresources` (pywal compatible)
- **Alpha**: Transparency support
- **Emoji**: Can view color characters like emoji
- **Password mode**: `-P` flag hides user input
- **Reject non-matching**: `-r` flag rejects input that doesn't match an option
- **Mouse clickable**: dmenu options are mouse clickable

---

## Patches

| Patch | Description |
|-------|-------------|
| [center](https://tools.suckless.org/dmenu/patches/center/) | Center dmenu on screen |
| [xresources](https://tools.suckless.org/dmenu/patches/xresources/) | Read colors and settings from ~/.Xresources |
| [alpha](https://tools.suckless.org/dmenu/patches/alpha/) | Transparency support |
| [password](https://tools.suckless.org/dmenu/patches/password/) | Hide input for password entry |
| mouse support | Click to select options |

---

## Usage

```bash
# Run dmenu centered
dmenu_run -c

# Vertical list centered
echo -e "option1\noption2\noption3" | dmenu -c -l 3

# Password mode
echo -e "option1\noption2" | dmenu -P

# Reject non-matching input
echo -e "yes\nno" | dmenu -r

# With prompt
dmenu -c -l 5 -p "Select:" < options.txt
```

---

## Installation

```bash
git clone https://github.com/krisyotam/dmenu
cd dmenu
sudo make install
```

---

## Credits

- [suckless.org](https://tools.suckless.org/dmenu/) - original dmenu
- [BreadOnPenguins](https://github.com/BreadOnPenguins/dmenu) - base build with center + xresources patches

---

## Other Suckless Repos

- [dwm](https://github.com/krisyotam/dwm) - dynamic window manager
- [st](https://github.com/krisyotam/st) - simple terminal
- [dwmblocks](https://github.com/krisyotam/dwmblocks) - modular status bar

---

## Contact

- Kris Yotam <krisyotam@protonmail.com>
- [https://krisyotam.com](https://krisyotam.com)
