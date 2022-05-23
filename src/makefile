CC = gcc
GCOV=-fprofile-arcs -ftest-coverage
OS=$(shell uname)
ifeq ($(OS), Linux)
  LIBS=-lcheck -lpthread -lrt -lm -lsubunit
  OPEN=xdg-open
else
  LIBS=-lcheck
  OPEN=open
endif

all: s21_string.a test gcov_report

string_test_run.out: s21_string.a
	$(CC) s21_string_test.c s21_string.a $(LIBS) -o string_test_run.out

test: clean s21_string.a string_test_run.out
	./string_test_run.out

gcov_report: s21_string.a
	$(CC) $(GCOV) s21_string_test.c s21_string.c $(LIBS) -o GCOV_rep.out
	./GCOV_rep.out
	lcov -t "GCOV_rep" -o GCOV_rep.info -c -d . 
	genhtml -o report GCOV_rep.info

s21_string.a: clean
	$(CC) -c s21_string.c -o s21_string.o
	ar rcs s21_string.a *.o

clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out
	rm -rf ./report

leaks: test
	CK_FORK=no leaks --atExit -- ./string_test_run.out
	make clean

vg: clean string_test_run.out
	CK_FORK=no valgrind \
		--leak-check=full  --show-leak-kinds=all \
		--track-origins=yes --verbose \
		--log-file=valgrind.txt ./string_test_run.out
