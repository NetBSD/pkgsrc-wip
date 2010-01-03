# $NetBSD: hacks.mk,v 1.1.1.1 2010/01/03 14:32:17 pallegra Exp $

.  include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
##
## NetBSD 2.x and earlier require pthread stubs
##
.  include "../../devel/pthread-stublib/buildlink3.mk"
PTHREAD_STUBLIB= -L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lpthstub
.elif !empty(MACHINE_PLATFORM:MNetBSD-*)
##
## NetBSD 3.x and later have pthread stubs in libc
##
PTHREAD_STUBLIB=
.else
##
## Other platforms may or may not have stubs provided by libc, but pulling in
## threading support via the pthread.buildlink3.mk definitions will provide
## all the necessary interfaces.  This matches the standard configuration for
## most platforms as they appear in "${WRKSRC}/configs", and is necessary
## for successful linking with libGL under many platforms.
##
.include "../../mk/pthread.buildlink3.mk"
PTHREAD_STUBLIB=	${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}
.endif

.  if ${OPSYS} == "NetBSD" && !empty(MACHINE_ARCH:M*86*) && \
	empty(PTHREAD_STUBLIB:U:M*pthstub*)
SUBST_CLASSES+= asm-hack
SUBST_FILES.asm-hack=	src/mesa/x86/glapi_x86.S
SUBST_FILES.asm-hack+=	src/mesa/x86-64/glapi_x86-64.S
SUBST_FILES.asm-hack+=	src/mesa/glapi/glthread.c
SUBST_MESSAGE.asm-hack=	Teaching glapi about NetBSD thread stubs
SUBST_SED.asm-hack=	-e 's,pthread_getspecific,__libc_thr_getspecific,g'
SUBST_STAGE.asm-hack=	pre-configure
.  endif

SUBST_CLASSES+= pthread-hack
SUBST_FILES.pthread-hack=	configs/current
SUBST_MESSAGE.pthread-hack=	pthread hack
SUBST_SED.pthread-hack=		-e 's,-lpthread,${PTHREAD_STUBLIB},g'
SUBST_STAGE.pthread-hack=	post-configure

CFLAGS.NetBSD+= -D_NETBSD_SOURCE
CFLAGS.NetBSD+= ${ATOMIC_OPS_CHECK}HAVE_NETBSD_ATOMIC_OPS

.if ${OPSYS} == "NetBSD" && !target(netbsd-atomic-ops-check)
.PHONY: netbsd-atomic-opts-check
netbsd-atomic-ops-check:
ATOMIC_OPS_CHECK!=\
  if ( ${NM} /usr/lib/libc.so | ${GREP} -q atomic_cas_uint ); then \
    ${ECHO} "-D"; \
  else  \
    ${ECHO} "-U"; \
  fi
.endif

.if (${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "sparc64" || \
    ${MACHINE_ARCH} == "alpha")
CFLAGS+=	-D__GLX_ALIGN64
.endif

.if !empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64)
###
### This is taken from <sys/arch/i386/include/npx.h>.  If we don't override
### it, the FPU control word will be restored to 0x037f.
###
### Also, see patch-aq about the libm functions required (float functions
### such as floorf).  Proper configuration of this should be a goal of
### the Mesa developers; alas, it obviously is not.
###
### XXX We need a reliable check for these functions.
###
#/* NetBSD uses IEEE double precision. */
CFLAGS.NetBSD+=		-DDEFAULT_X86_FPU=0x127f
###
#/* FreeBSD leaves some exceptions unmasked as well. */
###
CFLAGS.FreeBSD+=	-DDEFAULT_X86_FPU=0x1272
.endif

CFLAGS.FreeBSD+=	-DUSE_NATIVE_LIBM_FUNCS
CFLAGS.NetBSD+=		-DUSE_NATIVE_LIBM_FUNCS
CFLAGS.DragonFly+=	-DUSE_NATIVE_LIBM_FUNCS
