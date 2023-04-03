import sys

# Define the TSP greedy algorithm
def tsp_greedy(distances):
    # Get the number of cities
    n = len(distances)
    
    # Initialize the list of visited cities and mark the first city as visited
    visited = [False] * n
    visited[0] = True
    
    # Set the current city to the first city and the total distance traveled to zero
    curr_city = 0
    total_distance = 0
    path = ["1"]

    # Loop over the remaining n-1 cities and find the closest unvisited city to the current city
    for i in range(n-1):
        next_city = -1
        min_distance = sys.maxsize

        for j in range(n):
            # If city not visited and distance lower than min_distance
            if not visited[j] and distances[curr_city][j] < min_distance:
                next_city = j
                min_distance = distances[curr_city][j]

        # Mark the selected city as visited, update the current city, and add the distance to the total distance traveled
        visited[next_city] = True
        curr_city = next_city
        total_distance += min_distance

        path.append("{}({})".format(curr_city + 1, min_distance))

    # Add the distance back to the first city to complete the loop and return the total distance traveled
    path.append("1({})".format(distances[curr_city][0]))
    total_distance += distances[curr_city][0]

    return total_distance, path

# Read the input matrix of distances
n = int(input())

distances = []

for i in range(n):
    row = list(map(int, input().split()))
    distances.append(row)

# Solve the TSP using the greedy algorithm starting from the first city
min_distance, tsp_path = tsp_greedy(distances)

# Print the minimum distance traveled by the salesman
print("Tong chi phi={}".format(min_distance))
print("->".join(tsp_path))