# $NetBSD: Makefile,v 1.1 2014/03/21 21:00:35 jihbed Exp $

DISTNAME=	solpy-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/s/solpy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/nrcharles/solpy
COMMENT=	Solar Performance and Design library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-ephem>=3.7.5.1:../../math/py-ephem
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-geopy>=0.12.1:../../wip/py-geopy

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
