echo "[RUN] Compiling..."
gcc -o heap heap.c -g

# ./heap <size> <elem_0> ... <elem_size-1>
echo "[RUN] running with parameters "
echo "./heap 8 40 9 4 2 8 3 10 22"
echo "       1  2 3 4 5 6 7  8  9"

./heap 8 40 9 4 2 8 3 10 22
