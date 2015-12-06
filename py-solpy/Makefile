# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:50 thomasklausner Exp $

DISTNAME=	solpy-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/s/solpy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/nrcharles/solpy
COMMENT=	Solar Performance and Design library
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

DEPENDS+=	${PYPKGPREFIX}-ephem>=3.7.5.1:../../math/py-ephem
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-geopy>=0.12.1:../../wip/py-geopy

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
