import os
import requests
import hashlib
import hmac
import time
import json

CF_API_KEY = os.getenv("CF_API_KEY")
CF_API_SECRET = os.getenv("CF_API_SECRET")
CF_HANDLE = os.getenv("CF_HANDLE")

# Create API signature
def create_api_signature(params):
    rand = "123456"
    params_sorted = "&".join([f"{k}={v}" for k, v in sorted(params.items())])
    msg = f"{rand}/api/{method}?{params_sorted}#{CF_API_SECRET}".encode()
    sig = hashlib.sha512(msg).hexdigest()
    return f"{rand}{sig}"

def get_submissions():
    global method
    method = "user.status"

    params = {
        "handle": CF_HANDLE,
        "apiKey": CF_API_KEY,
        "time": int(time.time())
    }

    params["apiSig"] = create_api_signature(params)

    url = f"https://codeforces.com/api/{method}"
    r = requests.get(url, params=params)
    data = r.json()

    return data["result"]

def save_code(sub):
    contest_id = sub["contestId"]
    problem_index = sub["problem"]["index"]
    lang = sub["programmingLanguage"]

    # detect file extension based on language
    if "GNU C++" in lang:
        ext = "cpp"
    elif "Python" in lang:
        ext = "py"
    else:
        ext = "txt"

    folder = f"contests/{contest_id}"
    os.makedirs(folder, exist_ok=True)

    file_path = f"{folder}/{problem_index}.{ext}"

    # Save code only once
    if os.path.exists(file_path):
        return

    # Fetch submission code
    url = f"https://codeforces.com/contest/{contest_id}/submission/{sub['id']}"
    html = requests.get(url).text

    start = html.find("sourceCode'>") + len("sourceCode'>")
    end = html.find("</pre>", start)
    code = html[start:end]

    # Fix HTML escape sequences
    code = code.replace("&lt;", "<").replace("&gt;", ">").replace("&amp;", "&")

    with open(file_path, "w", encoding="utf-8") as f:
        f.write(code)

def main():
    subs = get_submissions()
    print(f"Found {len(subs)} submissions")

    for sub in subs:
        if sub["verdict"] == "OK":
            save_code(sub)

if __name__ == "__main__":
    main()
