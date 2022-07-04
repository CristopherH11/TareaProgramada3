test:
	mkdir -p bin
	g++ -g -c --std=c++17 src/producto.cpp -o bin/producto.o
	g++ -g -c --std=c++17 src/tienda.cpp -o bin/tienda.o
	g++ -g -c --std=c++17 tests/test_producto.cpp -o bin/test_producto.o
	g++ -g -c --std=c++17 tests/test_tienda.cpp -o bin/test_tienda.o
	g++ -g -o bin/tests bin/producto.o bin/test_producto.o bin/test_tienda.o bin/tienda.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin
	rm *.dat