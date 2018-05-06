#
# MAKEFILE
#

PROGNAME = draw

CPPFLAGS = -std=c++11 -Wall

OBJS  = bbox.o
OBJS += box.o
OBJS += circle.o
OBJS += color.o
OBJS += image.o
OBJS += line.o
OBJS += lodepng.o
OBJS += point.o
OBJS += poly.o
OBJS += regular.o
OBJS += shape.o


all: main.cc $(OBJS)
	g++ $(CPPFLAGS) -o $(PROGNAME) main.cc $(OBJS)

bbox: bbox.h bbox.cc
	g++ $(CPPFLAGS) -c bbox.cc

box: box.h box.cc
	g++ $(CPPFLAGS) -c box.cc

circle: circle.h circle.cc
	g++ $(CPPFLAGS) -c circle.cc

color: color.h color.cc
	g++ $(CPPFLAGS) -c color.cc

image: image.h image.cc
	g++ $(CPPFLAGS) -c image.cc

line: line.h line.cc
	g++ $(CPPFLAGS) -c line.cc

lodepng: lodepng.h lodepng.cc
	g++ $(CPPFLAGS) -c lodepng.cc

point: point.h point.cc
	g++ $(CPPFLAGS) -c point.cc

poly: poly.h poly.cc
	g++ $(CPPFLAGS) -c poly.cc

regular: regular.h regular.cc
	g++ $(CPPFLAGS) -c regular.cc

shape: shape.h shape.cc
	g++ $(CPPFLAGS) -c shape.cc

clean:
	-rm *.o

