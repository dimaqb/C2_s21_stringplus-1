CC = gcc
FLAGS = -std=c11 -Wall -Werror -Wextra
SRC = s21_*.c
HDR = s21_string.h
OBJ = $(SRC:.c=.o)

TEST = tests/test.c
TESTSUIT = tests/test_*.c
TESTFLAGS = -lcheck -coverage -lpthread -pthread

all: clean s21_string.a

s21_string.a: clean
	$(CC) $(FLAGS) -c $(SRC)
	ar rc s21_string.a $(OBJ)
	ranlib s21_string.a
	rm $(OBJ)

test: clean s21_string.a
	$(CC) $(FLAGS) -c $(TEST)
	$(CC) $(FLAGS) $(TEST) $(TESTSUIT) $(TESTFLAGS) s21_string.a -o test_suit -lm -lsubunit
	./test_suit

gcov_report: clean test
	$(CC) $(FLAGS) $(TEST) $(TESTSUIT) $(TESTFLAGS) $(SRC) -o gcov_report -lm -lsubunit
	./gcov_report
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	rm -rf *.gcda *.gcno s21_tests s21_tests.info
	open ./report/index.html

valgrind: test
	valgrind --tool=memcheck --leak-check=full --track-origins=yes  --num-callers=20 --log-file="vg_info.log" ./test_suit
	$(MAKE) clean

clean:
	rm -f *.o
	rm -f *.a
	rm -f test_suit*
	rm -f gcov_report
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.info
	rm -f *.log
	rm -rf report/

.PHONY: clean
