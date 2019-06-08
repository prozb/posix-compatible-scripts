/* Copyright (C) 1994,1996-1998,2001,2003,2005 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.

   As a special exception, if you link the code in this file with
   files compiled with a GNU compiler to produce an executable,
   that does not cause the resulting executable to be covered by
   the GNU Lesser General Public License.  This exception does not
   however invalidate any other reasons why the executable file
   might be covered by the GNU Lesser General Public License.
   This exception applies to code released by its copyright holders
   in files containing the exception.  */

/**********************************************************************
 * This is a scaled-down version of GNU getdelim().
 * You might link it with your programme to have a substitute for 
 * getline() in case the GNU C-library is not available on your machine.
 **********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

static const int delimiter = '\n';

/* Read up to (and including) a TERMINATOR ('\n') from FP into *LINEPTR
   (and null-terminate it).  *LINEPTR is a pointer returned from malloc (or
   NULL), pointing to *N characters of space.  It is realloc'ed as
   necessary.  Returns the number of characters read (not including the
   null terminator), or -1 on error or EOF.  */

ssize_t getline (char **lineptr, size_t *n, FILE *fp) {
	ssize_t cur_len = 0;
	size_t needed = 1;	// space at least for the terminating '\0'
	
	if (lineptr == NULL || n == NULL)
		return -1;
	if (*lineptr == NULL || *n == 0) {
		*n = 120;
		*lineptr = (char *) malloc (*n);
		if (*lineptr == NULL)
			return -1;
	}
	for (;;) {
		int nxtchr = fgetc (fp);

		if (nxtchr == EOF)
			break;
		if (++needed > *n) {
			char *new_lineptr;
			
			if (needed < 2 * *n)
				needed = 2 * *n;
			new_lineptr = (char *) realloc (*lineptr, needed);
			if (new_lineptr == NULL)
				return -1;
			*lineptr = new_lineptr;
			*n = needed;
			needed = cur_len + 1;
		}
		(*lineptr)[cur_len++] = nxtchr;
		if (nxtchr == delimiter)
			break;
	}
	(*lineptr)[cur_len] = '\0';
	return cur_len;
}
