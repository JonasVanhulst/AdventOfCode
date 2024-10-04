def readFile(filePath: any):
    """@brief Reads the contents of a file.

    @param filePath The path to the file to be read.
    @return The contents of the file as a string.
    """
    f = open(filePath, "r")
    return f.read()


def partOne(data: any) -> int:
    program: list[int] = [int(x) for x in data.split(",")]
    program[1] = 12
    program[2] = 2
    i: int = 0
    while program[i] != 99:
        if program[i] == 1:
            program[program[i + 3]] = program[program[i + 1]] + program[program[i + 2]]
        elif program[i] == 2:
            program[program[i + 3]] = program[program[i + 1]] * program[program[i + 2]]
        i += 4
    return program[0]


def partTwo(data: any) -> int:
    program: list[int] = [int(x) for x in data.split(",")]
    target_output: int = 19690720

    for noun in range(100):
        for verb in range(100):
            temp_program: list[int] = program.copy()
            temp_program[1] = noun
            temp_program[2] = verb

            i = 0

            while temp_program[i] != 99:
                if temp_program[i] == 1:
                    temp_program[temp_program[i + 3]] = (
                        temp_program[temp_program[i + 1]]
                        + temp_program[temp_program[i + 2]]
                    )
                elif temp_program[i] == 2:
                    temp_program[temp_program[i + 3]] = (
                        temp_program[temp_program[i + 1]]
                        * temp_program[temp_program[i + 2]]
                    )
                i += 4
            if temp_program[0] == target_output:
                return 100 * noun + verb
    return 0


def main():
    """@brief The main entry point of the program.
    Reads the input file, counts the number of valid passphrases using two different methods, and prints the results.
    """
    data: str = readFile(filePath="day2/input2")
    print(partOne(data))
    print(partTwo(data))


if __name__ == "__main__":
    main()
