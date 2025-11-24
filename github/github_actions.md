# GitHub Actions

- [GitHub Actions](#github-actions)
  - [Workflows](#workflows)
    - [Name](#name)
    - [On](#on)
    - [Jobs](#jobs)
      - [Run On](#run-on)
      - [Steps](#steps)
      - [Needs](#needs)
  - [Variables and Secrets](#variables-and-secrets)
    - [ප්‍රධාන Context වර්ග](#ප්රධාන-context-වර්ග)
      - [1. **GitHub Context** (`github.*`)](#1-github-context-github)
      - [2. **Runner Context** (`runner.*`)](#2-runner-context-runner)
      - [3. **Env Context** (`env.*`)](#3-env-context-env)
      - [4. **Secrets Context** (`secrets.*`)](#4-secrets-context-secrets)
      - [5. **Steps Context** (`steps.*`)](#5-steps-context-steps)
    - [ප්‍රායෝගික උදාහරණ](#ප්රායෝගික-උදාහරණ)
      - [උදාහරණ 1: Main branch එකට push කරද්දී පමණක් deploy කරන්න](#උදාහරණ-1-main-branch-එකට-push-කරද්දී-පමණක්-deploy-කරන්න)
      - [උදාහරණ 2: Docker image එකට tag කරන්න commit SHA එක use කරලා](#උදාහරණ-2-docker-image-එකට-tag-කරන්න-commit-sha-එක-use-කරලා)
      - [උදාහරණ 3: Pull Request තොරතුරු පෙන්වන්න](#උදාහරණ-3-pull-request-තොරතුරු-පෙන්වන්න)
    - [ඉතාමත් වැදගත් Variables](#ඉතාමත්-වැදගත්-variables)


GitHub Actions යනු GitHub හි ඇතුළතම Continuous Integration (CI) සහ Continuous Deployment (CD) සේවාවකි. GitHub Actions මඟින් ඔබට ඔබේ කේතය සෑදීම, පරීක්ෂා කිරීම සහ නිකුත් කිරීම ස්වයංක්‍රීය කිරීමට හැකියාව ලැබේ.

[Course Repo link](https://github.com/y-developer/devops-directive-github-actions-course.git)

## Workflows

![How to work GitHub Actions](../images/github/how_to_work_github_actions.jpg)

workflow එකක ප්‍රධාන කොටස් 3 ක් ඇත.
- `Name`: workflow එකේ නම
- `On`: workflow එක ක්‍රියාත්මක වීමට හේතු
- `Jobs`: workflow එකේ ක්‍රියාකාරකම්

![basic structure of workflow](../images/github/basic_structure_of_workflow.jpg)

### Name
workflow එකේ නම `name` keyword එක මඟින් සඳහන් කරයි. නමක් නොදැක්වුවහොත්, default ලෙස workflow file එකේ නම භාවිතා කරනු ලැබේ.

### On
`on` keyword එක මඟින් workflow එක ක්‍රියාත්මක වීමට හේතු සඳහන් කරයි. workflow එකක් විවිධ event මත ක්‍රියාත්මක කළ හැකිය. උදාහරණයක් ලෙස, `push`, `pull_request`, `schedule`, `workflow_dispatch` වැනි event මත workflow එක ක්‍රියාත්මක කළ හැකිය. [තවදුරටත් බලන්න](./github_actions_events.md)

### Jobs
workflow එකක් තුළ එක හෝ වැඩි job තිබිය හැක. job එකක් යනු workflow එකේ ක්‍රියාකාරකමක් වන අතර එය run වන්නේ isolated environment එකක (Ubuntu, Windows, MacOS) යටතේය.

#### Run On
`runs-on` keyword එක මඟින් job එක run වීමට අවශ්‍ය operating system එක සඳහන් කරයි. උදාහරණයක් ලෙස `ubuntu-latest`, `windows-latest`, `macos-latest` වැනි operating system එකක් සඳහන් කළ හැක.

#### Steps
job එකක් තුළ එක හෝ වැඩි steps තිබිය හැක. step එකක් යනු job එකේ ක්‍රියාකාරකමක් වන අතර එය run වන්නේ job එකේ defined compute environment එක තුළය.

steps වර්ග දෙකක් පවතී. 
1. `uses`: GitHub Action එකක් භාවිතා කිරීම
2. `run`: command එකක් run කිරීම. 

```yaml
jobs:
  <job_id>:
    runs-on: <run වෙන්නේ කොහොද? ubuntu, windows, macos>
    steps:

        # action steps examples
      - name: <step name>
        uses: <action එකක් භාවිතා කරනවා නම් එහි නම>
        with:
          <parameter_name>: <parameter_value>

        # run step example
      - name: <step name>
        run: <command එකක් භාවිතා කරනවා නම් එය>
        shell: <command එක run කිරීමට භාවිතා කරන shell එක (default: bash) (ex: python, bash, sh, pwsh, cmd)>
```

#### Needs

එක job එක්ක තවත් job එකක් depend වෙන්න ඕන නම් `needs` keyword එක භාවිතා කරන්න පුළුවන්. 

```yaml
name: Workflows, Jobs, and Steps

on:
  workflow_dispatch:
jobs:
  job-1:
    runs-on: ubuntu-24.04
    steps:
      - run: echo "A job consists of"
      - run: echo "one or more steps"
      - run: echo "which run sequentially"
      - run: echo "within the same compute environment"
  job-2:
    runs-on: ubuntu-24.04
    steps:
      - run: echo "Multiple jobs can run in parallel"
  job-3:
    runs-on: ubuntu-24.04
    needs:
      - job-1 # This job depends on job-1
      - job-2 # Also this job depends on job-2
    steps:
      - run: echo "They can also depend on one another..."
  job-4:
    runs-on: ubuntu-24.04
    needs:
      - job-2 # This job depends on job-2
      - job-3 # Also this job depends on job-3
    steps:
      - run: echo "...to form a directed acyclic graph (DAG)"
```

![dependent jobs](../images/github/need-jobs.jpg)

## Variables and Secrets

**Context variables** කියන්නේ GitHub Actions workflow එකක් run වෙන විට ස්වයංක්‍රීයව ලබාදෙන තොරතුරු වලට කියන නමයි. ඔබේ workflow එක තුළ ඔබට repository එක ගැන, commit එක ගැන, user ගැන වගේ විවිධ තොරතුරු භාවිතා කරන්න පුළුවන්.

### ප්‍රධාන Context වර්ග

#### 1. **GitHub Context** (`github.*`)
Repository එක සහ workflow එක ගැන තොරතුරු .

```yaml
- name: තොරතුරු පෙන්වන්න
  run: |
    echo "Repository එක: ${{ github.repository }}"
    echo "Branch එක: ${{ github.ref_name }}"
    echo "Commit SHA: ${{ github.sha }}"
    echo "User: ${{ github.actor }}"
```

**උදාහරණ output:**
```
Repository එක: myusername/myproject
Branch එක: main
Commit SHA: abc123def456
User: octocat
```

#### 2. **Runner Context** (`runner.*`)
Workflow එක run වෙන server එක ගැන තොරතුරු.

```yaml
- name: Runner තොරතුරු
  run: |
    echo "Operating System: ${{ runner.os }}"
    echo "Architecture: ${{ runner.arch }}"
```

#### 3. **Env Context** (`env.*`)
GitHub Actions workflow එකක් තුළ environment variables භාවිතා කළ හැක. Environment variables මඟින් workflow එකේ steps අතර දත්ත හුවමාරු කිරීම පහසු වේ. Environment variables define කිරීම සඳහා `env` keyword එක භාවිතා කරයි. [තවදුරටත් බලන්න](./github_actions_env_variables.md)

```yaml
env:
  APP_NAME: MyApp
  VERSION: 1.0.0

jobs:
  build:
    steps:
      - name: App එක build කරන්න
        run: echo "Building ${{ env.APP_NAME }} version ${{ env.VERSION }}"
```

#### 4. **Secrets Context** (`secrets.*`)
GitHub Actions workflow එකක් තුළ sensitive data (e.g., API keys, passwords) සහ non-sensitive configuration data (e.g., deployment environments, feature flags) භාවිතා කිරීමට Secrets සහ Variables භාවිතා කළ හැක. 

මෙය 
`https://github.com/organization/<your-organization>/settings/secrets/actions` 

හෝ 

`Settings > Secrets and variables > Actions` 

යන මාර්ගයෙන් කළ හැක. Secrets සහ Variables workflow එකේ steps අතර environment variables ලෙස භාවිතා කළ හැක. Secrets සහ Variables define කිරීම සඳහා `secrets` සහ `vars` keywords භාවිතා කරයි.

```yaml
- name: Docker login කරන්න
  run: |
    docker login -u ${{ secrets.DOCKER_USERNAME }} \
                 -p ${{ secrets.DOCKER_PASSWORD }}
```

#### 5. **Steps Context** (`steps.*`)
පෙර step එකක output එක භාවිතා කරන්න.

```yaml
- name: Version එක හොයන්න
  id: get_version
  run: echo "version=1.2.3" >> $GITHUB_OUTPUT

- name: Version එක පෙන්වන්න
  run: echo "අපේ version එක ${{ steps.get_version.outputs.version }}"
```

### ප්‍රායෝගික උදාහරණ

#### උදාහරණ 1: Main branch එකට push කරද්දී පමණක් deploy කරන්න

```yaml
- name: Production එකට deploy කරන්න
  if: github.ref == 'refs/heads/main'
  run: ./deploy.sh
```

#### උදාහරණ 2: Docker image එකට tag කරන්න commit SHA එක use කරලා

```yaml
- name: Docker image build කරන්න
  run: |
    docker build -t myapp:${{ github.sha }} .
    docker build -t myapp:latest .
```

#### උදාහරණ 3: Pull Request තොරතුරු පෙන්වන්න

```yaml
- name: PR තොරතුරු
  if: github.event_name == 'pull_request'
  run: |
    echo "PR එක කළේ: ${{ github.actor }}"
    echo "Source branch: ${{ github.head_ref }}"
    echo "Target branch: ${{ github.base_ref }}"
```

### ඉතාමත් වැදගත් Variables

| Variable               | අර්ථය             | උදාහරණය                 |
| ---------------------- | ---------------- | ---------------------- |
| `github.repository`    | Repository නම    | `octocat/Hello-World`  |
| `github.ref_name`      | Branch/tag නම    | `main`                 |
| `github.sha`           | Commit SHA       | `abc123...`            |
| `github.actor`         | User නම          | `octocat`              |
| `github.event_name`    | Event එක         | `push`, `pull_request` |
| `runner.os`            | Operating System | `Linux`, `Windows`     |
| `secrets.GITHUB_TOKEN` | Auto token       | `***`                  |

[තවදුරටත් බලන්න](./github_actions_context_variables.md)
