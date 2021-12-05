CC = clang
CFLAGS = -g -Wall -Wextra
outdir = compiled

%:
	@$(MAKE) day$@ --silent

day%: day%.c
	$(CC) $(CFLAGS) -o $(outdir)/$@ $<
	./$(outdir)/$@
