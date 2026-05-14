surf -- simple webkit-based browser


surf is a simple web browser based on WebKit/GTK+.


REQUIREMENTS

  In order to build surf you need GTK+ and WebKit/GTK+ header files.

  In order to use the functionality of the url-bar, also install dmenu:
    http://tools.suckless.org/dmenu


INSTALLATION

  Edit config.mk to match your local setup (surf is installed into the
  /usr/local namespace by default).

  Afterwards enter the following command to build and install surf (if
  necessary as root):

    make clean install


RUNNING SURF

  surf [URI]

  See the manpage for further options.


RUNNING SURF IN TABBED

  For running surf in tabbed there is a script included in the
  distribution, which is run like this:

    surf-open.sh [URI]

  Further invocations of the script will run surf with the specified URI
  in this instance of tabbed.

  tabbed: http://tools.suckless.org/tabbed


LICENSE

  MIT
