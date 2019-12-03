def runMoves(moves):
    r = 0
    c = 0
    
    M = set()
    P = {}
    steps = 0
    for move in moves:
        d = move[0]
        amt = int(move[1:])
        for i in range(amt):
            steps += 1
            if d == "U": 
                r -= 1
            elif d == "D": 
                r += 1
            elif d == "R":
                c += 1
            elif d == "L":
                c -= 1
            
            M.add((r, c))
            P[(r, c)] = steps
    return M, P

with open("input.txt") as f:
    lines = f.readlines()

S = [runMoves(l.split(",")) for l in lines]
intersections = S[0][0]&S[1][0]

min_dist = float("inf")
for intersect in intersections:
    min_dist = min(abs(intersect[0]) + abs(intersect[1]), min_dist)
print(min_dist)

min_steps = float("inf")
for intersect in intersections:
    min_steps = min(S[0][1][intersect] + S[1][1][intersect], min_steps)
print(min_steps)

