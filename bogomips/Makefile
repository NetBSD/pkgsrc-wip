# $NetBSD: Makefile,v 1.3 2010/04/08 23:23:02 schaecsn Exp $
#

DISTNAME=	bogomips-1.4.2
CATEGORIES=	benchmarks
MASTER_SITES=	http://djwong.org/programs/bogomips/

MAINTAINER=	schaecsn@gmx.net
HOMEPAGE=	http://djwong.org/programs/bogomips/
COMMENT=	Unscientific measurement of CPU speed
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/bogomips

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_TARGET=bogo586
.elif ${MACHINE_ARCH} == "alpha"
BUILD_TARGET=bogoAlpha
.elif ${MACHINE_ARCH} == "sparc64"
BUILD_TARGET=bogoSparc64
.elif ${MACHINE_ARCH} == "sparc"
BUILD_TARGET=bogoSparc
.elif ${MACHINE_ARCH} == "powerpc"
BUILD_TARGET=bogoPPC
.elif ${MACHINE_ARCH} == "hppa"
BUILD_TARGET=bogoPPC
.else
BUILD_TARGET=bogoport
.endif

INSTALLATION_DIRS+= share/doc/bogomips
INSTALLATION_DIRS+= bin


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_TARGET} ${DESTDIR}${PREFIX}/bin/bogomips
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/bogomips


.include "../../mk/bsd.pkg.mk"
