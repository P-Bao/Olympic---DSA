import math

def main():
    t = int(input())

    while t > 0:
        t -= 1

        n = int(input())
        n >>= 1

        res = str(math.comb(2 * n, n) // (n + 1))

        if len(res) > 10:
            print(res[:5] + "..." + res[-5:])
        else:
            print(res)

if __name__ == "__main__":
    main()
    
    