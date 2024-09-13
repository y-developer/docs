# File Upload to S3 bucket

## Setup S3 bucket
https://www.youtube.com/watch?v=39X5WdZbEwQ



## Python example with boto3

Install packages
```bash
pip3 install boto3 tqdm
```

python script
```py
import os
import boto3
from botocore.exceptions import NoCredentialsError
from tqdm import tqdm

ACCESS_KEY = ''
SECRET_KEY = ''
BUCKET_NAME = ''
LOCAL_FILE_PATH = ''
S3_FILE_PATH = ''
AS_PUBLIC = True

class ProgressPercentage:
    def __init__(self, filename):
        self._filename = filename
        self._size = float(os.path.getsize(filename))
        self._seen_so_far = 0
        self._lock = tqdm(total=self._size, unit='B', unit_scale=True, desc=filename)

    def __call__(self, bytes_amount):
        # Update the progress bar
        self._seen_so_far += bytes_amount
        self._lock.update(bytes_amount)

def upload_file_to_s3():
    s3 = boto3.client('s3', aws_access_key_id=ACCESS_KEY, aws_secret_access_key=SECRET_KEY)

    try:
        progress = ProgressPercentage(LOCAL_FILE_PATH)
        
        if AS_PUBLIC:
            s3.upload_file(LOCAL_FILE_PATH, BUCKET_NAME, S3_FILE_PATH, ExtraArgs={'ACL': 'public-read'}, Callback=progress)
        else:
            s3.upload_file(LOCAL_FILE_PATH, BUCKET_NAME, S3_FILE_PATH, Callback=progress)
        
        absolute_local_path = os.path.abspath(LOCAL_FILE_PATH)
        print(f"\nUpload Successful from {absolute_local_path} to {BUCKET_NAME}.s3.amazonaws.com/{S3_FILE_PATH}")
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