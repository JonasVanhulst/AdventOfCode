from numpy import character


def readFile(filepath: str) -> str:
    with open(filepath, "r") as file:
        content = file.read()
    return content


def partOne(content: str, grid: list[list[int]]) -> int:
    # Initial position (x, y) corresponds to '5' on the keypad
    x, y = 1, 1  # Starting at grid[1][1] (which is 5)
    code = []  # To store the final code

    for line in content.splitlines():  # Process each line of instructions
        for char in line:
            if char == "U":
                if y > 0:  # Prevent moving out of bounds
                    y -= 1
            elif char == "D":
                if y < 2:  # Prevent moving out of bounds
                    y += 1
            elif char == "L":
                if x > 0:  # Prevent moving out of bounds
                    x -= 1
            elif char == "R":
                if x < 2:  # Prevent moving out of bounds
                    x += 1

        # After processing the line, add the current position to the code
        code.append(grid[y][x])  # Append the value at the current position

    # Join the code list into a single string to represent the bathroom code
    return "".join(map(str, code))


def partTwo(content: str, grid: list[list[character]]) -> int:
    x, y = 0, 2  # Starting at grid[2][0] (which is 5)
    code = []  # To store the final code

    for line in content.splitlines():  # Process each line of instructions
        print(f"Processing Line: {line}")  # Debug output

        for char in line:
            if char == "U":
                if (
                    y > 0 and grid[y - 1][x] != " "
                ):  # Move up if not out of bounds and not a space
                    y -= 1
            elif char == "D":
                if y < len(grid) - 1 and grid[y + 1][x] != " ":  # Move down
                    y += 1
            elif char == "L":
                if x > 0 and grid[y][x - 1] != " ":  # Move left
                    x -= 1
            elif char == "R":
                if x < len(grid[y]) - 1 and grid[y][x + 1] != " ":  # Move right
                    x += 1

        # After processing the line, add the current position to the code
        code.append(grid[y][x])  # Append the value at the current position

    # Join the code list into a single string to represent the bathroom code
    return "".join(code)


def main():
    # Reading the input file
    fileContent: str = readFile(
        filepath="/home/jonas/Documents/Learning/AoC/2016/day2/in2"
    )

    data: list[list[int]] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

    data2: list[list[character]] = [
        [" ", " ", "1", " ", " "],
        [" ", "2", "3", "4", " "],
        ["5", "6", "7", "8", "9"],
        [" ", "A", "B", "C", " "],
        [" ", " ", "D", " ", " "],
    ]

    # Solution part one
    solutionPartOne: int = partOne(content=fileContent, grid=data)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(content=fileContent, grid=data2)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
