WEBSITE:= luogu
PROBLEM:= P1192

test:
	@clear
	@echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Compiling..."
	@g++ -std=c++17 -O2 -o ./now/${PROBLEM}.out ./now/${PROBLEM}.cpp
	@echo "\033[1;36m[ALGORITHM]\033[0m \033[1;34m[TEST]\033[0m Running tests..."
	@for infile in ./now/*.in; do \
		test=$$(basename "$$infile" .in); \
		if [ ! -s "$$infile" ]; then \
			echo "\033[1;36m[ALGORITHM]\033[0m \033[1;34m[TEST]\033[0m Skipping empty input file: \033[1;31m$$test\033[0m"; \
			continue; \
		fi; \
		echo "\033[1;36m[ALGORITHM]\033[0m \033[1;34m[TEST]\033[0m Running tests for \033[1;31m$$test\033[0m"; \
		echo "\033[1;36m[ALGORITHM]\033[0m \033[1;33m[TEST $$test INPUT]\033[0m"; \
		cat "$$infile"; \
		echo "\n\033[1;36m[ALGORITHM]\033[0m \033[1;33m[TEST $$test OUTPUT]\033[0m"; \
		./now/${PROBLEM}.out < "$$infile"; \
		echo ""; \
	done
	@find ./now -type f ! -name '*.cpp' ! -name '*.in' -exec rm -f {} +

new:
	@touch ./now/${PROBLEM}.cpp
	@echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Created new file ${PROBLEM}.cpp"
	@for i in 1 2 3 4 5; do \
		touch ./now/$$i.in; \
		echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Created new file $$i.in"; \
	done
	@echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Created new problem files for \033[1;34m${PROBLEM}\033[0m "

done:
	@echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Archiving files for ${PROBLEM}"
	@if [ ! -f "./now/${PROBLEM}.cpp" ]; then \
		echo "\033[1;36m[ALGORITHM]\033[0m \033[1;31m[ERROR]\033[0m ${PROBLEM}.cpp not found!"; \
		exit 1; \
	fi
	@mkdir -p ./${WEBSITE}/${PROBLEM}
	@# Move the source file
	@if [ -f "./now/${PROBLEM}.cpp" ]; then \
		mv "./now/${PROBLEM}.cpp" "./${WEBSITE}/${PROBLEM}/"; \
		echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Moved ${PROBLEM}.cpp to ${WEBSITE}/${PROBLEM}"; \
	fi
	@# Move non-empty .in files
	@for infile in ./now/*.in; do \
		if [ -f "$$infile" ] && [ -s "$$infile" ]; then \
			filename=$$(basename "$$infile"); \
			mv "$$infile" "./${WEBSITE}/${PROBLEM}/"; \
			echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Moved $$filename to ${WEBSITE}/${PROBLEM}"; \
		elif [ -f "$$infile" ]; then \
			filename=$$(basename "$$infile"); \
			echo "\033[1;36m[ALGORITHM]\033[0m \033[1;33m[INFO]\033[0m Skipping empty file: $$filename"; \
		fi; \
	done
	@# Clean up now directory
	@if [ -d "./now" ]; then \
		find ./now -type f -delete 2>/dev/null || true; \
		echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Cleared directory!"; \
	fi
	@git add .
	@git commit -s -m "${WEBSITE} ${PROBLEM}"
	@echo "\033[1;36m[ALGORITHM]\033[0m \033[1;32m[INFO]\033[0m Done!"
