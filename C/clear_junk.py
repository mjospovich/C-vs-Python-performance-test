import os

def delete_files_with_extensions(extensions):
    current_directory = os.getcwd()
    files_deleted = 0
    for file_name in os.listdir(current_directory):
        if any(file_name.endswith(ext) for ext in extensions):
            file_path = os.path.join(current_directory, file_name)
            os.remove(file_path)
            files_deleted += 1
            print(f"Deleted: {file_path}")
    print(f"Total files deleted: {files_deleted}")

if __name__ == "__main__":
    extensions_to_delete = [".pdb", ".ilk", ".obj"]
    delete_files_with_extensions(extensions_to_delete)
