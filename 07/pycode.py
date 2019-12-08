from itertools import permutations
import copy

def run(INPUT, signal, instructions):
    counter = 0
    while counter < len(instructions):
        ins = str(instructions[counter]).rjust(5, "0")
        opcode = int(ins[4:])
        if opcode == 1 or opcode == 2:
            modes = ins[0:3][::-1]
            a = instructions[counter + 1] if modes[0] == "1" else instructions[instructions[counter + 1]]
            b = instructions[counter + 2] if modes[1] == "1" else instructions[instructions[counter + 2]]
            if opcode == 1:
                if modes[2] == "0":
                    instructions[instructions[counter + 3]] = a + b
                else:
                    instructions[counter + 3] = a + b
            else:
                if modes[2] == "0":
                    instructions[instructions[counter + 3]] = a * b
                else:
                    instructions[counter + 3] = a * b
            counter += 4
        elif opcode == 3:
            # write input to address
            instructions[instructions[counter + 1]] = INPUT
            INPUT = signal
            if instructions[counter + 1] != counter:
                counter += 2
        elif opcode == 4:
            if ins[2] == "0":
                return instructions[instructions[counter + 1]]
            else:
                return instructions[counter + 1]
            counter += 2
        elif opcode == 5:
            modes = ins[0:3][::-1]
            a = instructions[counter + 1] if modes[0] == "1" else instructions[instructions[counter + 1]]
            b = instructions[counter + 2] if modes[1] == "1" else instructions[instructions[counter + 2]]
            if a != 0:
                counter = b
            else:
                counter += 3
        elif opcode == 6:
            modes = ins[0:3][::-1]
            a = instructions[counter + 1] if modes[0] == "1" else instructions[instructions[counter + 1]]
            b = instructions[counter + 2] if modes[1] == "1" else instructions[instructions[counter + 2]]
            if a == 0:
                counter = b
            else:
                counter += 3
        elif opcode == 7:
            modes = ins[0:3][::-1]
            a = instructions[counter + 1] if modes[0] == "1" else instructions[instructions[counter + 1]]
            b = instructions[counter + 2] if modes[1] == "1" else instructions[instructions[counter + 2]]
            c = instructions[counter + 3]
            instructions[c] = 1 if a < b else 0
            if c != counter:
                counter += 4
        elif opcode == 8:
            modes = ins[0:3][::-1]
            a = instructions[counter + 1] if modes[0] == "1" else instructions[instructions[counter + 1]]
            b = instructions[counter + 2] if modes[1] == "1" else instructions[instructions[counter + 2]]
            c = instructions[counter + 3]
            instructions[c] = 1 if a == b else 0
            if c != counter:
                counter += 4
        elif opcode == 99:
            break
        else:
            raise ValueError("Unrecognized opcode")

        
with open("input.txt") as f:
    instructions = [int(x) for x in f.readline().split(",")]

# TODO
# modify run to return in order: output, instructions, program counter AFTER move
# each time, run will only need ONE input EXCEPT for the first time.
# what if you run each
# I guess you could use yield and generators.
# TODO how do you handle the "next input" or special case phase?
phases_perms = list(permutations([5, 6, 7, 8, 9]))
states = [copy.deepcopy(instructions) for i in range(5)]
counters = [0 for i in range(5)]
inputs = [0 for i in range(5)]
bssf = 0
for perm in phases_perms:
    prev = 0
    amp = 0
    while True:
        prev, states[i], counters[i]  = run(inputs[i], prev, states[i], counters[i])
        amp = (amp + 1) % 5
        inputs[amp] = 
    bssf = max(bssf, prev)
print(bssf)

