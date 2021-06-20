

echo "
///////////teest 1 sans pb\\\\\\\\\\\\\\\\\\\\\\

"
gcc ../*.c -fsanitize=address -g3 && ./a.out  map.cub
leaks -atExit -- ./a.out map.cub

echo "
///////////teest2 1 info en moins\\\\\\\\\\\\\\\\\\\\\\

"
gcc ../*.c && ./a.out  map1.cub
leaks -atExit -- ./a.out map.cub1


echo "
///////////teest3 1 info dupliquer\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map2.cub
leaks -atExit -- ./a.out map2.cub

echo "
///////////teest4 1 delete + 1 dupliquer\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map3.cub
leaks -atExit -- ./a.out map3.cub

echo "
///////////teest5 resolution trop grande\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map4.cub
leaks -atExit -- ./a.out map4.cub

echo "
///////////teest6 resolution mal ecrite\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map5.cub
leaks -atExit -- ./a.out map5.cub

echo "
///////////teest7 rgb F mal ecris\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map6.cub
leaks -atExit -- ./a.out map6.cub

echo "
///////////teest8i rgb F trop grand\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map7.cub
leaks -atExit -- ./a.out map7.cub

echo "
///////////teest9 lignes mauvaise entre les info et la map\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map8.cub
leaks -atExit -- ./a.out map8.cub

echo "
///////////teest10 2 point de spawn\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map9.cub
leaks -atExit -- ./a.out map9.cub

echo "
///////////teest11 pas de spawn\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map10.cub
leaks -atExit -- ./a.out map10.cub

echo "
///////////teest12 map ouverte\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map11.cub
leaks -atExit -- ./a.out map11.cub

echo "
///////////teest13 char incorrecte ds la map\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map12.cub
leaks -atExit -- ./a.out map12.cub

echo "
///////////teest14ligne vide au milieu de la map\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map13.cub
leaks -atExit -- ./a.out map13.cub

echo "
///////////teest15 ligne vide en fin de fichier\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map14.cub
leaks -atExit -- ./a.out map14.cub

echo "
///////////teest16 2 lignes vide en fin de fichier\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map15.cub
leaks -atExit -- ./a.out map15.cub

echo "
///////////teest17 ligne vide au debut\\\\\\\\\\\\\\\\\\\\\\

"

gcc ../*.c && ./a.out  map16.cub
leaks -atExit -- ./a.out map16.cub
