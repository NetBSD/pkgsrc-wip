# $NetBSD: Makefile,v 1.10 2014/01/25 10:45:28 thomasklausner Exp $

DISTNAME=		imgSeek-0.8.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=imgseek/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.imgseek.net/
COMMENT=		Photo collection manager and viewer

USE_LANGUAGES=		c c++
PYDISTUTILSPKG=		yes
REPLACE_PYTHON=	*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-qt3-modules, py-imaging

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-modules/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
