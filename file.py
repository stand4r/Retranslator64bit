a = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/"
print(len(a))
x = {}
f = open("output.exh", "wb")
f2 = open("cz.txt", "rb").readlines()
for i in range(64):
    x[i] = a[i]

for i in range(len(f2)):
    f.write(x[int(f2[i], 16)])
    print("end")