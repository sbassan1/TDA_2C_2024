
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

 """

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

        