build:
	g++ ./*.cpp `wx-config --cxxflags --libs` -o mapcreator

debug:
	g++ -g ./*.cpp `wx-config --cxxflags --libs` -o mapcreator

valgrind:
	valgrind --leak-check=yes --log-file=valgrind.txt ./mapcreator

clean:
	rm -rf mapcreator mcprofile valgrind.txt