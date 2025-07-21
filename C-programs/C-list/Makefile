MAKEFLAGS += --silent
PHONY: clean
clean:
	@-rm -r *.dSYM > /dev/null 2>&1
	@-find . -maxdepth 1 -type f -perm -u+x -exec rm -f {} \;
