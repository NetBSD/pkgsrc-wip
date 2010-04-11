# $NetBSD: Makefile,v 1.4 2010/04/11 07:36:11 schaecsn Exp $
#

DISTNAME=	bogomips-1.4.2
CATEGORIES=	benchmarks
MASTER_SITES=	http://djwong.org/programs/bogomips/

MAINTAINER=	schaecsn@gmx.net
HOMEPAGE=	http://djwong.org/programs/bogomips/
COMMENT=	Unscientific measurement of CPU speed
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/bogomips

PKG_OPTIONS_VAR=	PKG_OPTIONS.bogomips
.if ${MACHINE_ARCH:Mi386} || ${MACHINE_ARCH:Mx86_64}
PKG_SUPPORTED_OPTIONS=	bogomips-pentium # version for pentium and above
PKG_SUGGESTED_OPTIONS=	bogomips-pentium # disable for i[34]86
.endif


.include "../../mk/bsd.options.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
.  if !empty(PKG_OPTIONS:Mbogomips-pentium)
   BUILD_TARGET=bogo586
.  else
   BUILD_TARGET=bogo386
.  endif
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
