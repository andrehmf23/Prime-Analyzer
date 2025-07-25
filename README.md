# Prime-Analyzer

Esse algoritmo busca entender o conceito e a variação entre os números primos, explorando além do escopo padrão.
Na definição padrão, um número primo é somente divisivel por ele mesmo e 1.

Ignorando a visão padronizada e considerando um número inicial I e um ultimo número análisado L, e um conjunto C de todos números primos 
de I até L. 
Temos que:
I = 1 -> Somente existirá um número primo

I > 1 -> Existirá infinitos números primos, e teremos que quanto menor o número primo mais importancia ele terá, poís sua aparição aumenta.
Ou seja, tendemos a consideramos como maior importância o pulo de 2 em 2 em I = 2 por sua aparição. 
Quando automatizado a busca de conjunto de números primos apartir de I, temos que a soma de 2 apartir de 3 é o mais eficiente, 
porém isso é considerando o 2 como o mais importante, se considerado 2, 3 e 5, temos que apartir de 5 pulo variando de 2 e 4 é mais eficiente.

Essa é a anotação encontrada para frequência limitada de pulos até o possivel número primo, tendo um conjunto limitado C.

```
2,3 / 2~50

2 2 4 
  2 4 
  2 4 
  2 4 
  2 4 
  2 4 
  2 4 
  2

2,3,5 / 2~100

2 4 2 4 2 4 6 2 6 4 
    2 4 2 4 6 2 6 4 
    2 4 2 4 6 2 6

2,3,5,7 / 2~500

4 2 4 2 4 6 2 6 4 2 4 6 6 2 6 4 2 6 4 6 8 4 2 4 2 4 8 6 4 6 2 4 6 2 6 6 4 2 4 6 2 6 4 2 4 2 10 2 10 2 4 
      2 4 6 2 6 4 2 4 6 6 2 6 4 2 6 4 6 8 4 2 4 2 4 8 6 4 6 2 4 6 2 6 6 4 2 4 6 2 6 4 2 4 2 10 2 10 2 4 
      2 4 6 2 6 4 2 4 6 6 2 6 4 2 6

2,3,5,7,11 / 2~5000

2 4 2 4 6 2 6 4 2 4 6 6 2 6 4 2 6 4 6 8 4 2 4 2 4 14 4 6 2 10 2 6 6 4 2 4 6 2 10 2 4 2 12 10 2 4 2 4 6 2 6 4 6 6 6 2 6 4 2 6 4 6 8 4 2 4 6 8 6 10 2 4 6 2 6 6 4 2 4 6 2 6 4 2 6 10 2 10 2 4 2 4 6 8 4 2 4 12 2 6 4 2 6 4 6 12 2 4 2 4 8 6 4 6 2 4 6 2 6 10 2 4 6 2 6 4 2 4 2 10 2 10 2 4 6 6 2 6 6 4 6 6 2 6 4 2 6 4 6 8 4 2 6 4 8 6 4 6 2 4 6 8 6 4 2 10 2 6 4 2 4 2 10 2 10 2 4 2 4 8 6 4 2 4 6 6 2 6 4 8 4 6 8 4 2 4 2 4 8 6 4 6 6 6 2 6 6 4 2 4 6 2 6 4 2 4 2 10 2 10 2 6 4 6 2 6 4 2 4 6 6 8 4 2 6 10 8 4 2 4 2 4 8 10 6 2 4 8 6 6 4 2 4 6 2 6 4 6 2 10 2 10 2 4 2 4 6 2 6 4 2 4 6 6 2 6 6 6 4 6 8 4 2 4 2 4 8 6 4 8 4 6 2 6 6 4 2 4 6 8 4 2 4 2 10 2 10 2 4 2 4 6 2 10 2 4 6 8 6 4 2 6 4 6 8 4 6 2 4 8 6 4 6 2 4 6 2 6 6 4 6 6 2 6 6 4 2 10 2 10 2 4 2 4 6 2 6 4 2 10 6 2 6 4 2 6 4 6 8 4 2 4 2 12 6 4 6 2 4 6 2 12 4 2 4 8 6 4 2 4 2 10 2 10 6 2 4 6 2 6 4 2 4 6 6 2 6 4 2 10 6 8 6 4 2 4 8 6 4 6 2 4 6 2 6 6 6 4 6 2 6 4 2 4 2 10 12 2 4 2 10 2 6 4 2 4 6 6 2 10 2 6 4 14 4 2 4 2 4 8 6 4 6 2 4 6 2 6 6 4 2 4 6 2 6 4 2 4 12 2 12 4 2 4 
        6 2 6 4 2 4 6 6 2 6 4 2 6 4 6 8 4 2 4 2 4 14 4 6 2 10 2 6 6 4 2 4 6 2 10 2 4 2 12 10 2 4 2 4 6 2 6 4 6 6 6 2 6 4 2 6 4 6 8 4 2 4 6 8 6 10 2 4 6 2 6 6 4 2 4 6 2 6 4 2 6 10 2 10 2 4 2 4 6 8 4 2 4 12 2 6 4 2 6 4 6 12 2 4 2 4 8 6 4 6 2 4 6 2 6 10 2 4 6 2 6 4 2 4 2 10 2 10 2 4 6 6 2 6 6 4 6 6 2 6 4 2 6 4 6 8 4 2 6 4 8 6 4 6 2 4 6 8 6 4 2 10 2 6 4 2 4 2 10 2 10 2 4 2 4 8 6 4 2 4 6 6 2 6 4 8 4 6 8 4 2 4 2 4 8 6 4 6 6 6 2 6 6 4 2 4 6 2 6 4 2 4 2 10 2 10 2 6 4 6 2 6 4 2 4 6 6 8 4 2 6 10 8 4 2 4 2 4 8 10 6 2 4 8 6 6 4 2 4 6 2 6 4 6 2 10 2 10 2 4 2 4 6 2 6 4 2 4 6 6 2 6 6 6 4 6 8 4 2 4 2 4 8 6 4 8 4 6 2 6 6 4 2 4 6 8 4 2 4 2 10 2 10 2 4 2 4 6 2 10 2 4 6 8 6 4 2 6 4 6 8 4 6 2 4 8 6 4 6 2 4 6 2 6 6 4 6 6 2 6 6 4 2 10 2 10 2 4 2 4 6 2 6 4 2 10 6 2 6 4 2 6 4 6 8 4 2 4 2 12 6 4 6 2 4 6 2 12 4 2 4 8 6 4 2 4 2 10 2 10 6 2 4 6 2 6 4 2 4 6 6 2 6 4 2 10 6 8 6 4 2 4 8 6 4 6 2 4 6 2 6 6 6 4 6 2 6 4 2 4 2 10 12 2 4 2 10 2 6 4 2 4 6 6 2 10 2 6 4 14 4 2 4 2 4 8 6 4 6 2 4 6 2 6 6 4 2 4 6 2 6 4 2 4 12 2 12 4 2 4 
        6 2 6 4 2 4 6 6 2 6 4 2 6 4 6 8 4 2 4 2 4 14 4 6 2 10 2 6 6 4 2 4 6 2 10 2 4 2 12 10 2 4 2 4 6 2 6 4 6 6 6 2 6 4 2 6 4 6 8 4 2 4 6 8 6 10 2 4 6 2 6 6 4 2
```

