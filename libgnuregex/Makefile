# $NetBSD$

DISTNAME=	regex-0.12
PKGNAME=	${DISTNAME:S/^/libgnu/}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnu.org/old-gnu/regex/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://directory.fsf.org/wiki/Regex
COMMENT=	GNU Regex library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

LIB=	libgnuregex.la
INC=	gnuregex.h

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	SHELL=${SH:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	subdirs=

INSTALLATION_DIRS=	${PREFIX}/include ${PREFIX}/lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/${LIB} 	\
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${INC:S/gnu//} 			\
		${DESTDIR}${PREFIX}/include/${INC}


.include "../../mk/bsd.pkg.mk"
