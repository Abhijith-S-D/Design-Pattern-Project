g++ -std=c++11 -c ObjectPool.cpp
g++ -std=c++11 -c client.cpp
g++ -std=c++11 -o out ObjectPool.o client.o
./out

"output:"

Creating new.
one = 10 [0x1cb0150]
Creating new.
two = foobar [0x1cb0170]
Reusing existing.
one = 10 [0x1cb0150]
Reusing existing.
two = foobar [0x1cb0170]
