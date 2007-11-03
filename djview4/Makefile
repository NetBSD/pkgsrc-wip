# $NetBSD: Makefile,v 1.1.1.1 2007/11/03 01:36:09 pmatias Exp $
#

DISTNAME=	djview4-4.1-2
PKGNAME=	djview4-4.1nb2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://djvu.sourceforge.net/
COMMENT=	Portable DjVu viewer and browser plugin

WRKSRC=		${WRKDIR}/djview4-4.1.orig
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
