# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:43 thomasklausner Exp $

DISTNAME=	scipy-data_fitting-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scipy-data_fitting/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/razor-x/scipy-data_fitting
COMMENT=	Data fitting system with SciPy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.4.1.:../../math/py-sympy

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.0.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
