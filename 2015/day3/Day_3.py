def readFile(filepath: str) -> str:
    file = open(filepath, "r")
    content = file.read()
    file.close()
    return content


def partOne(content: str) -> int:
    xSanta, ySanta = 0, 0

    visitedHouses = set()
    visitedHouses.add((xSanta, ySanta))

    for move in content:
        if move == "^":
            ySanta += 1
        elif move == "v":
            ySanta -= 1
        elif move == "<":
            xSanta += 1
        elif move == ">":
            xSanta -= 1

        visitedHouses.add((xSanta, ySanta))

    return len(visitedHouses)


def partTwo(content: str) -> int:
    xSantaClaus, ySantaClaus = 0, 0
    xRoboSanta, yRoboSanta = 0, 0

    visitedHouses = set()
    visitedHouses.add((xSantaClaus, ySantaClaus))

    for i, move in enumerate(content):
        if i % 2 == 0:
            if move == "^":
                ySantaClaus += 1
            elif move == "v":
                ySantaClaus -= 1
            elif move == "<":
                xSantaClaus += 1
            elif move == ">":
                xSantaClaus -= 1
            visitedHouses.add((xSantaClaus, ySantaClaus))
        else:
            if move == "^":
                yRoboSanta += 1
            elif move == "v":
                yRoboSanta -= 1
            elif move == "<":
                xRoboSanta += 1
            elif move == ">":
                xRoboSanta -= 1

        visitedHouses.add((xRoboSanta, yRoboSanta))

    return len(visitedHouses)


def main():
    # Reading the input file
    fileContent: str = readFile(filepath="day3/input_3.txt")

    # Solution part one
    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
