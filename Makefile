ifeq ($(OS), Windows_NT)
	RM = del /f /q
	MKDIR = mkdir
else
	RM = rm -rf
	MKDIR = mkdir -p
endif

all:
	$(MKDIR) build
	xxd -i site/index.html > build/html.c
	mv build/html.c src/html.c
	cmake -G Ninja -B build -S src -D CMAKE_BUILD_TYPE=Release
	cmake --build build
	$(RM) src/html.c

run:
	./build/bin/example

clean:
	$(RM) -rf build src/html.c