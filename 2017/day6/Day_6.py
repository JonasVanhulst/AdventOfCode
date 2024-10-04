def readFile(filePath: any):
    """@brief Reads the contents of a file.

    @param filePath The path to the file to be read.
    @return The contents of the file as a string.
    """
    f = open(filePath, "r")
    return f.read()


def partOne(data: str) -> int:
    banks = list(map(int, data.split()))
    seen = set()
    cycles = 0
    while tuple(banks) not in seen:
        seen.add(tuple(banks))
        max_blocks = max(banks)
        max_index = banks.index(max_blocks)
        banks[max_index] = 0
        for i in range(max_blocks):
            banks[(max_index + i + 1) % len(banks)] += 1
        cycles += 1
    return cycles


def partTwo(data: str) -> int:
    banks = list(map(int, data.split()))
    seen = set()
    cycles = 0
    loop_start = None
    while tuple(banks) not in seen:
        seen.add(tuple(banks))
        max_blocks = max(banks)
        max_index = banks.index(max_blocks)
        banks[max_index] = 0
        for i in range(max_blocks):
            banks[(max_index + i + 1) % len(banks)] += 1
        cycles += 1

    loop_start = tuple(banks)
    loop_cycles = 0
    while True:
        max_blocks = max(banks)
        max_index = banks.index(max_blocks)
        banks[max_index] = 0
        for i in range(max_blocks):
            banks[(max_index + i + 1) % len(banks)] += 1
        loop_cycles += 1
        if tuple(banks) == loop_start:
            break
    return loop_cycles


def main():
    """@brief The main entry point of the program.
    Reads the input file, counts the number of valid passphrases using two different methods, and prints the results.
    """
    data: str = readFile(filePath="day6/input6")
    print(partOne(data))
    print(partTwo(data))


if __name__ == "__main__":
    main()
