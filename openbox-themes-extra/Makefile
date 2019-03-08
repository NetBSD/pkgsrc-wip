# $NetBSD$

DISTNAME=	themes
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/bsfd80/qtxqfsts/releases/download/20190228/
EXTRACT_SUFX=	.tar.bz2
PKGNAME=	openbox-themes-extra
MAINTAINER=	pkgls@gmx.net
HOMEPAGE=	https://github.com/bsfd80/qtxqfsts/releases/download/20190228/
COMMENT=	More openbox themes

NO_BUILD=       yes

MAKE_DIRS+=     ${PREFIX}/share/themes/

USE_TOOLS+=     pax

INSTALLATION_DIRS=      share/themes

do-install:
	cd ${WRKSRC} && ${PAX} -rw . \
	${DESTDIR}${PREFIX}/share/themes/

.include "../../mk/bsd.pkg.mk"
