# $NetBSD$

DISTNAME=	htop-3.3.0.20241220
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=htop-dev/}
GITHUB_PROJECT=	htop
GITHUB_TAG=     28dcbd758488dcdf2b57f0b3fb26833a8495375a

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://htop.dev/
COMMENT=	Enhanced version of top utility
LICENSE=	gnu-gpl-v2

CONFLICTS=	htop-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf automake pkg-config
USE_CURSES=	getmouse

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./autogen.sh

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
