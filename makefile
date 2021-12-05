CC = clang
CFLAGS = -g -Wall -Wextra
outdir = compiled

%: day%

day%: day%.c
	$(CC) $(CFLAGS) -o $(outdir)/$@ $<
	./$(outdir)/$@
