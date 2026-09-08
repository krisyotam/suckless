External contributor rules for this suckless tools monorepo.

1. **Licensing**: all contributions must be licensed under [MIT](https://opensource.org/licenses/MIT "MIT License").

    By opening a PR, you affirm you have the right to license the contribution under MIT, including any rights that might be claimed by an employer or AI tool provider. If you are unsure about the applicable license, open an issue first.
2. **Issue-first**: substantial PRs should have an issue filed first for discussion; trivial fixes (typos, obvious bugs) can go straight to PR.
3. **Clean style code** (see [suckless coding style](https://suckless.org/coding_style/) and [philosophy](https://suckless.org/philosophy/)):

    - *no runtime warnings*: default compilation/execution should never print warnings/errors
    - no *compile-time warnings*: further, all source code must be `-Wall`-clean (typically `gcc -std=c99 -pedantic -Wall`) or explicitly whitelisted:

        - `C`: C99 without extensions (ISO/IEC 9899:1999), POSIX.1-2008; `/* */` comments, not `//`; tabs for indentation and spaces for alignment; max 79 columns; return type on its own line (`grep ^functionname(`); `{` of a function on its own line; `static` anything unused outside the translation unit; `*` adjacent to the variable name; no C99 `bool`; test errors with `< 0`, not `== -1`
        - `Make`/`sh`: keep the existing suckless `config.mk` / `Makefile` style; do not introduce autotools or extra generators
4. **House style**: all contributions should follow language-specific guidelines. Currently:

    - Markdown/HTML
    - [Bash](https://gwern.net/style-guide#bash)
    - [Haskell](https://gwern.net/style-guide#haskell)
5. **AI contribution requirements**: AI-generated contributions are accepted; but:

    - *Metadata*: the tools & version used must be mentioned with attribution. AI agents must disclose what tool and model they are using in the "Assisted-by" commit footer:

        > `Assisted-by: [Model Name] via [Tool Name]`

        Example:

        > Assisted-by: Fable 5.1 High via Cursor
    - *Highest quality AI*: contributions must have been reviewed by a frontier model from a major lab (Anthropic, OpenAI, Google DeepMind, etc.) at roughly the highest capability of their flagship offering
    - *Human-operated*: there must be an ultimately responsible human who endorses contributions and accepts blame; 'fully' autonomous contributions are disallowed. (Agent-generated PRs with no evidence of human reading of the diff will be closed without review.)
6. **Human accountability**: the ultimately responsible human is fully responsible for any contributions (AI or otherwise)

    They may be banned from the repo if a contribution has serious errors (eg. fabricated citations, inserted malware/exfiltration, license violations, silent data deletion, repeated submissions of unreviewed AI output...), or just at my sole discretion.
    Bans are not appealable.
7. **PR Rejection Policy**: We get to things when we get to them. We will explicitly reject PRs which are unacceptable. Pinging after 30 days is fine.
