/* vi: set sw=4 ts=4: */
/*
 * Utility routines.
 *
 * Copyright (C) 1999-2004 by Erik Andersen <andersen@codepoet.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void *xmalloc(size_t size)
{
	void *ptr = malloc(size);
	if (unlikely(ptr == NULL))
		err("Out of memory");
	return ptr;
}

static void *xcalloc(size_t nmemb, size_t size)
{
	void *ptr = calloc(nmemb, size);
	if (unlikely(ptr == NULL))
		err("Out of memory");
	return ptr;
}

static void *xzalloc(size_t size)
{
	void *ptr = xmalloc(size);
	if (unlikely(ptr == NULL))
		err("Out of memory");
	memset(ptr, 0x00, size);
	return ptr;
}

static void *xrealloc(void *optr, size_t size)
{
	void *ptr = realloc(optr, size);
	if (unlikely(ptr == NULL))
		err("Out of memory");
	return ptr;
}

static void *xmemdup(const void *src, size_t n)
{
	void *ret = xmalloc(n);
	memcpy(ret, src, n);
	return ret;
}
