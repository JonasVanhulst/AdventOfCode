def readFile(filePath: any):
    """@brief Reads the contents of a file.

    @param filePath The path to the file to be read.
    @return The contents of the file as a string.
    """
    f = open(filePath, "r")
    return f.read()


def partOne(data: any) -> int:
    paths: any = data.split("\n")
    path1: any = paths[0].split(",")
    path2: any = paths[1].split(",")

    visited1: set = set()
    visited2: set = set()

    x1, y1 = 0, 0
    x2, y2 = 0, 0

    for move in path1:
        direction: any = move[0]
        steps: int = int(move[1:])
        for _ in range(steps):
            if direction == "U":
                y1 += 1
            elif direction == "D":
                y1 -= 1
            elif direction == "L":
                x1 -= 1
            elif direction == "R":
                x1 += 1
            visited1.add((x1, y1))
    for move in path2:
        direction = move[0]
        steps = int(move[1:])
        for _ in range(steps):
            if direction == "U":
                y2 += 1
            elif direction == "D":
                y2 -= 1
            elif direction == "L":
                x2 -= 1
            elif direction == "R":
                x2 += 1
            visited2.add((x2, y2))

    intersections: set = visited1.intersection(visited2)
    return min(abs(x) + abs(y) for x, y in intersections)


def partTwo(data: any) -> int:
    paths: any = data.split("\n")
    path1: any = paths[0].split(",")
    path2: any = paths[1].split(",")

    visited1: dict = {}
    visited2: dict = {}

    x1, y1 = 0, 0
    x2, y2 = 0, 0
    steps1 = 0
    steps2 = 0

    for move in path1:
        direction: any = move[0]
        steps: int = int(move[1:])
        for _ in range(steps):
            if direction == "U":
                y1 += 1
            elif direction == "D":
                y1 -= 1
            elif direction == "L":
                x1 -= 1
            elif direction == "R":
                x1 += 1
            steps1 += 1
            visited1[(x1, y1)] = steps1

    for move in path2:
        direction = move[0]
        steps = int(move[1:])
        for _ in range(steps):
            if direction == "U":
                y2 += 1
            elif direction == "D":
                y2 -= 1
            elif direction == "L":
                x2 -= 1
            elif direction == "R":
                x2 += 1
            steps2 += 1
            visited2[(x2, y2)] = steps2

    intersections: set = set(visited1.keys()).intersection(set(visited2.keys()))
    return min(
        visited1[intersection] + visited2[intersection]
        for intersection in intersections
    )


def main():
    """@brief The main entry point of the program.
    Reads the input file, counts the number of valid passphrases using two different methods, and prints the results.
    """
    data: str = readFile(filePath="day3/input3")
    print(partOne(data))
    print(partTwo(data))


if __name__ == "__main__":
    main()
