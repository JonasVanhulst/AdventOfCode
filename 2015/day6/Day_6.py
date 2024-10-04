import numpy as np

LED_ON: int = 1
LED_OFF: int = 0
DIMENSIONS_PANEL: int = 1000


def readFile(filepath: str) -> str:
    with open(filepath, "r") as file:
        return file.read()


def partOne(content: str) -> int:
    # parse the content
    data = [line.strip() for line in content.strip().split("\n")]

    # create 1000x1000 grid
    ledPanel = np.full((DIMENSIONS_PANEL, DIMENSIONS_PANEL), LED_OFF)

    # fill the grid with the requested commands & count the leds
    for panelInstructions in data:
        # Parse instruction
        parts = panelInstructions.split()

        # Determine command
        if parts[0] == "toggle":
            command = "toggle"
            start_coords = parts[1]
            end_coords = parts[3]
        else:
            command = parts[1]  # 'on' or 'off'
            start_coords = parts[2]
            end_coords = parts[4]

        # Convert coordinate strings to integer tuples
        start_x, start_y = map(int, start_coords.split(","))
        end_x, end_y = map(int, end_coords.split(","))

        # Update the grid based on the command
        for x in range(start_x, end_x + 1):
            for y in range(start_y, end_y + 1):
                if command == "on":
                    ledPanel[x, y] = LED_ON
                elif command == "off":
                    ledPanel[x, y] = LED_OFF
                elif command == "toggle":
                    ledPanel[x, y] = LED_OFF if ledPanel[x, y] == LED_ON else LED_ON

    # Count the number of lights that are on
    return np.sum(ledPanel == LED_ON)


def partTwo(content: str) -> int:
    # parse the content
    data = [line.strip() for line in content.strip().split("\n")]

    # create 1000x1000 grid
    ledPanel = np.full((DIMENSIONS_PANEL, DIMENSIONS_PANEL), LED_OFF)

    # fill the grid with the requested commands & count the leds
    for panelInstructions in data:
        # Parse instruction
        parts = panelInstructions.split()

        # Determine command
        if parts[0] == "toggle":
            command = "toggle"
            start_coords = parts[1]
            end_coords = parts[3]
        else:
            command = parts[1]  # 'on' or 'off'
            start_coords = parts[2]
            end_coords = parts[4]

        # Convert coordinate strings to integer tuples
        start_x, start_y = map(int, start_coords.split(","))
        end_x, end_y = map(int, end_coords.split(","))

        # Update the grid based on the command
        for x in range(start_x, end_x + 1):
            for y in range(start_y, end_y + 1):
                if command == "on":
                    ledPanel[x, y] += 1
                elif command == "off":
                    ledPanel[x, y] = max(0, ledPanel[x, y] - 1)
                elif command == "toggle":
                    ledPanel[x, y] += 2

    # Count the total of brightness
    return np.sum(ledPanel)


def main():
    # Reading the input file
    fileContent: str = readFile(filepath="day6/input_6.txt")

    # Solution part one
    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two
    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
