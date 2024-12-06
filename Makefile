
LABS := $(wildcard lab_*/)

BINS_PATTERNS := main a.out run_tests lib.o main.o coverage.info coverage_report *.exe *.out *.app *.o *.a *.gcno *.gcda *.gcov

.PHONY: clean

clean:
	@for lab in $(LABS); do \
		find "$$lab" -type f \( $(foreach pattern, $(BINS_PATTERNS), -name "$(pattern)" -o ) -false \) -exec rm -rf {} + && echo "Removed binaries in $$lab"; \
	done