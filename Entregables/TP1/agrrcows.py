
""" 
1
5 3
1
2
8
4
9

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other 
once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows 
to the stalls, such that the minimum distance between any two of them is as large as possible. 
What is the largest minimum distance?

El problema pide asignar las vacas de la forma mas apartada posible unas de otras y ver cual es
la distancia minima maxima entre ellas.


Lo que tengo que hacer es guardar lsa vacas en todas las posiciones posibles hasta tener todas
separadas con la mayor cantidad de distancia entre ellas y luego sacar cual es la menor distancia
 """


def distanciarVacas( cubiculo :int, cantidadVacas:int, i :int, mayorDistanciaMenor :int):



def main():
    t = int(input())

    for _ in range(t):

        n, c = map(int, input().split())

        cubiculo = []

        for _ in range(n):
            cubiculo.append(int(input()))

        cubiculo.sort()

        print(cubiculo)

if __name__ == "__main__":
    main()

        