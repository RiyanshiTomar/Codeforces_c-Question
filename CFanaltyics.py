import requests
from collections import Counter

# 🔁 1. Replace this with your Codeforces handle
HANDLE = "Riyanshi-Tomar"  # <<< REPLACE with your Codeforces handle (e.g., "your_username")

# 🔹 2. Get basic user info
user_url = f"https://codeforces.com/api/user.info?handles={HANDLE}"
user_response = requests.get(user_url).json()

if user_response["status"] == "OK":
    user = user_response["result"][0]
    print(f"User: {user['handle']}")
    print(f"Rating: {user.get('rating', 'Unrated')}")
    print(f"Rank: {user.get('rank', 'Unranked')}")
else:
    print("Error fetching user info:", user_response["comment"])

# 🔹 3. Get submission history
sub_url = f"https://codeforces.com/api/user.status?handle={HANDLE}&from=1&count=1000"
sub_response = requests.get(sub_url).json()

if sub_response["status"] == "OK":
    submissions = sub_response["result"]

    verdicts = Counter()
    solved = set()

    for sub in submissions:
        verdict = sub.get("verdict", "N/A")
        problem_id = f"{sub['problem']['contestId']}-{sub['problem']['index']}"
        if verdict == "OK":
            solved.add(problem_id)
        verdicts[verdict] += 1

    print("\nTotal unique problems solved:", len(solved))
    print("Submission verdicts breakdown:")
    for verdict, count in verdicts.items():
        print(f"  {verdict}: {count}")
else:
    print("Error fetching submissions:", sub_response["comment"])
