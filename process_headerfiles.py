import os
import re
import sys

def find_exact_file(directory, filename):
    for root, dirs, files in os.walk(directory):
        if filename in files:
            return os.path.join(root, filename)

def find_files_with_pattern(directory, pattern):
    matching_files = []
    
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_path = os.path.join(root, file)
            with open(file_path, 'r') as file_content:
                for line_number, line in enumerate(file_content, start=1):
                    if re.search(pattern, line):
                        matching_files.append((file_path, line_number, line.strip()))

    return matching_files

def find_pattern_in_file(file_path, pattern):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        matching_lines = [(line_number, line.strip()) for line_number, line in enumerate(lines, start=1) if re.search(pattern, line)]

    return matching_lines

def replace_line_with_exact_path(file_path, line_number, new_line):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    lines[line_number - 1] = new_line + '\n'

    with open(file_path, 'w') as file:
        file.writelines(lines)

def process_directory(directory):
    pattern = r'^\s*#include\s+[<"](.+?)[>"]'

    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith((".c", ".h")):
                file_path = os.path.join(root, file)
                matching_lines = find_pattern_in_file(file_path, pattern)

                if matching_lines:
                    print(f"Lines matching the pattern in {file_path}:")
                    for line_number, line in matching_lines:
                        print(line)

                        # Extract the filename from the matched line
                        match_filename = re.search(pattern, line)
                        if match_filename:
                            full_path = match_filename.group(1)
                            base_filename = os.path.basename(full_path)

                            # Using the extracted base filename to find the exact file
                            exact_file_path = find_exact_file(directory, base_filename)

                            if exact_file_path:
                                print(f"\nExact file found: {exact_file_path}")

                                # Replace the matched line in the original file with the exact_file_path
                                replace_line_with_exact_path(file_path, line_number, f'#include "{exact_file_path}"')
                                print("Updated line in the file.")
                            else:
                                print("\nNo exact file found for the extracted filename.")
                        else:
                            print("\nUnable to extract filename from the matched line.")
                else:
                    print(f"No matching lines found in {file_path}.\n")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python process_headerfiles.py <directory>")
        sys.exit(1)

    target_directory = sys.argv[1]
    process_directory(target_directory)
