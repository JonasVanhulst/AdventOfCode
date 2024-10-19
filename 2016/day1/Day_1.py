def readFile(filepath: str) -> str:
    file = open(filepath, "r")
    content = file.read()
    file.close()
    return content


def partOne(content: str) -> int:
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # North, East, South, West
    current_direction = 0
    x, y = 0, 0
    for instruction in content.split(", "):
        turn = instruction[0]
        steps = int(instruction[1:])
        if turn == "L":
            current_direction = (current_direction - 1) % 4
        elif turn == "R":
            current_direction = (current_direction + 1) % 4
        dx, dy = directions[current_direction]
        x += dx * steps
        y += dy * steps
    return abs(x) + abs(y)


def partTwo(content: str) -> int:
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # North, East, South, West
    current_direction = 0
    x, y = 0, 0
    visited = set([(0, 0)])
    for instruction in content.split(", "):
        turn = instruction[0]
        steps = int(instruction[1:])
        if turn == "L":
            current_direction = (current_direction - 1) % 4
        elif turn == "R":
            current_direction = (current_direction + 1) % 4
        dx, dy = directions[current_direction]
        for _ in range(steps):
            x += dx
            y += dy
            if (x, y) in visited:
                return abs(x) + abs(y)
            visited.add((x, y))
    return -1


def main():
    # Reading the input file
    fileContent: str = readFile(
        filepath="/home/jonas/Documents/Learning/AoC/2016/day1/in1"
    )

    # Solution part one
    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
