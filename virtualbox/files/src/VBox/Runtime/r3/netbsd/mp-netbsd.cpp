#include <iprt/mp.h>
#include <iprt/cpuset.h>
#include <iprt/assert.h>
#include <iprt/string.h>
#include <iprt/alloc.h>
#include <iprt/log.h>
#include <iprt/once.h>
#include <iprt/critsect.h>

RTDECL(uint32_t) RTMpGetCurFrequency(RTCPUID idCpu)
{
}

RTDECL(uint32_t) RTMpGetMaxFrequency(RTCPUID idCpu)
{
}

RTDECL(RTCPUID) RTMpGetOnlineCount(void)
{
}
