# $NetBSD: Makefile,v 1.6 2012/10/03 22:14:53 thomasklausner Exp $
#

DISTNAME=		imgSeek-0.8.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=imgseek/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.imgseek.net/
COMMENT=		Photo collection manager and viewer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
PYDISTUTILSPKG=		yes
PYTHON_PATCH_SCRIPTS=	*.py

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-modules/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
