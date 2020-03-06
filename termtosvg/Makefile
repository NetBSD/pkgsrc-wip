# $NetBSD$

DISTNAME=	termtosvg-1.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nbedos/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://nbedos.github.io/termtosvg/
COMMENT=	Record terminal sessions as SVG animations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pyte-[0-9]*:../../devel/py-pyte
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

REPLACE_PYTHON=	*.py

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
