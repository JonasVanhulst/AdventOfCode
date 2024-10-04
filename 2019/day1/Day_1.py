import math


def readFile(filepath: str) -> list:
    with open(filepath, "r") as file:
        content = file.readlines()

    # Convert the lines to integers and return as a list
    cleanText = [int(line.strip()) for line in content if line.strip()]

    return cleanText


def partOne(numbers: list) -> int:
    result: int = 0

    for value in numbers:
        result += math.floor(value / 3) - 2

    return result


def calculate_fuel(mass: int) -> int:
    total_fuel: int = 0
    while mass > 0:
        mass = math.floor(mass / 3) - 2
        if mass > 0:
            total_fuel += mass
    return total_fuel


def partTwo(numbers: list) -> int:
    total_fuel: int = 0
    for mass in numbers:
        total_fuel += calculate_fuel(mass)
    return total_fuel


def main():
    # Reading the input file
    fileContent: list = readFile(filepath="day1/input1")

    # Solution part one
    solutionPartOne: int = partOne(numbers=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(numbers=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
