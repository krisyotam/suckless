# DWM - Development Rules

## Build System: dwm-flexipatch

This is a **flexipatch** build. Patches are toggled via `#define` flags, NOT by applying `.diff` files.

### Critical File Hierarchy

| File | Role | Committed? |
|------|------|------------|
| `config.def.h` | **Source of truth** for all configuration | YES |
| `patches.def.h` | **Source of truth** for patch enable/disable flags | YES |
| `config.h` | Local working copy (generated from `config.def.h`) | NO (gitignored) |
| `patches.h` | Local working copy (generated from `patches.def.h`) | NO (gitignored) |
| `config.mk` | Compiler/linker flags, library paths | YES |
| `dwm.c` | Core window manager (includes config.h at line 878) | YES |
| `patch/*.c` `patch/*.h` | Patch implementations and headers | YES |
| `patch/include.c` `patch/include.h` | Conditional patch includes (do NOT edit by hand) | YES |

### Rules for Editing Configuration

1. **ALWAYS edit `config.def.h`** for keybindings, layouts, rules, colors, and custom functions.
2. **ALWAYS edit `patches.def.h`** to enable/disable patches (`#define PATCH_NAME 0` or `1`).
3. **ALSO update `config.h` and `patches.h`** to match, so local builds work without regenerating.
4. **NEVER edit only `config.h` or `patches.h`** — those are gitignored and will be lost.
5. When `config.h` does not exist, `make` generates it by copying `config.def.h`. Same for `patches.h`.

### Build & Deploy Process

**Local build (this desktop):**
```bash
cd /home/krisyotam/dev/dwm
sudo make clean install
```

**Deploy to laptop (khr1st):**
```bash
# 1. Commit and push from desktop
cd /home/krisyotam/dev/dwm
git add config.def.h patches.def.h
git commit -m "description"
git push

# 2. SSH to laptop, pull, rebuild
ssh khr1st
cd ~/.local/src/dwm && git pull && sudo make clean install

# 3. Self-restart dwm (preserves all windows — no session kill)
# Trigger via sysact menu or a keybinding mapped to self_restart
```

**NEVER** tell the user to "restart dwm" or "log out and back in" without mentioning self_restart. The SELFRESTART_PATCH is enabled and does an in-place `execv()` that preserves all window positions.

---

## Code Style (Suckless C Conventions)

### Formatting
- **Indentation:** Tabs (width 8). Never spaces for indentation.
- **Brace style:** K&R — opening brace on same line, closing at column 0.
- **Line length:** ~80 characters preferred, not strictly enforced.
- **No trailing whitespace.**

### Naming
- `CamelCase` for types and structs: `Client`, `Monitor`, `Layout`, `Key`, `Button`
- `lowercase` or `lowercasemultiword` for functions: `focusmon`, `tagmon`, `sendmon`, `killclient`
- `UPPERCASE` for macros and constants: `MODKEY`, `NUMTAGS`, `CLEANMASK`, `SHCMD`
- Enum values: `SchemeNorm`, `SchemeSel`, `NetSupported`

### Functions
```c
static void
functionname(const Arg *arg)
{
	/* body indented with tabs */
}
```
- Return type on its own line.
- Function name on the next line.
- Opening brace on its own line (for function definitions only — NOT for if/for/while).
- Minimize variable declarations; declare at top of scope.

### Comments
- `/* C89-style block comments */` preferred in source.
- `// C99 inline comments` acceptable in config files for brief annotations.
- Preprocessor guards: `#endif // PATCH_NAME`

### Conditional Compilation (Patch Guards)
```c
#if SOME_PATCH
/* patch-specific code */
#endif // SOME_PATCH
```
- Always include the patch name in the `#endif` comment.
- Custom (non-patch) code added to `config.def.h` does NOT need guards.

### Example: Adding a Custom Function in config.def.h
Custom functions go **before** the `static const Key keys[]` array. They can reference any forward-declared function from `dwm.c` (`sendmon`, `focusmon`, `arrange`, `focus`, `selmon`, `mons`, etc.) because `config.h` is included after all declarations in `dwm.c`.

