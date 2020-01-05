CXX = cl
CXXFLAGS = /EHsc /nologo
MAIN_EXECUTABLE = main.exe
OBJ = main.obj sort.obj

all: $(MAIN_EXECUTABLE)
.PHONY: all

$(MAIN_EXECUTABLE): $(OBJ)
	link /nologo $^ /OUT:$@
	
%.obj: %.cpp %.h
	$(CXX) $(CXXFLAGS) /c $<


clean:
	del *.obj
.PHONY: clean

distclean: clean
	del $(MAIN_EXECUTABLE)
PHONY: distclean

