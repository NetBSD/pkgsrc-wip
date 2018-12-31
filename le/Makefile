# $NetBSD$

DISTNAME=	le-1.16.5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=lavv17/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	fred@statdns.com
HOMEPAGE=	https://github.com/lavv17/le/
COMMENT=	Full screen text editor inspired by Norton Editor
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
