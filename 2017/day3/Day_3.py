def readFile(filePath: any):
    """@brief Reads the contents of a file.

    @param filePath The path to the file to be read.
    @return The contents of the file as a string.
    """
    f = open(filePath, "r")
    return f.read()


def partOne(data: int) -> int:
    return 0


def partTwo(data: any) -> int:
    return 0


def main():
    """@brief The main entry point of the program.
    Reads the input file, counts the number of valid passphrases using two different methods, and prints the results.
    """
    data: str = readFile(filePath="day3/input3")
    print(partOne(data))
    print(partTwo(data))


if __name__ == "__main__":
    main()
