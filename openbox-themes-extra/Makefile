# $NetBSD$

DISTNAME=	openbox-themes-1.0
CATEGORIES=	wm
MASTER_SITES=	https://github.com/bsfd80/qtxqfsts/releases/download/20190228/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgls@gmx.net
HOMEPAGE=	https://github.com/bsfd80/qtxqfsts/releases/download/20190228/
COMMENT=	Openbox window manager themes

WRKSRC=		${WRKDIR}/themes
USE_LANGUAGES=	# none
NO_BUILD=	yes
DESTDIR=	$WRKSRC

do-install:
	${INSTALL_PROGRAM} ${WRKSRC} ${DESTDIR}${PREFIX}/themes

.include "../../mk/bsd.pkg.mk"
