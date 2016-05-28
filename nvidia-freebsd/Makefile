# $NetBSD: Makefile,v 1.11 2012/10/03 18:15:33 asau Exp $
#

DISTNAME=	NVIDIA-FreeBSD-x86-${DIST_VERSION}
PKGNAME=	nvidia-freebsd-${DIST_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.nvidia.com/freebsd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nvidia.com/
COMMENT=	NVIDIA Graphic drivers for FreeBSD/i386

ONLY_FOR_PLATFORM=	FreeBSD-5*-i386 # Yeah I don't use 4.x, sorry.
DIST_VERSION=		1.0-4365
LINUX_DISTVER=		1.0.4365

RESTRICTED=		Redistribution of unmodified source only; resale prohibited.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_PACKAGE=		# Oi!


.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	X11_TYPE
BUILD_DEFS+=	COMPAT_LINUX

X11_TYPE?=		XFree86		# If you use XFree86 from pkgsrc.
COMPAT_LINUX?=		no		# Linux compat libraries.
CHECK_SHLIBS=		no

.if !empty(X11_TYPE:MXFree86)
SUBST_CLASSES+=		fixme
SUBST_STAGE.fixme=	post-patch
SUBST_FILES.fixme=	doc/Makefile driver/Makefile \
			extension/Makefile lib/libGL/Makefile \
			lib/libGLcore/Makefile lib/libXvMCNVIDIA/Makefile \
			lib/Makefile
SUBST_SED.fixme=	-e "s|\$${X11BASE}|${X11BASE}|g"
SUBST_MESSAGE.fixme=	Fixing X11BASE for pkgsrc.
.endif # X11_TYPE=XFree86

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
X11MODDIR=		${X11BASE}/lib/modules
X11_LINUX_LIBDIR=	${PREFIX}/emul/linux/usr/X11R6/lib
DISTOBJDIR=		${WRKSRC}/obj

LINUX_LIBS=		libGL libGLcore
XFREE86_LIBS=		${LINUX_LIBS} libXvMCNVIDIA

do-build:
	cd ${WRKSRC} && /usr/bin/make

do-install:

# Module kernel
.if !exists(/boot/kernel/nvidia.ko)
	${INSTALL_DATA} ${WRKSRC}/module/nvidia.ko /boot/kernel
.else
	@(							\
	${ECHO_MSG};						\
	${ECHO_MSG} "==> nvidia.ko module already installed";	\
	${ECHO_MSG};						\
	)
.endif

# Documentation
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README* ${DOCDIR}

# XFree86 module driver
.if !exists(${X11MODDIR}/drivers/nvidia_drv.o)
	${INSTALL_DATA} ${DISTOBJDIR}/nvidia_drv.o ${X11MODDIR}/drivers
.else
	${RM} ${X11MODDIR}/drivers/nvidia_drv.o
.endif

# OpenGL & NVIDIA libraries
.for nlib in ${XFREE86_LIBS}
.  if !exists(${X11BASE}/lib/${nlib}.so.1)
	${INSTALL_DATA} ${DISTOBJDIR}/${nlib}.so.1 ${X11BASE}/lib
.  else
.    if exists(${X11BASE}/lib/${nlib}.so.1.bak)
	${MV} ${X11BASE}/lib/${nlib}.so.1.bak ${X11BASE}/lib/${nlib}.so.1
.    else
	${CP} ${X11BASE}/lib/${nlib}.so.1 ${X11BASE}/lib/${nlib}.so.1.bak
.    endif
.  endif
	${LN} -sf ${X11BASE}/lib/${nlib}.so.1 ${X11BASE}/lib/${nlib}.so
.endfor

.if !exists(${X11MODDIR}/extensions/libglx.so.1)
	${INSTALL_DATA} ${DISTOBJDIR}/libglx.so.1 ${X11MODDIR}/extensions
	${LN} -sf ${X11MODDIR}/extensions/libglx.so.1 \
		${X11MODDIR}/extensions/libglx.so
.else
.  if exists(${X11MODDIR}/extensions/libglx.so.1.bak)
	${MV} ${X11MODDIR}/extensions/libglx.so.1.bak \
		${X11MODDIR}/extensions/libglx.so.1
.  else
	${CP} ${X11MODDIR}/extensions/libglx.so.1 \
		${X11MODDIR}/extensions/libglx.so.1.bak
.  endif
	${LN} -sf ${X11MODDIR}/extensions/libglx.so.1 \
		${X11MODDIR}/extensions/libglx.so
.endif # libglx.so

# Linux compat libraries
.if !empty(COMPAT_LINUX:M[Yy][Ee][Ss])
.  for clib in ${LINUX_LIBS}
.    if !exists(${X11_LINUX_LIBDIR}/${clib}.so.${LINUX_DISTVER})
	${INSTALL_DATA} ${DISTOBJDIR}/linux/${clib}.so.${LINUX_DISTVER} \
		${X11_LINUX_LIBDIR}
.    else
.      if exists(${X11_LINUX_LIBDIR}/${clib}.so.${LINUX_DISTVER}.bak)
	${MV} ${X11_LINUX_LIBDIR}/${clib}.so.${LINUX_DISTVER}.bak \
		${X11_LINUX_LIBDIR}/${clib}.so.${LINUX_DISTVER}
.      else
	${CP} ${X11_LINUX_LIBDIR}/${clib}.so.${LINUX_DISTVER} \
		${X11_LINUX_LIBDIR}/${clib}.so.${LINUX_DISTVER}.bak
.      endif
.    endif
	${LN} -sf ${X11_LINUX_LIBDIR}/${clib}.so.${LINUX_DISTVER} \
		${X11_LINUX_LIBDIR}/${clib}.so.1
	${LN} -sf ${X11_LINUX_LIBDIR}/${clib}.so.${LINUX_DISTVER} \
		${X11_LINUX_LIBDIR}/${clib}.so
.  endfor
.endif # USE_COMPAT_LINUX

post-install:
	${LDCONFIG} -m ${X11BASE}/lib

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
