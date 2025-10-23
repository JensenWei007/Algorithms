WEBSITE:= luogu
PROBLEM:= P1307

test:
	@clear
	@echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Compiling..."
	@g++ -std=c++17 -O2 -o ./${WEBSITE}/${PROBLEM}/${PROBLEM}.out ./${WEBSITE}/${PROBLEM}/${PROBLEM}.cpp
	@echo "\033[1;36m[ALGORITHM]\033[0m \033[1;34m[TEST]\033[0m Running tests..."
	@for infile in ./${WEBSITE}/${PROBLEM}/*.in; do \
		test=$$(basename "$$infile" .in); \
		echo "\033[1;36m[ALGORITHM]\033[0m \033[1;34m[TEST]\033[0m Running tests for \033[1;31m$$test\033[0m"; \
		echo "\033[1;36m[ALGORITHM]\033[0m \033[1;33m[TEST $$test INPUT]\033[0m"; \
		cat "$$infile"; \
		echo "\n\033[1;36m[ALGORITHM]\033[0m \033[1;33m[TEST $$test OUTPUT]\033[0m"; \
		./${WEBSITE}/${PROBLEM}/${PROBLEM}.out < $$infile; \
	done
	@for dir in ./${WEBSITE}/*/; do \
		if [ -d "$$dir" ]; then \
			find "$$dir" -type f ! -name '*.cpp' ! -name '*.in' -exec rm -f {} +; \
		fi \
	done

new:
	@if [ -d ./${WEBSITE}/${PROBLEM} ]; then \
		echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m TEST \033[1;34m${PROBLEM}\033[0m already exists"; \
	else \
		mkdir -p ./${WEBSITE}/${PROBLEM}; \
		touch ./${WEBSITE}/${PROBLEM}/${PROBLEM}.cpp; \
		touch ./${WEBSITE}/${PROBLEM}/1.in; \
		echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Created new problem files for \033[1;34m${PROBLEM}\033[0m"; \
	fi