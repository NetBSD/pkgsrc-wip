# $NetBSD: Makefile,v 1.9 2004/05/10 22:04:39 blef Exp $
#

DISTNAME=		mingw-gcc-3.3.1-20030804
PKGNAME=		${DISTNAME:S/-20030804//}
WRKSRC=			${WRKDIR}/gcc-3.3.1-20030804-1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_MINGW}
DISTFILES=		gcc-core-3.3.1-20030804-1-src.tar.gz \
			gcc-g++-3.3.1-20030804-1-src.tar.gz \
			gcc-objc-3.3.1-20030804-1-src.tar.gz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://mingw.sf.net/
COMMENT=		GNU C Compiler ported to win32 platforms

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=      	yes
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_GNU_TOOLS+=		make

PATH:=			${CROSSBASE}/bin:${PATH}

CONFIGURE_ARGS+=	--prefix=${PREFIX} --exec-prefix=${PREFIX} \
			--target=${MINGW_TARGET}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} all-target-libobjc
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} all-target-libstdc++-v3

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} install-target-libobjc
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} install-target-libstdc++-v3
	${LN} -s ${CROSSBASE}/bin/${MINGW_TARGET}-cpp ${CROSSBASE}/${MINGW_TARGET}/bin/cpp
	${LN} -s ${CROSSBASE}/bin/${MINGW_TARGET}-gcc ${CROSSBASE}/${MINGW_TARGET}/bin/cc
	cd ${CROSSBASE}/bin/ && ${LN} -s ${MINGW_TARGET}-gcc ${MINGW_TARGET}-cc

.include "../../wip/mingw/Makefile.common"
.include "../../wip/mingw-binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
