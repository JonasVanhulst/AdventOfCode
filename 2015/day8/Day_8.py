def readFile(filepath: str) -> str:
    with open(filepath, "r") as file:
        content = file.read()
    return content


def partOne(content: str) -> int:
    code_length: int = 0
    memory_length: int = 0

    # Process each line separately
    lines = content.splitlines()

    for line in lines:
        code_length += len(line)

        i = 1  # Start after the first double quote
        while i < len(line) - 1:  # Stop before the last double quote
            if line[i] == "\\":  # Escape sequence starts
                if line[i + 1] == "\\" or line[i + 1] == '"':
                    # \\" or \\ => 1 character in memory
                    memory_length += 1
                    i += 2  # Skip both characters in the escape sequence
                elif line[i + 1] == "x" and i + 3 < len(line):
                    # \xXX => 1 character in memory
                    memory_length += 1
                    i += 4  # Skip the \x and the two hex digits
            else:
                # Normal character
                memory_length += 1
                i += 1

    return code_length - memory_length


def partTwo(content: str) -> int:
    encoded_length: int = 0
    original_length: int = 0

    lines = content.splitlines()

    for line in lines:
        original_length += len(line)

        # Start with two extra characters for the surrounding double quotes
        encoded_length += 2
        for char in line:
            if char == "\\" or char == '"':
                # Each backslash or double quote needs to be escaped
                encoded_length += 2
            else:
                encoded_length += 1

    return encoded_length - original_length


def main():
    # Reading the input file
    fileContent: str = readFile(filepath="day8/input_8.txt")

    # Solution part one
    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
