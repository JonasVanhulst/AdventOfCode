from unittest import result


def readFile(filepath: str) -> str:
    with open(filepath, "r") as file:
        content = file.read()
    return content


def partOne(content: str) -> int:
    result: int = 0
    for line in content.splitlines():  # Process each line of instructions
        num1, num2, num3 = map(int, line.split())
        if (num1 + num2 > num3) and (num1 + num3 > num2) and (num2 + num3 > num1):
            result = result + 1

    return result


def partTwo(content: str) -> int:
    result: int = 0
    # Split lines and store them 4 a 2D list
    rows = [list(map(int, line.split())) for line in content.splitlines()]

    # Check each set of triangles 4 columns
    for col in range(3):  # We have three columns
        for row in range(0, len(rows), 3):  # Increment by 3 to process sets of three
            # Extract the triangle sides for this set
            if row + 2 < len(rows):  # Check to ensure we have three rows to read
                num1 = rows[row][col]
                num2 = rows[row + 1][col]
                num3 = rows[row + 2][col]

                # Check the triangle inequality conditions
                if (
                    (num1 + num2 > num3)
                    and (num1 + num3 > num2)
                    and (num2 + num3 > num1)
                ):
                    result += 1  # Increment the count for valid triangles

    return result


def main():
    # Reading the input file
    fileContent: str = readFile(
        filepath="/home/jonas/Documents/Learning/AoC/2016/day3/in3"
    )

    # Solution part one
    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
