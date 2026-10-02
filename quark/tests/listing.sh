#!/bin/sh
# Exercise the real listing generator with synthetic filenames; no HTTP server.
set -eu
cd "$(dirname "$0")/.."
build=$(mktemp -d)
trap 'rm -rf "$build"' EXIT HUP INT TERM
${CC:-cc} -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700 -std=c99 -Wall -Wextra \
  -ffunction-sections -fdata-sections -Wl,--gc-sections \
  tests/listing.c data.c util.c -o "$build/listing"
"$build/listing"
