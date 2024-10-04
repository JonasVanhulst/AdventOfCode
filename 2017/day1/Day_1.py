def readFile(filePath: any):
    """@brief Reads the contents of a file.

    @param filePath The path to the file to be read.
    @return The contents of the file as a string.
    """
    f = open(filePath, "r")
    return f.read()


def partOne(data: any) -> int:
    """@brief Counts the number of valid passphrases using the first method.

    @param data The input data as a string.
    @return The total count of valid passphrases.
    """
    total: int = 0
    data: str = str(data)
    for i in range(len(data)):
        if data[i] == data[(i + 1) % len(data)]:
            total += int(data[i])
    return total


def partTwo(data: any) -> int:
    """@brief Counts the number of valid passphrases using the second method.

    @param data The input data as a string.
    @return The total count of valid passphrases.
    """
    total: int = 0
    data: str = str(data)
    step: int = len(data) // 2
    for i in range(len(data)):
        if data[i] == data[(i + step) % len(data)]:
            total += int(data[i])
    return total


def main():
    """@brief The main entry point of the program.
    Reads the input file, counts the number of valid passphrases using two different methods, and prints the results.
    """
    data: str = readFile(filePath="day1/input1")
    print(partOne(data))
    print(partTwo(data))


if __name__ == "__main__":
    main()
