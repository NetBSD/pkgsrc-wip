# $NetBSD: Makefile,v 1.13 2005/05/24 10:31:02 rillig Exp $
#

DISTNAME=		mingw-gcc-${DIST_VERSION}
PKGNAME=		${DISTNAME:S/-${DIST_VERSION}/-3.4.2/}
WRKSRC=			${WRKDIR}/gcc-${DIST_VERSION}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_MINGW}
DISTFILES=		gcc-core-${DIST_VERSION}-src.tar.gz \
			gcc-g++-${DIST_VERSION}-src.tar.gz \
			gcc-objc-${DIST_VERSION}-src.tar.gz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://mingw.sf.net/
COMMENT=		GNU C Compiler ported to win32 platforms

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=      	yes
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes

DIST_VERSION=		3.4.2-20040916-1

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		all-target-libobjc
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		all-target-libstdc++-v3

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} install-target-libobjc
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} install-target-libstdc++-v3
	${LN} -fs ${CROSSBASE}/bin/${MINGW_TARGET}-cpp \
		${CROSSBASE}/${MINGW_TARGET}/bin/cpp
	${LN} -fs ${CROSSBASE}/bin/${MINGW_TARGET}-gcc \
		${CROSSBASE}/${MINGW_TARGET}/bin/cc
	cd ${CROSSBASE}/bin/ && ${LN} -fs ${MINGW_TARGET}-gcc ${MINGW_TARGET}-cc

.include "../../wip/mingw/Makefile.common"
.include "../../wip/mingw-binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
