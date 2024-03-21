def generate_stub_function(return_type, function_name):
    # Generate the stub function with the body commented out
    stub = f"{return_type} {function_name}(void) {{\n"
    stub += "    // STUB\n"
    if return_type != "void":
        stub += f"    return ({return_type})0;  // Default return value\n"
    stub += "}\n\n"
    return stub

def rename_original_function(file_content, function_name):
    # Replace the original function name with a new name
    new_function_name = function_name + "_original"
    renamed_content = file_content.replace(function_name, new_function_name)
    return renamed_content

def main():
    # Hardcoded arguments
    file_location = "edk2/MdeModulePkg/Core/PiSmmCore/SmramProfileRecord.c"
    return_type = "UINTN"
    function_name = "SmramProfileGetDataSize"

      # Read the file content
    with open(file_location, 'r') as f:
        file_content = f.read()

    # Rename the original function
    file_content = rename_original_function(file_content, function_name)

    # Generate and append the stub function
    stub = generate_stub_function(return_type, function_name)
    file_content += stub

    # Write the modified content back to the file
    with open(file_location, 'w') as f:
        f.write(file_content)

    print(f"Original '{function_name}' function renamed to '{function_name}_original' and stub function added to {file_location}")

if __name__ == "__main__":
    main()
