import random
letter=("a","e","i","o","u","b","c","d","f","g","h","j","k","l","m","n","p","r","s","t","v","w","x","q","y","z")
try:
    number=int(input("Number of nicknames :"))
    nick_lenght = int(input("Nickname lenght : "))
except:
    print("Please enter number !")
    exit("Invalid Character")
results=[]
for i in range(0,number):
    nick=""
    for i in range(0,nick_lenght):
        nick=nick+letter[int(random.random()*26)]
    results.append(nick)
print(results)
