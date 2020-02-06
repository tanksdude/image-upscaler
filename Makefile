CC = g++

TARGET = upscaler

make:
	@echo "Building $(TARGET)"
	$(CC) `Magick++-config --cxxflags --cppflags` -o $(TARGET) main.cpp `Magick++-config --ldflags --libs`

clean:
	@echo "Deleting $(TARGET)"
	rm -f $(TARGET)

mario:
	@echo "Making an upscaled 8-bit Mario..."
	make
	./$(TARGET) 8bitmario-transparent.png 32
	make clean