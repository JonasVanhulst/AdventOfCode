def readFile(filepath: str) -> list:
    with open(filepath, "r") as file:
        content = file.readlines()

    # Convert the lines to integers and return as a list
    cleanText = [int(line.strip()) for line in content if line.strip()]
    
    return cleanText


def partOne(numbers: list) -> int:
    result: int = 0
    
    # Loop through the numbers to find the two that sum to 2020
    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):  # Start j from i + 1 to avoid duplication
            if numbers[i] + numbers[j] == 2020:
                result = numbers[i] * numbers[j]
                return result  # Return as soon as we find the pair

    return result  # Return 0 if no pairs found


def partTwo(numbers: list) -> int:
    result: int = 0
    
    # Loop through the numbers to find the two that sum to 2020
    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):  # Start j from i + 1 to avoid duplication
           for k in range(i + 2, len(numbers)): 
                if numbers[i] + numbers[j] + numbers[k] == 2020:
                    result = numbers[i] * numbers[j] * numbers[k]
                    return result  # Return as soon as we find the pair

    return result  # Return 0 if no pairs found



def main():
    # Reading the input file
    fileContent: list = readFile(
        filepath="/home/jonas/Documents/Learning/AoC/2020/day1/input1"
    )

    # Solution part one
    solutionPartOne: int = partOne(numbers=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(numbers=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
