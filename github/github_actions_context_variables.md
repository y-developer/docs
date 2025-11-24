# GitHub Actions Default Context Variables

## GitHub Context Variables (`github.*`)

| Variable                     | Description                                                   | Example                                                        |
| ---------------------------- | ------------------------------------------------------------- | -------------------------------------------------------------- |
| `github.action`              | The name of the action currently running, or the id of a step | `run1` or `my-custom-action`                                   |
| `github.action_path`         | The path where your action is located                         | `/home/runner/work/_actions/actions/checkout/v4`               |
| `github.action_ref`          | The ref of the action being run                               | `v4`                                                           |
| `github.action_repository`   | The owner and repository name of the action                   | `actions/checkout`                                             |
| `github.action_status`       | The result of a composite action                              | `success`                                                      |
| `github.actor`               | Username of the person who triggered the workflow             | `octocat`                                                      |
| `github.actor_id`            | The account ID of the person who triggered the workflow       | `583231`                                                       |
| `github.api_url`             | The API URL for GitHub                                        | `https://api.github.com`                                       |
| `github.base_ref`            | The base branch of the pull request (target branch)           | `main`                                                         |
| `github.env`                 | Path to the file that sets environment variables              | `/home/runner/work/_temp/_runner_file_commands/set_env_...`    |
| `github.event`               | The full webhook event payload                                | `{ "push": {...} }`                                            |
| `github.event_name`          | The name of the event that triggered the workflow             | `push`, `pull_request`, `workflow_dispatch`                    |
| `github.event_path`          | Path to the file containing the full event payload            | `/home/runner/work/_temp/_github_workflow/event.json`          |
| `github.graphql_url`         | The GraphQL API URL                                           | `https://api.github.com/graphql`                               |
| `github.head_ref`            | The source branch of the pull request                         | `feature-branch`                                               |
| `github.job`                 | The job ID of the current job                                 | `build`                                                        |
| `github.path`                | Path to the file that sets system PATH variables              | `/home/runner/work/_temp/_runner_file_commands/add_path_...`   |
| `github.ref`                 | The full git ref that triggered the workflow                  | `refs/heads/main` or `refs/tags/v1.0.0`                        |
| `github.ref_name`            | The short ref name (branch or tag name)                       | `main` or `v1.0.0`                                             |
| `github.ref_protected`       | Whether the ref is protected                                  | `true` or `false`                                              |
| `github.ref_type`            | The type of ref                                               | `branch` or `tag`                                              |
| `github.repository`          | Owner and repository name                                     | `octocat/Hello-World`                                          |
| `github.repository_id`       | The ID of the repository                                      | `1296269`                                                      |
| `github.repository_owner`    | The repository owner's username                               | `octocat`                                                      |
| `github.repository_owner_id` | The repository owner's account ID                             | `583231`                                                       |
| `github.repositoryUrl`       | The Git URL to the repository                                 | `git://github.com/octocat/Hello-World.git`                     |
| `github.retention_days`      | Days that workflow logs and artifacts are retained            | `90`                                                           |
| `github.run_id`              | Unique number for each workflow run                           | `1658821493`                                                   |
| `github.run_number`          | Unique number for each run of a workflow                      | `3`                                                            |
| `github.run_attempt`         | Unique number for each attempt of a workflow run              | `1` or `2` (if re-run)                                         |
| `github.secret_source`       | Source of a secret used in a workflow                         | `Actions` or `Dependabot`                                      |
| `github.server_url`          | The URL of the GitHub server                                  | `https://github.com`                                           |
| `github.sha`                 | The commit SHA that triggered the workflow                    | `ffac537e6cbbf934b08745a378932722df287a53`                     |
| `github.token`               | Automatically generated token for authenticating              | `***` (secret)                                                 |
| `github.triggering_actor`    | Username of person who initiated the workflow run             | `octocat`                                                      |
| `github.workflow`            | The name of the workflow                                      | `CI`                                                           |
| `github.workflow_ref`        | The ref path to the workflow                                  | `octocat/Hello-World/.github/workflows/ci.yml@refs/heads/main` |
| `github.workflow_sha`        | The commit SHA for the workflow file                          | `ffac537e6cbbf934b08745a378932722df287a53`                     |
| `github.workspace`           | The default working directory path                            | `/home/runner/work/Hello-World/Hello-World`                    |

## Runner Context Variables (`runner.*`)

| Variable             | Description                                      | Example                          |
| -------------------- | ------------------------------------------------ | -------------------------------- |
| `runner.name`        | The name of the runner executing the job         | `GitHub Actions 2`               |
| `runner.os`          | The operating system of the runner               | `Linux`, `Windows`, or `macOS`   |
| `runner.arch`        | The architecture of the runner                   | `X64`, `ARM`, or `ARM64`         |
| `runner.temp`        | Path to temporary directory on the runner        | `/home/runner/work/_temp`        |
| `runner.tool_cache`  | Path to directory containing pre-installed tools | `/opt/hostedtoolcache`           |
| `runner.debug`       | Whether debug logging is enabled                 | `1` or empty                     |
| `runner.environment` | The runner environment                           | `github-hosted` or `self-hosted` |

## Job Context Variables (`job.*`)

| Variable                | Description                            | Example                              |
| ----------------------- | -------------------------------------- | ------------------------------------ |
| `job.container.id`      | The ID of the job's container          | `d8c5f1e85b4d`                       |
| `job.container.network` | The network ID of the job's container  | `github_network_1234`                |
| `job.services`          | Service containers created for the job | `{ "redis": {...} }`                 |
| `job.status`            | The current status of the job          | `success`, `failure`, or `cancelled` |

