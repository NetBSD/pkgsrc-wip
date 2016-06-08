# $NetBSD$

DISTNAME=	sdeint-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sdeint/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/mattja/sdeint/
COMMENT=	Numerical integration of stochastic differential equations
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
