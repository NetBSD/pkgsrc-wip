# $NetBSD: Makefile,v 1.1.1.1 2010/08/10 15:30:56 tnn2 Exp $
#

DISTNAME=	mingw-w64-v1.0-snapshot-20100730
PKGNAME=	mingw-w64-headers-1.0
CATEGORIES=	cross
MASTER_SITES=	 ${MASTER_SITE_SOURCEFORGE:=mingw-w64/mingw-w64/mingw-w64-snapshot/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mingw-w64.sourceforge.net/
COMMENT=	Headers for win32/64 cross-development
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME:S/-snapshot//}
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_TOOLS+=		gmake

USE_GNU_CONFIGURE_HOST=	no
CONFIGURE_ARGS+=	--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}	\
			--host=x86_64-w64-mingw32

CONFIGURE_DIRS=		../build
BUILD_DIRS=		../build
INSTALL_DIRS=		../build

CONFIGURE_SCRIPT=	${WRKSRC}/mingw-w64-headers/configure

INSTALLATION_DIRS+=	cross/x86_64-w64-mingw32/lib

post-extract:
	mkdir ${WRKDIR}/build

post-install:
	ln -sf x86_64-w64-mingw32 ${DESTDIR}${PREFIX}/mingw

.include "../../mk/bsd.pkg.mk"
