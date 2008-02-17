#ifndef EL__UTIL_MEMORY_H
#define EL__UTIL_MEMORY_H

#include <mm.h>

/* If defined, we'll crash if ALLOC_MAXTRIES is attained,
 * if not defined, we'll try to continue. */
/* #define CRASH_IF_ALLOC_MAXTRIES */

/** Max. number of retry in case of memory allocation failure. */
#define ALLOC_MAXTRIES 3

/** Delay in seconds between each alloc try. */
#define ALLOC_DELAY 3

#define mem_mmap_alloc(x) mem_alloc(x)
#define mem_mmap_free(x, y) mem_free(x)
#define mem_mmap_realloc(x, y, z) mem_realloc(x, z)

void *mem_alloc(size_t);
void *mem_calloc(size_t, size_t);
void mem_free(void *);
void *mem_realloc(void *, size_t);
void mem_destroy(void);
size_t mem_sizeof(void *);
char *mem_strdup(const char *);

/* fmem_* functions should be use for allocation and freeing of memory
 * inside a function.
 * See alloca(3) manpage. */

#include "malloca.h"
#define fmem_alloc(x) 	safe_alloca(x)
#define fmem_free(x) 	freea(x)


/** @name Granular memory allocation.
 * The granularity used by the aligned memory functions below must be a mask
 * with all bits set from but not including the most significant bit and down.
 * So if an alignment of 256 is wanted use 0xFF.
 * @{ */

/** The 'old' style granularity. XXX: Must be power of 2 */
#define ALLOC_GR 0x100

#define ALIGN_MEMORY_SIZE(x, gr) (((x) + (gr)) & ~(gr))

static inline void *
mem_align_alloc__(
		  void **ptr, size_t old, size_t new, size_t objsize, size_t mask)
{
	size_t newsize = ALIGN_MEMORY_SIZE(new, mask);
	size_t oldsize = ALIGN_MEMORY_SIZE(old, mask);

	if (newsize > oldsize) {
		unsigned char *data;

		newsize *= objsize;
		oldsize *= objsize;

		data = mem_realloc(*ptr, newsize);
		if (!data) return NULL;

		*ptr = (void *) data;
		memset(&data[oldsize], 0, newsize - oldsize);
	}

	return *ptr;
}

#define mem_align_alloc(ptr, old, new, mask) \
	mem_align_alloc__((void **) ptr, old, new, sizeof(**ptr), mask)

/** @} */


/** @name Maybe-free macros
 * @todo TODO: Think about making what they do more obvious in their
 * identifier, they could be obfuscating their users a little for the
 * newcomers otherwise.
 * @{ */

#define mem_free_set(x, v) do { if (*(x)) mem_free(*(x)); *(x) = (v); } while (0)
#define mem_free_if(x) do { register void *p = (x); if (p) mem_free(p); } while (0)

#if 0
/* This may help to find bugs. */
#undef mem_free_if
#define mem_free_if(x) mem_free_set(&x, NULL)
#endif
/** @} */


/* This is out of place, but there is no better place. */

#define intdup(i) intdup__(i)

static inline int *
intdup__(int i)
{
	int *p = mem_alloc(sizeof(*p));

	if (p) *p = i;

	return p;
}

#endif
