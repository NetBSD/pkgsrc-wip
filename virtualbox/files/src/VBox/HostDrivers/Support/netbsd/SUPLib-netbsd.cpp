#define LOG_GROUP LOG_GROUP_SUP
#ifdef IN_SUP_HARDENED_R3
# undef DEBUG /* Warning: disables RT_STRICT */
# define LOG_DISABLED
  /** @todo RTLOGREL_DISABLED */
# include <iprt/log.h>
# undef LogRelIt
# define LogRelIt(pvInst, fFlags, iGroup, fmtargs) do { } while (0)
#endif

#include <VBox/log.h>
#include <VBox/sup.h>
#include <iprt/path.h>
#include <iprt/assert.h>
#include <VBox/types.h>
#include <iprt/string.h>
#include <VBox/err.h>
#include <VBox/param.h>
#include "../SUPLibInternal.h"
#include "../SUPDrvIOC.h"


int suplibOsInit(PSUPLIBDATA pThis, bool fPreInited)
{
}

int suplibOsTerm(PSUPLIBDATA pThis)
{
}

int suplibOsInstall(void)
{
}

int suplibOsUninstall(void)
{
}

int suplibOsIOCtl(PSUPLIBDATA pThis, uintptr_t uFunction, void *pvReq, size_t cbReq)
{
}

int suplibOsIOCtlFast(PSUPLIBDATA pThis, uintptr_t uFunction, uintptr_t idCpu)
{
}

int suplibOsPageAlloc(PSUPLIBDATA pThis, size_t cPages, void **ppvPages)
{
}

int suplibOsPageFree(PSUPLIBDATA pThis, void *pvPages, size_t cPages)
{
}
