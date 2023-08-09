all:
	g++ -std=c++17 CBasicMath.cpp -o CBasicMath
	g++ -std=c++17 TestBasicMath.cpp -lcppunit -o TestBasicMath

test:
	chmod +x CBasicMath
	./TestBasicMath

clean:
	$(RM) CBasicMath TestBasicMath