# $NetBSD$

DISTNAME=	galry-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics parallel
MASTER_SITES=	${MASTER_SITE_PYPI:=g/galry/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/rossant/galry
COMMENT=	High-performance interactive visualization in Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-OpenGL>=3.0.1:../../graphics/py-OpenGL

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
