#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function to execute a shell command and capture its output
void execute_command(const char *command) {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error opening pipe");
        exit(1);
    }

    // Print the output of the command
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
}

// Function to analyze disk usage using 'df' and 'du'
void analyze_disk_usage() {
    printf("Disk Usage Overview (using 'df'):\n");
    // Run the 'df' command to show disk space usage
    execute_command("df -h");

    printf("\nDirectory Usage Overview (using 'du'):\n");
    // Run the 'du' command to show disk usage per directory
    execute_command("du -sh * | sort -h");
}

// Function to check for optimization opportunities
void check_for_optimization() {
    printf("\nChecking for optimization opportunities:\n");

    // Example: Identify large files in the system
    execute_command("find / -type f -size +100M -exec ls -lh {} \\; | sort -k5 -rh | head -n 10");

    // Additional checks (could be added):
    // - Identify unused disk space
    // - Suggest deleting old log files, temporary files, etc.
}

int main() {
    printf("Starting disk usage analysis...\n");

    // Step 1: Analyze overall disk usage
    analyze_disk_usage();

    // Step 2: Check for optimization opportunities
    check_for_optimization();

    return 0;
}

