g++ -std=c++11 -c ObjectPool.cpp && g++ -std=c++11 -c client.cpp && g++ -std=c++11 -o out ObjectPool.o client.o && ./out

"output:"

pool created  [0x1eddc20]
Creating new.
one = 10 [0x1ede150]
Creating new.
two = hello [0x1ede190]
Reusing existing.
one = 10 [0x1ede150]
Reusing existing.
two = hi [0x1ede190]
deleting [0x1ede150]
deleting [0x1ede190]
