#include <iprt/alloc.h>
#include <iprt/assert.h>
#include <iprt/param.h>
#include <iprt/err.h>
#include <iprt/string.h>

RTDECL(void *) RTMemExecAlloc(size_t cb) RT_NO_THROW
{
}

RTDECL(void) RTMemExecFree(void *pv) RT_NO_THROW
{
}

RTDECL(void *) RTMemPageAlloc(size_t cb) RT_NO_THROW
{
}

RTDECL(void *) RTMemPageAllocZ(size_t cb) RT_NO_THROW
{
}

RTDECL(void) RTMemPageFree(void *pv) RT_NO_THROW
{
}

RTDECL(int) RTMemProtect(void *pv, size_t cb, unsigned fProtect) RT_NO_THROW
{
}
