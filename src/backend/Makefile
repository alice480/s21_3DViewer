CFLAGS = -Wall -Werror -Wextra -std=c11 -g
CFLAGS += -D_GNU_SOURCE
# CFLAGS += -fsanitize=address
# CFLAGS += -pedantic
GCOVF = --coverage
GCOV_DISPLAY_BRANCHES = 0
CC = gcc
SOURCES = objparser.c affinity.c

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CHECKF = -lcheck -pthread -lcheck_pic -lrt -lm -lsubunit
endif
ifeq ($(UNAME_S),Darwin)
	CHECKF = -lcheck -pthread -lm
endif

all: clean gcov_report open_gcov

v3d_backend.a: $(SOURCES)
	$(CC) $(CFLAGS) -c $?
	ar -rcs $@ *.o
	ranlib $@
	rm -f *.o

v3d_backend_gcov.a: $(SOURCES)
	$(CC) $(CFLAGS) $(GCOVF) -c $?
	ar -rcs $@ *.o
	ranlib $@
	rm -f *.o

clean:
	rm -rf *.o *.a a.out *.gcno *.gcda *.log test_v3d_backend* html_gcov coverage.info documentation latex

rebuild: clean all

format:
	clang-format -style=google -i *.c *.h

check:
	clang-format -style=google -n *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

leaks: test_v3d_backend
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=tmp_valgrind.log ./test_v3d_backend > tmp_out.log

leaks_for_mac: test_v3d_backend
	leaks -atExit -- ./test_v3d_backend > tmp_out.log

test: test_v3d_backend
	./test_v3d_backend > tmp_out.log

test_v3d_backend: v3d_backend_gcov.a test_v3d_backend.o
	$(CC) $(CFLAGS) $(GCOVF) -o $@ test_v3d_backend.o v3d_backend_gcov.a  $(CHECKF)

test_v3d_backend.o: test_v3d_backend.c
	$(CC) $(CFLAGS) $(GCOVF) -c $?

test_v3d_backend.c:
	checkmk clean_mode=1 tests/header.check tests/test_*.check tests/footer.check > test_v3d_backend.c
	clang-format -style=google -i test_v3d_backend.c

gcov_report: test
	geninfo $(SOURCES:c=gcda) -o ./coverage.info --rc lcov_branch_coverage=$(GCOV_DISPLAY_BRANCHES)
	genhtml coverage.info -o html_gcov --rc lcov_branch_coverage=$(GCOV_DISPLAY_BRANCHES)
	rm *.gcno *.gcda coverage.info

open_gcov:
	open html_gcov/index.html

open_dvi:
	open documentation/index.html

dvi:
	if [ ! -f "doxygen.conf" ]; then doxygen -g doxygen.conf; fi;
	doxygen doxygen.conf && mv html documentation