---

## Layout Array Reference

The layout array uses **flextile-deluxe**. Index matters for keybindings.

| Index | Symbol | Layout | Notes |
|-------|--------|--------|-------|
| 0 | `[]=` | Tile | Default |
| 1 | `><>` | Floating | |
| 2 | `[M]` | Monocle | |
| 3 | `\|\|\|` | Columns | |
| 4 | `>M>` | Floating master | |
| 5 | `[D]` | Deck | |
| 6 | `TTT` | Bottom stack | |
| 7 | `===` | Bottom stack horiz | |
| 8 | `\|M\|` | Centered master | |
| 9 | `-M-` | Centered master horiz | |
| 10 | `:::` | Gappless grid | |
| 11 | `[\\]` | Fibonacci dwindle | |
| 12 | `(@)` | Fibonacci spiral | |
| 13 | `[T]` | Tatami mats | |
| 14 | `RRR` | Reading mode (3 vertical panes) | Custom: nmaster=3 |

**When referencing layouts in keybindings, ALWAYS verify the index by counting from 0 in the `layouts[]` array.** Off-by-one errors here cause the wrong layout to activate with no obvious error.

---

## Currently Enabled Patches

Patches set to `1` in `patches.def.h`:

**Bar:** BAR_DWMBLOCKS, BAR_LTSYMBOL, BAR_STATUS, BAR_STATUSCMD, BAR_TAGS, BAR_WINTITLE, BAR_HIDEVACANTTAGS

**Core:** CFACTS, COOL_AUTOSTART, CYCLELAYOUTS, PERTAG, RESTARTSIG, SCRATCHPADS, SEAMLESS_RESTART, SELFRESTART, SHIFTTAG, SHIFTVIEW, STACKER, STICKY, SWALLOW, TOGGLEFULLSCREEN, VANITYGAPS, XRESOURCES

**Layouts:** BSTACK, CENTEREDMASTER, CENTEREDFLOATINGMASTER, COLUMNS, DECK, FIBONACCI_DWINDLE, FIBONACCI_SPIRAL, NROWGRID, TILE, MONOCLE

---

## Current Custom Keybindings

| Binding | Action |
|---------|--------|
| Super+Q | Reading mode (RRR layout) |
| Super+Shift+Q | Kill client (close window) |
| Super+Backspace | sysact (system actions menu) |
| Super+Left/Right/Up/Down | Send window to monitor in that direction |
| Super+Comma/Period | Focus previous/next monitor |
| Super+T | Tile layout |
| Super+F | Floating layout |

---

## Rules for Making Changes

1. **Read before writing.** Always read the relevant section of `config.def.h` before modifying it. Understand the surrounding `#if` guards.
2. **Count layout indices.** Never assume a layout index. Count from 0 in the `layouts[]` array every time.
3. **Check for keybinding conflicts.** Before adding a new binding, grep for the key symbol (e.g., `XK_w`) across `config.def.h` to find all uses and check which patches guard them.
4. **Test compilation.** Clang diagnostics on `config.h` standalone are ALWAYS false positives (missing types like `Arg`, `Client`, `Monitor`). The only valid test is `make` in the repo root.
5. **Keep both files in sync.** Every edit to `config.def.h` must also be applied to `config.h` (and vice versa for patches).
6. **Preserve removed bindings as comments.** When removing a keybinding, comment it out with a `// removed: reason` note rather than deleting the line, so the history is visible.
7. **Do not modify `dwm.c` unless absolutely necessary.** Configuration belongs in `config.def.h`. New functions go in `config.def.h` (before the keys array) or as a new file in `patch/`.
8. **Do not modify `patch/include.c` or `patch/include.h`** unless adding a completely new patch file to the `patch/` directory.
9. **Commit messages:** Imperative mood, concise. Example: `"Rebind reading mode to Super+Q, add directional tagmon"`. No "Co-Authored-By" lines.
