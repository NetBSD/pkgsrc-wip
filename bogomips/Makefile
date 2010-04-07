# $NetBSD: Makefile,v 1.1.1.1 2010/04/07 05:05:54 schaecsn Exp $
#

DISTNAME=	bogomips-1.4.2
CATEGORIES=	benchmarks
MASTER_SITES=	http://djwong.org/programs/bogomips/

MAINTAINER=	schaecsn@gmx.net

HOMEPAGE=	http://djwong.org/programs/bogomips/
COMMENT=	Unscientific measurement of CPU speed

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/bogomips

.  if ${MACHINE_ARCH} == "i386"
BUILD_TARGET=bogo586
.  elif ${MACHINE_ARCH} == "alpha"
BUILD_TARGET=bogoAlpha
.  elif ${MACHINE_ARCH} == "sparc64"
BUILD_TARGET=bogoSparc64
.  elif ${MACHINE_ARCH} == "sparc"
BUILD_TARGET=bogoSparc
.  elif ${MACHINE_ARCH} == "powerpc"
BUILD_TARGET=bogoPPC
.  elif ${MACHINE_ARCH} == "parisc"
BUILD_TARGET=bogoPPC
.  elif ${MACHINE_ARCH} == "x86_64"
BUILD_TARGET=bogoia64
.else
BUILD_TARGET=bogoport
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_TARGET} ${PREFIX}/bin/bogomips


.include "../../mk/bsd.pkg.mk"
