# 🧭 Git Foundation

---

## 🗂️ GIT REPOSITORY

| Command        | Detail |
|----------------|------------|
| `git init`     | Creates a `.git` directory in the folder and turns it into a Git repo—start a fresh repository. |
| `git remote add <remote-repo> <URL>` | Links the local repository to a remote URL (e.g., GitHub, GitLab). |
| `git clone <URL> <project-name>`    | Copies the entire setup (commits, branches, files) from a remote repo into the machine. |
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
git branch -vv                                       # check what local branch is tracking
   
\* branch                                            = current branch   
repo_alias/HEAD -> repo_alias/remote_branch          = remote's default branch   
branch                                               = indicate local branch   
repo/branch                                          = indicate remote branch
```
❗Remote branches are read only references.

### Configuration
```bash
git branch <new-branch>                              # create new branch pointing to the current commits
git branch -M <new-name>                             # rename current branch to 'new name'
git branch -m <old-branch> <new-branch>              # rename branch 'old' to 'new'
git checkout <upstream>                              # switch to source branch
```

### Operation
```bash
git branch <new-local-branch>                                               # create local branch
git branch -d <local-branch>                                                # delete local branch
git checkout -b local_branch remote_alias/remote_branch                     # create local branch -> sets it to track remote branch -> copies remote's commit history -> switches to new local branch.   
git branch --set-upstream-to=<remote-repo>/<remote-branch> <local-branch>   # set tracking.
git push <remote-repo> --delete <remote-branch>                             # delete remote branch
git remote set-head origin -a                                               # update local git to match repo's default branch   
```
❕Switch to another branch will update the workspace.

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
git add <files>                                                    # stage files
git restore --staged <files>                                       # unstage files
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

### Full update: Pull = Fetch + Merge / Rebase / Fast-Forward
```bash
git pull <remote-repo> <remote-branch>    # fetch + merge by default
git pull --no-rebase                      # fetch + merge
git pull --rebase
git pull --ff-only
git pull <remote-repo> <remote-branch> --allow-unrelated-histories
```
Bring remote changes into your current branch—fetches and merges together, by default.   
It assumes the local repo has a local branch already.

### Stash
```bash
git stash                                 # save tracked files and clear from working directory
git stach list
git stash show -p
git shash pop                             # bring stashed back into the CURRENT branch
```
❗Should stay on the same branch before stash pop.

### Differences in both branches

| Problem       | Description       | Git action         |
|---------------|--------------------|------------------------|
| Local Changes Don’t Conflict      | local and remote changed but they touch different files or lines        | changes stay intact |
| Local Changes Do Conflict    | local and remote changed the same lines in the same files   |  wait for developer's decision |
| Untracked Files       | files not added to local branch (Git)   | files are untouched in any case |
| Unrelated Histories    | local and remote branch were created independently (no shared commits)        | need flag to unblock |

### 🔧 Set a default behavior (optional)
```bash
git config pull.rebase false              # always merge
git config pull.rebase true               # always rebase
git config pull.ff only                   # only fast-forward 
git config --global <flag>                # apply setting to across all repos
```

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
git commit -m "message"
git branch -M main
git remote add <remote-repo> <repo-url>
git push -u <remote-repo> <remote-branch>
```

### Option 2: Push an existing repository
```bash
git remote add <remote-repo> <repo-url>
git branch -M main
git push -u <remote-repo> main
```
