g++ -std=c++11 -c ObjectPool.cpp && g++ -std=c++11 -c client.cpp && g++ -std=c++11 -o out ObjectPool.o client.o && ./out

//for modification
 g++ -std=c++11 -c ObjectPool.cpp && g++ -std=c++11 -c new_client.cpp && g++ -std=c++11 -o out2 ObjectPool.o new_client.o && ./out2


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

"output_for_modification"

pool created  [0x2162c20]
Creating new.
one = 10 [0x2163150]
Creating new.
two = hello [0x2163190]
Creating new.
three = 64 [0x21631d0]
Creating new.
four = chiku [0x2163210]
Reusing existing.
one = 10 [0x2163150]
Reusing existing.
two = hi [0x2163190]
deleting priority 1
 longetivity is 1
deleting [0x21631d0]
 longetivity is 2
deleting [0x2163210]
deleting priority 0
 longetivity is 1
deleting [0x2163150]
 longetivity is 2
deleting [0x2163190]
deleting object pool[0x2162c20]
