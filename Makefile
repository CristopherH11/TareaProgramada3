test:
	mkdir -p bin
	g++ -g -c --std=c++17 src/producto.cpp -o bin/producto.o
	g++ -g -c --std=c++17 src/tienda.cpp -o bin/tienda.o
	g++ -g -c --std=c++17 tests/test_empleado.cpp -o bin/test_empleado.o
	g++ -g -c --std=c++17 tests/test_empleadoNomina.cpp -o bin/test_empleadoNomina.o
	g++ -g -o bin/tests bin/producto.o bin/test_empleado.o bin/test_planilla.o bin/tienda.o bin/test_empleadoPorHoras.o bin/test_empleadoNomina.o bin/empleadoNomina.o bin/empleadoPorHoras.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin