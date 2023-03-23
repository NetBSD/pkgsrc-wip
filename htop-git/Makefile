# $NetBSD$

DISTNAME=	htop-3.2.2.20230304
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=htop-dev/}
GITHUB_PROJECT=	htop
GITHUB_TAG=     e207c8aebdcdb88bc8ab838e2ac3dd1774d6a618

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://htop.dev/
COMMENT=	Enhanced version of top utility
LICENSE=	gnu-gpl-v2

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
