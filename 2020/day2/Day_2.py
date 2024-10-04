def readFile(filepath: str) -> str:
    with open(filepath, "r") as file:
        content = file.read().strip().splitlines()
    return content

def checkValid(policy: str, password: str) -> bool:
    policy_range, letter = policy.split(' ')
    min_count, max_count = map(int, policy_range.split('-'))
    letter_count = password.count(letter[0])
    return min_count <= letter_count <= max_count

def checkValidP2(policy: str, password: str) -> bool:
    policy_range, letter = policy.split(' ')
    pos1, pos2 = map(int, policy_range.split('-'))
    letter_at_pos1 = password[pos1 - 1] == letter[0]  # Position 1
    letter_at_pos2 = password[pos2 - 1] == letter[0]  # Position 2
    return letter_at_pos1 != letter_at_pos2  

def partOne(content: list) -> int:
    value: int = 0
    
    for line in content:
        policy, password = line.split(': ')
        if checkValid(policy, password):
            value += 1
    
    return value


def partTwo(content: list) -> int:
    value: int = 0
    
    for line in content:
        policy, password = line.split(': ')
        if checkValidP2(policy, password):  # Use the new validity check
            value += 1
    
    return value

def main():
    # Reading the input file
    fileContent: list = readFile(
        filepath="/home/jonas/Documents/Learning/AoC/2020/day2/input2"
    )

    # Solution part one
    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
