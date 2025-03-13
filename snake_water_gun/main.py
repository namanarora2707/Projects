import random
'''
snake=1
water=-1
gun=0
'''
computer = random.choice([-1,0,1])
you= input("enter your choice:")
youdicr={"s":1,"w":-1,"g":0}
num=youdicr[you]
reversedict={1:"snake",-1:"water",0:"gun"}
print(f"You chose {reversedict[num]}\nComputer chose {reversedict[computer]}")
if(computer==num):
    print("draw")
else:
    if(computer==-1 and num==1):
        print("Win!")
    elif(computer==-1 and num==0):
        print("Lose")
    elif(computer==1 and num==-1):
        print("lose")
    elif(computer==1 and num ==0):
        print("win")
    elif(computer==0 and num==-1):
        print("win")
    elif(computer==0 and num ==1):
        print("lose")
    else:
        print("Something went wrong")