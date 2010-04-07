# $NetBSD: Makefile,v 1.2 2010/04/07 22:01:55 schaecsn Exp $
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


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_TARGET} ${DESTDIR}/${PREFIX}/bin/bogomips
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}/${PREFIX}/share/doc/bogomips


.include "../../mk/bsd.pkg.mk"
