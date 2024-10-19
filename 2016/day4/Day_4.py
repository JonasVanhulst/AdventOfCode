from collections import Counter


def readFile(filepath: str) -> str:
    with open(filepath, "r") as file:
        content = file.read()
    return content


def partOne(content: str) -> int:
    realRooms: int = 0

    for line in content.splitlines():
        parts = line.rsplit("-", 1)
        room_name = parts[0].replace("-", "")
        sector_id_and_checksum = parts[1]
        sectorID, checksum = sector_id_and_checksum.strip("]").split("[")

        char_count = Counter(room_name)
        sorted_chars = sorted(char_count, key=lambda char: (-char_count[char], char))
        calculated_checksum = ''.join(sorted_chars[:5])

        if calculated_checksum == checksum:
            realRooms += int(sectorID)

    return realRooms


def partTwo(content: str) -> int:
 return 0


def main():
    fileContent: str = readFile(filepath="in4")

    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
