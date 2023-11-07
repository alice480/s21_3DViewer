PREFIX := -DCMAKE_PREFIX_PATH=~/Qt/6.5.1/gcc_64
.PHONY := all, install, uninstall, clean, dvi, dist, test, gcov_report

all: start

install: to_build
	if [ ! -d "install" ]; then mkdir install; fi;
	cp build/3DViewer install/3DViewer

uninstall:
	if [ -d "install" ]; then rm -rf install; fi;

clean: uninstall
	if [ -d "build" ]; then rm -rf build; fi;
	if [ -d "dist" ]; then rm -rf dist; fi;
	cd backend && make clean

dvi:
	cd backend && make dvi

dist: to_build
	if [ ! -d "dist/3DViewer" ]; then mkdir -p dist/3DViewer; fi;
	cp build/3DViewer dist/3DViewer/3DViewer
	cd dist && tar -czvf 3DViewer.tar.gz 3DViewer && rm -rf 3DViewer

test:
	cd backend && make

gcov_report:
	cd backend && make gcov_report open_gcov

to_build:
	if [ ! -d "build" ]; then mkdir build; fi;
	cd build && cmake $(PREFIX) ../ && make

start: install
	cd install && ./3DViewer
