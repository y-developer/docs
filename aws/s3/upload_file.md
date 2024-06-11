# File Upload to S3 bucket

## Python example with boto3
```py
import os
import boto3
from botocore.exceptions import NoCredentialsError

ACCESS_KEY = ''
SECRET_KEY = ''
BUCKET_NAME = ''
LOCAL_FILE_PATH = ''
S3_FILE_PATH = ''
AS_PUBLIC = True

def upload_file_to_s3():
    s3 = boto3.client('s3', aws_access_key_id=ACCESS_KEY, aws_secret_access_key=SECRET_KEY)

    try:
        if AS_PUBLIC:
            s3.upload_file(LOCAL_FILE_PATH, BUCKET_NAME, S3_FILE_PATH, ExtraArgs={'ACL': 'public-read'})
        else:
            s3.upload_file(LOCAL_FILE_PATH, BUCKET_NAME, S3_FILE_PATH)
        absolute_local_path = os.path.abspath(LOCAL_FILE_PATH)
        print(f"Upload Successful from {absolute_local_path} to {BUCKET_NAME}.s3.amazonaws.com/{S3_FILE_PATH}")
        return True
    
    except FileNotFoundError:
        print("The file was not found")
        return False
    
    except NoCredentialsError:
        print("Credentials not available")
        return False
    

if __name__ == "__main__":
    upload_file_to_s3()
```