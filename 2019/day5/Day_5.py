def readFile(filePath: any):
    """@brief Reads the contents of a file.

    @param filePath The path to the file to be read.
    @return The contents of the file as a string.
    """
    f = open(filePath, "r")
    return f.read()


def partOne(data: any) -> int:
    program: list[int] = list(map(int, data.split(",")))
    pointer: int = 0

    while True:
        instruction: str = str(program[pointer]).zfill(4)
        opcode: int = int(instruction[-2:])
        mode1: int = int(instruction[-3])
        mode2: int = int(instruction[-4])

        if opcode == 1:
            if mode1 == 0:
                val1 = program[program[pointer + 1]]
            else:
                val1 = program[pointer + 1]
            if mode2 == 0:
                val2 = program[program[pointer + 2]]
            else:
                val2 = program[pointer + 2]
            program[program[pointer + 3]] = val1 + val2
            pointer += 4
        elif opcode == 2:
            if mode1 == 0:
                val1 = program[program[pointer + 1]]
            else:
                val1 = program[pointer + 1]
            if mode2 == 0:
                val2 = program[program[pointer + 2]]
            else:
                val2 = program[pointer + 2]
            program[program[pointer + 3]] = val1 * val2
            pointer += 4
        elif opcode == 3:
            program[program[pointer + 1]] = 1
            pointer += 2
        elif opcode == 4:
            if mode1 == 0:
                val1 = program[program[pointer + 1]]
            else:
                val1 = program[pointer + 1]
            if val1 != 0:
                return val1
            pointer += 2
        elif opcode == 99:
            return program[0]


def partTwo(data: any) -> int:
    program: list[int] = list(map(int, data.split(",")))
    pointer: int = 0

    while True:
        instruction: str = str(program[pointer]).zfill(4)
        opcode: int = int(instruction[-2:])
        mode1: int = int(instruction[-3])
        mode2: int = int(instruction[-4])

        if opcode == 1:
            if mode1 == 0:
                val1 = program[program[pointer + 1]]
            else:
                val1 = program[pointer + 1]
            if mode2 == 0:
                val2 = program[program[pointer + 2]]
            else:
                val2 = program[pointer + 2]
            program[program[pointer + 3]] = val1 + val2
            pointer += 4
        elif opcode == 2:
            if mode1 == 0:
                val1 = program[program[pointer + 1]]
            else:
                val1 = program[pointer + 1]
            if mode2 == 0:
                val2 = program[program[pointer + 2]]
            else:
                val2 = program[pointer + 2]
            program[program[pointer + 3]] = val1 * val2
            pointer += 4
        elif opcode == 3:
            program[program[pointer + 1]] = 5
            pointer += 2
        elif opcode == 4:
            if mode1 == 0:
                val1 = program[program[pointer + 1]]
            else:
                val1 = program[pointer + 1]
            return val1
            pointer += 2
        elif opcode == 5:
            if mode1 == 0:
                val1 = program[program[pointer + 1]]
            else:
                val1 = program[pointer + 1]
            if mode2 == 0:
                val2 = program[program[pointer + 2]]
            else:
                val2 = program[pointer + 2]
            if val1 != 0:
                pointer = val2
            else:
                pointer += 3
        elif opcode == 6:
            if mode1 == 0:
                val1 = program[program[pointer + 1]]
            else:
                val1 = program[pointer + 1]
            if mode2 == 0:
                val2 = program[program[pointer + 2]]
            else:
                val2 = program[pointer + 2]
            if val1 == 0:
                pointer = val2
            else:
                pointer += 3
        elif opcode == 7:
            if mode1 == 0:
                val1 = program[program[pointer + 1]]
            else:
                val1 = program[pointer + 1]
            if mode2 == 0:
                val2 = program[program[pointer + 2]]
            else:
                val2 = program[pointer + 2]
            if val1 < val2:
                program[program[pointer + 3]] = 1
            else:
                program[program[pointer + 3]] = 0
            pointer += 4
        elif opcode == 8:
            if mode1 == 0:
                val1 = program[program[pointer + 1]]
            else:
                val1 = program[pointer + 1]
            if mode2 == 0:
                val2 = program[program[pointer + 2]]
            else:
                val2 = program[pointer + 2]
            if val1 == val2:
                program[program[pointer + 3]] = 1
            else:
                program[program[pointer + 3]] = 0
            pointer += 4
        elif opcode == 99:
            return program[0]


def main():
    """@brief The main entry point of the program.
    Reads the input file, counts the number of valid passphrases using two different methods, and prints the results.
    """
    data: str = readFile(filePath="day5/input5")
    print(partOne(data))
    print(partTwo(data))


if __name__ == "__main__":
    main()
