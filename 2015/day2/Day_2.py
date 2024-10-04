def readFile(filepath: str) -> str:
    with open(filepath, "r") as file:
        content = file.read()
    return content


def convert_to_list_of_dimensions(file_content: str) -> list[list[int]]:
    lines = file_content.strip().split("\n")
    return [[int(x) for x in line.split("x")] for line in lines]


def partOne(content: list[list[int]]) -> int:
    total_paper: int = 0

    for dimensions in content:
        length, width, height = dimensions

        lw: int = length * width
        wh: int = width * height
        hl: int = height * length

        smallest_side: int = min(lw, wh, hl)

        total_paper += 2 * lw + 2 * wh + 2 * hl + smallest_side

    return total_paper


def partTwo(content: list[list[int]]) -> int:
    total_ribber: int = 0

    for dimensions in content:
        length, width, height = sorted(dimensions)

        ribbon_wrap = 2 * (length + width)

        ribbon_bow: int = length * width * height

        total_ribber += ribbon_wrap + ribbon_bow

    return total_ribber


def main():
    # Formula: 2*l*w + 2*w*h + 2*h*l + smallest

    # Reading the input file
    fileContent: str = readFile(filepath="day2/input_2.txt")

    # Convert the content to a list of dimensions
    fileContent = convert_to_list_of_dimensions(file_content=fileContent)

    # Solution part one
    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
