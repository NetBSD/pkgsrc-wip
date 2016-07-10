$NetBSD$

--- src/VBox/Runtime/r0drv/netbsd/mp-r0drv-netbsd.c.orig	2016-07-07 07:08:46.919669571 +0000
+++ src/VBox/Runtime/r0drv/netbsd/mp-r0drv-netbsd.c
@@ -0,0 +1,268 @@
+/*  mp-r0drv-netbsd.c $ */
+/** @file
+ * IPRT - Multiprocessor, Ring-0 Driver, NetBSD.
+ */
+
+/*
+ * Copyright (C) 2008-2015 Oracle Corporation
+ *
+ * This file is part of VirtualBox Open Source Edition (OSE), as
+ * available from http://www.virtualbox.org. This file is free software;
+ * you can redistribute it and/or modify it under the terms of the GNU
+ * General Public License (GPL) as published by the Free Software
+ * Foundation, in version 2 as it comes in the "COPYING" file of the
+ * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
+ * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
+ *
+ * The contents of this file may alternatively be used under the terms
+ * of the Common Development and Distribution License Version 1.0
+ * (CDDL) only, as it comes in the "COPYING.CDDL" file of the
+ * VirtualBox OSE distribution, in which case the provisions of the
+ * CDDL are applicable instead of those of the GPL.
+ *
+ * You may elect to license modified versions of this file under the
+ * terms and conditions of either the GPL or the CDDL or both.
+ */
+
+
+/*********************************************************************************************************************************
+*   Header Files                                                                                                                 *
+*********************************************************************************************************************************/
+#include "the-netbsd-kernel.h"
+
+#include <iprt/mp.h>
+#include <iprt/err.h>
+#include <iprt/asm.h>
+#include <iprt/cpuset.h>
+#include "r0drv/mp-r0drv.h"
+
+
+RTDECL(RTCPUID) RTMpCpuId(void)
+{
+    return curcpu;
+}
+
+
+RTDECL(int) RTMpCurSetIndex(void)
+{
+    return curcpu;
+}
+
+
+RTDECL(int) RTMpCurSetIndexAndId(PRTCPUID pidCpu)
+{
+    return *pidCpu = curcpu;
+}
+
+
+RTDECL(int) RTMpCpuIdToSetIndex(RTCPUID idCpu)
+{
+    return idCpu < RTCPUSET_MAX_CPUS && idCpu <= mp_maxid ? (int)idCpu : -1;
+}
+
+
+RTDECL(RTCPUID) RTMpCpuIdFromSetIndex(int iCpu)
+{
+    return (unsigned)iCpu <= mp_maxid ? (RTCPUID)iCpu : NIL_RTCPUID;
+}
+
+
+RTDECL(RTCPUID) RTMpGetMaxCpuId(void)
+{
+    return mp_maxid;
+}
+
+
+RTDECL(bool) RTMpIsCpuPossible(RTCPUID idCpu)
+{
+    return idCpu <= mp_maxid;
+}
+
+
+RTDECL(PRTCPUSET) RTMpGetSet(PRTCPUSET pSet)
+{
+    RTCPUID idCpu;
+
+    RTCpuSetEmpty(pSet);
+    idCpu = RTMpGetMaxCpuId();
+    do
+    {
+        if (RTMpIsCpuPossible(idCpu))
+            RTCpuSetAdd(pSet, idCpu);
+    } while (idCpu-- > 0);
+    return pSet;
+}
+
+
+RTDECL(RTCPUID) RTMpGetCount(void)
+{
+    return mp_maxid + 1;
+}
+
+
+RTDECL(RTCPUID) RTMpGetCoreCount(void)
+{
+    return mp_maxid + 1;
+}
+
+RTDECL(bool) RTMpIsCpuOnline(RTCPUID idCpu)
+{
+    return idCpu <= mp_maxid
+        && !CPU_ABSENT(idCpu);
+}
+
+
+RTDECL(PRTCPUSET) RTMpGetOnlineSet(PRTCPUSET pSet)
+{
+    RTCPUID idCpu;
+
+    RTCpuSetEmpty(pSet);
+    idCpu = RTMpGetMaxCpuId();
+    do
+    {
+        if (RTMpIsCpuOnline(idCpu))
+            RTCpuSetAdd(pSet, idCpu);
+    } while (idCpu-- > 0);
+
+    return pSet;
+}
+
+
+RTDECL(RTCPUID) RTMpGetOnlineCount(void)
+{
+    return mp_ncpus;
+}
+
+
+/**
+ * Wrapper between the native NetBSD per-cpu callback and PFNRTWORKER
+ * for the RTMpOnAll API.
+ *
+ * @param   pvArg   Pointer to the RTMPARGS package.
+ */
+static void rtmpOnAllNetBSDWrapper(void *pvArg)
+{
+    PRTMPARGS pArgs = (PRTMPARGS)pvArg;
+    pArgs->pfnWorker(curcpu, pArgs->pvUser1, pArgs->pvUser2);
+}
+
+
+RTDECL(int) RTMpOnAll(PFNRTMPWORKER pfnWorker, void *pvUser1, void *pvUser2)
+{
+    RTMPARGS Args;
+    Args.pfnWorker = pfnWorker;
+    Args.pvUser1 = pvUser1;
+    Args.pvUser2 = pvUser2;
+    Args.idCpu = NIL_RTCPUID;
+    Args.cHits = 0;
+    smp_rendezvous(NULL, rtmpOnAllNetBSDWrapper, smp_no_rendevous_barrier, &Args);
+    return VINF_SUCCESS;
+}
+
+
+/**
+ * Wrapper between the native NetBSD per-cpu callback and PFNRTWORKER
+ * for the RTMpOnOthers API.
+ *
+ * @param   pvArg   Pointer to the RTMPARGS package.
+ */
+static void rtmpOnOthersNetBSDWrapper(void *pvArg)
+{
+    PRTMPARGS pArgs = (PRTMPARGS)pvArg;
+    RTCPUID idCpu = curcpu;
+    if (pArgs->idCpu != idCpu)
+        pArgs->pfnWorker(idCpu, pArgs->pvUser1, pArgs->pvUser2);
+}
+
+
+RTDECL(int) RTMpOnOthers(PFNRTMPWORKER pfnWorker, void *pvUser1, void *pvUser2)
+{
+    /* Will panic if no rendezvousing cpus, so check up front. */
+    if (RTMpGetOnlineCount() > 1)
+    {
+        cpuset_t    Mask;
+        RTMPARGS    Args;
+
+        Args.pfnWorker = pfnWorker;
+        Args.pvUser1 = pvUser1;
+        Args.pvUser2 = pvUser2;
+        Args.idCpu = RTMpCpuId();
+        Args.cHits = 0;
+    Mask = all_cpus;
+    CPU_CLR(curcpu, &Mask);
+        smp_rendezvous_cpus(Mask, NULL, rtmpOnOthersNetBSDWrapper, smp_no_rendevous_barrier, &Args);
+    }
+    return VINF_SUCCESS;
+}
+
+
+/**
+ * Wrapper between the native NetBSD per-cpu callback and PFNRTWORKER
+ * for the RTMpOnSpecific API.
+ *
+ * @param   pvArg   Pointer to the RTMPARGS package.
+ */
+static void rtmpOnSpecificNetBSDWrapper(void *pvArg)
+{
+    PRTMPARGS   pArgs = (PRTMPARGS)pvArg;
+    RTCPUID     idCpu = curcpu;
+    if (pArgs->idCpu == idCpu)
+    {
+        pArgs->pfnWorker(idCpu, pArgs->pvUser1, pArgs->pvUser2);
+        ASMAtomicIncU32(&pArgs->cHits);
+    }
+}
+
+
+RTDECL(int) RTMpOnSpecific(RTCPUID idCpu, PFNRTMPWORKER pfnWorker, void *pvUser1, void *pvUser2)
+{
+    cpuset_t    Mask;
+    RTMPARGS    Args;
+
+    /* Will panic if no rendezvousing cpus, so make sure the cpu is online. */
+    if (!RTMpIsCpuOnline(idCpu))
+        return VERR_CPU_NOT_FOUND;
+
+    Args.pfnWorker = pfnWorker;
+    Args.pvUser1 = pvUser1;
+    Args.pvUser2 = pvUser2;
+    Args.idCpu = idCpu;
+    Args.cHits = 0;
+
+    CPU_SETOF(idCpu, &Mask);
+    smp_rendezvous_cpus(Mask, NULL, rtmpOnSpecificNetBSDWrapper, smp_no_rendevous_barrier, &Args);
+
+    return Args.cHits == 1
+         ? VINF_SUCCESS
+         : VERR_CPU_NOT_FOUND;
+}
+
+
+/**
+ * Dummy callback for RTMpPokeCpu.
+ * @param   pvArg   Ignored
+ */
+static void rtmpNetBSDPokeCallback(void *pvArg)
+{
+    NOREF(pvArg);
+}
+
+
+RTDECL(int) RTMpPokeCpu(RTCPUID idCpu)
+{
+    cpuset_t    Mask;
+
+    /* Will panic if no rendezvousing cpus, so make sure the cpu is online. */
+    if (!RTMpIsCpuOnline(idCpu))
+        return VERR_CPU_NOT_FOUND;
+
+    CPU_SETOF(idCpu, &Mask);
+    smp_rendezvous_cpus(Mask, NULL, rtmpNetBSDPokeCallback, smp_no_rendevous_barrier, NULL);
+
+    return VINF_SUCCESS;
+}
+
+RTDECL(bool) RTMpOnAllIsConcurrentSafe(void)
+{
+    return true;
+}
