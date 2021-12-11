CC := gcc
CXX := g++
STRIP := strip
PYTHONDIR := $(shell echo $$LOCALAPPDATA)/Programs/Python/Python310
FLAGS := -mdll -O2 -Wall -DMS_WIN64=1 -I $(PYTHONDIR)/include -I $(PYTHONDIR)/Include -I $(PYTHONDIR)/Lib/site-packages/pybind11/include -I ./olcPixelGameEngine
LDFLAGS := -static-libstdc++ -shared -L $(PYTHONDIR) -L $(PYTHONDIR)/libs -L $(PYTHONDIR)/PCbuild/amd64 -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -lpython310 -lvcruntime140

TARGET = olc.pyd
CSOURCES = $(shell echo *.cpp)

OBJECTS = $(CSOURCES:.cpp=_cpp.o)

all: $(TARGET)

%_cpp.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(TARGET)
	$(STRIP) $(TARGET)


clean:
	rm *.o $(TARGET)

