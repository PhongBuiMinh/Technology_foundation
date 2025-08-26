# 🧭 Git Foundation

---

## 🗂️ GIT REPOSITORY

| Command        | Detail |
|----------------|------------|
| `git init`     | Creates a `.git` directory in the folder and turns it into a Git repo—start a fresh repository. |
| `git remote add <remote-repo> URL` | Links the local repository to a remote URL (e.g., GitHub, GitLab). |
| `git clone`    | Copies the entire setup (commits, branches, files) from a remote repo into the machine. |
| `git remote remove <remote-repo>`     | Removes a reference to a remote repository. |
| `rm -rf .git`     | Deletes the entire Git history and configuration for the current folder (project). |

❗Every .git repository has its OWN branch/es with commit history.

## 🌐 CONNECTION

### SSH - SSH KEY
```bash
ssh-keygen -t ed25519 -C "email@example.com"      # -t keytype; -C label
~/.ssh/id_ed25519                                 # path to the key pair
ssh -T git@github.com                             # test the connection
```
❕SSH is like having a private tunnel between client and server, it uses a pair of cryptographic keys to silently prove the identity.

### HTTPS - PERSONAL ACCESS TOKEN
```bash
1. github settings
2. choose "fine-grained" or "classic" token          # classic: general scope -> entire account; fine-grained detailed -> specific repos
3. get scopes (permission)
4. generate and copy
```
❕PAT is like a secure and customizable password, it’s used to authenticate with services.

## 🌿 BRANCH

### Types
```bash
git branch                                           # show local branches
git branch -r                                        # show remote branches
git branch -a                                        # show all branches
```

\* branch                                      # current branch   
repo_alias/HEAD -> repo_alias/remote_branch    # remote's default branch   
branch                                         # indicate local branch   
repo/branch                                    # indicate remote branch

### Configuration
```bash
git branch -M <new-name>                             # rename current branch to 'new name'
git branch -m <old-branch> <new-branch>              # rename branch 'old' to 'new'
git checkout (-b) <branch>                           # switch to branch; -b create branch
```
Combination: `git checkout -b local_branch remote_alias/remote_branch` creates local_branch -> sets it to track remote_branch -> copies commit history -> switches to local_branch.

### Operation
```bash
git branch <new-local-branch>                        # create local branch
git branch -d <local-branch>                         # delete local branch
git push <remote-repo> --delete <remote-branch>      # delete remote branch
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
git add changes                                                    # stage files
git commit -m "message"                                            # RECORD and ADD snapshot to default local branch (create) or specified one (apply) 
git push -u <remote-repo> <(local-branch:)remote-branch>           # push local branch to remote; -u set tracking; create repo_alias/repo_branch if it doesnt exist
git push --force <remote-repo> <remote-branch>                     # overwrite remote branch with local branch
```
❗Push is allowed only if the local branch is ahead of the remote.   
Git add + git commit -> creates a local branch if there isn't any.

---

## 📦 SUBPUSH

### Split and push a subdirectory
```bash
git filter-repo --path <path-to-directory/unwanted-file> --invert-paths --force   # remove unwanted file from a branch and REWRITE history
git subtree split -P <path-to-directory> -b <new-local-branch>                    # create a new local branch with the history of dir from the CURRENT branch
git ls-tree -r --name-only <new-local-branch>                                     # list files and directories in a branch
git push <remote-repo> <new-local-branch>:<remote-branch>         
```
Create a subtree split for the directory and pushes that split as a new separate branch.   
❗Remove files and their history only on temporary branch.

---

## 🔄 REQUEST

### Non-intrusive: Fetch updates
```bash
git fetch <remote-repo> <remote-branch>
```
Grab new commits from the remote without merging—like observing quietly.

git stash stach the local changes

### Streamlined Update: Fetch + Rebase
```bash
git rebase <upstream>       # move current branch’s commits to follow the latest commits from source branch
```
Rewrite the local branch by reaplying the commits on top of remote branch. The history is linear (rewritten).

### Traditional Update: Fetch + Merge
```bash
git merge <upstream>        # merge source branch into current branch
```
Create a new merge commit in the local branch by combining the changes from both banches. The history includes merge commits (preserved).


### Full update: Pull = Fetch + Merge
```bash
git pull <remote-repo> <remote-branch>
```
Bring remote changes into your current branch—fetches and merges together.   
It assumes the local repo has a local branch already.

---

## 📚 LOG
```bash
git log --oneline --graph --decorate --all <upstream>

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
