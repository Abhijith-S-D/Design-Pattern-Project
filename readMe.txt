g++ -std=c++11 -c ObjectPool.cpp
g++ -std=c++11 -c client.cpp
g++ -std=c++11 -o out ObjectPool.o client.o
./out

"output:"

Creating new.
one = 10 [0x983150]
Creating new.
two = hello [0x983170]
Reusing existing.
one = 10 [0x983150]
Reusing existing.
two = hi [0x983170]
