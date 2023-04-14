CC = gcc
CFLAGS = -Wall -g -pedantic

OBJ_FILES = image_crafter.o \
            Sources/buckets.o \
            Sources/layers.o \
            Sources/matrix.o \
            Sources/points.o \
            Sources/colors.o \
            Sources/machine.o \
            Sources/pixels.o \
            Sources/ppm.o

all: image_craft

image_craft: $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o image_craft

image_crafter.o: image_crafter.c Headers/buckets.h Headers/layers.h Headers/matrix.h \
                 Headers/points.h Headers/colors.h Headers/machine.h Headers/pixels.h \
                 Headers/ppm.h
	$(CC) $(CFLAGS) -c image_crafter.c -o image_crafter.o

Sources/buckets.o: Sources/buckets.c Headers/buckets.h
	$(CC) $(CFLAGS) -c Sources/buckets.c -o Sources/buckets.o

Sources/layers.o: Sources/layers.c Headers/layers.h
	$(CC) $(CFLAGS) -c Sources/layers.c -o Sources/layers.o

Sources/matrix.o: Sources/matrix.c Headers/matrix.h
	$(CC) $(CFLAGS) -c Sources/matrix.c -o Sources/matrix.o

Sources/points.o: Sources/points.c Headers/points.h
	$(CC) $(CFLAGS) -c Sources/points.c -o Sources/points.o

Sources/colors.o: Sources/colors.c Headers/colors.h
	$(CC) $(CFLAGS) -c Sources/colors.c -o Sources/colors.o

Sources/machine.o: Sources/machine.c Headers/machine.h
	$(CC) $(CFLAGS) -c Sources/machine.c -o Sources/machine.o

Sources/pixels.o: Sources/pixels.c Headers/pixels.h
	$(CC) $(CFLAGS) -c Sources/pixels.c -o Sources/pixels.o

Sources/ppm.o: Sources/ppm.c Headers/ppm.h
	$(CC) $(CFLAGS) -c Sources/ppm.c -o Sources/ppm.o

clean:
	rm -f *.o Sources/*.o image_craft
