import math

a, b, k = map(int, input().split())

res = str()
while a > 0 and b > 0:
    numStringStartWith_a = math.comb(a + b - 1, a - 1)
    
    if k > numStringStartWith_a:
        res += 'b'
        k -= numStringStartWith_a
        b -= 1
    else:
        res += 'a'
        a -= 1
        # k -= math.comb(a + b - 1, b - 1)
res += 'a' * a + 'b' * b
        
print(res)