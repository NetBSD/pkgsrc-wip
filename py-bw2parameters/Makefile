# $NetBSD$

DISTNAME=	bw2parameters-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bw2parameters/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/bw2parameters/
COMMENT=	Library for storing, validating, and calculating with parameters
#LICENSE=	Copyright (c) 2016, Chris Mutel and Paul Scherrer Institut.

DEPENDS+=	${PYPKGPREFIX}-asteval>=0.9.21:../../math/py-asteval
DEPENDS+=	${PYPKGPREFIX}-astunparse>=1.6.3:../../wip/py-astunparse
DEPENDS+=	${PYPKGPREFIX}-stats-arrays>=0.6.4:../../wip/py-stats-arrays

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