## Steps Context Variables (`steps.*`)

| Variable                                | Description                                  | Example                                         |
| --------------------------------------- | -------------------------------------------- | ----------------------------------------------- |
| `steps.<step_id>.outputs.<output_name>` | Output value from a previous step            | `steps.build.outputs.version` → `1.2.3`         |
| `steps.<step_id>.conclusion`            | Result of a completed step                   | `success`, `failure`, `cancelled`, or `skipped` |
| `steps.<step_id>.outcome`               | Result before `continue-on-error` is applied | `success` or `failure`                          |

## Environment Variables (`env.*`)

| Variable         | Description                                  | Example                       |
| ---------------- | -------------------------------------------- | ----------------------------- |
| `env.<env_name>` | Access environment variables set in workflow | `env.NODE_ENV` → `production` |

## Secrets Context (`secrets.*`)

| Variable                | Description                                 | Example                   |
| ----------------------- | ------------------------------------------- | ------------------------- |
| `secrets.<secret_name>` | Access encrypted secrets                    | `secrets.DOCKER_PASSWORD` |
| `secrets.GITHUB_TOKEN`  | Automatically provided authentication token | `***` (auto-generated)    |

## Matrix Context (`matrix.*`)

| Variable            | Description                        | Example                          |
| ------------------- | ---------------------------------- | -------------------------------- |
| `matrix.<property>` | Current value from matrix strategy | `matrix.node` → `14`, `16`, `18` |

## Needs Context (`needs.*`)

| Variable                               | Description                                 | Example                                         |
| -------------------------------------- | ------------------------------------------- | ----------------------------------------------- |
| `needs.<job_id>.result`                | Result of a job that current job depends on | `success`, `failure`, `cancelled`, or `skipped` |
| `needs.<job_id>.outputs.<output_name>` | Output from a dependent job                 | `needs.build.outputs.image_tag` → `v1.0.0`      |

## Inputs Context (`inputs.*`)

| Variable              | Description                                  | Example                          |
| --------------------- | -------------------------------------------- | -------------------------------- |
| `inputs.<input_name>` | Input value for manually triggered workflows | `inputs.environment` → `staging` |

## Useful Environment Variables

| Variable            | Description                                         | Example                                    |
| ------------------- | --------------------------------------------------- | ------------------------------------------ |
| `GITHUB_ACTIONS`    | Always set to `true` when running in GitHub Actions | `true`                                     |
| `CI`                | Always set to `true` in CI environment              | `true`                                     |
| `GITHUB_WORKSPACE`  | Default working directory path                      | `/home/runner/work/repo/repo`              |
| `GITHUB_REPOSITORY` | Owner and repository name                           | `octocat/Hello-World`                      |
| `GITHUB_SHA`        | Commit SHA that triggered workflow                  | `ffac537e6cbbf934b08745a378932722df287a53` |
| `GITHUB_REF`        | Full git ref                                        | `refs/heads/main`                          |
| `GITHUB_HEAD_REF`   | Source branch of PR (only for pull_request)         | `feature-branch`                           |
| `GITHUB_BASE_REF`   | Target branch of PR (only for pull_request)         | `main`                                     |
| `GITHUB_ACTOR`      | Username who triggered the workflow                 | `octocat`                                  |
| `GITHUB_RUN_ID`     | Unique run ID                                       | `1658821493`                               |
| `GITHUB_RUN_NUMBER` | Unique run number for workflow                      | `42`                                       |

## Usage Examples

### Example 1: Docker Image Tagging
```yaml
- name: Build and tag
  run: |
    docker build -t ${{ github.repository }}:${{ github.sha }} .
    docker tag ${{ github.repository }}:${{ github.sha }} ${{ github.repository }}:latest
```

### Example 2: Conditional Execution
```yaml
- name: Deploy to production
  if: github.ref == 'refs/heads/main' && github.event_name == 'push'
  run: ./deploy.sh
```

### Example 3: PR Information
```yaml
- name: Comment on PR
  if: github.event_name == 'pull_request'
  run: |
    echo "PR from ${{ github.head_ref }} to ${{ github.base_ref }}"
    echo "Opened by ${{ github.actor }}"
```

### Example 4: Using Step Outputs
```yaml
- name: Get version
  id: version
  run: echo "tag=v1.2.3" >> $GITHUB_OUTPUT

- name: Use version
  run: echo "Version is ${{ steps.version.outputs.tag }}"
```

### Example 5: Matrix Strategy
```yaml
strategy:
  matrix:
    node: [14, 16, 18]
    os: [ubuntu-latest, windows-latest]

steps:
  - name: Setup Node
    uses: actions/setup-node@v3
    with:
      node-version: ${{ matrix.node }}
  
  - name: Show info
    run: echo "Testing on Node ${{ matrix.node }} with ${{ matrix.os }}"
```

### Example 6: Dependent Jobs
```yaml
jobs:
  build:
    runs-on: ubuntu-latest
    outputs:
      image_tag: ${{ steps.meta.outputs.tag }}
    steps:
      - id: meta
        run: echo "tag=v1.0.0" >> $GITHUB_OUTPUT

  deploy:
    needs: build
    runs-on: ubuntu-latest
    steps:
      - name: Deploy
        run: |
          echo "Deploying ${{ needs.build.outputs.image_tag }}"
```

---

**Note:** For Gitea Actions, replace `github.*` with `gitea.*` for most variables. The structure and usage are similar!