CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

all: rod_cut_policy_A rod_cut_policy_B

rod_cut_policy_A: main.o read_rod_data.o rod_cut_recursive.o output_results.o cache_fifo.o
	$(CC) $(CFLAGS) -o rod_cut_policy_A main.o read_rod_data.o rod_cut_recursive.o output_results.o cache_fifo.o

rod_cut_policy_B: main.o read_rod_data.o rod_cut_recursive.o output_results.o cache_lru.o
	$(CC) $(CFLAGS) -o rod_cut_policy_B main.o read_rod_data.o rod_cut_recursive.o output_results.o cache_lru.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o rod_cut_policy_A rod_cut_policy_B
