# $NetBSD: options.mk,v 1.8 2008/04/22 21:36:38 bsadewitz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.MesaLib
PKG_SUPPORTED_OPTIONS=	mesa-execmem-mmap

# Assembler code build configurations
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS+=		${MACHINE_ARCH}
.endif
###
### XXX Previously, Mesa only allocated executable memory properly on 
###	on linux.  On OpenBSD, NetBSD, etc., for instance, pages which
###	needed to be executable were allocated using malloc(3).  Why
###	did it only work on linux?  Well, #ifdef __linux__ might do that.
###	(ARGH!!@#!@#!@#)
###	See patch-ap for more information.  Please do take note of the 
###	little hack I added to provide for wiring this memory down
###	upon setting the MESA_EXECMEM_MMAP environment variable.
###
###	You may also define MESA_EXECMEM_HEAP_SIZE in your build
###	environment to adjust the size of the anonymous executable
###	memory pool (in bytes).  The default is 10MB.
###
.if (!empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux")
PKG_SUGGESTED_OPTIONS=	mesa-execmem-mmap
.endif
###
### XXX  There are [probably] others, but let's not get crazy just yet.
### 	 This will take a while to test for the myriad platforms we
### 	 support.
###
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
     ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc" || \
     ${MACHINE_ARCH} == "sparc64") && \
    (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD")
PKG_SUPPORTED_OPTIONS+=		dri
.endif

.include "../../mk/bsd.options.mk"
###
### XXX Yes, this is a bit overly verbose; with Mesa, that can't hurt much.
###
.if !empty(PKG_OPTIONS:Mi386) || !empty(PKG_OPTIONS:Mx86_64)
BUILD_TARGET_SUFFIX=	-${MACHINE_ARCH}
.else
BUILD_TARGET_SUFFIX=	# empty
.endif

.if !empty(PKG_OPTIONS:Mdri)
BUILD_TARGET=	pkgsrc-dri${BUILD_TARGET_SUFFIX}
.  include "../../textproc/expat/buildlink3.mk"
.  include "../../x11/glproto/buildlink3.mk"
.  include "../../x11/libXdamage/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libdrm/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  include "../../x11/xf86driproto/buildlink3.mk"
.  include "../../x11/xf86vidmodeproto/buildlink3.mk"
PLIST.dri=	# empty
.else
BUILD_TARGET=	pkgsrc${BUILD_TARGET_SUFFIX}
PLIST.nodri=	# empty
.endif
###
### XXX This is the default heap size.  Would there be an occasion to 
### change it?
###
MESA_EXECMEM_HEAPSIZE?=	10485760
.if !empty(PKG_OPTIONS:Mmesa-execmem-mmap)
CFLAGS+=	-DMESA_EXECMEM_MMAP
CFLAGS+=	-DEXEC_HEAP_SIZE=${MESA_EXECMEM_HEAP_SIZE:M[0-9]*:Q}
.  endif
.endif
