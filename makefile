EDPelip.dat : EDPelip.x
	./EDPelip.x 10 20 30 40 50 60 70 80 90 100 > EDPelip.dat

EDPelip.x : EDPelip.cpp
	c++ EDPelip.cpp -o EDPelip.x