# $NetBSD$

DISTNAME=	htop-3.1.2.20220103
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=htop-dev/}
GITHUB_PROJECT=	htop
GITHUB_TAG=     2c3a64ac9c755d2d6e0c8aa58ec62c756510201b

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://htop.dev/
COMMENT=	Enhanced version of top utility
LICENSE=	gnu-gpl-v2

# This version does not need procfs mount in NetBSD
# Report bugs to fox@NetBSD.org
CONFLICTS=	htop-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoreconf automake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "../../mk/curses.buildlink3.mk"

.if ${CURSES_TYPE} != "ncursesw"
# See netbsd/README.md
CONFIGURE_ARGS+=	--disable-unicode
.endif

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./autogen.sh

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
