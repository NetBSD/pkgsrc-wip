# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:50 thomasklausner Exp $

DISTNAME=	solpy-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/solpy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/nrcharles/solpy
COMMENT=	Solar Performance and Design library
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

DEPENDS+=	${PYPKGPREFIX}-ephem>=3.7.5.1:../../math/py-ephem
DEPENDS+=	${PYPKGPREFIX}-geopy>=0.12.1:../../wip/py-geopy
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
