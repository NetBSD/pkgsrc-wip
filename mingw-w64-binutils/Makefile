# $NetBSD: Makefile,v 1.2 2012/10/03 15:09:55 asau Exp $

DISTNAME=	binutils-2.20.1
PKGNAME=	mingw-w64-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/binutils/
COMMENT=	GNU binutils for win32/64 cross-development
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE_PREFIX=	${PREFIX}/cross
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--target=x86_64-w64-mingw32
CONFIGURE_ARGS+=	--enable-targets=x86_64-w64-mingw32,i686-w64-mingw32
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--disable-debug

CONFIGURE_DIRS=		../build
BUILD_DIRS=		../build
INSTALL_DIRS=		../build

CONFIGURE_SCRIPT=	${WRKSRC}/configure

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=		-fbracket-depth=1024
.endif

post-extract:
	mkdir ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"
