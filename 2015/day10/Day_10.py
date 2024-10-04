def readFile(filepath: str) -> str:
    file = open(filepath, "r")
    content = file.read()
    file.close()
    return content


def look(sequence: str) -> str:
    result = []
    i = 0
    while i < len(sequence):
        count = 1
        while i + 1 < len(sequence) and sequence[i] == sequence[i + 1]:
            count += 1
            i += 1
        result.append(str(count))
        result.append(sequence[i])
        i += 1

    return "".join(result)


def solution(sequence: str, iterations: int) -> int:
    for _ in range(iterations):
        sequence = look(sequence)
    return len(sequence)


def main():
    # Reading the input file
    fileContent: str = readFile(filepath="day10/input_10.txt")

    # Solution part one
    solutionPartOne: int = solution(sequence=fileContent, iterations=40)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = solution(sequence=fileContent, iterations=50)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
