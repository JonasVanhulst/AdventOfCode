def readFile(filePath: any) -> list[str]:
    """
    @brief Reads the contents of a file.
    @param filePath The path to the file to be read.
    @return A list of strings, where each string is a line from the file.
    """
    with open(filePath, "r") as f:
        data: list[str] = f.readlines()
    return data


def partOne(data: list[str]) -> int:
    """
    @brief Counts the number of valid passphrases in the given data.
    A passphrase is valid if it contains no duplicate words.
    @param data A list of passphrases, where each passphrase is a string.
    @return The number of valid passphrases.
    """
    valid_passphrases: int = 0
    for passphrase in data:
        words = passphrase.split()
        if len(words) == len(set(words)):
            valid_passphrases += 1
    return valid_passphrases


def partTwo(data: list[str]) -> int:
    """
    @brief Counts the number of valid passphrases in the given data.
    A passphrase is valid if it contains no anagrams.
    @param data A list of passphrases, where each passphrase is a string.
    @return The number of valid passphrases.
    """
    valid_passphrases: int = 0
    for passphrase in data:
        words = passphrase.split()
        sorted_words = ["".join(sorted(word)) for word in words]
        if len(words) == len(set(sorted_words)):
            valid_passphrases += 1
    return valid_passphrases


def main():
    """
    @brief The main entry point of the program.
    Reads the input file, counts the number of valid passphrases using two different methods, and prints the results.
    """
    data: list[str] = readFile("day4/input4")
    print(partOne(data=data))
    print(partTwo(data=data))


if __name__ == "__main__":
    main()
