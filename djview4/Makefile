# $NetBSD: Makefile,v 1.8 2012/09/28 21:24:37 asau Exp $
#

DISTNAME=	djview4-4.3
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://djvu.sourceforge.net/djview4.html
COMMENT=	Portable DjVu viewer and browser plugin
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/djview4-4.3
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
