# Github Actions Environment Variables

- [Github Actions Environment Variables](#github-actions-environment-variables)
  - [Environment Variable Scopes](#environment-variable-scopes)
  - [$GITHUB\_ENV භාවිතා කිරීම](#github_env-භාවිතා-කිරීම)
    - [උදාරහරණ කීපයක්](#උදාරහරණ-කීපයක්)
      - [Basic Usage - $GITHUB\_ENV භාවිතා කිරීම](#basic-usage---github_env-භාවිතා-කිරීම)
      - [Practical Example 1: Build Configuration](#practical-example-1-build-configuration)
      - [Practical Example 2: Dynamic Version Management](#practical-example-2-dynamic-version-management)
      - [Practical Example 3: Database Connection Configuration](#practical-example-3-database-connection-configuration)
      - [Practical Example 4: Multi-Step Build Pipeline](#practical-example-4-multi-step-build-pipeline)
      - [Practical Example 5: AWS Deployment with Dynamic Config](#practical-example-5-aws-deployment-with-dynamic-config)
    - [වැදගත් Tips - $GITHUB\_ENV භාවිතා කිරීම සඳහා](#වැදගත්-tips---github_env-භාවිතා-කිරීම-සඳහා)
  - [$GITHUB\_OUTPUT භාවිතා කිරීම](#github_output-භාවිතා-කිරීම)
    - [Passing Variables](#passing-variables)
      - [Steps අතර variables pass කිරීම](#steps-අතර-variables-pass-කිරීම)
      - [Jobs අතර variables pass කිරීම](#jobs-අතර-variables-pass-කිරීම)
    - [උදාරහරණ කීපයක්](#උදාරහරණ-කීපයක්-1)
      - [Multiple jobs සමඟ complex workflow එකක්](#multiple-jobs-සමඟ-complex-workflow-එකක්)
      - [Practical Example: Docker Build සහ Deploy](#practical-example-docker-build-සහ-deploy)
    - [**වැදගත් Tips - $GITHUB\_OUTPUT භාවිතා කිරීම සඳහා**](#වැදගත්-tips---github_output-භාවිතා-කිරීම-සඳහා)
  - [$GITHUB\_ENV vs $GITHUB\_OUTPUT](#github_env-vs-github_output)
    - [$GITHUB\_ENV සහ $GITHUB\_OUTPUT අතර වෙනස](#github_env-සහ-github_output-අතර-වෙනස)
    - [$GITHUB\_ENV සහ $GITHUB\_OUTPUT භාවිතා කරන්නේ මොනඅවස්ථා වලදීද?](#github_env-සහ-github_output-භාවිතා-කරන්නේ-මොනඅවස්ථා-වලදීද)


GitHub Actions workflow එකක් තුළ environment variables භාවිතා කළ හැක. Environment variables මඟින් workflow එකේ steps අතර දත්ත හුවමාරු කිරීම පහසු වේ. Environment variables define කිරීම සඳහා `env` keyword එක භාවිතා කරයි.

## Environment Variable Scopes

environment variables define කිරීම  `workflow`, `job`, සහ `step` යන scope 3 ක් තුල සිදුකල හැක.

**Workflow scope:**

```yaml
name: Workflow with Environment Variables
on: [push]
env:
  GLOBAL_VAR: 'This is a global variable'

jobs:
  example-job:
    runs-on: ubuntu-latest
    steps:
      - name: Print Global Variable
        run: echo $GLOBAL_VAR
```

**Job scope:**

```yaml
jobs:
  example-job:
    runs-on: ubuntu-latest
    env:
      JOB_VAR: 'This is a job variable'
    steps:
      - name: Print Job Variable
        run: echo $JOB_VAR
```

**Step scope:**

```yaml
jobs:
  example-job:
    runs-on: ubuntu-latest
    steps:
      - name: Print Step Variable
        env:
          STEP_VAR: 'This is a step variable'
        run: echo $STEP_VAR
```

## $GITHUB_ENV භාවිතා කිරීම

`$GITHUB_ENV` යනු workflow එකේ steps අතර environment variables dynamically set කිරීමට භාවිතා කරන විශේෂ file එකකි. මෙය `$GITHUB_OUTPUT` වලට සමානයි, නමුත් environment variables සඳහා භාවිතා වේ.

### උදාරහරණ කීපයක්
#### Basic Usage - $GITHUB_ENV භාවිතා කිරීම

```yaml
name: GITHUB_ENV Example
on:
  workflow_dispatch

jobs:
  example:
    runs-on: ubuntu-latest
    steps:
      # Step 1: Environment variable එකක් set කිරීම
      - name: Set environment variable
        run: |
          echo "APP_VERSION=1.2.3" >> $GITHUB_ENV
          echo "BUILD_NUMBER=456" >> $GITHUB_ENV
          echo "ENVIRONMENT=production" >> $GITHUB_ENV
      
      # Step 2: Set කළ environment variables භාවිතා කිරීම
      - name: Use environment variables
        run: |
          echo "Application Version: $APP_VERSION"
          echo "Build Number: $BUILD_NUMBER"
          echo "Environment: $ENVIRONMENT"
      
      # Step 3: Expression syntax එකෙන් access කිරීම
      - name: Use with expression syntax
        run: |
          echo "Version: ${{ env.APP_VERSION }}"
          echo "Build: ${{ env.BUILD_NUMBER }}"
          echo "Env: ${{ env.ENVIRONMENT }}"
```

#### Practical Example 1: Build Configuration

```yaml
name: Build with Dynamic Configuration
on:
  push:
    branches: [main, develop]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout code
        uses: actions/checkout@v3
      
      # Branch එක අනුව environment variables set කිරීම
      - name: Set environment based on branch
        run: |
          if [ "${{ github.ref }}" == "refs/heads/main" ]; then
            echo "DEPLOY_ENV=production" >> $GITHUB_ENV
            echo "API_URL=https://api.production.com" >> $GITHUB_ENV
            echo "DEBUG_MODE=false" >> $GITHUB_ENV
          else
            echo "DEPLOY_ENV=development" >> $GITHUB_ENV
            echo "API_URL=https://api.dev.com" >> $GITHUB_ENV
            echo "DEBUG_MODE=true" >> $GITHUB_ENV
          fi
      
      - name: Build application
        run: |
          echo "Building for: $DEPLOY_ENV"
          echo "API URL: $API_URL"
          echo "Debug Mode: $DEBUG_MODE"
          # Build commands with environment variables
          npm run build -- --env=$DEPLOY_ENV --api=$API_URL
      
      - name: Deploy application
        run: |
          echo "Deploying to $DEPLOY_ENV environment"
          # Deploy commands
```

#### Practical Example 2: Dynamic Version Management

```yaml
name: Version Management
on:
  workflow_dispatch:
  push:
    tags:
      - 'v*'

jobs:
  release:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout code
        uses: actions/checkout@v3
      
      # Version information calculate කිරීම
      - name: Calculate version
        run: |
          if [ "${{ github.ref_type }}" == "tag" ]; then
            # Tag name එකෙන් version ගන්නවා
            VERSION="${{ github.ref_name }}"
          else
            # Git commit SHA එකෙන් version generate කරනවා
            VERSION="dev-${{ github.sha }}"
          fi
          
          echo "VERSION=$VERSION" >> $GITHUB_ENV
          echo "BUILD_DATE=$(date +'%Y-%m-%d')" >> $GITHUB_ENV
          echo "BUILD_TIME=$(date +'%H:%M:%S')" >> $GITHUB_ENV
          
          echo "Generated version: $VERSION"
      
      - name: Build with version
        run: |
          echo "Building version: $VERSION"
          echo "Build date: $BUILD_DATE"
          echo "Build time: $BUILD_TIME"
          
          # Version info file එකක් create කරනවා
          cat > version.txt << EOF
          Version: $VERSION
          Build Date: $BUILD_DATE
          Build Time: $BUILD_TIME
          Commit: ${{ github.sha }}
          EOF
          
          cat version.txt
      
      - name: Create artifact with version
        run: |
          ARTIFACT_NAME="app-$VERSION.tar.gz"
          echo "ARTIFACT_NAME=$ARTIFACT_NAME" >> $GITHUB_ENV
          
          echo "Creating artifact: $ARTIFACT_NAME"
          tar -czf $ARTIFACT_NAME .
      
      - name: Upload artifact
        run: |
          echo "Uploading: $ARTIFACT_NAME"
          # Upload commands
```

#### Practical Example 3: Database Connection Configuration

```yaml
name: Database Operations
on:
  workflow_dispatch:
    inputs:
      environment:
        description: 'Target environment'
        required: true
        type: choice
        options:
          - development
          - staging
          - production

jobs:
  database-setup:
    runs-on: ubuntu-latest
    steps:
      # Environment එක අනුව database configuration set කිරීම
      - name: Setup database configuration
        run: |
          ENV="${{ inputs.environment }}"
          
          if [ "$ENV" == "production" ]; then
            echo "DB_HOST=prod-db.example.com" >> $GITHUB_ENV
            echo "DB_PORT=5432" >> $GITHUB_ENV
            echo "DB_NAME=prod_database" >> $GITHUB_ENV
            echo "DB_POOL_SIZE=50" >> $GITHUB_ENV
          elif [ "$ENV" == "staging" ]; then
            echo "DB_HOST=staging-db.example.com" >> $GITHUB_ENV
            echo "DB_PORT=5432" >> $GITHUB_ENV
            echo "DB_NAME=staging_database" >> $GITHUB_ENV
            echo "DB_POOL_SIZE=20" >> $GITHUB_ENV
          else
            echo "DB_HOST=dev-db.example.com" >> $GITHUB_ENV
            echo "DB_PORT=5432" >> $GITHUB_ENV
            echo "DB_NAME=dev_database" >> $GITHUB_ENV
            echo "DB_POOL_SIZE=10" >> $GITHUB_ENV
          fi
      
      - name: Run database migrations
        run: |
          echo "Connecting to: $DB_HOST:$DB_PORT"
          echo "Database: $DB_NAME"
          echo "Pool size: $DB_POOL_SIZE"
          
          # Migration commands with environment variables
          # psql -h $DB_HOST -p $DB_PORT -d $DB_NAME -f migrations.sql
      
      - name: Verify database
        run: |
          echo "Verifying database at $DB_HOST"
          # Database verification commands
```

#### Practical Example 4: Multi-Step Build Pipeline

```yaml
name: Multi-Step Build Pipeline
on:
  push:
    branches: [main]

jobs:
  build-and-test:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout
        uses: actions/checkout@v3
      
      # Build configuration set කිරීම
      - name: Set build configuration
        run: |
          echo "NODE_ENV=production" >> $GITHUB_ENV
          echo "BUILD_ID=$(date +%Y%m%d-%H%M%S)" >> $GITHUB_ENV
          echo "ARTIFACT_DIR=./dist" >> $GITHUB_ENV
      
      - name: Install dependencies
        run: |
          echo "Installing dependencies for $NODE_ENV"
          npm ci --production
      
      - name: Run build
        run: |
          echo "Building with ID: $BUILD_ID"
          echo "Output directory: $ARTIFACT_DIR"
          npm run build
          
          # Build metadata save කිරීම
          echo "BUILD_SIZE=$(du -sh $ARTIFACT_DIR | cut -f1)" >> $GITHUB_ENV
      
      - name: Run tests
        run: |
          echo "Running tests on build: $BUILD_ID"
          npm test
          
          # Test results save කිරීම
          echo "TEST_STATUS=passed" >> $GITHUB_ENV
      
      - name: Generate build report
        run: |
          echo "===== Build Report ====="
          echo "Build ID: $BUILD_ID"
          echo "Node Environment: $NODE_ENV"
          echo "Artifact Directory: $ARTIFACT_DIR"
          echo "Build Size: $BUILD_SIZE"
          echo "Test Status: $TEST_STATUS"
          echo "======================="
          
          # Report file එකක් create කිරීම
          cat > build-report.txt << EOF
          Build Report
          ============
          Build ID: $BUILD_ID
          Environment: $NODE_ENV
          Artifact Dir: $ARTIFACT_DIR
          Build Size: $BUILD_SIZE
          Test Status: $TEST_STATUS
          Timestamp: $(date)
          EOF
```

#### Practical Example 5: AWS Deployment with Dynamic Config

```yaml
name: AWS Deployment
on:
  workflow_dispatch:
    inputs:
      region:
        description: 'AWS Region'
        required: true
        type: choice
        options:
          - us-east-1
          - us-west-2
          - eu-west-1
          - ap-south-1

jobs:
  deploy-to-aws:
    runs-on: ubuntu-latest
    steps:
      # AWS configuration setup කිරීම
      - name: Setup AWS configuration
        run: |
          REGION="${{ inputs.region }}"
          
          echo "AWS_REGION=$REGION" >> $GITHUB_ENV
          echo "S3_BUCKET=my-app-$REGION" >> $GITHUB_ENV
          echo "CLOUDFRONT_ID=cloudfront-$REGION-id" >> $GITHUB_ENV
          
          # Region එක අනුව වෙනත් settings
          case $REGION in
            us-east-1)
              echo "PRIMARY_REGION=true" >> $GITHUB_ENV
              echo "BACKUP_ENABLED=true" >> $GITHUB_ENV
              ;;
            *)
              echo "PRIMARY_REGION=false" >> $GITHUB_ENV
              echo "BACKUP_ENABLED=false" >> $GITHUB_ENV
              ;;
          esac
      
      - name: Checkout code
        uses: actions/checkout@v3
      
      - name: Build application
        run: |
          echo "Building for region: $AWS_REGION"
          npm run build
          
          # Build artifacts වලට region info එකතු කිරීම
          echo $AWS_REGION > dist/region.txt
      
      - name: Deploy to S3
        run: |
          echo "Deploying to S3 bucket: $S3_BUCKET"
          echo "Region: $AWS_REGION"
          # aws s3 sync dist/ s3://$S3_BUCKET/ --region $AWS_REGION
      
      - name: Invalidate CloudFront
        if: env.PRIMARY_REGION == 'true'
        run: |
          echo "Invalidating CloudFront: $CLOUDFRONT_ID"
          # aws cloudfront create-invalidation --distribution-id $CLOUDFRONT_ID
      
      - name: Setup backup
        if: env.BACKUP_ENABLED == 'true'
        run: |
          echo "Setting up backup for region: $AWS_REGION"
          # Backup commands
```

### වැදගත් Tips - $GITHUB_ENV භාවිතා කිරීම සඳහා

1. **Multi-line values සඳහා EOF delimiter භාවිතා කරන්න:**
   ```yaml
   - name: Set multi-line variable
     run: |
       cat >> $GITHUB_ENV << EOF
       MULTI_LINE_VAR<<DELIMITER
       This is line 1
       This is line 2
       This is line 3
       DELIMITER
       EOF
   ```

2. **Environment variables validate කරන්න:**
   ```yaml
   - name: Set and validate variable
     run: |
       echo "API_KEY=secret123" >> $GITHUB_ENV
   
   - name: Validate variable
     run: |
       if [ -z "$API_KEY" ]; then
         echo "Error: API_KEY not set!"
         exit 1
       fi
       echo "API_KEY is set correctly"
   ```

3. **Computed values සඳහා භාවිතා කරන්න:**
   ```yaml
   - name: Calculate and set values
     run: |
       CURRENT_DATE=$(date +%Y-%m-%d)
       COMMIT_SHORT=$(echo ${{ github.sha }} | cut -c1-7)
       BRANCH_NAME=$(echo ${{ github.ref }} | sed 's/refs\/heads\///')
       
       echo "DEPLOY_DATE=$CURRENT_DATE" >> $GITHUB_ENV
       echo "SHORT_SHA=$COMMIT_SHORT" >> $GITHUB_ENV
       echo "BRANCH=$BRANCH_NAME" >> $GITHUB_ENV
   ```

4. **Default values සමඟ භාවිතා කරන්න:**
   ```yaml
   - name: Set with defaults
     run: |
       # Default value එකක් සමඟ set කිරීම
       CUSTOM_VAR="${{ inputs.custom_value }}"
       echo "CUSTOM=${CUSTOM_VAR:-default_value}" >> $GITHUB_ENV
       
       # Input එකක් තිබේනම් use කරන්න, නැත්නම් default
       echo "LOG_LEVEL=${LOG_LEVEL:-info}" >> $GITHUB_ENV
   ```
## $GITHUB_OUTPUT භාවිතා කිරීම
### Passing Variables
GitHub Actions workflow එකක variables pass කිරීමට ප්‍රධාන ක්‍රම දෙකක් භාවිතා වේ:
- **Step & Job input/outputs** - Steps සහ jobs අතර structured data pass කිරීමට
- **Environment Variables** - Simple values share කිරීමට

#### Steps අතර variables pass කිරීම

එක step එකක output එක වෙනත් step එකකට pass කිරීම සඳහා `$GITHUB_OUTPUT` භාවිතා කරයි.

```yaml
name: Pass Variables Between Steps
on:
  workflow_dispatch

jobs:
  example:
    runs-on: ubuntu-latest
    steps:
      # Step 1: Variable එකක් set කිරීම
      - name: Set output variable
        id: step1  # මෙම step එක identify කිරීමට id එකක් දෙන්න
        run: |
          echo "username=john_doe" >> $GITHUB_OUTPUT
          echo "user_id=12345" >> $GITHUB_OUTPUT
          echo "timestamp=$(date +%s)" >> $GITHUB_OUTPUT
      
      # Step 2: Step 1 එකේ output භාවිතා කිරීම
      - name: Use output variable
        run: |
          echo "Username: ${{ steps.step1.outputs.username }}"
          echo "User ID: ${{ steps.step1.outputs.user_id }}"
          echo "Timestamp: ${{ steps.step1.outputs.timestamp }}"
```

**වැදගත් කරුණු:**
- Output set කරන step එකට `id` එකක් තිබිය යුතුයි
- Output access කිරීමට `steps.<step-id>.outputs.<output-name>` භාවිතා කරන්න
- Multiple outputs එකම step එකකින් set කළ හැකිය

#### Jobs අතර variables pass කිරීම

එක job එකක output එක වෙනත් job එකකට pass කිරීම සඳහා job level `outputs` සහ `needs` භාවිතා කරයි.

```yaml
name: Pass Variables Between Jobs
on:
  workflow_dispatch

jobs:
  # Producer Job - දත්ත generate කරයි
  producer:
    runs-on: ubuntu-latest
    
    # Job outputs define කිරීම
    outputs:
      build-version: ${{ steps.version.outputs.version }}
      build-date: ${{ steps.date.outputs.date }}
      environment: ${{ steps.env.outputs.env }}
    
    steps:
      - name: Generate version
        id: version
        run: |
          VERSION="v1.2.3"
          echo "version=$VERSION" >> $GITHUB_OUTPUT
          echo "Generated version: $VERSION"
      
      - name: Get current date
        id: date
        run: |
          DATE=$(date +%Y-%m-%d)
          echo "date=$DATE" >> $GITHUB_OUTPUT
          echo "Build date: $DATE"
      
      - name: Set environment
        id: env
        run: |
          ENV="production"
          echo "env=$ENV" >> $GITHUB_OUTPUT
          echo "Environment: $ENV"
  
  # Consumer Job - Producer එකේ දත්ත භාවිතා කරයි
  consumer:
    runs-on: ubuntu-latest
    needs: producer  # Producer job එක complete වෙන තෙක් wait කරයි
    
    steps:
      - name: Use producer outputs
        run: |
          echo "Building version: ${{ needs.producer.outputs.build-version }}"
          echo "Build date: ${{ needs.producer.outputs.build-date }}"
          echo "Target environment: ${{ needs.producer.outputs.environment }}"
      
      - name: Deploy application
        run: |
          echo "Deploying ${{ needs.producer.outputs.build-version }} to ${{ needs.producer.outputs.environment }}"
          # Deployment commands here
```

**වැදගත් කරුණු:**
- Producer job එකේ `outputs` section එකේ outputs define කරන්න
- Consumer job එකේ `needs` භාවිතා කර producer job එක specify කරන්න
- Outputs access කිරීමට `needs.<job-id>.outputs.<output-name>` භාවිතා කරන්න

### උදාරහරණ කීපයක්
#### Multiple jobs සමඟ complex workflow එකක්

```yaml
name: Complex Multi-Job Workflow
on:
  workflow_dispatch:
    inputs:
      environment:
        description: 'Deployment environment'
        required: true
        type: choice
        options:
          - development
          - staging
          - production

jobs:
  # Job 1: Build කිරීම
  build:
    runs-on: ubuntu-latest
    outputs:
      build-id: ${{ steps.build.outputs.id }}
      artifact-name: ${{ steps.build.outputs.artifact }}
      build-status: ${{ steps.build.outputs.status }}
    
    steps:
      - name: Checkout code
        uses: actions/checkout@v3
      
      - name: Build application
        id: build
        run: |
          BUILD_ID="build-$(date +%Y%m%d-%H%M%S)"
          ARTIFACT="app-$BUILD_ID.tar.gz"
          
          echo "Building application..."
          # Build commands here
          
          echo "id=$BUILD_ID" >> $GITHUB_OUTPUT
          echo "artifact=$ARTIFACT" >> $GITHUB_OUTPUT
          echo "status=success" >> $GITHUB_OUTPUT
          
          echo "✅ Build completed: $BUILD_ID"
  
  # Job 2: Test කිරීම
  test:
    runs-on: ubuntu-latest
    needs: build
    outputs:
      test-result: ${{ steps.test.outputs.result }}
      coverage: ${{ steps.test.outputs.coverage }}
    
    steps:
      - name: Run tests
        id: test
        run: |
          echo "Testing build: ${{ needs.build.outputs.build-id }}"
          
          # Test commands here
          TEST_RESULT="passed"
          COVERAGE="85%"
          
          echo "result=$TEST_RESULT" >> $GITHUB_OUTPUT
          echo "coverage=$COVERAGE" >> $GITHUB_OUTPUT
          
          echo "✅ Tests $TEST_RESULT with $COVERAGE coverage"
  
  # Job 3: Security scan කිරීම
  security-scan:
    runs-on: ubuntu-latest
    needs: build
    outputs:
      vulnerabilities: ${{ steps.scan.outputs.vulns }}
      scan-status: ${{ steps.scan.outputs.status }}
    
    steps:
      - name: Security scan
        id: scan
        run: |
          echo "Scanning artifact: ${{ needs.build.outputs.artifact-name }}"
          
          # Security scan commands here
          VULNS="0"
          STATUS="clean"
          
          echo "vulns=$VULNS" >> $GITHUB_OUTPUT
          echo "status=$STATUS" >> $GITHUB_OUTPUT
          
          echo "✅ Security scan complete: $VULNS vulnerabilities found"
  
  # Job 4: Deploy කිරීම (test සහ security scan pass නම් පමණක්)
  deploy:
    runs-on: ubuntu-latest
    needs: [build, test, security-scan]
    if: |
      needs.test.outputs.test-result == 'passed' &&
      needs.security-scan.outputs.scan-status == 'clean'
    
    steps:
      - name: Deploy summary
        run: |
          echo "=== Deployment Summary ==="
          echo "Build ID: ${{ needs.build.outputs.build-id }}"
          echo "Artifact: ${{ needs.build.outputs.artifact-name }}"
          echo "Test Result: ${{ needs.test.outputs.test-result }}"
          echo "Code Coverage: ${{ needs.test.outputs.coverage }}"
          echo "Security Status: ${{ needs.security-scan.outputs.scan-status }}"
          echo "Vulnerabilities: ${{ needs.security-scan.outputs.vulnerabilities }}"
          echo "Environment: ${{ inputs.environment }}"
      
      - name: Deploy to ${{ inputs.environment }}
        run: |
          echo "🚀 Deploying ${{ needs.build.outputs.artifact-name }} to ${{ inputs.environment }}"
          # Deployment commands here
      
      - name: Deployment complete
        run: |
          echo "✅ Successfully deployed to ${{ inputs.environment }}"
  
  # Job 5: Notification (සියලු jobs complete වූ පසු)
  notify:
    runs-on: ubuntu-latest
    needs: [build, test, security-scan, deploy]
    if: always()  # Deploy එක fail වුනත් notification එවයි
    
    steps:
      - name: Send notification
        run: |
          if [ "${{ needs.deploy.result }}" == "success" ]; then
            echo "📧 Sending success notification..."
            echo "Build: ${{ needs.build.outputs.build-id }}"
            echo "Deployed to: ${{ inputs.environment }}"
          else
            echo "📧 Sending failure notification..."
            echo "Deployment failed or skipped"
          fi
```

#### Practical Example: Docker Build සහ Deploy

```yaml
name: Docker Build and Deploy
on:
  push:
    branches: [main]
  workflow_dispatch:

jobs:
  # Docker image build කිරීම
  docker-build:
    runs-on: ubuntu-latest
    outputs:
      image-tag: ${{ steps.meta.outputs.tag }}
      image-name: ${{ steps.meta.outputs.name }}
      digest: ${{ steps.build.outputs.digest }}
    
    steps:
      - name: Checkout
        uses: actions/checkout@v3
      
      - name: Set image metadata
        id: meta
        run: |
          TAG="v1.0.${{ github.run_number }}"
          IMAGE_NAME="myapp"
          
          echo "tag=$TAG" >> $GITHUB_OUTPUT
          echo "name=$IMAGE_NAME" >> $GITHUB_OUTPUT
          
          echo "Image: $IMAGE_NAME:$TAG"
      
      - name: Build Docker image
        id: build
        run: |
          IMAGE="${{ steps.meta.outputs.name }}:${{ steps.meta.outputs.tag }}"
          docker build -t $IMAGE .
          
          # Get image digest
          DIGEST=$(docker images --no-trunc --quiet $IMAGE)
          echo "digest=$DIGEST" >> $GITHUB_OUTPUT
          
          echo "✅ Built image: $IMAGE"
  
  # Development environment එකට deploy කිරීම
  deploy-dev:
    runs-on: ubuntu-latest
    needs: docker-build
    environment: development
    outputs:
      deploy-url: ${{ steps.deploy.outputs.url }}
    
    steps:
      - name: Deploy to development
        id: deploy
        run: |
          IMAGE="${{ needs.docker-build.outputs.image-name }}:${{ needs.docker-build.outputs.image-tag }}"
          echo "Deploying $IMAGE to development..."
          
          URL="https://dev.myapp.com"
          echo "url=$URL" >> $GITHUB_OUTPUT
          
          echo "✅ Deployed to: $URL"
  
  # Staging environment එකට deploy කිරීම
  deploy-staging:
    runs-on: ubuntu-latest
    needs: [docker-build, deploy-dev]
    environment: staging
    outputs:
      deploy-url: ${{ steps.deploy.outputs.url }}
    
    steps:
      - name: Deploy to staging
        id: deploy
        run: |
          IMAGE="${{ needs.docker-build.outputs.image-name }}:${{ needs.docker-build.outputs.image-tag }}"
          echo "Deploying $IMAGE to staging..."
          
          URL="https://staging.myapp.com"
          echo "url=$URL" >> $GITHUB_OUTPUT
          
          echo "✅ Deployed to: $URL"
  
  # Production environment එකට deploy කිරීම (manual approval සමඟ)
  deploy-production:
    runs-on: ubuntu-latest
    needs: [docker-build, deploy-staging]
    environment: production
    outputs:
      deploy-url: ${{ steps.deploy.outputs.url }}
    
    steps:
      - name: Deploy to production
        id: deploy
        run: |
          IMAGE="${{ needs.docker-build.outputs.image-name }}:${{ needs.docker-build.outputs.image-tag }}"
          echo "Deploying $IMAGE to production..."
          
          URL="https://myapp.com"
          echo "url=$URL" >> $GITHUB_OUTPUT
          
          echo "✅ Deployed to: $URL"
  
  # Deployment summary
  summary:
    runs-on: ubuntu-latest
    needs: [docker-build, deploy-dev, deploy-staging, deploy-production]
    if: always()
    
    steps:
      - name: Deployment summary
        run: |
          echo "=== Deployment Summary ==="
          echo "Docker Image: ${{ needs.docker-build.outputs.image-name }}:${{ needs.docker-build.outputs.image-tag }}"
          echo "Image Digest: ${{ needs.docker-build.outputs.digest }}"
          echo ""
          echo "Deployment URLs:"
          echo "  Development: ${{ needs.deploy-dev.outputs.deploy-url }}"
          echo "  Staging: ${{ needs.deploy-staging.outputs.deploy-url }}"
          echo "  Production: ${{ needs.deploy-production.outputs.deploy-url }}"
```

### **වැදගත් Tips - $GITHUB_OUTPUT භාවිතා කිරීම සඳහා**

1. **Output names විශිෂ්ට සහ අර්ථවත් විය යුතුයි:**
   ```yaml
   # හොඳයි ✅
   outputs:
     build-version: ${{ steps.version.outputs.version }}
     docker-image-tag: ${{ steps.docker.outputs.tag }}
   
   # නරකයි ❌
   outputs:
     output1: ${{ steps.step1.outputs.var }}
     data: ${{ steps.step2.outputs.result }}
   ```

2. **Output values validate කරන්න:**
   ```yaml
   - name: Validate output
     run: |
       if [ -z "${{ steps.build.outputs.version }}" ]; then
         echo "Error: Version not set!"
         exit 1
       fi
   ```

3. **Complex data structures සඳහා JSON භාවිතා කරන්න:**
   ```yaml
   - name: Create JSON output
     id: data
     run: |
       JSON_DATA=$(cat <<EOF
       {
         "version": "1.0.0",
         "build": "123",
         "status": "success"
       }
       EOF
       )
       echo "data=$JSON_DATA" >> $GITHUB_OUTPUT
   
   - name: Parse JSON
     run: |
       echo '${{ steps.data.outputs.data }}' | jq '.version'
   ```

4. **Conditional outputs:**
   ```yaml
   - name: Set conditional output
     id: check
     run: |
       if [ "${{ github.ref }}" == "refs/heads/main" ]; then
         echo "environment=production" >> $GITHUB_OUTPUT
       else
         echo "environment=development" >> $GITHUB_OUTPUT
       fi
   ```

   ## $GITHUB_ENV vs $GITHUB_OUTPUT

### $GITHUB_ENV සහ $GITHUB_OUTPUT අතර වෙනස

| Feature | $GITHUB_ENV | $GITHUB_OUTPUT |
|---------|-------------|----------------|
| **භාවිතය** | Environment variables set කිරීමට | Step outputs pass කිරීමට |
| **Access කරන ආකාරය** | `$VARIABLE_NAME` හෝ `${{ env.VARIABLE_NAME }}` | `${{ steps.step-id.outputs.output-name }}` |
| **Scope** | එකම job එකේ අනෙක් steps වලට | එකම job එකේ හෝ වෙනත් jobs වලට |
| **සුදුසු වන්නේ** | Simple values share කිරීමට | Job outputs සඳහා |

### $GITHUB_ENV සහ $GITHUB_OUTPUT භාවිතා කරන්නේ මොනඅවස්ථා වලදීද?

**$GITHUB_ENV භාවිතා කරන්න:**
- ✅ එකම job එකේ steps අතර simple values share කිරීමට
- ✅ Build configuration සඳහා
- ✅ Environment settings සඳහා
- ✅ Shell scripts වල environment variables ලෙස භාවිතා කිරීමට

**$GITHUB_OUTPUT භාවිතා කරන්න:**
- ✅ Jobs අතර data pass කිරීමට
- ✅ Step outputs වෙනත් jobs වලට යැවීමට
- ✅ Workflow outputs define කිරීමට
- ✅ Reusable workflows සමඟ භාවිතා කිරීමට
