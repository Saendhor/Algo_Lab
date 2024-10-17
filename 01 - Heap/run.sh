echo "[RUN] Compiling..."
gcc -o heap heap.c -g

# ./heap <size> <elem_0> ... <elem_size-1>
echo "[RUN] running with parameters "
echo "./heap 6 9 4 2 8 3 10"
echo "       1 2 3 4 5 6 7 "
./heap 6 9 4 2 8 3 10