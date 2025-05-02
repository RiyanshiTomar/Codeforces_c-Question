import requests
from collections import Counter
import matplotlib.pyplot as plt

handle = "Riyanshi-Tomar"  # 🔁 Replace with your Codeforces handle

# Step 1: Get submission data
url = f"https://codeforces.com/api/user.status?handle={handle}&from=1&count=10000"
res = requests.get(url).json()

# Step 2: Collect ratings of accepted problems
if res['status'] == 'OK':
    submissions = res['result']
    solved = set()
    ratings = []

    for sub in submissions:
        if sub['verdict'] == 'OK':
            problem = sub['problem']
            key = f"{problem.get('contestId', 0)}-{problem.get('index', '')}"
            if key not in solved:
                if 'rating' in problem:
                    ratings.append(problem['rating'])
                    solved.add(key)

    # Step 3: Count and plot
    count_by_rating = Counter(ratings)
    x = sorted(count_by_rating.keys())
    y = [count_by_rating[r] for r in x]

    plt.bar(x, y, width=50, color='skyblue')
    plt.xlabel("Problem Rating")
    plt.ylabel("Number of Problems Solved")
    plt.title(f"Problem Rating Distribution for {handle}")
    plt.grid(True, axis='y')
    plt.xticks(x, rotation=45)
    plt.tight_layout()
    plt.show()
else:
    print("Error fetching submissions:", res.get("comment", "Unknown error"))
