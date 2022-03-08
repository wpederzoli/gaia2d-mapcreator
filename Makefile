build:
	g++ ./*.cpp `wx-config --cxxflags --libs std,aui` -o mapcreator