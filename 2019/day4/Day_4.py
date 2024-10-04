def readFile(filePath: any):
    """@brief Reads the contents of a file.

    @param filePath The path to the file to be read.
    @return The contents of the file as a string.
    """
    f = open(filePath, "r")
    return f.read()


def partOne(data: any) -> int:
    start, end = map(int, data.split("-"))
    count: int = 0

    for password in range(start, end + 1):
        password_str = str(password)
        if len(password_str) != 6:
            continue
        if not any(password_str[i] == password_str[i + 1] for i in range(5)):
            continue
        if not all(password_str[i] <= password_str[i + 1] for i in range(5)):
            continue
        count += 1
    return count


def partTwo(data: any) -> int:
    start, end = map(int, data.split("-"))
    count: int = 0

    for password in range(start, end + 1):
        password_str = str(password)
        if len(password_str) != 6:
            continue
        if not any(password_str.count(password_str[i]) == 2 for i in range(6)):
            continue
        if not all(password_str[i] <= password_str[i + 1] for i in range(5)):
            continue
        count += 1
    return count


def main():
    """@brief The main entry point of the program.
    Reads the input file, counts the number of valid passphrases using two different methods, and prints the results.
    """
    data: str = readFile(filePath="day4/input4")
    print(partOne(data))
    print(partTwo(data))


if __name__ == "__main__":
    main()
