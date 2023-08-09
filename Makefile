CXX = g++                    # The C++ compiler
INCLUDES= -I./               
CXXFLAGS = -g $(INCLUDES)    # C++ complilation flags
NATIVE=on            # compiles code targeted to current hardware
TUNE=generic         # performance-tuning switch

all:
	g++ -std=c++17 CBasicMath.cpp -o CBasicMath
	g++ -std=c++17 TestBasicMath.cpp -lcppunit -o TestBasicMath

test:
	chmod +x CBasicMath
	./TestBasicMath

clean:
	$(RM) CBasicMath TestBasicMath
