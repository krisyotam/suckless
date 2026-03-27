/*
 * This file contains patch control flags.
 *
 * Kris Yotam's dmenu build - patches enabled:
 * - border (visible border when centered)
 * - caseinsensitive (case-insensitive by default)
 * - center (centered on screen)
 * - ctrl_v_to_paste (Ctrl+V paste support)
 * - fuzzymatch (fuzzy matching)
 * - highlight (highlight matched chars)
 * - line_height (configurable line height)
 * - mouse_support (click to select)
 * - numbers (show match count)
 * - password (hide input with -P)
 * - rejectnomatch (reject non-matching input)
 * - xresources (pywal compatible)
 */

/* Patches */

/* The alpha patch adds transparency for the dmenu window. */
#define ALPHA_PATCH 0

/* Adds padding for dmenu similar to dwm barpadding. */
#define BARPADDING_PATCH 0

/* Right-To-Left language support (requires fribidi). */
#define BIDI_PATCH 0

/* Adds a border around the dmenu window. */
#define BORDER_PATCH 1

/* Colored caret option via SchemeCaret. */
#define CARET_SCHEME_PATCH 0

/* Configurable caret width. */
#define CARET_WIDTH_PATCH 0

/* Case-insensitive by default. */
#define CASEINSENSITIVE_PATCH 0

/* Centers dmenu in the middle of the screen. */
#define CENTER_PATCH 1

/* Ctrl+v to paste support. */
#define CTRL_V_TO_PASTE_PATCH 1

/* Dynamically changes dmenu window size based on items. */
#define DYNAMIC_HEIGHT_PATCH 0

/* Dynamic options based on input. */
#define DYNAMIC_OPTIONS_PATCH 0

/* Emoji highlight with colored background. */
#define EMOJI_HIGHLIGHT_PATCH 0

/* Fuzzy matching support. */
#define FUZZYMATCH_PATCH 1

/* Fzf-like functionality. */
#define FZFEXPECT_PATCH 0

/* Grid layout for entries. */
#define GRID_PATCH 0

/* Grid navigation with arrows. */
#define GRIDNAV_PATCH 0

/* Highlight matched characters. */
#define HIGHLIGHT_PATCH 1

/* Sort results by priority. */
#define HIGHPRIORITY_PATCH 0

/* Print current text on each keypress. */
#define INCREMENTAL_PATCH 0

/* Preselected text option. */
#define INITIALTEXT_PATCH 0

/* Input method support (fcitx, ibus). */
#define INPUTMETHOD_PATCH 0

/* Auto-select if only one match. */
#define INSTANT_PATCH 0

/* Minimum line height option. */
#define LINE_HEIGHT_PATCH 1

/* Let window manager manage dmenu window. */
#define MANAGED_PATCH 0

/* Additional color scheme for adjacent items. */
#define MORECOLOR_PATCH 0

/* Mouse support for clicking items. */
#define MOUSE_SUPPORT_PATCH 1

/* Mouse hover support. */
#define MOTION_SUPPORT_PATCH 0

/* Multi-selection with Ctrl+Enter. */
#define MULTI_SELECTION_PATCH 0

/* Bash-like history navigation. */
#define NAVHISTORY_PATCH 0

/* Workaround for BadLength with color glyphs. */
#define NO_COLOR_EMOJI_PATCH 0

/* Disable sorting after matching. */
#define NO_SORT_PATCH 0

/* Non-blocking stdin reading. */
#define NON_BLOCKING_STDIN_PATCH 0

/* Show matched/total count. */
#define NUMBERS_PATCH 1

/* Pango markup support. */
#define PANGO_PATCH 0

/* Password mode - hide input with dots. */
#define PASSWORD_PATCH 1

/* Pipe selected text back out. */
#define PIPEOUT_PATCH 0

/* Plain prompt without colors. */
#define PLAIN_PROMPT_PATCH 0

/* Tab completion support. */
#define PREFIXCOMPLETION_PATCH 0

/* Preselect item by index. */
#define PRESELECT_PATCH 0

/* Print index instead of text. */
#define PRINTINDEX_PATCH 0

/* Return prints input text instead of selection. */
#define PRINTINPUTTEXT_PATCH 0

/* Don't show items if search is empty. */
#define QUIET_PATCH 0

/* Reject input if no match. */
#define REJECTNOMATCH_PATCH 1

/* Input width relative to options. */
#define RELATIVE_INPUT_WIDTH_PATCH 0

/* Disable Shift/Ctrl+Return. */
#define RESTRICT_RETURN_PATCH 0

/* Text scrolling for long input. */
#define SCROLL_PATCH 0

/* Separator for display vs output. */
#define SEPARATOR_PATCH 0

/* Custom symbols for overflow. */
#define SYMBOLS_PATCH 0

/* TSV input support. */
#define TSV_PATCH 0

/* Vertical full width items. */
#define VERTFULL_PATCH 0

/* Vi mode keybindings. */
#define VI_MODE_PATCH 0

/* Extended window manager hints. */
#define WMTYPE_PATCH 0

/* Xresources support for colors/settings. */
#define XRESOURCES_PATCH 1

/* Position and width options. */
#define XYW_PATCH 0
