# $NetBSD$

DISTNAME=	ScalPy-0.1.0b
EGG_NAME=	${DISTNAME}0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=S/ScalPy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/sum33it/scalpy
COMMENT=	ScalPy: A python tool to study dynamical systems in cosmology
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
