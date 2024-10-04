import itertools


def readFile(filepath: str) -> str:
    with open(filepath, "r") as file:
        return file.read()


def parseInput(content: str):
    distances = {}
    locations = set()

    for line in content.splitlines():
        parts = line.split(" ")
        loc1, loc2 = parts[0], parts[2]
        distance = int(parts[-1])

        # Store distances in both directions (since it's a symmetric problem)
        distances[(loc1, loc2)] = distance
        distances[(loc2, loc1)] = distance

        # Add locations to the set
        locations.add(loc1)
        locations.add(loc2)

    return distances, list(locations)


def calculateRouteDistance(route, distances):
    total_distance = 0
    for i in range(len(route) - 1):
        total_distance += distances[(route[i], route[i + 1])]
    return total_distance


def partOne(content: str) -> int:
    distances, locations = parseInput(content)

    # Generate all possible routes (permutations)
    all_routes = itertools.permutations(locations)

    # Find the shortest route by calculating the distance for each
    shortest_distance = min(
        calculateRouteDistance(route, distances) for route in all_routes
    )

    return shortest_distance


def partTwo(content: str) -> int:
    distances, locations = parseInput(content)

    # Generate all possible routes (permutations)
    all_routes = itertools.permutations(locations)

    # Find the longest route by calculating the distance for each
    longest_distance = max(
        calculateRouteDistance(route, distances) for route in all_routes
    )

    return longest_distance


def main():
    # Reading the input file
    fileContent: str = readFile(filepath="day9/input_9.txt")

    # Solution part one (shortest route)
    solutionPartOne: int = partOne(content=fileContent)
    print(f"Solution Part One: {solutionPartOne}")

    # Solution part two (longest route)
    solutionPartTwo: int = partTwo(content=fileContent)
    print(f"Solution Part Two: {solutionPartTwo}")


if __name__ == "__main__":
    main()
