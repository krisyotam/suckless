/*
 * This file contains patch control flags.
 *
 * In principle you should be able to mix and match any patches
 * you may want. In cases where patches are logically incompatible
 * one patch may take precedence over the other as noted in the
 * relevant descriptions.
 *
 * Kris Yotam's st build - patches enabled:
 * - alpha (transparency)
 * - anygeometry (dynamic borders)
 * - blinking_cursor
 * - boxdraw
 * - clipboard
 * - columns (prevent text cut on resize)
 * - copyurl
 * - externalpipe
 * - font2 (fallback fonts)
 * - iso14755 (unicode input)
 * - ligatures (HarfBuzz)
 * - newterm
 * - scrollback + scrollback_mouse
 * - sixel (NEW - image support for manga-tui)
 * - swapmouse
 * - sync
 * - xresources + xresources_reload (live reload)
 */

/* Patches */

/* The alpha patch adds transparency for the terminal. */
#define ALPHA_PATCH 0

/* Alpha focus highlight - different opacity for focused/unfocused */
#define ALPHA_FOCUS_HIGHLIGHT_PATCH 0

/* Gradient transparency */
#define ALPHA_GRADIENT_PATCH 0

/* Initial size as pixel width/height using -G option */
#define ANYGEOMETRY_PATCH 1

/* Resize to any pixel size */
#define ANYSIZE_PATCH 1

/* Simple anysize variant */
#define ANYSIZE_SIMPLE_PATCH 0

/* Background image in farbfeld format */
#define BACKGROUND_IMAGE_PATCH 0

/* Background image reload on SIGUSR1 */
#define BACKGROUND_IMAGE_RELOAD_PATCH 0

/* Blinking cursor support */
#define BLINKING_CURSOR_PATCH 1

/* Bold is not bright */
#define BOLD_IS_NOT_BRIGHT_PATCH 0

/* Box drawing characters without font glyphs */
#define BOXDRAW_PATCH 1

/* Set CLIPBOARD on selection */
#define CLIPBOARD_PATCH 1

/* Resize without cutting off text */
#define COLUMNS_PATCH 1

/* Select and copy last URL with Mod+l */
#define COPYURL_PATCH 1

/* Copyurl with highlight */
#define COPYURL_HIGHLIGHT_SELECTED_URLS_PATCH 0

/* CSI 22/23 support */
#define CSI_22_23_PATCH 0

/* Default cursor on escape sequence 0 */
#define DEFAULT_CURSOR_PATCH 0

/* Return BS on backspace, DEL on delete */
#define DELKEY_PATCH 0

/* Disable bold fonts */
#define DISABLE_BOLD_FONTS_PATCH 0

/* Disable italic fonts */
#define DISABLE_ITALIC_FONTS_PATCH 0

/* Disable roman fonts */
#define DISABLE_ROMAN_FONTS_PATCH 0

/* Drag and drop files */
#define DRAG_AND_DROP_PATCH 0

/* Dynamic cursor color */
#define DYNAMIC_CURSOR_COLOR_PATCH 0

/* Dynamic padding with anysize */
#define DYNAMIC_PADDING_PATCH 0

/* External pipe support */
#define EXTERNALPIPE_PATCH 1

/* External pipe in */
#define EXTERNALPIPEIN_PATCH 0

/* Fix keyboard input */
#define FIXKEYBOARDINPUT_PATCH 0

/* Secondary font support (emoji fallback) */
#define FONT2_PATCH 1

/* Fullscreen toggle */
#define FULLSCREEN_PATCH 0

/* Hide cursor on keypress */
#define HIDECURSOR_PATCH 0

/* Hide terminal cursor on unfocus */
#define HIDE_TERMINAL_CURSOR_PATCH 0

/* Invert colorscheme keybinding */
#define INVERT_PATCH 0

/* Unicode input via dmenu */
#define ISO14755_PATCH 1

/* Keyboard select */
#define KEYBOARDSELECT_PATCH 0

/* HarfBuzz ligature support */
#define LIGATURES_PATCH 1

/* Monochrome mode */
#define MONOCHROME_PATCH 0

/* Window icon from PNG */
#define NETWMICON_PATCH 0

/* Window icon from farbfeld */
#define NETWMICON_FF_PATCH 0

/* Window icon legacy */
#define NETWMICON_LEGACY_PATCH 0

/* Spawn new terminal in current directory */
#define NEWTERM_PATCH 1

/* No window decorations */
#define NO_WINDOW_DECORATIONS_PATCH 0

/* Open copied URL in browser */
#define OPENCOPIED_PATCH 0

/* Open selected text */
#define OPEN_SELECTED_TEXT_PATCH 0

/* Open URL on click */
#define OPENURLONCLICK_PATCH 0

/* OSC 7 working directory */
#define OSC7_PATCH 0

/* OSC 133 prompt jumping */
#define OSC133_PATCH 0

/* Text reflow on resize */
#define REFLOW_PATCH 0

/* Relative border size */
#define RELATIVEBORDER_PATCH 0

/* Right click to plumb */
#define RIGHTCLICKTOPLUMB_PATCH 0

/* Scrollback support */
#define SCROLLBACK_PATCH 1

/* Scrollback with mouse wheel + Shift */
#define SCROLLBACK_MOUSE_PATCH 1

/* Scrollback mouse in alt screen */
#define SCROLLBACK_MOUSE_ALTSCREEN_PATCH 1

/* Custom selection colors */
#define SELECTION_COLORS_PATCH 0

/* Selection background alpha */
#define SELECTIONBG_ALPHA_PATCH 0

/* Single drawable buffer for w3m */
#define SINGLE_DRAWABLE_BUFFER_PATCH 0

/* SIXEL graphics support - for manga-tui! */
#define SIXEL_PATCH 1

/* Embed applications into st */
#define ST_EMBEDDER_PATCH 0

/* Spoiler mode */
#define SPOILER_PATCH 0

/* Swap mouse shape in programs */
#define SWAPMOUSE_PATCH 1

/* Synchronized updates */
#define SYNC_PATCH 1

/* Themed cursor from Xcursor */
#define THEMED_CURSOR_PATCH 0

/* Undercurl/special underlines */
#define UNDERCURL_PATCH 0

/* Universal scroll */
#define UNIVERSCROLL_PATCH 0

/* Use XftFontMatch */
#define USE_XFTFONTMATCH_PATCH 0

/* Vertical center lines */
#define VERTCENTER_PATCH 0

/* Visual bell */
#define VISUALBELL_1_PATCH 0

/* W3M images - incompatible with SIXEL */
#define W3M_PATCH 0

/* Wide glyphs rendering */
#define WIDE_GLYPHS_PATCH 0

/* Wide glyph spacing fix */
#define WIDE_GLYPH_SPACING_PATCH 0

/* Working directory option */
#define WORKINGDIR_PATCH 0

/* Xresources support */
#define XRESOURCES_PATCH 1

/* Xresources reload on SIGUSR1 */
#define XRESOURCES_RELOAD_PATCH 1

/* Xdefaults support */
#define XRESOURCES_XDEFAULTS_PATCH 0
