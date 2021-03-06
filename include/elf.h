/*
 * elf.h: header file for elf.c
 *
 * Copyright 2007 EPIC Software Labs
 * See the COPYRIGHT file, or do a HELP IRCII COPYRIGHT 
 */
/*
 * This code was contributed to EPIC Software Labs by Alexander Grotewohl,
 * used with permission.
 */

#ifndef _ELF_H_
#define _ELF_H_

#include "irc.h"

#ifdef HAVE_LIBARCHIVE
#include <archive.h>
#include <archive_entry.h>
#endif

struct epic_loadfile {
    FILE * fp;
#ifdef HAVE_LIBARCHIVE
    struct archive *a;
    struct archive_entry *entry;
#endif
    int eof;
};

	struct epic_loadfile * epic_fopen (char *filename, const char *mode, int do_error);
	int 	epic_fgetc (struct epic_loadfile *elf);
	char *	epic_fgets (char *s, int n, struct epic_loadfile *elf);
	int 	epic_feof (struct epic_loadfile *elf);
	int 	epic_fclose (struct epic_loadfile *elf);
	off_t 	epic_stat (const char *filename, struct stat *buf);
	size_t  slurp_elf_file (struct epic_loadfile *elf, char **file_contents, off_t *file_contents_size);

	int     string_feof( const char *file_contents, off_t file_contents_size);
	int     string_fgetc (const char **file_contents, off_t *file_contents_size);
	off_t	string_fgets (char *buffer, size_t buffer_size, const char **file_contents, off_t *file_contents_size);


#endif /* _ELF_H_ */
