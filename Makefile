build:
	g++ ./*.cpp `wx-config --cxxflags --libs` -o mapcreator

debug:
	g++ -g ./*.cpp `wx-config --cxxflags --libs` -o mapcreator