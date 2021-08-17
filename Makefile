COMPILER = gcc
TARGET = rle
OBJECTS = main.o 

all: 
	make $(TARGET)

%.o: %.c Makefile
	$(COMPILER) -c $<

$(TARGET): $(OBJECTS) Makefile
	$(COMPILER) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) rle