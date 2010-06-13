# $NetBSD: Makefile,v 1.5 2010/06/13 22:46:59 thomasklausner Exp $
#

DISTNAME=	djview4-4.3
PKGNAME=	djview4-4.3
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://djvu.sourceforge.net/
COMMENT=	Portable DjVu viewer and browser plugin

WRKSRC=		${WRKDIR}/djview4-4.3
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
