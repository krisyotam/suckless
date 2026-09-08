# tabbed

Kris's build of tabbed -- a generic tabbed interface for X11 from suckless.org.

tabbed is a simple container that manages X windows as tabs. It is commonly used with surf (tabbed browsing) and st (tabbed terminals).

## Usage

```sh
# Tabbed surf browser
tabbed -c surf -e

# Tabbed terminal
tabbed -c st -w
```

## Keybindings

| Key | Action |
|-----|--------|
| Ctrl+Shift+Return | New tab |
| Ctrl+Shift+h/l | Rotate tabs |
| Ctrl+Shift+j/k | Move tab |
| Ctrl+Tab | Next tab |
| Ctrl+1-9 | Jump to tab |
| Ctrl+q | Close tab |
| F11 | Fullscreen |

## Configuration

Edit `config.h` for colors, fonts, tab width, and keybindings. Rebuild after changes.

## Requirements

Xlib header files.

## Installation

```sh
make clean install
```
