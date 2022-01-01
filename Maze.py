import os

map1 = [['P', ' ', ' ', ' ', 'X', 'X'], [' ', ' ', 'X', ' ', 'X', ' '], [' ', ' ', ' ', ' ', ' ', ' '], [' ', 'X', 'X', 'X', 'X', ' '], [' ', 'X', ' ', ' ', 'X', ' '], [' ', 'X', ' ', 'X', 'X', 'O']]
map2 = [['P', ' ', ' ', ' ', 'X', 'X'], [' ', ' ', 'X', ' ', 'X', ' '], [' ', ' ', 'X', ' ', ' ', ' '], [' ', 'X', 'X', 'X', 'X', ' '], [' ', 'X', ' ', ' ', 'X', ' '], [' ', 'X', ' ', 'X', 'X', 'O']]
map3 = [['P', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', 'X', 'X', ' '], [' ', 'X', 'X', ' ', ' ', ' '], [' ', 'X', ' ', ' ', 'X', 'X'], ['X', 'X', ' ', 'X', ' ', ' '], [' ', ' ', ' ', ' ', ' ', 'O']]
map4 = [['P', ' ', 'X', ' ', ' ', ' '], ['X', ' ', 'X', ' ', 'X', ' '], [' ', ' ', 'X', ' ', 'X', ' '], [' ', 'X', 'X', ' ', ' ', ' '], [' ', 'X', 'X', ' ', 'X', ' '], [' ', ' ', ' ', ' ', 'X', 'O']]
map5 = [['P', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', 'O']]

maps = [map1, map2, map3, map4, map5]

def ClearConsole():
    command = 'clear'
    if os.name in ('nt', 'dos'):
        command = 'cls'
    os.system(command)

def ChooseMap():
    mapNumber = int (input("Map Number (0~4): "))
    return mapNumber

ClearConsole()
mapNumber = ChooseMap()
myMap = maps[mapNumber]

def DisplayMap():
    for line in myMap:
        print(f"[{line[0]}][{line[1]}][{line[2]}][{line[3]}][{line[4]}][{line[5]}]")

def FindPlayer():
    for i in range(0, 6):
        for j in range(0, 6):
            if myMap[i][j] == 'P':
                return [i, j]

def CanMove(moveDir):
    x = FindPlayer()[0]
    y = FindPlayer()[1]
    
    if moveDir == 'W':
        if x == 0:
            return False
        elif myMap[x - 1][y] == 'X':
            return False
        elif myMap[x - 1][y] == ' ':
            return True
        elif myMap[x - 1][y] == 'O':
            return "Passed"
        
    elif moveDir == 'A':
        if y == 0:
            return False
        elif myMap[x][y - 1] == 'X':
            return False
        elif myMap[x][y - 1] == ' ':
            return True
        elif myMap[x][y - 1] == 'O':
            return "Passed"
        
    elif moveDir == 'S':
        if x == 5:
            return False
        elif myMap[x + 1][y] == 'X':
            return False
        elif myMap[x + 1][y] == ' ':
            return True
        elif myMap[x + 1][y] == 'O':
            return "Passed"
        
    elif moveDir == 'D':
        if y == 5:
            return False
        elif myMap[x][y + 1] == 'X':
            return False
        elif myMap[x][y + 1] == ' ':
            return True
        elif myMap[x][y + 1] == 'O':
            return "Passed"

def Move(moveDir):
    x = FindPlayer()[0]
    y = FindPlayer()[1]
    
    if moveDir == 'W':
        myMap[x][y] = ' '
        myMap[x - 1][y] = 'P'
    
    elif moveDir == 'A':
        myMap[x][y] = ' '
        myMap[x][y - 1] = 'P'
    
    elif moveDir == 'S':
        myMap[x][y] = ' '
        myMap[x + 1][y] = 'P'
    
    elif moveDir == 'D':
        myMap[x][y] = ' '
        myMap[x][y + 1] = 'P'

def TakeMove():
    while True:
        move = input("Move Direction (WASD): ")
        move = move.upper()
        if move == 'W' or move == 'A' or move == 'S' or move == 'D':
            break
    
    canMove = CanMove(move)
    
    if canMove == True:
        Move(move)
        return "Moved"
    elif canMove == False:
        return "Wasted"
    elif canMove == "Passed":
        return "Passed"

def GameOver():
    ClearConsole()
    print("GameOver")
    return

def Winner():
    print("Passed")
    return

while True:
    ClearConsole()
    DisplayMap()
    move = TakeMove()
    if move == "Wasted":
        GameOver()
        break
    elif move == "Moved":
        continue
    elif move == "Passed":
        Winner()
        break