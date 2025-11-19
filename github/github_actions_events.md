# Github Actions Events

[Official Documentation](https://docs.github.com/en/actions/reference/workflows-and-actions/events-that-trigger-workflows)

- [Github Actions Events](#github-actions-events)
  - [Manual \& Scheduled Triggers](#manual--scheduled-triggers)
    - [**`workflow_dispatch`**](#workflow_dispatch)
    - [**`schedule`**](#schedule)
    - [**`repository_dispatch`**](#repository_dispatch)
    - [**`workflow_call`**](#workflow_call)
    - [**`workflow_run`**](#workflow_run)
  - [Code Changes](#code-changes)
    - [**`push`**](#push)
    - [**`create`**](#create)
    - [**`delete`**](#delete)
    - [**`branch_protection_rule`**](#branch_protection_rule)
    - [**`merge_group`**](#merge_group)
  - [Pull Requests](#pull-requests)
    - [**`pull_request`**](#pull_request)
    - [**`pull_request_target`**](#pull_request_target)
    - [**`pull_request_review`**](#pull_request_review)
    - [**`pull_request_review_comment`**](#pull_request_review_comment)
    - [**`pull_request_comment`**](#pull_request_comment)
  - [Issues \& Project Management](#issues--project-management)
    - [**`issues`**](#issues)
    - [**`issue_comment`**](#issue_comment)
    - [**`label`**](#label)
    - [**`milestone`**](#milestone)
    - [**`project`**](#project)
    - [**`discussion`**](#discussion)
    - [**`discussion_comment`**](#discussion_comment)
  - [Releases \& Deployments](#releases--deployments)
    - [**`release`**](#release)
    - [**`deployment`**](#deployment)
    - [**`deployment_status`**](#deployment_status)
    - [**`status`**](#status)
    - [**`check_run`**](#check_run)
    - [**`check_suite`**](#check_suite)
    - [**`page_build`**](#page_build)
    - [**`registry_package`**](#registry_package)
  - [Repository Activity](#repository-activity)
    - [**`fork`**](#fork)
    - [**`watch`**](#watch)
    - [**`public`**](#public)
    - [**`gollum`**](#gollum)


## Manual & Scheduled Triggers

### **`workflow_dispatch`**
GitHub UI එකෙන් හෝ API එකෙන් manually workflow එකක් run කිරීමට ඉඩ දෙයි. අතින් ක්‍රියාත්මක කළ හැකි trigger එකකි.

`inputs` භාවිතා කරමින් workflow run කරන විට parameters ලබා ගත හැකිය:

```yaml
on:
  workflow_dispatch:
    inputs:
      name:
        description: 'පුද්ගලයාගේ නම'
        required: true
        default: 'World'
        type: string
      environment:
        description: 'Deploy කළ යුතු environment එක'
        required: true
        type: choice
        options:
        - development
        - staging
        - production
      debug_enabled:
        description: 'Debug mode සක්‍රීය කරන්නද?'
        required: false
        type: boolean
        default: false
      log_level:
        description: 'Log level එක තෝරන්න'
        required: false
        type: choice
        options:
        - info
        - warning
        - debug
```

**වැදගත් input types:**
- `string` - Text input එකක්
- `boolean` - True/False checkbox එකක්
- `choice` - Dropdown selection එකක්
- `environment` - GitHub environment එකක් තෝරන්න

Workflow තුළ inputs භාවිතා කිරීම:

```yaml
jobs:
  greet:
    runs-on: ubuntu-latest
    steps:
    - name: Greet user
      run: echo "Hello ${{ inputs.name }}"
    - name: Deploy to environment
      run: echo "Deploying to ${{ inputs.environment }}"
```

### **`schedule`**
නිශ්චිත වේලාවකට cron syntax භාවිතයෙන් workflow ස්වයංක්‍රීයව ධාවනය කරයි. නිත්‍ය කාර්යයන් සඳහා භාවිතා වේ.

`cron` syntax එකක් ලෙස පහත ආකාරයට භාවිතා කළ හැකිය:

```yaml
on:
  schedule:
    - cron: '0 0 * * *'  # දිනපතා මධ්‍යහ්නට ක්‍රියාත්මක වේ (UTC timezone)
    - cron: '0 9 * * 1'  # සෑම සඳුදා දිනකම පෙරවරු 9ට ක්‍රියාත්මක වේ (UTC timezone)
    - cron: '*/15 * * * *'  # සෑම මිනිත්තු 15කට එක් වරක්
    - cron: '0 */6 * * *'    # සෑම පැය 6කට එක් වරක්
    - cron: '0 0 * * 0'      # සෑම ඉරිදා දිනකම මධ්‍යහ්නට
    - cron: '0 0 1 * *'      # සෑම මාසයේම පළමු දින මධ්‍යහ්නට
```

**Cron syntax structure:** `minute hour day(month) month day(week)`
- `*` - ඕනෑම අගයක්
- `*/n` - සෑම n වරක්
- `n,m` - n සහ m අගයන්
- `n-m` - n සිට m දක්වා පරාසය

**වැදගත්:** 
- සියලුම schedules UTC timezone එකේ ධාවනය වේ
- Minimum interval එක මිනිත්තු 5කි
- High load times වලදී schedules ප්‍රමාද විය හැකිය

### **`repository_dispatch`**
බාහිර සේවාවකින් හෝ API call එකකින් custom event එකක් මගින් workflow trigger කිරීමට ඉඩ දෙයි. බාහිර integration සඳහා භාවිතා වේ.

Custom event types සහ payloads භාවිතා කළ හැකිය:

```yaml
on:
  repository_dispatch:
    types: [build, deploy, test]  # විශේෂිත event types සඳහා පමණක් trigger වේ
```

GitHub API භාවිතයෙන් trigger කිරීම:

```bash
curl -X POST \
  -H "Accept: application/vnd.github.v3+json" \
  -H "Authorization: token YOUR_TOKEN" \
  https://api.github.com/repos/OWNER/REPO/dispatches \
  -d '{"event_type":"build","client_payload":{"environment":"production"}}'
```

Workflow තුළ payload data භාවිතා කිරීම:

```yaml
jobs:
  deploy:
    runs-on: ubuntu-latest
    steps:
    - name: Use payload data
      run: |
        echo "Event type: ${{ github.event.action }}"
        echo "Environment: ${{ github.event.client_payload.environment }}"
```

### **`workflow_call`**
වෙනත් workflow එකකින් reusable workflow එකක් කැඳවන විට trigger වේ. Workflow එකක් අනෙක් එකකින් භාවිතා කිරීමට ඉඩ දෙයි.

Reusable workflow එකක් නිර්මාණය කිරීම (inputs සහ outputs සමඟ):

```yaml
on:
  workflow_call:
    inputs:
      environment:
        description: 'Target environment'
        required: true
        type: string
      version:
        description: 'Version to deploy'
        required: false
        type: string
        default: 'latest'
    outputs:
      deployment-id:
        description: 'Deployment ID'
        value: ${{ jobs.deploy.outputs.dep-id }}
    secrets:
      deploy-token:
        description: 'Deployment token'
        required: true

jobs:
  deploy:
    runs-on: ubuntu-latest
    outputs:
      dep-id: ${{ steps.deploy.outputs.id }}
    steps:
    - name: Deploy
      id: deploy
      run: echo "id=12345" >> $GITHUB_OUTPUT
```

Reusable workflow එකක් භාවිතා කිරීම:

```yaml
jobs:
  call-workflow:
    uses: owner/repo/.github/workflows/reusable.yml@main
    with:
      environment: production
      version: v1.0.0
    secrets:
      deploy-token: ${{ secrets.DEPLOY_TOKEN }}
```

### **`workflow_run`**
වෙනත් workflow එකක් සම්පූර්ණ වන විට හෝ request කරන විට trigger වේ. Workflow chains සහ dependencies සඳහා භාවිතා වේ.

විශේෂිත workflows සහ outcomes සඳහා trigger කිරීම:

```yaml
on:
  workflow_run:
    workflows: ["CI", "Build"]  # මෙම workflows සම්පූර්ණ වන විට trigger වේ
    types:
      - completed    # Workflow එකක් සම්පූර්ණ වන විට
      - requested    # Workflow එකක් request කරන විට
    branches:
      - main
      - develop
```

**වැදගත් `types` options:**
- `completed` - Workflow සම්පූර්ණ වූ විට (success හෝ failure)
- `requested` - Workflow request කරන විට

Workflow status check කිරීම:

```yaml
jobs:
  on-success:
    runs-on: ubuntu-latest
    if: ${{ github.event.workflow_run.conclusion == 'success' }}
    steps:
    - name: Run on success
      run: echo "Previous workflow succeeded"
  
  on-failure:
    runs-on: ubuntu-latest
    if: ${{ github.event.workflow_run.conclusion == 'failure' }}
    steps:
    - name: Run on failure
      run: echo "Previous workflow failed"
```

**වැදගත්:** මෙම event එක `GITHUB_TOKEN` permissions සඳහා default branch එකේ permissions භාවිතා කරයි, security සඳහා වැදගතය.

## Code Changes

### **`push`**
කෙනෙකු repository එකට commits push කරන විට trigger වේ. Branch එකකට හෝ tag එකකට code යවන විට මෙය ක්‍රියාත්මක වේ.

`branches` සහ `tags` options භාවිතා කරමින් විශේෂිත branches හෝ tags සඳහා trigger කිරීමට හැකිය:

```yaml
on:
  push:
    branches:
      - main
      - 'releases/**'    # releases/ යටතේ සියලුම branches
      - 'feature/*'      # feature/ යටතේ සියලුම branches
    branches-ignore:
      - 'dev-*'          # dev- වලින් ආරම්භ වන branches නොසලකා හරිනු ලැබේ
```

Tags සඳහා trigger කිරීම:

```yaml
on:
  push:
    tags:
      - v*               # v වලින් ආරම්භ වන සියලුම tags (v1.0, v2.0)
      - 'v[0-9]+.[0-9]+.[0-9]+'  # Semantic versioning tags (v1.2.3)
    tags-ignore:
      - 'beta*'          # beta versions නොසලකා හරිනු ලැබේ
```

විශේෂිත files හෝ paths වෙනස් වන විට පමණක් trigger කිරීම:

```yaml
on:
  push:
    branches:
      - main
    paths:
      - 'src/**'         # src ෆෝල්ඩරයේ වෙනස්කම් සඳහා
      - 'package.json'   # package.json වෙනස් වන විට
      - '**.js'          # සියලුම JavaScript files
    paths-ignore:
      - 'docs/**'        # docs ෆෝල්ඩරය නොසලකා හරිනු ලැබේ
      - '**.md'          # Markdown files නොසලකා හරිනු ලැබේ
      - 'README.md'
```

සම්පූර්ණ උදාහරණයක්:

```yaml
on:
  push:
    branches:
      - main
      - develop
      - 'releases/**'
    paths:
      - 'src/**'
      - 'tests/**'
      - 'package*.json'
    paths-ignore:
      - '**.md'
```

**වැදගත් wildcard patterns:**
- `*` - ඕනෑම characters, `/` හැර
- `**` - ඕනෑම characters, `/` ඇතුළුව
- `?` - එක් character එකක්
- `[abc]` - a, b, හෝ c characters
- `[0-9]` - 0 සිට 9 දක්වා ඕනෑම digit එකක්

### **`create`**
Branch එකක් හෝ tag එකක් නිර්මාණය කරන විට trigger වේ. නව references සඳහා ප්‍රතිචාර දැක්වීමට භාවිතා වේ.

මෙම event එකට filters නොමැත, නමුත් workflow තුළ ref type check කළ හැකිය:

```yaml
on:
  create:

jobs:
  on-branch-create:
    runs-on: ubuntu-latest
    if: ${{ github.event.ref_type == 'branch' }}
    steps:
      - name: New branch created
        run: |
          echo "New branch: ${{ github.event.ref }}"
          echo "Created by: ${{ github.actor }}"
  
  on-tag-create:
    runs-on: ubuntu-latest
    if: ${{ github.event.ref_type == 'tag' }}
    steps:
      - name: New tag created
        run: |
          echo "New tag: ${{ github.event.ref }}"
          echo "Tag description: ${{ github.event.description }}"
```

**වැදගත් context variables:**
- `github.event.ref` - නිර්මාණය වූ branch හෝ tag name
- `github.event.ref_type` - `branch` හෝ `tag`
- `github.event.master_branch` - Repository එකේ default branch
- `github.event.description` - Tag description (if available)

### **`delete`**
Branch එකක් හෝ tag එකක් මකා දමන විට trigger වේ. Cleanup කාර්යයන් සඳහා උපයෝගී වේ.

මෙම event එකට filters නොමැත, නමුත් workflow තුළ ref type check කළ හැකිය:

```yaml
on:
  delete:

jobs:
  cleanup:
    runs-on: ubuntu-latest
    steps:
      - name: Handle deletion
        run: |
          echo "Deleted ref: ${{ github.event.ref }}"
          echo "Ref type: ${{ github.event.ref_type }}"
          
      - name: Cleanup environments
        if: ${{ github.event.ref_type == 'branch' }}
        run: |
          echo "Cleaning up environment for branch: ${{ github.event.ref }}"
          # Delete associated resources, environments, etc.
      
      - name: Cleanup release assets
        if: ${{ github.event.ref_type == 'tag' }}
        run: |
          echo "Cleaning up assets for tag: ${{ github.event.ref }}"
```

**වැදගත් context variables:**
- `github.event.ref` - මකා දැමූ branch හෝ tag name
- `github.event.ref_type` - `branch` හෝ `tag`
- `github.event.pusher_type` - `user` හෝ `deploy_key`

**Use cases:**
- Feature branch එකක් delete කරන විට preview environments cleanup කිරීම
- Old tags සඳහා associated resources cleanup කිරීම
- Database backups හෝ artifacts මකා දැමීම

### **`branch_protection_rule`**
Branch protection rule එකක් නිර්මාණය කරන විට, වෙනස් කරන විට, හෝ මකා දමන විට trigger වේ. Branch security settings කළමනාකරණය කිරීම සඳහා භාවිතා වේ.

විශේෂිත actions සඳහා trigger කිරීම:

```yaml
on:
  branch_protection_rule:
    types:
      - created   # නව rule එකක් නිර්මාණය කරන විට
      - edited    # Rule එකක් සංස්කරණය කරන විට
      - deleted   # Rule එකක් මකා දමන විට
```

Protection rules monitor කිරීම:

```yaml
jobs:
  audit-protection-rules:
    runs-on: ubuntu-latest
    steps:
      - name: Log protection rule change
        run: |
          echo "Action: ${{ github.event.action }}"
          echo "Rule ID: ${{ github.event.rule.id }}"
          echo "Rule name: ${{ github.event.rule.name }}"
          echo "Changed by: ${{ github.actor }}"
      
      - name: Notify security team
        if: ${{ github.event.action == 'deleted' }}
        run: |
          echo "⚠️ Branch protection rule deleted!"
          echo "Rule: ${{ github.event.rule.name }}"
          # Send notification to security team
```

**වැදගත් `types` options:**
- `created` - නව protection rule නිර්මාණය කරන විට
- `edited` - Existing rule වෙනස් කරන විට
- `deleted` - Rule මකා දමන විට

**Use cases:**
- Security policy changes audit කිරීම
- Compliance monitoring
- Automated notifications for critical changes
- Rule changes log කිරීම

### **`merge_group`**
Pull request එකක් merge queue එකට එකතු කරන විට trigger වේ. Merge queue automation සඳහා භාවිතා වේ.

Merge queue events handle කිරීම:

```yaml
on:
  merge_group:
    types:
      - checks_requested  # Queue තුළ checks request කරන විට

jobs:
  validate-merge:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout merge group
        uses: actions/checkout@v3
        with:
          ref: ${{ github.event.merge_group.head_sha }}
      
      - name: Run tests on merge group
        run: |
          echo "Testing merge of PRs in queue"
          echo "Base SHA: ${{ github.event.merge_group.base_sha }}"
          echo "Head SHA: ${{ github.event.merge_group.head_sha }}"
          npm test
      
      - name: Validate deployment
        run: |
          echo "Running deployment validation"
          # Additional validation before merge
```

**වැදගත් context variables:**
- `github.event.merge_group.head_sha` - Merge group එකේ head commit
- `github.event.merge_group.base_sha` - Base branch commit
- `github.event.merge_group.head_ref` - Merge group branch name
- `github.event.merge_group.base_ref` - Target branch name

**Use cases:**
- Merge queue තුළ PRs එකට test කිරීම
- Multiple PRs merge කිරීමට පෙර validation
- Deployment prerequisites verify කිරීම
- Integration tests before final merge

**වැදගත්:** මෙම event එක GitHub merge queue feature එක සක්‍රීය කර ඇති විට පමණක් ක්‍රියාත්මක වේ.

## Pull Requests

### **`pull_request`**
Pull request එකක් විවෘත කරන විට, යාවත්කාලීන කරන විට, හෝ merge කරන විට trigger වේ. Code review ක්‍රියාවලියේදී බහුලව භාවිතා වේ.

`types` option එක භාවිතා කරමින් විශේෂිත pull request actions සඳහා trigger කිරීමට හැකිය. උදාහරණයක් ලෙස:

```yaml
on:
  pull_request:
    types: 
    - opened # Pull request එකක් විවෘත කරන විට
    - reopened # Pull request එකක් නැවත විවෘත කරන විට
    - synchronize # Pull request එකක් යාවත්කාලීන කරන විට
```

**වැදගත් `types` options:**
- `assigned` - කෙනෙකු PR එකට assign කරන විට
- `unassigned` - කෙනෙකු PR එකෙන් unassign කරන විට
- `labeled` - PR එකකට label එකක් එකතු කරන විට
- `unlabeled` - PR එකකින් label එකක් ඉවත් කරන විට
- `closed` - PR එකක් වසන විට (merged හෝ closed)
- `ready_for_review` - Draft PR එකක් ready for review කරන විට
- `converted_to_draft` - PR එකක් draft බවට පරිවර්තනය කරන විට
- `review_requested` - Review request කරන විට
- `review_request_removed` - Review request ඉවත් කරන විට
- `auto_merge_enabled` - Auto merge සක්‍රීය කරන විට
- `auto_merge_disabled` - Auto merge අක්‍රීය කරන විට
- `edited` - PR title හෝ body සංස්කරණය කරන විට

`paths` සහ `paths-ignore` options භාවිතා කරමින් විශේෂිත ගොනු හෝ ෆෝල්ඩර් වෙනස්කම් සඳහා trigger කිරීමට හැකිය. උදාහරණයක් ලෙස:

```yaml
on:
  pull_request:
    paths:
    - 'src/**'        # src ෆෝල්ඩරයේ ගොනු වෙනස්කම් සඳහා
    - 'docs/**'       # docs ෆෝල්ඩරයේ ගොනු වෙනස්කම් සඳහා
    paths-ignore:
    - 'README.md'     # README.md ගොනුවේ වෙනස්කම් නොසලකා හරිනු ලැබේ
```

`branches` සහ `branches-ignore` options භාවිතා කරමින් විශේෂිත branches සඳහා trigger කිරීමට හැකිය:

```yaml
on:
  pull_request:
    branches:
    - main            # main branch එකට pull request සඳහා පමණක්
    - 'releases/**'   # releases/ ෆෝල්ඩරයේ branches සඳහා
    branches-ignore:
    - development     # development branch එක නොසලකා හරිනු ලැබේ
```

සියලුම options එකට භාවිතා කරන සම්පූර්ණ උදාහරණයක්:

```yaml
on:
  pull_request:
    types: [opened, synchronize, reopened, closed]
    branches:
    - main
    - develop
    paths:
    - 'src/**'
    - 'tests/**'
    paths-ignore:
    - '**.md'         # සියලුම markdown ගොනු නොසලකා හරිනු ලැබේ
    - 'docs/**'
```

### **`pull_request_target`**
Pull request එකක් විවෘත කරන විට, යාවත්කාලීන කරන විට, හෝ merge කරන විට trigger වේ. මෙය pull request source branch එකේ code භාවිතා නොකර target branch එකේ code භාවිතා කරයි.

**වැදගත්:** `pull_request_target` එක `pull_request` එකට වඩා වෙනස් ආකාරයකින් ක්‍රියාත්මක වේ:
- Target branch එකේ workflow file භාවිතා කරයි (fork වලින් වුවද)
- Target repository එකේ secrets වලට access ඇත
- `GITHUB_TOKEN` එකට write permissions ඇත
- Security sensitive operations සඳහා භාවිතා වේ

```yaml
on:
  pull_request_target:
    types: [opened, synchronize, reopened, closed]
    branches:
      - main

jobs:
  secure-build:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout target branch
        uses: actions/checkout@v3
        # Default: target branch checkout වේ
      
      - name: Checkout PR branch (careful!)
        uses: actions/checkout@v3
        with:
          ref: ${{ github.event.pull_request.head.sha }}
        # ⚠️ Security risk: untrusted code run විය හැකිය
```

**Security best practices:**

```yaml
jobs:
  label-pr:
    runs-on: ubuntu-latest
    # PR code run නොකර labels කළමනාකරණය කිරීම
    steps:
      - name: Add label
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.issues.addLabels({
              owner: context.repo.owner,
              repo: context.repo.repo,
              issue_number: context.issue.number,
              labels: ['automated']
            })
```

**Use cases:**
- Fork වලින් PRs සඳහා secrets භාවිතා කිරීම
- PR labeling automation
- Comment posting වෙත external APIs
- Secure builds for untrusted code

**වැදගත්:** PR code run කරන්නේ නම් ඉතා පරිස්සමෙන් - security vulnerabilities ඇති විය හැකිය!

### **`pull_request_review`**
Pull request එකක් සඳහා review එකක් submit කරන විට trigger වේ. Approve, request changes, හෝ comment කරන විට ක්‍රියාත්මක වේ.

විශේෂිත review actions සඳහා trigger කිරීම:

```yaml
on:
  pull_request_review:
    types:
      - submitted   # Review submit කරන විට
      - edited      # Review සංස්කරණය කරන විට
      - dismissed   # Review dismiss කරන විට
```

Review status අනුව විවිධ actions ගැනීම:

```yaml
jobs:
  handle-review:
    runs-on: ubuntu-latest
    steps:
      - name: Check review state
        run: |
          echo "Review state: ${{ github.event.review.state }}"
          echo "Reviewer: ${{ github.event.review.user.login }}"
          echo "Review body: ${{ github.event.review.body }}"
      
      - name: On approval
        if: ${{ github.event.review.state == 'approved' }}
        run: |
          echo "✅ PR approved!"
          # Auto-label, notify team, etc.
      
      - name: On changes requested
        if: ${{ github.event.review.state == 'changes_requested' }}
        run: |
          echo "🔄 Changes requested"
          # Notify author, add label, etc.
      
      - name: On comment
        if: ${{ github.event.review.state == 'commented' }}
        run: |
          echo "💬 Review comment added"
```

**වැදගත් `types` options:**
- `submitted` - නව review එකක් submit කරන විට
- `edited` - Review එකක් edit කරන විට
- `dismissed` - Review එකක් dismiss කරන විට

**වැදගත් context variables:**
- `github.event.review.state` - `approved`, `changes_requested`, හෝ `commented`
- `github.event.review.body` - Review comment text
- `github.event.review.user.login` - Reviewer username
- `github.event.pull_request.number` - PR number

**Use cases:**
- Approval පසු auto-merge කිරීම
- Required reviewers check කිරීම
- Review metrics collect කිරීම
- Team notifications

### **`pull_request_review_comment`**
Pull request review එකක විශේෂිත code line එකකට comment කරන විට trigger වේ. Code-specific සාකච්ඡා සඳහා භාවිතා වේ.

```yaml
on:
  pull_request_review_comment:
    types:
      - created   # නව review comment එකක්
      - edited    # Comment සංස්කරණය කරන විට
      - deleted   # Comment මකා දමන විට
```

Review comments handle කිරීම:

```yaml
jobs:
  handle-review-comment:
    runs-on: ubuntu-latest
    steps:
      - name: Comment details
        run: |
          echo "Comment: ${{ github.event.comment.body }}"
          echo "File: ${{ github.event.comment.path }}"
          echo "Line: ${{ github.event.comment.line }}"
          echo "Commenter: ${{ github.event.comment.user.login }}"
      
      - name: Check for keywords
        if: contains(github.event.comment.body, '/deploy')
        run: |
          echo "Deploy command detected in review comment"
          # Trigger deployment
      
      - name: Respond to comment
        uses: actions/github-script@v6
        with:
          script: |
            await github.rest.pulls.createReplyForReviewComment({
              owner: context.repo.owner,
              repo: context.repo.repo,
              pull_number: context.issue.number,
              comment_id: ${{ github.event.comment.id }},
              body: 'Thank you for the review! 🙏'
            })
```

**වැදගත් context variables:**
- `github.event.comment.body` - Comment text
- `github.event.comment.path` - File path commented on
- `github.event.comment.line` - Line number
- `github.event.comment.diff_hunk` - Code diff context
- `github.event.comment.position` - Position in diff
- `github.event.comment.commit_id` - Commit SHA

**Use cases:**
- Bot commands in review comments (e.g., `/deploy`, `/test`)
- Code quality checks on specific lines
- Automated responses to reviewers
- Tracking review discussions

### **`pull_request_comment`**
Pull request එකක් සඳහා comment එකක් එකතු කරන විට trigger වේ. Code review discussion සඳහා භාවිතා වේ.

**සටහන:** මෙය `issue_comment` event එකේම subset එකකි. PR comments සහ issue comments දෙකම `issue_comment` භාවිතා කරයි.

```yaml
on:
  issue_comment:
    types: [created, edited, deleted]

jobs:
  handle-pr-comment:
    # PR comment නම් පමණක් run වන්න
    if: ${{ github.event.issue.pull_request }}
    runs-on: ubuntu-latest
    steps:
      - name: Check comment
        run: |
          echo "Comment: ${{ github.event.comment.body }}"
          echo "PR Number: ${{ github.event.issue.number }}"
          echo "Commenter: ${{ github.event.comment.user.login }}"
      
      - name: Bot commands
        if: startsWith(github.event.comment.body, '/')
        run: |
          echo "Processing bot command"
          # Handle /test, /deploy, etc.
```

PR-specific comment handling:

```yaml
jobs:
  pr-commands:
    if: github.event.issue.pull_request
    runs-on: ubuntu-latest
    steps:
      - name: Checkout PR
        uses: actions/checkout@v3
        with:
          ref: refs/pull/${{ github.event.issue.number }}/head
      
      - name: Run tests on command
        if: contains(github.event.comment.body, '/test')
        run: npm test
      
      - name: Deploy on command
        if: contains(github.event.comment.body, '/deploy') && github.event.comment.user.login == 'authorized-user'
        run: |
          echo "Deploying PR preview..."
          # Deploy preview environment
      
      - name: React to comment
        uses: actions/github-script@v6
        with:
          script: |
            await github.rest.reactions.createForIssueComment({
              owner: context.repo.owner,
              repo: context.repo.repo,
              comment_id: ${{ github.event.comment.id }},
              content: 'rocket'
            })
```

**වැදගත් context variables:**
- `github.event.comment.body` - Comment text
- `github.event.issue.number` - PR number
- `github.event.issue.pull_request` - PR object (null නම් issue)
- `github.event.comment.user.login` - Commenter username

**Use cases:**
- Chat ops commands (`/deploy`, `/test`, `/rebase`)
- Automated PR assistant bots
- User permission verification
- Custom slash commands

## Issues & Project Management

### **`issues`**
Issue එකක් විවෘත කරන විට, වසා දමන විට, හෝ වෙනස් කරන විට trigger වේ. Issue management සඳහා භාවිතා වේ.

විශේෂිත issue actions සඳහා trigger කිරීම:

```yaml
on:
  issues:
    types:
      - opened          # නව issue එකක් විවෘත කරන විට
      - edited          # Issue එකක් සංස්කරණය කරන විට
      - deleted         # Issue එකක් මකා දමන විට
      - closed          # Issue එකක් වසන විට
      - reopened        # Issue එකක් නැවත විවෘත කරන විට
      - assigned        # කෙනෙකු issue එකට assign කරන විට
      - unassigned      # කෙනෙකු issue එකෙන් unassign කරන විට
      - labeled         # Label එකක් එකතු කරන විට
      - unlabeled       # Label එකක් ඉවත් කරන විට
      - locked          # Issue එකක් lock කරන විට
      - unlocked        # Issue එකක් unlock කරන විට
      - transferred     # Issue එකක් වෙනත් repo එකකට transfer කරන විට
      - pinned          # Issue එකක් pin කරන විට
      - unpinned        # Issue එකක් unpin කරන විට
      - milestoned      # Milestone එකක් assign කරන විට
      - demilestoned    # Milestone එකක් ඉවත් කරන විට
```

Issue automation උදාහරණ:

```yaml
jobs:
  auto-label:
    runs-on: ubuntu-latest
    if: github.event.action == 'opened'
    steps:
      - name: Add triage label to new issues
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.issues.addLabels({
              owner: context.repo.owner,
              repo: context.repo.repo,
              issue_number: context.issue.number,
              labels: ['needs-triage']
            })
  
  notify-team:
    runs-on: ubuntu-latest
    if: github.event.action == 'labeled' && github.event.label.name == 'bug'
    steps:
      - name: Notify on bug label
        run: |
          echo "🐛 Bug reported: ${{ github.event.issue.title }}"
          echo "Reporter: ${{ github.event.issue.user.login }}"
          # Send notification to team
  
  auto-close-stale:
    runs-on: ubuntu-latest
    if: github.event.action == 'labeled' && github.event.label.name == 'wontfix'
    steps:
      - name: Close issue
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.issues.update({
              owner: context.repo.owner,
              repo: context.repo.repo,
              issue_number: context.issue.number,
              state: 'closed'
            })
```

**වැදගත් context variables:**
- `github.event.issue.number` - Issue number
- `github.event.issue.title` - Issue title
- `github.event.issue.body` - Issue description
- `github.event.issue.user.login` - Issue creator
- `github.event.issue.state` - `open` හෝ `closed`
- `github.event.issue.labels` - Issue labels array
- `github.event.label.name` - Labeled/unlabeled event වල label name

**Use cases:**
- Auto-labeling based on issue content
- Assigning issues to team members
- Automated triaging workflows
- Issue notifications and alerts
- Stale issue management

### **`issue_comment`**
Issue එකක හෝ pull request එකක comment එකක් එකතු කරන විට trigger වේ. සාකච්ඡා සඳහා ප්‍රතිචාර දැක්වීමට භාවිතා වේ.

```yaml
on:
  issue_comment:
    types:
      - created   # නව comment එකක්
      - edited    # Comment සංස්කරණය කරන විට
      - deleted   # Comment මකා දමන විට
```

Issue සහ PR comments වෙන්කර handle කිරීම:

```yaml
jobs:
  handle-issue-comment:
    runs-on: ubuntu-latest
    # Issue comment පමණක් (PR නොවේ)
    if: ${{ !github.event.issue.pull_request }}
    steps:
      - name: Process issue comment
        run: |
          echo "Issue comment: ${{ github.event.comment.body }}"
          echo "Issue number: ${{ github.event.issue.number }}"
  
  handle-pr-comment:
    runs-on: ubuntu-latest
    # PR comment පමණක්
    if: ${{ github.event.issue.pull_request }}
    steps:
      - name: Process PR comment
        run: |
          echo "PR comment: ${{ github.event.comment.body }}"
          echo "PR number: ${{ github.event.issue.number }}"
```

Bot commands implementation:

```yaml
jobs:
  bot-commands:
    runs-on: ubuntu-latest
    if: github.event.action == 'created'
    steps:
      - name: Check for slash commands
        id: command
        run: |
          COMMENT="${{ github.event.comment.body }}"
          if [[ "$COMMENT" == /assign* ]]; then
            echo "command=assign" >> $GITHUB_OUTPUT
          elif [[ "$COMMENT" == /close* ]]; then
            echo "command=close" >> $GITHUB_OUTPUT
          elif [[ "$COMMENT" == /reopen* ]]; then
            echo "command=reopen" >> $GITHUB_OUTPUT
          fi
      
      - name: Auto-assign issue
        if: steps.command.outputs.command == 'assign'
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.issues.addAssignees({
              owner: context.repo.owner,
              repo: context.repo.repo,
              issue_number: context.issue.number,
              assignees: [context.actor]
            })
      
      - name: Close issue
        if: steps.command.outputs.command == 'close'
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.issues.update({
              owner: context.repo.owner,
              repo: context.repo.repo,
              issue_number: context.issue.number,
              state: 'closed'
            })
      
      - name: Add reaction
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.reactions.createForIssueComment({
              owner: context.repo.owner,
              repo: context.repo.repo,
              comment_id: ${{ github.event.comment.id }},
              content: '+1'
            })
```

**වැදගත් context variables:**
- `github.event.comment.body` - Comment text
- `github.event.comment.user.login` - Commenter username
- `github.event.issue.number` - Issue/PR number
- `github.event.issue.pull_request` - PR object (null නම් issue)
- `github.event.comment.id` - Comment ID

**Use cases:**
- Issue bot commands (`/assign`, `/close`, `/label`)
- Automated responses to users
- Comment sentiment analysis
- FAQ auto-responses
- User permission checks

### **`label`**
Repository එකේ label එකක් එකතු කරන විට, මකා දමන විට, හෝ සංස්කරණය කරන විට trigger වේ.

```yaml
on:
  label:
    types:
      - created   # නව label එකක් නිර්මාණය කරන විට
      - edited    # Label එකක් සංස්කරණය කරන විට
      - deleted   # Label එකක් මකා දමන විට
```

Label management automation:

```yaml
jobs:
  sync-labels:
    runs-on: ubuntu-latest
    steps:
      - name: Log label change
        run: |
          echo "Action: ${{ github.event.action }}"
          echo "Label name: ${{ github.event.label.name }}"
          echo "Label color: ${{ github.event.label.color }}"
          echo "Label description: ${{ github.event.label.description }}"
      
      - name: Sync to other repos
        if: github.event.action == 'created'
        run: |
          echo "Syncing label '${{ github.event.label.name }}' to other repositories"
          # Sync labels across organization repos
      
      - name: Notify on deletion
        if: github.event.action == 'deleted'
        run: |
          echo "⚠️ Label deleted: ${{ github.event.label.name }}"
          # Alert team about label deletion
```

**වැදගත් context variables:**
- `github.event.label.name` - Label name
- `github.event.label.color` - Label color (hex code)
- `github.event.label.description` - Label description

**Use cases:**
- Label synchronization across repositories
- Label standards enforcement
- Audit label changes
- Automated label documentation

### **`milestone`**
Milestone එකක් නිර්මාණය කරන විට, වසා දමන විට, හෝ වෙනස් කරන විට trigger වේ. Project tracking සඳහා භාවිතා වේ.

```yaml
on:
  milestone:
    types:
      - created   # නව milestone එකක් නිර්මාණය කරන විට
      - closed    # Milestone එකක් වසන විට
      - opened    # Milestone එකක් විවෘත කරන විට
      - edited    # Milestone එකක් සංස්කරණය කරන විට
      - deleted   # Milestone එකක් මකා දමන විට
```

Milestone tracking automation:

```yaml
jobs:
  milestone-automation:
    runs-on: ubuntu-latest
    steps:
      - name: Milestone event details
        run: |
          echo "Action: ${{ github.event.action }}"
          echo "Milestone: ${{ github.event.milestone.title }}"
          echo "Due date: ${{ github.event.milestone.due_on }}"
          echo "Description: ${{ github.event.milestone.description }}"
      
      - name: Create release on milestone close
        if: github.event.action == 'closed'
        uses: actions/github-script@v6
        with:
          script: |
            const milestone = context.payload.milestone;
            console.log(`Milestone closed: ${milestone.title}`);
            // Create GitHub release for closed milestone
            
      - name: Generate milestone report
        if: github.event.action == 'closed'
        run: |
          echo "📊 Generating report for milestone: ${{ github.event.milestone.title }}"
          echo "Open issues: ${{ github.event.milestone.open_issues }}"
          echo "Closed issues: ${{ github.event.milestone.closed_issues }}"
          # Generate and publish milestone report
      
      - name: Notify team
        if: github.event.action == 'created'
        run: |
          echo "🎯 New milestone created: ${{ github.event.milestone.title }}"
          # Send notification to team
```

**වැදගත් context variables:**
- `github.event.milestone.title` - Milestone title
- `github.event.milestone.description` - Milestone description
- `github.event.milestone.due_on` - Due date
- `github.event.milestone.state` - `open` හෝ `closed`
- `github.event.milestone.open_issues` - Open issues count
- `github.event.milestone.closed_issues` - Closed issues count
- `github.event.milestone.number` - Milestone number

**Use cases:**
- Automated release creation on milestone completion
- Milestone progress reports
- Team notifications for milestone events
- Project planning automation

### **`project`**
Project board එකක් හෝ project card එකක් වෙනස් කරන විට trigger වේ. Project management සඳහා භාවිතා වේ.

**සටහන:** මෙය classic GitHub Projects සඳහා වේ. නව GitHub Projects (Projects v2) සඳහා වෙනත් events භාවිතා වේ.

```yaml
on:
  project:
    types:
      - created   # නව project එකක් නිර්මාණය කරන විට
      - edited    # Project එකක් සංස්කරණය කරන විට
      - closed    # Project එකක් වසන විට
      - reopened  # Project එකක් නැවත විවෘත කරන විට
      - deleted   # Project එකක් මකා දමන විට
```

Project automation:

```yaml
jobs:
  project-automation:
    runs-on: ubuntu-latest
    steps:
      - name: Project event
        run: |
          echo "Action: ${{ github.event.action }}"
          echo "Project name: ${{ github.event.project.name }}"
          echo "Project body: ${{ github.event.project.body }}"
      
      - name: Archive on close
        if: github.event.action == 'closed'
        run: |
          echo "📦 Archiving project: ${{ github.event.project.name }}"
          # Archive project data
      
      - name: Setup new project
        if: github.event.action == 'created'
        run: |
          echo "🆕 Setting up new project: ${{ github.event.project.name }}"
          # Initialize project columns, automation rules, etc.
```

**වැදගත්:** Classic Projects වෙනුවට නව GitHub Projects (v2) භාවිතා කරන්නේ නම්, GraphQL API සහ `projects_v2` webhooks භාවිතා කරන්න.

### **`discussion`**
GitHub Discussions එකක discussion එකක් නිර්මාණය කරන විට, සංස්කරණය කරන විට, හෝ මකා දමන විට trigger වේ. Community discussions කළමනාකරණය කිරීම සඳහා භාවිතා වේ.

```yaml
on:
  discussion:
    types:
      - created           # නව discussion එකක්
      - edited            # Discussion සංස්කරණය කරන විට
      - deleted           # Discussion මකා දමන විට
      - transferred       # Discussion transfer කරන විට
      - pinned            # Discussion pin කරන විට
      - unpinned          # Discussion unpin කරන විට
      - labeled           # Label එකක් එකතු කරන විට
      - unlabeled         # Label එකක් ඉවත් කරන විට
      - locked            # Discussion lock කරන විට
      - unlocked          # Discussion unlock කරන විට
      - category_changed  # Category වෙනස් කරන විට
      - answered          # Discussion answer කරන විට
      - unanswered        # Answer ඉවත් කරන විට
```

Community discussion automation:

```yaml
jobs:
  discussion-automation:
    runs-on: ubuntu-latest
    steps:
      - name: Welcome new discussions
        if: github.event.action == 'created'
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.discussions.createComment({
              owner: context.repo.owner,
              repo: context.repo.repo,
              discussion_number: context.payload.discussion.number,
              body: '👋 Thank you for starting this discussion! Our team will review it soon.'
            })
      
      - name: Auto-label discussions
        if: github.event.action == 'created'
        run: |
          TITLE="${{ github.event.discussion.title }}"
          if [[ "$TITLE" == *"bug"* ]]; then
            echo "Adding 'bug' label"
            # Add bug label
          elif [[ "$TITLE" == *"feature"* ]]; then
            echo "Adding 'feature-request' label"
            # Add feature request label
          fi
      
      - name: Celebrate answered discussions
        if: github.event.action == 'answered'
        run: |
          echo "✅ Discussion answered: ${{ github.event.discussion.title }}"
          # Send notification or add reaction
```

**වැදගත් context variables:**
- `github.event.discussion.number` - Discussion number
- `github.event.discussion.title` - Discussion title
- `github.event.discussion.body` - Discussion content
- `github.event.discussion.user.login` - Discussion creator
- `github.event.discussion.category.name` - Category name
- `github.event.discussion.answer_html_url` - Answer URL (if answered)

**Use cases:**
- Welcome messages for new discussions
- Auto-categorization and labeling
- Discussion notifications
- Community engagement tracking
- FAQ automation

### **`discussion_comment`**
Discussion එකකට comment එකක් එකතු කරන විට, සංස්කරණය කරන විට, හෝ මකා දමන විට trigger වේ. Discussion engagement සඳහා භාවිතා වේ.

```yaml
on:
  discussion_comment:
    types:
      - created   # නව comment එකක්
      - edited    # Comment සංස්කරණය කරන විට
      - deleted   # Comment මකා දමන විට
```

Discussion comment automation:

```yaml
jobs:
  discussion-comment-handler:
    runs-on: ubuntu-latest
    steps:
      - name: Comment details
        run: |
          echo "Comment: ${{ github.event.comment.body }}"
          echo "Commenter: ${{ github.event.comment.user.login }}"
          echo "Discussion: ${{ github.event.discussion.title }}"
      
      - name: Check for solutions
        if: contains(github.event.comment.body, '/solved')
        uses: actions/github-script@v6
        with:
          script: |
            // Mark comment as answer
            console.log('Marking discussion as answered');
      
      - name: Thank commenters
        if: github.event.action == 'created'
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.reactions.createForDiscussionComment({
              owner: context.repo.owner,
              repo: context.repo.repo,
              comment_id: context.payload.comment.node_id,
              content: 'heart'
            })
      
      - name: Moderate content
        if: github.event.action == 'created'
        run: |
          COMMENT="${{ github.event.comment.body }}"
          # Check for spam or inappropriate content
          echo "Moderating comment..."
```

**වැදගත් context variables:**
- `github.event.comment.body` - Comment text
- `github.event.comment.user.login` - Commenter username
- `github.event.discussion.number` - Discussion number
- `github.event.discussion.title` - Discussion title
- `github.event.comment.id` - Comment ID

**Use cases:**
- Community engagement automation
- Spam detection and moderation
- Answer marking automation
- Contributor recognition
- Discussion statistics tracking

## Releases & Deployments

### **`release`**
Repository එකේ නව release එකක් නිර්මාණය කරන විට හෝ ප්‍රකාශයට පත් කරන විට trigger වේ. Software version නිකුත් කිරීම් සඳහා උපයෝගී වේ.

විශේෂිත release actions සඳහා trigger කිරීම:

```yaml
on:
  release:
    types:
      - published       # Release එකක් publish කරන විට
      - unpublished     # Release එකක් unpublish කරන විට
      - created         # Release එකක් draft ලෙස නිර්මාණය කරන විට
      - edited          # Release එකක් සංස්කරණය කරන විට
      - deleted         # Release එකක් මකා දමන විට
      - prereleased     # Pre-release එකක් publish කරන විට
      - released        # Draft release එකක් publish කරන විට
```

Release automation උදාහරණ:

```yaml
jobs:
  deploy-on-release:
    runs-on: ubuntu-latest
    if: github.event.action == 'published'
    steps:
      - name: Checkout code
        uses: actions/checkout@v3
        with:
          ref: ${{ github.event.release.tag_name }}
      
      - name: Release details
        run: |
          echo "Release: ${{ github.event.release.name }}"
          echo "Tag: ${{ github.event.release.tag_name }}"
          echo "Pre-release: ${{ github.event.release.prerelease }}"
          echo "Draft: ${{ github.event.release.draft }}"
      
      - name: Deploy to production
        if: ${{ !github.event.release.prerelease }}
        run: |
          echo "🚀 Deploying to production..."
          echo "Version: ${{ github.event.release.tag_name }}"
          # Deploy application
      
      - name: Deploy to staging
        if: ${{ github.event.release.prerelease }}
        run: |
          echo "🧪 Deploying to staging..."
          echo "Pre-release: ${{ github.event.release.tag_name }}"
          # Deploy to staging environment
  
  build-assets:
    runs-on: ubuntu-latest
    if: github.event.action == 'published'
    steps:
      - name: Build release artifacts
        run: |
          echo "Building artifacts for ${{ github.event.release.tag_name }}"
          # Build binaries, packages, etc.
      
      - name: Upload release assets
        uses: actions/upload-release-asset@v1
        env:
          GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }}
        with:
          upload_url: ${{ github.event.release.upload_url }}
          asset_path: ./dist/app.zip
          asset_name: app-${{ github.event.release.tag_name }}.zip
          asset_content_type: application/zip
  
  notify-users:
    runs-on: ubuntu-latest
    if: github.event.action == 'published' && !github.event.release.prerelease
    steps:
      - name: Send notifications
        run: |
          echo "📢 New release: ${{ github.event.release.name }}"
          echo "Release notes: ${{ github.event.release.body }}"
          # Send email, Slack, Discord notifications
```

**වැදගත් context variables:**
- `github.event.release.tag_name` - Release tag name
- `github.event.release.name` - Release name/title
- `github.event.release.body` - Release notes/description
- `github.event.release.draft` - `true` නම් draft release
- `github.event.release.prerelease` - `true` නම් pre-release
- `github.event.release.created_at` - Release creation timestamp
- `github.event.release.published_at` - Release publish timestamp
- `github.event.release.upload_url` - Assets upload කිරීම සඳහා URL
- `github.event.release.html_url` - Release page URL

**Use cases:**
- Automated production deployments
- Building and uploading release assets
- User notifications for new releases
- Documentation generation and publishing
- Container image publishing

### **`deployment`**
Deployment එකක් නිර්මාණය කරන විට trigger වේ. Deploy ක්‍රියාවලිය ආරම්භ කිරීම සඳහා භාවිතා වේ.

```yaml
on:
  deployment:
```

Deployment handling:

```yaml
jobs:
  deploy:
    runs-on: ubuntu-latest
    steps:
      - name: Deployment details
        run: |
          echo "Environment: ${{ github.event.deployment.environment }}"
          echo "Ref: ${{ github.event.deployment.ref }}"
          echo "SHA: ${{ github.event.deployment.sha }}"
          echo "Task: ${{ github.event.deployment.task }}"
          echo "Payload: ${{ github.event.deployment.payload }}"
      
      - name: Set deployment status to in_progress
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.repos.createDeploymentStatus({
              owner: context.repo.owner,
              repo: context.repo.repo,
              deployment_id: context.payload.deployment.id,
              state: 'in_progress',
              description: 'Deployment started'
            })
      
      - name: Checkout code
        uses: actions/checkout@v3
        with:
          ref: ${{ github.event.deployment.sha }}
      
      - name: Deploy application
        id: deploy
        run: |
          echo "Deploying to ${{ github.event.deployment.environment }}..."
          # Deployment logic here
          echo "url=https://app-${{ github.event.deployment.environment }}.example.com" >> $GITHUB_OUTPUT
      
      - name: Set deployment status to success
        if: success()
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.repos.createDeploymentStatus({
              owner: context.repo.owner,
              repo: context.repo.repo,
              deployment_id: context.payload.deployment.id,
              state: 'success',
              description: 'Deployment successful',
              environment_url: '${{ steps.deploy.outputs.url }}'
            })
      
      - name: Set deployment status to failure
        if: failure()
        uses: actions/github-script@v6
        with:
          script: |
            github.rest.repos.createDeploymentStatus({
              owner: context.repo.owner,
              repo: context.repo.repo,
              deployment_id: context.payload.deployment.id,
              state: 'failure',
              description: 'Deployment failed'
            })
```

**වැදගත් context variables:**
- `github.event.deployment.id` - Deployment ID
- `github.event.deployment.sha` - Commit SHA to deploy
- `github.event.deployment.ref` - Branch හෝ tag reference
- `github.event.deployment.task` - Deployment task type
- `github.event.deployment.environment` - Target environment name
- `github.event.deployment.description` - Deployment description
- `github.event.deployment.payload` - Custom payload data

**Use cases:**
- Multi-environment deployments (production, staging, dev)
- Deployment status tracking
- Rollback automation
- Deployment approval workflows

### **`deployment_status`**
Deployment එකක status වෙනස් වන විට trigger වේ. Deploy සාර්ථක හෝ අසාර්ථක බව නිරීක්ෂණය කිරීමට භාවිතා වේ.

```yaml
on:
  deployment_status:
```

Deployment status monitoring:

```yaml
jobs:
  notify-deployment-status:
    runs-on: ubuntu-latest
    steps:
      - name: Status details
        run: |
          echo "State: ${{ github.event.deployment_status.state }}"
          echo "Environment: ${{ github.event.deployment_status.environment }}"
          echo "URL: ${{ github.event.deployment_status.environment_url }}"
          echo "Description: ${{ github.event.deployment_status.description }}"
      
      - name: Notify success
        if: github.event.deployment_status.state == 'success'
        run: |
          echo "✅ Deployment successful!"
          echo "Environment: ${{ github.event.deployment_status.environment }}"
          echo "URL: ${{ github.event.deployment_status.environment_url }}"
          # Send success notification
      
      - name: Notify failure
        if: github.event.deployment_status.state == 'failure'
        run: |
          echo "❌ Deployment failed!"
          echo "Environment: ${{ github.event.deployment_status.environment }}"
          # Send failure notification, trigger rollback
      
      - name: Run smoke tests
        if: github.event.deployment_status.state == 'success'
        run: |
          echo "Running smoke tests on ${{ github.event.deployment_status.environment_url }}"
          # Execute smoke tests
```

**වැදගත් deployment states:**
- `error` - Deployment error
- `failure` - Deployment failed
- `inactive` - Deployment inactive
- `in_progress` - Deployment in progress
- `queued` - Deployment queued
- `pending` - Deployment pending
- `success` - Deployment successful

**වැදගත් context variables:**
- `github.event.deployment_status.state` - Deployment state
- `github.event.deployment_status.environment` - Environment name
- `github.event.deployment_status.environment_url` - Deployed application URL
- `github.event.deployment_status.description` - Status description
- `github.event.deployment.sha` - Deployed commit SHA

**Use cases:**
- Deployment notifications
- Post-deployment smoke tests
- Automated rollback on failure
- Deployment metrics collection

### **`status`**
Commit එකක status check එකක් වෙනස් වන විට trigger වේ. CI/CD status updates සඳහා භාවිතා වේ.

```yaml
on:
  status:
```

Status check monitoring:

```yaml
jobs:
  handle-status:
    runs-on: ubuntu-latest
    steps:
      - name: Status details
        run: |
          echo "State: ${{ github.event.state }}"
          echo "Context: ${{ github.event.context }}"
          echo "Description: ${{ github.event.description }}"
          echo "Target URL: ${{ github.event.target_url }}"
          echo "Commit SHA: ${{ github.event.sha }}"
      
      - name: On success
        if: github.event.state == 'success'
        run: |
          echo "✅ All checks passed for ${{ github.event.sha }}"
          # Trigger next step in pipeline
      
      - name: On failure
        if: github.event.state == 'failure'
        run: |
          echo "❌ Checks failed for ${{ github.event.sha }}"
          # Send notification, create issue
```

**වැදගත් status states:**
- `pending` - Check pending
- `success` - Check passed
- `failure` - Check failed
- `error` - Check error

**වැදගත් context variables:**
- `github.event.state` - Status state
- `github.event.context` - Status context/name
- `github.event.description` - Status description
- `github.event.sha` - Commit SHA
- `github.event.target_url` - Details URL

**Use cases:**
- CI/CD pipeline orchestration
- Status aggregation
- Deployment gate automation
- Build notifications

### **`check_run`**
Check run එකක් නිර්මාණය කරන විට, යාවත්කාලීන කරන විට, හෝ සම්පූර්ණ කරන විට trigger වේ. CI checks කළමනාකරණය කිරීම සඳහා භාවිතා වේ.

```yaml
on:
  check_run:
    types:
      - created       # Check run නිර්මාණය කරන විට
      - completed     # Check run සම්පූර්ණ කරන විට
      - rerequested   # Check run නැවත request කරන විට
      - requested_action  # Action button ක්ලික් කරන විට
```

Check run automation:

```yaml
jobs:
  handle-check-run:
    runs-on: ubuntu-latest
    steps:
      - name: Check run details
        run: |
          echo "Action: ${{ github.event.action }}"
          echo "Check name: ${{ github.event.check_run.name }}"
          echo "Status: ${{ github.event.check_run.status }}"
          echo "Conclusion: ${{ github.event.check_run.conclusion }}"
          echo "SHA: ${{ github.event.check_run.head_sha }}"
      
      - name: Handle completion
        if: github.event.action == 'completed'
        run: |
          if [ "${{ github.event.check_run.conclusion }}" == "success" ]; then
            echo "✅ Check passed: ${{ github.event.check_run.name }}"
          elif [ "${{ github.event.check_run.conclusion }}" == "failure" ]; then
            echo "❌ Check failed: ${{ github.event.check_run.name }}"
          fi
      
      - name: Handle rerun request
        if: github.event.action == 'rerequested'
        run: |
          echo "🔄 Re-running check: ${{ github.event.check_run.name }}"
          # Re-run the check
```

**වැදගත් check statuses:**
- `queued` - Check queued
- `in_progress` - Check running
- `completed` - Check completed

**වැදගත් check conclusions:**
- `success` - Check passed
- `failure` - Check failed
- `neutral` - Check neutral
- `cancelled` - Check cancelled
- `skipped` - Check skipped
- `timed_out` - Check timed out
- `action_required` - Action required

**වැදගත් context variables:**
- `github.event.check_run.name` - Check name
- `github.event.check_run.status` - Check status
- `github.event.check_run.conclusion` - Check conclusion
- `github.event.check_run.head_sha` - Commit SHA
- `github.event.check_run.output.title` - Check output title
- `github.event.check_run.output.summary` - Check output summary

**Use cases:**
- Check result aggregation
- Failed check notifications
- Re-run automation
- Check metrics collection

### **`check_suite`**
Check suite එකක් නිර්මාණය කරන විට හෝ සම්පූර්ණ කරන විට trigger වේ. Multiple checks එකට run කිරීම සඳහා භාවිතා වේ.

```yaml
on:
  check_suite:
    types:
      - completed     # Check suite සම්පූර්ණ කරන විට
      - requested     # Check suite request කරන විට
      - rerequested   # Check suite නැවත request කරන විට
```

Check suite handling:

```yaml
jobs:
  handle-check-suite:
    runs-on: ubuntu-latest
    steps:
      - name: Suite details
        run: |
          echo "Action: ${{ github.event.action }}"
          echo "Conclusion: ${{ github.event.check_suite.conclusion }}"
          echo "SHA: ${{ github.event.check_suite.head_sha }}"
          echo "Branch: ${{ github.event.check_suite.head_branch }}"
      
      - name: All checks passed
        if: |
          github.event.action == 'completed' &&
          github.event.check_suite.conclusion == 'success'
        run: |
          echo "✅ All checks passed for ${{ github.event.check_suite.head_sha }}"
          # Trigger deployment or next pipeline stage
      
      - name: Some checks failed
        if: |
          github.event.action == 'completed' &&
          github.event.check_suite.conclusion == 'failure'
        run: |
          echo "❌ Some checks failed"
          # Send notification, create issue
```

**වැදගත් context variables:**
- `github.event.check_suite.conclusion` - Overall conclusion
- `github.event.check_suite.status` - Suite status
- `github.event.check_suite.head_sha` - Commit SHA
- `github.event.check_suite.head_branch` - Branch name

**Use cases:**
- Gating deployments on all checks passing
- Suite-level notifications
- Pipeline orchestration
- Quality gate enforcement

### **`page_build`**
GitHub Pages site එකක් build කරන යෑම සිදු වන විට trigger වේ. Static site deployment tracking සඳහා භාවිතා වේ.

```yaml
on:
  page_build:
```

Pages build monitoring:

```yaml
jobs:
  monitor-pages-build:
    runs-on: ubuntu-latest
    steps:
      - name: Build details
        run: |
          echo "Build status: ${{ github.event.build.status }}"
          echo "Build error: ${{ github.event.build.error.message }}"
          echo "Commit: ${{ github.event.build.commit }}"
      
      - name: On success
        if: github.event.build.status == 'built'
        run: |
          echo "✅ GitHub Pages built successfully"
          echo "URL: https://${{ github.repository_owner }}.github.io/${{ github.event.repository.name }}"
          # Send notification, run tests on deployed site
      
      - name: On failure
        if: github.event.build.status == 'errored'
        run: |
          echo "❌ GitHub Pages build failed"
          echo "Error: ${{ github.event.build.error.message }}"
          # Create issue, send notification
```

**වැදගත් build statuses:**
- `built` - Build successful
- `errored` - Build failed

**වැදගත් context variables:**
- `github.event.build.status` - Build status
- `github.event.build.error.message` - Error message (if failed)
- `github.event.build.commit` - Commit SHA
- `github.event.build.duration` - Build duration

**Use cases:**
- Pages deployment notifications
- Post-deployment testing
- Build failure alerts
- Deployment metrics

### **`registry_package`**
GitHub Package Registry එකේ package එකක් publish කරන විට, යාවත්කාලීන කරන විට, හෝ මකා දමන විට trigger වේ. Package management සඳහා භාවිතා වේ.

```yaml
on:
  registry_package:
    types:
      - published   # Package publish කරන විට
      - updated     # Package යාවත්කාලීන කරන විට
```

Package automation:

```yaml
jobs:
  handle-package:
    runs-on: ubuntu-latest
    steps:
      - name: Package details
        run: |
          echo "Action: ${{ github.event.action }}"
          echo "Package: ${{ github.event.registry_package.name }}"
          echo "Type: ${{ github.event.registry_package.package_type }}"
          echo "Version: ${{ github.event.registry_package.package_version.version }}"
      
      - name: On publish
        if: github.event.action == 'published'
        run: |
          echo "📦 New package published!"
          echo "Package: ${{ github.event.registry_package.name }}"
          echo "Version: ${{ github.event.registry_package.package_version.version }}"
          # Send notifications, trigger downstream builds
      
      - name: Scan package
        if: github.event.action == 'published'
        run: |
          echo "🔍 Scanning package for vulnerabilities..."
          # Run security scans
```

**වැදගත් package types:**
- `npm` - npm packages
- `docker` - Container images
- `maven` - Maven packages
- `nuget` - NuGet packages
- `rubygems` - Ruby gems

**වැදගත් context variables:**
- `github.event.registry_package.name` - Package name
- `github.event.registry_package.package_type` - Package type
- `github.event.registry_package.package_version.version` - Version
- `github.event.registry_package.owner.login` - Package owner

**Use cases:**
- Package publication notifications
- Automated security scanning
- Downstream build triggers
- Package metrics collection

## Repository Activity

### **`fork`**
කෙනෙකු repository එක fork කරන විට trigger වේ. Repository එක copy කරන විට ක්‍රියාත්මක වේ. Community engagement සහ project popularity tracking සඳහා භාවිතා වේ.

මෙම event එකට types නොමැත - fork සිදු වන සෑම අවස්ථාවකම trigger වේ:

```yaml
on:
  fork:
```

Fork tracking සහ automation:

```yaml
jobs:
  welcome-forker:
    runs-on: ubuntu-latest
    steps:
      - name: Fork details
        run: |
          echo "Forked by: ${{ github.event.forkee.owner.login }}"
          echo "Fork URL: ${{ github.event.forkee.html_url }}"
          echo "Fork full name: ${{ github.event.forkee.full_name }}"
          echo "Forked at: ${{ github.event.forkee.created_at }}"
      
      - name: Thank the forker
        uses: actions/github-script@v6
        with:
          github-token: ${{ secrets.GITHUB_TOKEN }}
          script: |
            const forker = context.payload.forkee.owner.login;
            console.log(`🍴 Repository forked by ${forker}`);
            
            // Optional: Create an issue to welcome the forker
            // or send them a message (requires additional permissions)
      
      - name: Track fork statistics
        run: |
          echo "Total forks: ${{ github.event.repository.forks_count }}"
          # Log fork data to analytics service
      
      - name: Notify team
        run: |
          echo "📊 New fork detected!"
          echo "User: ${{ github.event.forkee.owner.login }}"
          # Send notification to Slack, Discord, etc.
```

Fork analytics automation:

```yaml
jobs:
  fork-analytics:
    runs-on: ubuntu-latest
    steps:
      - name: Collect fork data
        uses: actions/github-script@v6
        with:
          script: |
            const fork = context.payload.forkee;
            const data = {
              forker: fork.owner.login,
              fork_url: fork.html_url,
              fork_name: fork.full_name,
              timestamp: fork.created_at,
              repository_stars: context.payload.repository.stargazers_count,
              repository_forks: context.payload.repository.forks_count
            };
            
            console.log('Fork Data:', JSON.stringify(data, null, 2));
            // Send to analytics platform
      
      - name: Update fork list
        run: |
          echo "Updating fork tracking dashboard..."
          # Update internal dashboard or database
```

**වැදගත් context variables:**
- `github.event.forkee.owner.login` - Fork කළ user username
- `github.event.forkee.html_url` - Fork repository URL
- `github.event.forkee.full_name` - Fork repository full name (owner/repo)
- `github.event.forkee.created_at` - Fork creation timestamp
- `github.event.forkee.clone_url` - Fork clone URL
- `github.event.repository.forks_count` - Total forks count

**Use cases:**
- Welcome messages to contributors who fork
- Fork statistics tracking
- Community growth metrics
- Contributor identification
- Project popularity monitoring
- Team notifications for new forks

**වැදගත්:** මෙම event එක public repositories සඳහා පමණක් ක්‍රියාත්මක වේ.

### **`watch`**
කෙනෙකු repository එක star කරන විට trigger වේ. Repository එකට අනුමත කිරීම් ලබා ගන්නා විට ක්‍රියාත්මක වේ. Community engagement සහ popularity tracking සඳහා භාවිතා වේ.

`types` option භාවිතා කරමින් star events handle කිරීම:

```yaml
on:
  watch:
    types:
      - started   # Repository එකට star කරන විට පමණක්
```

**වැදගත්:** GitHub API එකේ "watch" යන්නෙන් අදහස් කරන්නේ "star" ක්‍රියාවයි. Repository එකක් watch කිරීම (notifications සඳහා) වෙනත් action එකකි.

Star tracking automation:

```yaml
jobs:
  track-star:
    runs-on: ubuntu-latest
    steps:
      - name: Star event details
        run: |
          echo "Starred by: ${{ github.event.sender.login }}"
          echo "User profile: ${{ github.event.sender.html_url }}"
          echo "Total stars: ${{ github.event.repository.stargazers_count }}"
          echo "Starred at: ${{ github.event.repository.updated_at }}"
      
      - name: Thank the stargazer
        run: |
          echo "⭐ Thank you ${{ github.event.sender.login }} for starring!"
          # Send personalized thank you message (if applicable)
      
      - name: Milestone celebration
        if: github.event.repository.stargazers_count % 100 == 0
        run: |
          echo "🎉 Milestone reached: ${{ github.event.repository.stargazers_count }} stars!"
          # Create celebratory issue or social media post
      
      - name: Update star analytics
        uses: actions/github-script@v6
        with:
          script: |
            const data = {
              user: context.payload.sender.login,
              user_url: context.payload.sender.html_url,
              total_stars: context.payload.repository.stargazers_count,
              timestamp: new Date().toISOString()
            };
            
            console.log('Star Event:', JSON.stringify(data, null, 2));
            // Log to analytics service
```

Star milestone automation:

```yaml
jobs:
  star-milestones:
    runs-on: ubuntu-latest
    steps:
      - name: Check for milestones
        id: milestone
        run: |
          STARS=${{ github.event.repository.stargazers_count }}
          
          if [ $((STARS % 1000)) -eq 0 ]; then
            echo "milestone=major" >> $GITHUB_OUTPUT
            echo "count=$STARS" >> $GITHUB_OUTPUT
          elif [ $((STARS % 100)) -eq 0 ]; then
            echo "milestone=minor" >> $GITHUB_OUTPUT
            echo "count=$STARS" >> $GITHUB_OUTPUT
          fi
      
      - name: Create milestone issue
        if: steps.milestone.outputs.milestone
        uses: actions/github-script@v6
        with:
          script: |
            const stars = '${{ steps.milestone.outputs.count }}';
            const type = '${{ steps.milestone.outputs.milestone }}';
            
            await github.rest.issues.create({
              owner: context.repo.owner,
              repo: context.repo.repo,
              title: `🎉 ${stars} Stars Milestone!`,
              body: `We've reached ${stars} stars! Thank you to all our supporters! ⭐`,
              labels: ['milestone', 'community']
            });
      
      - name: Tweet milestone
        if: steps.milestone.outputs.milestone == 'major'
        run: |
          echo "Tweeting about ${{ steps.milestone.outputs.count }} stars milestone!"
          # Post to social media
```

**වැදගත් `types` options:**
- `started` - Repository එකට star කරන විට (එකම available type එක)

**වැදගත් context variables:**
- `github.event.sender.login` - Star කළ user username
- `github.event.sender.html_url` - User profile URL
- `github.event.repository.stargazers_count` - Total stars count
- `github.event.repository.html_url` - Repository URL

**Use cases:**
- Thank you messages to stargazers
- Star milestone celebrations
- Community growth tracking
- Popularity metrics
- Social media automation
- Contributor recognition

**වැදගත්:** Unstarring repository එකක් කරන විට event එකක් trigger නොවේ.

### **`public`**
Private repository එකක් public කරන විට trigger වේ. Visibility වෙනස් වන විට ක්‍රියාත්මක වේ. Security සහ compliance monitoring සඳහා වැදගත්.

මෙම event එකට types නොමැත - repository public කරන විට පමණක් trigger වේ:

```yaml
on:
  public:
```

Repository visibility change handling:

```yaml
jobs:
  handle-public-event:
    runs-on: ubuntu-latest
    steps:
      - name: Repository made public
        run: |
          echo "⚠️ Repository is now public!"
          echo "Repository: ${{ github.event.repository.full_name }}"
          echo "Owner: ${{ github.event.repository.owner.login }}"
          echo "URL: ${{ github.event.repository.html_url }}"
          echo "Made public by: ${{ github.event.sender.login }}"
      
      - name: Security audit
        run: |
          echo "Running security audit..."
          # Check for sensitive data, secrets, tokens
          # Scan for hardcoded credentials
      
      - name: Notify security team
        run: |
          echo "🔔 Notifying security team about visibility change"
          # Send alert to security team
          # Log event to security information system
      
      - name: Check for sensitive files
        uses: actions/checkout@v3
      
      - name: Scan for secrets
        run: |
          echo "Scanning for exposed secrets..."
          # Use secret scanning tools
          # Check for .env files, API keys, etc.
```

Compliance and security automation:

```yaml
jobs:
  compliance-check:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout repository
        uses: actions/checkout@v3
      
      - name: Scan for sensitive data
        run: |
          echo "Performing security scan..."
          
          # Check for common sensitive files
          if [ -f ".env" ]; then
            echo "⚠️ .env file found!"
          fi
          
          if [ -f "config/secrets.yml" ]; then
            echo "⚠️ secrets.yml file found!"
          fi
          
          # Scan for patterns like API keys
          grep -r "api_key\|secret\|password\|token" . || true
      
      - name: Update documentation
        run: |
          echo "Checking if README is appropriate for public repository..."
          # Verify documentation is public-ready
      
      - name: Create audit issue
        uses: actions/github-script@v6
        with:
          script: |
            await github.rest.issues.create({
              owner: context.repo.owner,
              repo: context.repo.repo,
              title: '🔓 Repository Made Public - Security Audit Required',
              body: `This repository was made public at ${new Date().toISOString()}.
              
              **Required Actions:**
              - [ ] Verify no secrets are exposed
              - [ ] Review all file contents
              - [ ] Update documentation for public audience
              - [ ] Check license file
              - [ ] Review issue/PR history
              
              Made public by: @${{ github.event.sender.login }}`,
              labels: ['security', 'audit'],
              assignees: ['security-team-lead']
            });
      
      - name: Enable security features
        uses: actions/github-script@v6
        with:
          script: |
            // Enable security features for public repo
            try {
              // Enable vulnerability alerts
              await github.rest.repos.enableVulnerabilityAlerts({
                owner: context.repo.owner,
                repo: context.repo.repo
              });
              
              console.log('✅ Vulnerability alerts enabled');
            } catch (error) {
              console.log('Error enabling security features:', error);
            }
```

**වැදගත් context variables:**
- `github.event.repository.full_name` - Repository full name
- `github.event.repository.html_url` - Repository URL
- `github.event.repository.private` - `false` (now public)
- `github.event.sender.login` - User who made repo public
- `github.event.repository.visibility` - `public`

**Use cases:**
- Security audits when repository becomes public
- Sensitive data scanning
- Compliance notifications
- Automated security feature enablement
- Team alerts for visibility changes
- Audit trail creation

**වැදගත්:** මෙය critical security event එකකි - repository එකක් public වීමෙන් සියලුම code, issues, සහ history public වේ.

### **`gollum`**
Wiki page එකක් නිර්මාණය කරන විට හෝ යාවත්කාලීන කරන විට trigger වේ. Repository wiki changes track කිරීම සඳහා භාවිතා වේ. Documentation management සහ collaboration tracking සඳහා උපයෝගී වේ.

මෙම event එකට types නොමැත - wiki වෙනස්කම් සියල්ල capture කරයි:

```yaml
on:
  gollum:
```

Wiki change tracking:

```yaml
jobs:
  track-wiki-changes:
    runs-on: ubuntu-latest
    steps:
      - name: Wiki changes details
        run: |
          echo "Changed by: ${{ github.event.sender.login }}"
          echo "Number of pages changed: ${{ github.event.pages.length }}"
      
      - name: Process each page
        uses: actions/github-script@v6
        with:
          script: |
            const pages = context.payload.pages;
            
            for (const page of pages) {
              console.log(`\nPage: ${page.title}`);
              console.log(`Action: ${page.action}`);
              console.log(`URL: ${page.html_url}`);
              console.log(`SHA: ${page.sha}`);
              
              if (page.action === 'created') {
                console.log('📝 New wiki page created');
              } else if (page.action === 'edited') {
                console.log('✏️  Wiki page edited');
              }
            }
      
      - name: Notify documentation team
        run: |
          echo "📚 Wiki updated by ${{ github.event.sender.login }}"
          # Send notification to documentation team
```

Wiki change validation and automation:

```yaml
jobs:
  wiki-automation:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout wiki
        uses: actions/checkout@v3
        with:
          repository: ${{ github.repository }}.wiki
      
      - name: Analyze changes
        uses: actions/github-script@v6
        with:
          script: |
            const pages = context.payload.pages;
            
            for (const page of pages) {
              const action = page.action; // 'created' or 'edited'
              const title = page.title;
              const pageName = page.page_name;
              
              console.log(`Processing ${action} page: ${title}`);
              
              // Track changes
              if (action === 'created') {
                // New page created
                await github.rest.issues.createComment({
                  owner: context.repo.owner,
                  repo: context.repo.repo,
                  issue_number: 1, // Documentation tracking issue
                  body: `📝 New wiki page created: [${title}](${page.html_url}) by @${context.payload.sender.login}`
                });
              }
            }
      
      - name: Check for formatting issues
        run: |
          echo "Checking wiki pages for formatting issues..."
          # Run markdown linter or spell checker
      
      - name: Update wiki index
        run: |
          echo "Updating wiki index/table of contents..."
          # Auto-generate wiki index page
      
      - name: Create backup
        run: |
          echo "Creating wiki backup..."
          # Backup wiki content to separate repository
```

Wiki metrics and notifications:

```yaml
jobs:
  wiki-metrics:
    runs-on: ubuntu-latest
    steps:
      - name: Collect wiki statistics
        uses: actions/github-script@v6
        with:
          script: |
            const pages = context.payload.pages;
            const user = context.payload.sender.login;
            
            const metrics = {
              editor: user,
              pages_modified: pages.length,
              pages_created: pages.filter(p => p.action === 'created').length,
              pages_edited: pages.filter(p => p.action === 'edited').length,
              timestamp: new Date().toISOString()
            };
            
            console.log('Wiki Metrics:', JSON.stringify(metrics, null, 2));
            // Send to analytics platform
      
      - name: Recognize contributors
        uses: actions/github-script@v6
        with:
          script: |
            const pages = context.payload.pages;
            const newPages = pages.filter(p => p.action === 'created');
            
            if (newPages.length > 0) {
              console.log(`🎉 ${context.payload.sender.login} created ${newPages.length} new wiki page(s)!`);
              // Add contributor badge or recognition
            }
```

**වැදගත් page actions:**
- `created` - නව wiki page නිර්මාණය කරන විට
- `edited` - Existing wiki page සංස්කරණය කරන විට

**වැදගත් context variables:**
- `github.event.pages` - වෙනස් වූ pages array
- `github.event.pages[].page_name` - Page filename
- `github.event.pages[].title` - Page title
- `github.event.pages[].action` - `created` හෝ `edited`
- `github.event.pages[].sha` - Page commit SHA
- `github.event.pages[].html_url` - Page URL
- `github.event.sender.login` - User who made changes

**Use cases:**
- Documentation change notifications
- Wiki content validation
- Automatic wiki indexing
- Documentation team alerts
- Wiki backup automation
- Contributor recognition
- Content quality checks
- Spell checking and formatting validation

**වැදගත්:** Wiki enabled කර නැති නම් මෙම event trigger නොවේ. Wiki එක Git repository එකක් ලෙස clone කර edit කළ හැකිය.