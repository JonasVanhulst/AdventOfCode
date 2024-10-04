import hashlib


def readFile(filepath: str) -> str:
    file = open(filepath, "r")
    content = file.read()
    file.close()
    return content


def partOne(secretKey: str) -> int:
    lowestNumber: int = 1

    while True:
        keyString = secretKey + str(lowestNumber)
        hashObj = hashlib.md5(keyString.encode())
        hashHex = hashObj.hexdigest()

        if hashHex.startswith("00000"):
            return lowestNumber

        lowestNumber += 1


def partTwo(secretKey: str) -> int:
    lowestNumber: int = 1

    while True:
        keyString = secretKey + str(lowestNumber)
        hashObj = hashlib.md5(keyString.encode())
        hashHex = hashObj.hexdigest()

        if hashHex.startswith("000000"):
            return lowestNumber

        lowestNumber += 1


def main():
    # Reading the input file
    fileContent: str = readFile(filepath="day4/input_4.txt")

    # Solution part one
    solutionPartOne: int = partOne(secretKey=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(secretKey=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
