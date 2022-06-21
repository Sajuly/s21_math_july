.PHONY: all re s21_math clean check test main
#.PHONY если есть файлы с именем как цель, они игнорируются

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TST_LIBS :=  -lcheck -lm -lpthread
OS := $(shell uname -s)

ifeq ($(OS),Linux)
	CFLAGS+=-D LINUX
else
	ifeq ($(OS),Darwin)
		CFLAGS+=-D MAC
	endif
endif

all: test gcov_report

re: clean test gcov_report

test: s21_math.a s21_test.o
	$(CC) $(CFLAGS) s21_test.o s21_math.a $(TST_LIBS) -o test
	@./test

main: s21_math.c main.c
	@$(CC) s21_math.c main.c -o main
	@./main
	
s21_test.o: s21_math_test.c
	$(CC) $(CFLAGS) -c s21_math_test.c -o s21_test.o

s21_math.o: s21_math.c 
	$(CC) $(CFLAGS) -c s21_math.c -o s21_math.o

s21_math.a: s21_math.o
	@ar rcs s21_math.a s21_math.o
	ranlib s21_math.a

gcov_report: gcov_test.info
	@genhtml -o report/ gcov_test.info
	@open report/index.html

gcov_test.info: gcov_test gcov_test.gcda
	@lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .

gcov_test: s21_math_test.c s21_math.c
	$(CC) $(CFLAGS) --coverage s21_math_test.c s21_math.c $(TST_LIBS) -o gcov_test

gcov_test.gcda:
	@chmod +x *
	@./gcov_test

clean: 
	@rm -rf s21_math gcov_test *.gcno *.gcda *.info *.gch report main *.o *.a test

cpp:
	python3 cpplint.py *.h *.c

check:
	cppcheck s21_math.c s21_math_test.c 
	
valgrind:
	valgrind --leak-check=full --track-origins=yes --trace-children=yes -s ./s21_math
