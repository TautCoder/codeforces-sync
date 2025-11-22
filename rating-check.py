import requests
import json
import os
from datetime import datetime

HANDLE = "Taut_Coder"
EMAIL = os.environ.get("MY_EMAIL")
APP_PASSWORD = os.environ.get("MY_APP_PASSWORD")

def send_email(subject, body):
    import smtplib
    from email.mime.text import MIMEText

    msg = MIMEText(body)
    msg["Subject"] = subject
    msg["From"] = EMAIL
    msg["To"] = EMAIL

    with smtplib.SMTP_SSL("smtp.gmail.com", 465) as server:
        server.login(EMAIL, APP_PASSWORD)
        server.sendmail(EMAIL, EMAIL, msg.as_string())

def get_rating():
    URL = f"https://codeforces.com/api/user.info?handles={HANDLE}"
    res = requests.get(URL).json()
    return res["result"][0]["rating"]

def main():
    curr_rating = get_rating()
    print(f"Current rating: {curr_rating}")

    if not os.path.exists("last_rating.json"):
        with open("last_rating.json", "w") as f:
            json.dump({"rating": curr_rating}, f)
        return

    with open("last_rating.json", "r") as f:
        old = json.load(f)["rating"]

    if curr_rating != old:
        diff = curr_rating - old
        sign = "+" if diff > 0 else ""
        msg = f"Your Codeforces rating changed!\nOld: {old}\nNew: {curr_rating}\nChange: {sign}{diff}"
        send_email("Codeforces Rating Update", msg)

    with open("last_rating.json", "w") as f:
        json.dump({"rating": curr_rating}, f)

if __name__ == "__main__":
    main()
