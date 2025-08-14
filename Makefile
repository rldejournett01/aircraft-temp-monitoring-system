# Convenience targets that wrap CMake
all:
	mkdir -p build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && $(MAKE) -j

run:
	./build/aircraft-temp-monitor --threshold 27.0 --period_ms 1000 --iterations 10

test:
	cd build && ctest --output-on-failure

clean:
	rm -rf build
