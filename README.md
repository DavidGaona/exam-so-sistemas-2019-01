1)

Primero (fuera del for)
0.050627
0.049187
0.050270

Segundo (dentro del for)
2.149656
2.115582
2.171911

se usó ./threads 10000000



La respuesta es bastante clara de porque el primer programa (cerrar la door antes del for) 
fue mucho más rápido que el segundo, lo que pasa es que en el primero la puerta solo se cierra
y se abre una vez, abrir y cerrar la puerta se demora cierto tiempo, entonces en el segundo
programa cuando el cerrar y abrir se mete dentro del loop, esta operación se hace por cada 
ciclo añadiendo así un pequeño tiempo de ejecución por cada ciclo, que se va sumando y
termina por hacer que el programa se demore mucho más. 


2) La operación se lleva a cabo en el orden deseado x*(z/y), para lograr esto se hace uso de las puertas
sincronizando asi los hilos. y tiene como resultado 89.285714.
