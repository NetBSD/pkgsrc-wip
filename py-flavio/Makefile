# $NetBSD$

DISTNAME=	flavio-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flavio/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://flav-io.github.io/
COMMENT=	Flavour physics phenomenology in the Standard Model and beyond
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mpmath>=0.19:../../math/py-mpmath
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.12:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
