def readFile(filepath: str) -> str:
    file = open(filepath, "r")
    content = file.read()
    file.close()
    return content


def niceString(content: str) -> bool:
    vowels = "aeiou"
    forbiddenSubstrings = ["ab", "cd", "pq", "xy"]

    vowelCount = sum(1 for letter in content if letter in vowels)

    hasDouble = any(content[i] == content[i + 1] for i in range(len(content) - 1))

    hasForbidden = any(substring in content for substring in forbiddenSubstrings)

    return vowelCount >= 3 and hasDouble and not hasForbidden


def partOne(content: str) -> int:
    strings = content.splitlines()

    niceCount = sum(1 for string in strings if niceString(content=string))

    return niceCount


def niceStringP2(content: str) -> bool:
    hasDoublePair = any(
        content[i : i + 2] in content[i + 2 :] for i in range(len(content) - 1)
    )

    hasRepeat = any(content[i] == content[i + 2] for i in range(len(content) - 2))

    return hasDoublePair and hasRepeat


def partTwo(content: str) -> int:
    strings = content.splitlines()
    niceStringCount = sum(1 for string in strings if niceStringP2(content=string))
    return niceStringCount


def main():
    # Reading the input file
    fileContent: str = readFile(filepath="day5/input_5.txt")

    # Solution part one
    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
