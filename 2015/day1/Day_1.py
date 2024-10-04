def readFile(filepath: str) -> str:
    file = open(filepath, "r")
    content = file.read()
    file.close()
    return content


def partOne(content: str) -> int:
    upCounter: int = 0
    downCounter: int = 0

    for item in content:
        if item == "(":
            upCounter += 1
        elif item == ")":
            downCounter += 1

    return upCounter - downCounter


def partTwo(content: str) -> int:
    currentFloor = 0

    for position, item in enumerate(content, start=1):
        if item == "(":
            currentFloor += 1
        elif item == ")":
            currentFloor -= 1

        if currentFloor == -1:
            return position

    return -1


def main():
    # Reading the input file
    fileContent: str = readFile(filepath="day1/input_1.txt")

    # Solution part one
    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
