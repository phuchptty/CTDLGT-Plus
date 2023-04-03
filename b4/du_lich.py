import sys

def tsp_greedy(distances):
    # lấy số thành phố
    n = len(distances)
    
    # khởi tạo danh sách các thành phố và đánh dấu thành phố đầu tiên là đã đi qua
    visited = [False] * n
    visited[0] = True
    
    # đặt thành phố hiện tại là thành phố đầu tiên và tổng khoảng cách = 0
    curr_city = 0
    total_distance = 0
    path = ["1"]

    # Loop qua các thành phố còn lại và tìm thành phố có khoảng cách ngắn nhất với thành phố hiện tại
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