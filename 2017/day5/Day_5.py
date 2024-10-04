def readFile(filePath: any):
    """@brief Reads the contents of a file.

    @param filePath The path to the file to be read.
    @return The contents of the file as a string.
    """
    f = open(filePath, "r")
    return f.read()


def partOne(data: any) -> int:
    jumps = list(map(int, data.split()))
    steps = 0
    i = 0
    while 0 <= i < len(jumps):
        jump = jumps[i]
        jumps[i] += 1
        i += jump
        steps += 1
    return steps


def partTwo(data: any) -> int:
    jumps = list(map(int, data.split()))
    steps = 0
    i = 0
    while 0 <= i < len(jumps):
        jump = jumps[i]
        if jump >= 3:
            jumps[i] -= 1
        else:
            jumps[i] += 1
        i += jump
        steps += 1
    return steps


def main():
    """@brief The main entry point of the program.
    Reads the input file, counts the number of valid passphrases using two different methods, and prints the results.
    """
    data: str = readFile(filePath="day5/input5")
    print(partOne(data))
    print(partTwo(data))


if __name__ == "__main__":
    main()
