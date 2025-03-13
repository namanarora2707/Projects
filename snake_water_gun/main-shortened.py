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
    if((computer-num)==-1 or (computer-num)== 2 ):
        print("lose")
    elif((computer-num)== 1 or (computer-num)== -2):
        print("win")