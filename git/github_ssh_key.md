

# Create a New Dedicated Key on That Server

1. Keep the old key in place (do not overwrite if you still need it).
2. Generate a new Ed25519 key just for GitHub:

```
ssh-keygen -t ed25519 -C "github-<hostname>-$(date +%Y%m%d)" -f ~/.ssh/id_ed25519_github
```

(If Ed25519 unsupported: `ssh-keygen -t rsa -b 4096 -C "github-<hostname>-$(date +%Y%m%d)" -f ~/.ssh/id_rsa_github`)

3. Restrict permissions (usually done automatically):

```
chmod 700 ~/.ssh
chmod 600 ~/.ssh/id_ed25519_github
chmod 644 ~/.ssh/id_ed25519_github.pub
```

4. Add to ssh-agent (if you use one):

```
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519_github
```

5. Create (or update) `~/.ssh/config` entry:

```
Host github.com
  HostName github.com
  User git
  IdentityFile ~/.ssh/id_ed25519_github
  IdentitiesOnly yes
```

6. Add the public key (`id_ed25519_github.pub`) to GitHub:
   - If ONLY one repo access is needed → add as a Deploy Key in that repo (Settings → Deploy keys → Add deploy key).
   - If broad access needed via your personal account (less ideal on a server) → Settings → SSH and GPG keys → New SSH key.

7. Test:

```
ssh -T git@github.com
```

You should see:  
`Hi <username>! You've successfully authenticated, but GitHub does not provide shell access.`

---

## If You Already Uploaded the Old id_rsa.pub

1. Generate and add the new dedicated key (steps above).
2. Confirm it works: `ssh -T git@github.com`.
3. Remove the old key from GitHub UI to reduce risk.
4. (Optional) Rename old files if you want to avoid accidental use:

```
mv ~/.ssh/id_rsa ~/.ssh/id_rsa_legacy
mv ~/.ssh/id_rsa.pub ~/.ssh/id_rsa_legacy.pub
```

5. Ensure your config explicitly points to the new key (so Git doesn’t silently fallback).

---

## Using a Deploy Key Instead (Single Repo)

If the server only needs repo `owner/repo`:

1. Generate key (as above) but maybe name it per repo:

```
ssh-keygen -t ed25519 -C "deploy-owner-repo-$(date +%Y%m%d)" -f ~/.ssh/deploy_owner_repo_ed25519
```

2. Add to `~/.ssh/config` (optional but nice):

```
Host github-repo-owner-repo
  HostName github.com
  User git
  IdentityFile ~/.ssh/deploy_owner_repo_ed25519
  IdentitiesOnly yes
```

3. In the repo’s GitHub UI: Settings → Deploy keys → Add deploy key → paste `.pub`. Grant write access only if the server must push.
4. Clone using the normal host `github.com` (config picks key), or with an alias:

```
git clone git@github.com:owner/repo.git
```

Deploy key is isolated: if compromised, attacker only gets that single repo.

---

## Avoid These Mistakes

- Never upload the PRIVATE key (`id_rsa`, `id_ed25519`)—only the `.pub`.
- Don’t reuse one private key across many unrelated services.
- Don’t store your personal account’s powerful key on a shared or less-secure production server.
- Don’t overwrite existing keys unless you know every service that depends on them.

---

## Quick Validation Checklist

- Public key you added matches `cat <key>.pub`
- `ssh -T git@github.com` greets the expected username (or succeeds for deploy key usage)
- `~/.ssh/config` has `IdentitiesOnly yes` to prevent other keys interfering
- Key has a passphrase if it’s on a sensitive host (balance automation vs. security) OR use an agent / key manager

---

