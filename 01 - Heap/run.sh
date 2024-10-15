echo "[RUN] Compiling..."
gcc -o heap heap.c -g

# ./heap <size> <elem_0> ... <elem_size-1>
echo "[RUN] running with parameters "
./heap 6 9 4 2 8 3 10