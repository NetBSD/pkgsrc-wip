# $NetBSD$

DISTNAME=	Equation-1.2.01
EGG_NAME=	Equation-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=E/Equation/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/alphaomega-technology/Equation
COMMENT=	General Equation Parser and Evaluator

BUILD_DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.2:../../math/py-numpy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
