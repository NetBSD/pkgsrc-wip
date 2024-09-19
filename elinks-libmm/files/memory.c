/** Memory allocation manager
 * @file */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <mm.h>

#define	CHECKSIZE(s) 	(((s) < 0) || (MM_available() < (s)))

#ifndef MM_FAIL_FATAL
#define MM_FAIL_FATAL 0
#endif

#include "elinks.h"

#include "util/error.h"
#include "util/memory.h"

static int shmpool_created = 0;

void *
mem_alloc(size_t size)
{
	void *p = NULL;

	if (shmpool_created == 0) {
		if (MM_create(0, NULL) < 0) 
			goto fail;

		if (MM_permission(0700, getuid(), getgid()) < 0)
			goto destroy;

		shmpool_created = 1;
	}

	if CHECKSIZE(size) {
		ERROR("mem_alloc(): invalid size %d", size);
		goto fail;
	}

	if ((p = MM_malloc(size)) == NULL)
		goto fail;

	return p;

	INTERNAL("mem_alloc(): should not be here!");
destroy:
	mem_destroy();
fail:
#if MM_FAIL_FATAL
	ERROR("mem_alloc(): Nowhere to go, nothing to do.  Cheers!");
#endif
	return NULL;
}

void *
mem_calloc(size_t number, size_t size)
{
	void *p;

	if CHECKSIZE(number * size) {
		ERROR("mem_calloc(): invalid args (num: %zd), (size: %zd)",
		number, size);
		goto fail;
	}

	if ((p = MM_calloc(number, size)) == NULL)
		goto fail;

	return p;

	INTERNAL("mem_alloc(): should not be here!");
fail:
#if MM_FAIL_FATAL
	ERROR("mem_alloc(): Nowhere to go, nothing to do.  Cheers!");
#endif
	return NULL;
}

void
mem_free(void *ptr)
{
	if (ptr == NULL) {
		INTERNAL("mem_free(): freeing NULL pointer!");
		return;
	}
	MM_free(ptr);
}

void *
mem_realloc(void *ptr, size_t size)
{
	void *p;

	if (ptr == NULL) 
		return mem_alloc(size);

	if CHECKSIZE(size)
		goto fail;

	if ((p = MM_realloc(ptr, size)) == NULL) 
		goto fail;

	return p;

	INTERNAL("mem_alloc(): should not be here!");
fail:
	ERROR("mem_realloc() failed: %s,", MM_error());
#if MM_FAIL_FATAL
	INTERNAL("mem_realloc(): Nowhere to go, nothing to do.  Cheers!");
#endif
	return NULL;
}

void
mem_destroy(void)
{
	MM_destroy();
	return;
}

size_t 
mem_sizeof(void *ptr)
{
	return MM_sizeof(ptr);
}

char *
mem_strdup(const char *str)
{
	return MM_strdup(str);
}
