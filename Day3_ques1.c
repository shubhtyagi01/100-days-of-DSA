# Read input
n = int(input())
arr = list(map(int, input().split()))
k = int(input())

comparisons = 0
found_index = -1

# Linear search
for i in range(n):
    comparisons += 1
    if arr[i] == k:
        found_index = i
        break

# Output result
if found_index != -1:
    print(f"Found at index {found_index}")
else:
    print("Not Found")

print(f"Comparisons = {comparisons}")
