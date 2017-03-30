ROOTCFLAGS    				= `root-config --cflags`
ROOTLIBS      				= `root-config --libs`
ROOTGLIBS     				= `root-config --glibs`

CXX           				= g++
CXXFLAGS      				= -I$(ROOTSYS)/include -O -Wall -fPIC -Wno-reorder
LD            				= g++
LDFLAGS       				= -g
SOFLAGS       				= -shared

TARGET								= run
DICTNAME 							= aDict
SOURCES								= main.cpp
HEADERS 							= A.h B.h C.h
LINKDEF 							= $(wildcard *LinkDef.h *Linkdef.h)

CXXFLAGS 				   	 += $(ROOTCFLAGS)
GLIBS 								= $(ROOTGLIBS)

all: $(TARGET)

clean:
	@rm *.o *.pcm *.d *.so $(TARGET) $(DICTNAME).cc *.root 2>/dev/null || true

$(DICTNAME).cc: $(HEADERS) $(LINKDEF)
	@rootcling -f $@ -c $(CXXFLAGS) $(HEADERS) $(LINKDEF)
$(DICTNAME).o: $(DICTNAME).cc
	@$(CXX) -c $(DICTNAME).cc $(CXXFLAGS) 
	@echo "\033[95mBuilt ${DICTNAME}.\033[0m"
	
$(TARGET): $(SOURCES) $(DICTNAME).o
	@$(CXX) $(SOURCES) -o $(TARGET) $(DICTNAME).o $(CXXFLAGS) $(GLIBS)
	@echo "\033[95mBuilt executable $(TARGET).\033[0m"