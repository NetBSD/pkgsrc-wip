# $NetBSD: Makefile,v 1.3 2003/12/15 15:23:37 mpasternak Exp $
#

DISTNAME=		mingw-gcc-3.3.1-20030804
WRKSRC=			${WRKDIR}/gcc-3.3.1-20030804-1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_MINGW}
DISTFILES=		gcc-core-3.3.1-20030804-1-src.tar.gz \
			gcc-g++-3.3.1-20030804-1-src.tar.gz \
			gcc-objc-3.3.1-20030804-1-src.tar.gz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://mingw.sf.net/
COMMENT=		GNU C Compiler ported to win32 platforms

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=      	yes
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_GMAKE=		yes

PATH:=			${CROSSBASE}/bin:${PATH}

CONFIGURE_ARGS+=	--prefix=${PREFIX} --exec-prefix=${PREFIX} \
			--target=${MINGW_TARGET} \
			--enable-languages="c++" --enable-languages="objc" \
			--enable-languages="c"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS}

# is it needed? 
#	cd ${GCCDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} all-target-libobjc

post-install:
	${LN} -s ${CROSSBASE}/bin/${MINGW_TARGET}-cpp ${CROSSBASE}/${MINGW_TARGET}/bin/cpp
	${LN} -s ${CROSSBASE}/bin/${MINGW_TARGET}-gcc ${CROSSBASE}/${MINGW_TARGET}/bin/cc
	cd ${CROSSBASE}/bin/ && ${LN} -s ${MINGW_TARGET}-gcc ${MINGW_TARGET}-cc

.include "../../wip/mingw/Makefile.common"
.include "../../wip/mingw-binutils/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
