// Unit-V File Management: Overview of file management system, disk space management, directory structures, file sharing and protection, access control lists, protection models.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 5
#define MAX_USERS 3
#define DISK_SIZE 32

// ------------------ File Management System Overview ------------------
void file_system_overview() {
    printf("\n[FILE MANAGEMENT SYSTEM OVERVIEW]\n");
    printf("Responsible for: File naming, storage, access, security, and protection.\n");
}

// ------------------ Disk Space Management (Bitmap) ------------------
void disk_space_management() {
    printf("\n[DISK SPACE MANAGEMENT - Bitmap Simulation]\n");
    int bitmap[DISK_SIZE] = {0}; // 0: Free, 1: Used

    // Allocate blocks 2, 3, 7, 8
    bitmap[2] = bitmap[3] = bitmap[7] = bitmap[8] = 1;

    printf("Disk Bitmap: ");
    for (int i = 0; i < DISK_SIZE; i++) {
        printf("%d", bitmap[i]);
    }
    printf("\n");
}

// ------------------ Directory Structure ------------------
typedef struct {
    char name[20];
    char owner[20];
} File;

File single_level[MAX_FILES];
int file_count = 0;

void single_level_directory() {
    printf("\n[SINGLE-LEVEL DIRECTORY STRUCTURE]\n");

    strcpy(single_level[file_count].name, "report.txt");
    strcpy(single_level[file_count++].owner, "alice");

    strcpy(single_level[file_count].name, "data.csv");
    strcpy(single_level[file_count++].owner, "bob");

    for (int i = 0; i < file_count; i++) {
        printf("File: %s, Owner: %s\n", single_level[i].name, single_level[i].owner);
    }
}

// ------------------ Access Control Lists ------------------
typedef struct {
    char username[20];
    int read;
    int write;
    int execute;
} ACL;

typedef struct {
    char filename[20];
    ACL acl[MAX_USERS];
} ProtectedFile;

void access_control_lists() {
    printf("\n[ACCESS CONTROL LISTS (ACL)]\n");

    ProtectedFile pf;
    strcpy(pf.filename, "confidential.txt");

    strcpy(pf.acl[0].username, "alice");
    pf.acl[0].read = 1; pf.acl[0].write = 1; pf.acl[0].execute = 0;

    strcpy(pf.acl[1].username, "bob");
    pf.acl[1].read = 1; pf.acl[1].write = 0; pf.acl[1].execute = 0;

    for (int i = 0; i < 2; i++) {
        printf("User: %s → R:%d W:%d X:%d\n",
               pf.acl[i].username,
               pf.acl[i].read,
               pf.acl[i].write,
               pf.acl[i].execute);
    }
}

// ------------------ File Sharing & Protection ------------------
void file_sharing_protection() {
    printf("\n[FILE SHARING & PROTECTION]\n");
    printf("Shared file: project.docx (read-only to guest, read-write to admin)\n");
}

// ------------------ Protection Models ------------------
void protection_models() {
    printf("\n[PROTECTION MODELS - Simplified Matrix View]\n");

    char *users[] = {"alice", "bob"};
    char *files[] = {"file1", "file2"};
    char rights[2][2][4] = {
        {"RW", "R"},  // alice: file1 RW, file2 R
        {"R", "RW"}   // bob: file1 R, file2 RW
    };

    for (int i = 0; i < 2; i++) {
        printf("User: %s\n", users[i]);
        for (int j = 0; j < 2; j++) {
            printf("  File: %s → Access: %s\n", files[j], rights[i][j]);
        }
    }
}

int main() {
    printf("=== OPERATING SYSTEMS UNIT V DEMO ===\n");

    file_system_overview();
    disk_space_management();
    single_level_directory();
    access_control_lists();
    file_sharing_protection();
    protection_models();

    return 0;
}
