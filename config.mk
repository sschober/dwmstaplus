NAME = dwmstaplus
VERSION = 1.0

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# includes and libs
INCS = 
LIBS = -lpthread -L${X11LIB} -lX11

# flags
CPPFLAGS = -DVERSION=\"${VERSION}\"
CFLAGS = -std=c++11
LDFLAGS = ${LIBS}

# compiler and linker
CC = c++

