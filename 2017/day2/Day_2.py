def readFile(filePath: str) -> list[list[int]]:
    """@brief Reads a file and yields each line as a list of integers.
    @param filePath The path to the file to read.
    @return A list of lists of integers, where each inner list represents a line in the file.
    """
    with open(filePath, "r") as f:
        for line in f:
            yield [int(x) for x in line.split()]


def partOne(data: list[list[int]]) -> int:
    """@brief Calculates the sum of the differences between the max and min values in each line.
    @param data A list of lists of integers, where each inner list represents a line.
    @return The sum of the differences between the max and min values in each line.
    """
    # Calculate the difference between the max and min values in each line
    min_max_diffs = [max(line) - min(line) for line in data]
    return sum(min_max_diffs)


def partTwo(data: list[list[int]]) -> int:
    """@brief Calculates the sum of the divisions of each pair of numbers in each line.
    @param data A list of lists of integers, where each inner list represents a line.
    @return The sum of the divisions of each pair of numbers in each line.
    """
    result = 0
    for line in data:
        # Iterate over each pair of numbers in the line
        for i in range(len(line)):
            for j in range(len(line)):
                # Check if the numbers are not the same and if one is divisible by the other
                if i != j and line[i] % line[j] == 0:
                    # Add the division result to the total
                    result += line[i] // line[j]
                    break
    return result


def main():
    """@brief The main entry point of the program.
    Reads the input file, calculates the sum of the differences between the max and min values in each line,
    and the sum of the divisions of each pair of numbers in each line, and prints the results.
    """
    # Read the input file
    data = list(readFile(filePath="day2/input2"))
    # Print the results of part one and part two
    print(partOne(data))
    print(partTwo(data))


if __name__ == "__main__":
    main()
