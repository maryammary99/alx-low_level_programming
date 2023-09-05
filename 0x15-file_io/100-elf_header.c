#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <elf.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to print an error message and exit with status code 98
void error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(98);
}

// Function to check if a file is an ELF file
void check_elf(unsigned char *e_ident) {
    if (memcmp(e_ident, ELFMAG, SELFMAG) != 0) {
        error("Error: Not an ELF file");
    }
}

// Function to print the ELF magic numbers
void print_magic(unsigned char *e_ident) {
    printf("Magic: ");
    for (int i = 0; i < SELFMAG; i++) {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
}

// Function to print the ELF class
void print_class(unsigned char *e_ident) {
    printf("Class: ");
    switch (e_ident[EI_CLASS]) {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown: %x>\n", e_ident[EI_CLASS]); break;
    }
}

// Function to print the ELF data encoding
void print_data(unsigned char *e_ident) {
    printf("Data: ");
    switch (e_ident[EI_DATA]) {
        case ELFDATANONE: printf("none\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown: %x>\n", e_ident[EI_DATA]); break;
    }
}

// Function to print the ELF version
void print_version(unsigned char *e_ident) {
    printf("Version: %d", e_ident[EI_VERSION]);
    switch (e_ident[EI_VERSION]) {
        case EV_CURRENT: printf(" (current)\n"); break;
        default: printf("\n"); break;
    }
}

// Function to print the OS/ABI
void print_osabi(unsigned char *e_ident) {
    printf("OS/ABI: ");
    switch (e_ident[EI_OSABI]) {
        case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM: printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
        default: printf("<unknown: %x>\n", e_ident[EI_OSABI]); break;
    }
}

// Function to print the ABI version
void print_abi(unsigned char *e_ident) {
    printf("ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

// Function to print the ELF file type
void print_type(unsigned int e_type, unsigned char *e_ident) {
    printf("Type: ");
    switch (e_type) {
        case ET_NONE: printf("NONE (None)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %x>\n", e_type); break;
    }
}

// Function to print the entry point address
void print_entry(unsigned long int e_entry, unsigned char *e_ident) {
    printf("Entry point address: ");
    if (e_ident[EI_CLASS] == ELFCLASS32) {
        printf("0x%x\n", (unsigned int)e_entry);
    } else {
        printf("0x%lx\n", e_entry);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error("Usage: elf_header elf_filename");
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        error("Unable to open file");
    }

    // Read the ELF header
    Elf64_Ehdr elf_header;
    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
        error("Error reading ELF header");
    }

    // Check for the ELF magic number
    check_elf(elf_header.e_ident);

    // Display the ELF header information
    printf("ELF Header:\n");
    print_magic(elf_header.e_ident);
    print_class(elf_header.e_ident);
    print_data(elf_header.e_ident);
    print_version(elf_header.e_ident);
    print_osabi(elf_header.e_ident);
    print_abi(elf_header.e_ident);
    print_type(elf_header.e_type, elf_header.e_ident);
    print_entry(elf_header.e_entry, elf_header.e_ident);

    close(fd);
    return 0;
}

