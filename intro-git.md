# 🧭 Git Foundation

---

## 🗂️ GIT REPOSITORY

| Command        | Detail |
|----------------|------------|
| `git init`     | Creates a `.git` directory in the folder and turns it into a Git repo—start a fresh repository. |
| `git remote add alias_repo URL` | Links the local repository to a remote URL (e.g., GitHub, GitLab). |
| `git clone`    | Copies the entire setup (commits, branches, files) from a remote repo into the machine. |

!Every git repository has its OWN branch/es with commit history.

## CONNECTION

### SSH - SSH KEY
```bash
ssh-keygen -t ed25519 -C "email@example.com"      # -t keytype, -C label
~/.ssh/id_ed25519                                 # path to the key pair
ssh -T git@github.com                             # test the connection
```
SSH is like having a private tunnel between client and server, it uses a pair of cryptographic keys to silently prove the identity.

### HTTPS - PERSONAL ACCESS TOKEN
```bash
github_settings
choose "fine-grained" or "classic token"          # classic: general scope - entire account; fine-grained detailed - specific repos
get scopes (permission)
generate and copy
```
PAT is like a secure and customizable password, it’s used to authenticate with services.

## 🌿 BRANCH

### Types
```bash
git branch                               # shows local branches
git branch -r                            # shows remote branches
git branch -a                            # shows all branches
```

* branch                                       # current branch 
repo_alias/HEAD -> repo_alias/remote_branch    # remote's default branch

### Configuration
```bash
git branch -M main                       # rename current branch to 'main'
git branch -m master main                # rename branch 'master' to 'main'
git checkout (-b) branch                 # switch to a branch, -b create branch
```
Combination: `git checkout -b local_branch remote_alias/remote_branch` creates local_branch -> sets it to track remote_branch -> copies commit history -> switches to local_branch.

### Operation
```bash
git branch new_branch                    # create local branch
git branch -d branch-name                # delete local branch
git push origin --delete branch-name     # delete remote branch
```

---

## 🌍 Local vs Remote Branches

| Concept       | Local Branch       | Remote Branch         |
|---------------|--------------------|------------------------|
| Location      | Your machine        | Remote server (e.g., GitHub) |
| Created By    | `git checkout -b`   | ONLY `git push` from local  |
| Shared?       | No (until pushed)   | Yes (visible to others) |
| Updated By    | `git commit`        | `git push` / `git fetch` |

---

## 🚀 PUSH

Git push command pushes commits, files, history from LOCAL to REMOTE branch.

### Typical workflow
```bash
git status
git add changes                                                # stage files
git commit -m "your message"                                   # RECORD and ADD snapshot to default local_branch (create) or specified one (apply) 
git push -u repo_alias (local_branch:)remote_branch            # push local to remote, -u set tracking, create repo_alias/repo_branch if it doesnt exist
git push --force ... ... ...                                   # overwrite the remote_branch with the local_branch
```
!Push is allowed only if the local branch is ahead of the remote.
Git add + git commit -> creates a local branch if there isn't any.

---

## 📦 SUBPUSH

### Split and push a subdirectory
```bash
git subtree split -P path_to_directory -b new_branch
git ls-tree -r --name-only new_branch_name                    # list files and directories in a branch
git push repo_alias new_branch:main                           # local_branch:remote_branch
```
Creates a subtree split for the directory and pushes that split as a separate branch named `main`.

---

## 🔄 REQUEST

### Non-intrusive: Fetch updates
```bash
git fetch repo_alias branch
```
Grabs new commits from the remote without merging—like observing quietly.

git stash stach the local changes

### Streamlined Update: Fetch + Rebase
```bash
git rebase repo_alias/remote_branch
```
Rewrites the local branch by reaplying the commits on top of remote branch. The history is linear (rewritten).

### Traditional Update: Fetch + Merge
```bash
git merge repo_alias/remote_branch
```
Create a new merge commit in the local branch by combining the changes from both banches. The history includes merge commits (preserved).


### Full update: Pull = Fetch + Merge
```bash
git pull remote_alias branch
```
Brings remote changes into your current branch—fetches and merges together.
It assumes the local repo has a local branch already.

---

## 📚 LOG
```bash
git log --oneline --graph --decorate --all branch_name

```
| Flag           | Description                                                  |
|----------------|--------------------------------------------------------------|
| `--oneline`    | Displays each commit as a single concise line.               |
| `--graph`      | Adds an ASCII graph showing branches and merges.             |
| `--decorate`   | Shows branch names and tags next to commit messages.         |
| `--all`        | Includes commits from all branches, not just the current one.|

## 🏁 Repository Creation Examples

### Option 1: Create a new repo and push
```bash
echo "" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add repo_alias repo-url
git push -u repo_alias main
```

### Option 2: Push an existing repository
```bash
git remote add repo_alias repo-url
git branch -M main
git push -u repo_alias main
```
