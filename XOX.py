import os

matris=[[' ' , ' ' , ' '],[' ' , ' ' , ' '],[' ' , ' ' , ' ']]

siraKimde= 'X'

def siraDegistir():
    
    global siraKimde
    
    if siraKimde== 'X':
        siraKimde= 'O'
    
    else: 
        siraKimde= 'X'
    

def hamleAl():
    
    print(f'Sıra şuan {siraKimde} kullanıcısındadır')
    
    while True:
        
        satir= int(input("Satır Ver: "))-1
        sutun= int(input("Sütun Ver: "))-1
    
        if matris [satir] [sutun]== ' ' :
            matris[satir] [sutun]= siraKimde
            break
        else:
            print('Belirlediğiniz hücre doludur')

def matrisiYazdir():
    for  satir in matris:
        print(f'[{satir[0]}] [{satir[1]}] [{satir[2]}]')
       # for sutun in satir:
        #    print(sutun)

def oyunBittiMi():
    
    
    for satir in matris:
        if satir[0]== 'X' and satir[1]== 'X' and satir[2]== 'X' :
            return 'X'
        elif satir[0]== 'O' and satir[1]== 'O' and satir[2]== 'O' :
            return 'O'
        
    for x in range(0,3):
        
        if matris[0][x]== 'X' and matris[1][x]== 'X' and matris[2][x]== 'X' :
            return 'X'
        elif matris[0][x]== 'O' and matris[1][x]== 'O' and matris[2][x]== 'O' :
            return 'O'
    
    if matris[0][0]=='X' and matris[1][1]=='X' and matris[2][2]=='X':
        return 'X'
    elif matris[0][0]=='O' and matris[1][1]=='O' and matris[2][2]=='O':
        return 'O'
    elif matris[0][2]=='X' and matris[1][1]=='X' and matris[2][0]=='X':
        return 'X'
    elif matris[0][2]=='O' and matris[1][1]=='O' and matris[2][0]=='O':
        return 'O'
    else:
        for satir in matris:
            for sutun in satir:
                if sutun== ' ':
                    return False
        return ' '

def clearConsole():
    command = 'clear'
    if os.name in ('nt', 'dos'):
        command = 'cls'
    os.system(command)

while True:
    clearConsole()

    matrisiYazdir()

    hamleAl()

    siraDegistir()

    if oyunBittiMi()== 'X':
        print('Oyunu X kazandı')
        break
    
    elif oyunBittiMi()== 'O':
        print('Oyunu O kazandı')
        break
    
    elif oyunBittiMi()== False:
        continue
    
    else:
        print('Oyun berabere bitti')
        break