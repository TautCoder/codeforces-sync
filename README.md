# 📄 **README**

**Project: Codeforces Auto Sync**

---

# **Codeforces Auto Sync**

**Codeforces Auto Sync** is an automated system that continuously monitors your Codeforces account and synchronizes every new accepted submission directly into your GitHub repository.

This workflow eliminates the need for manual file creation, committing, or pushing from your local machine. All new Codeforces solutions are automatically fetched, saved, and version-controlled — fully hands-free.

---

## **Features**

* **Automatic Submission Fetching**
  Fetches all new Codeforces submissions for the configured handle.

* **GitHub Repository Synchronization**
  New accepted solutions are automatically committed and pushed into the repository.

* **Organized File Structure**
  Submissions are saved using clear naming conventions (ProblemName.cpp, etc.).

* **Secure API Access**
  Uses GitHub Actions Secrets to store the Codeforces API key, secret, and GitHub token.

* **Scheduled or Manual Execution**
  Automatically runs at fixed intervals or can be triggered manually through GitHub Actions.

---

## **How It Works**

The workflow uses:

* **GitHub Actions** to run on a schedule
* A **Python script** (`sync.py`) to:

  * Retrieve Codeforces submissions
  * Detect new problems that are not yet in the repository
  * Download and store the solution code
  * Commit and push changes automatically

---

## **Repository Structure**

```
/
├── .github/
│   └── workflows/
│       └── cf-sync.yml
├── Code-Forces/
│   └── <synced files appear here>
├── sync.py
└── README.md
```

---

## **Setup Instructions**

### **1. Add GitHub Secrets**

Configure the following secrets under:

**GitHub → Repository Settings → Secrets and variables → Actions**

| Secret Name     | Description                                  |
| --------------- | -------------------------------------------- |
| `CF_API_KEY`    | Codeforces API key                           |
| `CF_API_SECRET` | Codeforces API secret                        |
| `CF_HANDLE`     | Codeforces username                          |
| `GH_TOKEN`      | GitHub fine-grained token (repo: read/write) |

---

### **2. Workflow Automation**

The `cf-sync.yml` workflow handles:

* Code checkout
* Installing dependencies
* Running the sync script
* Committing updated submissions

The workflow runs automatically based on its defined schedule or can be triggered manually.

---

## **Usage**

Once setup is completed:

* Submit any solution on Codeforces
* GitHub Actions automatically detects it
* Your repository updates with the new file within minutes

No manual git commands required.

---

## **Status**

This repository is actively maintained and updated as new solutions are submitted to Codeforces.

---

## **License**

This project is provided without explicit license.
Please contact the author before reusing significant components.

