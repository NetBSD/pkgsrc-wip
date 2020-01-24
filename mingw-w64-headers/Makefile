# $NetBSD: Makefile,v 1.6 2012/10/03 15:09:55 asau Exp $

DISTNAME=	mingw-w64-v2.0
PKGNAME=	mingw-w64-headers-2.0
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mingw-w64/mingw-w64/mingw-w64-release/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mingw-w64.sourceforge.net/
COMMENT=	Headers for win32/64 cross-development
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=			${WRKDIR}/${DISTNAME:S/-snapshot//}
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/cross
USE_TOOLS+=		gmake

USE_GNU_CONFIGURE_HOST=	no
CONFIGURE_ARGS+=	--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}	\
			--host=x86_64-w64-mingw32

CONFIGURE_DIRS=		../build
BUILD_DIRS=		../build
INSTALL_DIRS=		../build

CONFIGURE_SCRIPT=	${WRKSRC}/mingw-w64-headers/configure

INSTALLATION_DIRS+=	x86_64-w64-mingw32/lib

post-extract:
	mkdir ${WRKDIR}/build

post-install:
	ln -sf x86_64-w64-mingw32 ${DESTDIR}${PREFIX}/cross/mingw
	ln -sf lib ${DESTDIR}${PREFIX}/cross/x86_64-w64-mingw32/lib64

.include "../../mk/bsd.pkg.mk"
