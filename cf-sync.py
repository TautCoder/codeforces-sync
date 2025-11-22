import requests
import time
import json
import os

HANDLE = "Taut_Coder"  # your Codeforces handle
OUTPUT_DIR = "cf_submissions"

if not os.path.exists(OUTPUT_DIR):
    os.makedirs(OUTPUT_DIR)

def fetch_submissions():
    url = f"https://codeforces.com/api/user.status?handle={HANDLE}&from=1&count=20"
    r = requests.get(url)
    data = r.json()

    if data["status"] != "OK":
        print("API Error:", data)
        return []

    return data["result"]

def save_submission(sub):
    problem = sub["problem"]
    contest_id = problem.get("contestId", "misc")
    index = problem.get("index", "X")
    name = problem.get("name", "unknown")
    lang = sub.get("programmingLanguage", "text")

    code = sub.get("sourceCode", None)

    # If Codeforces API doesn't send source, skip
    if code is None:
        return False

    folder = f"{OUTPUT_DIR}/{contest_id}{index}"
    if not os.path.exists(folder):
        os.makedirs(folder)

    filename = f"{folder}/{sub['id']}.txt"

    with open(filename, "w", encoding="utf-8") as f:
        f.write(code)

    return True

def main():
    print("Fetching submissions...")
    subs = fetch_submissions()
    count = 0

    for s in subs:
        if s["verdict"] == "OK":  # only accepted ones
            if save_submission(s):
                count += 1

    print(f"Saved {count} submissions")

if __name__ == "__main__":
    main()
