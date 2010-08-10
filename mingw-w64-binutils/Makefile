# $NetBSD: Makefile,v 1.1.1.1 2010/08/10 14:50:56 tnn2 Exp $
#

DISTNAME=	binutils-2.20.1
PKGNAME=	mingw-w64-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/binutils/
COMMENT=	GNU binutils for win32/64 cross-development
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_CROSSBASE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--target=x86_64-w64-mingw32	\
			  --enable-targets=x86_64-w64-mingw32,i686-w64-mingw32

CONFIGURE_DIRS=		../build
BUILD_DIRS=		../build
INSTALL_DIRS=		../build

CONFIGURE_SCRIPT=	${WRKSRC}/configure

post-extract:
	mkdir ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"
