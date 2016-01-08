# $NetBSD$

DISTNAME=	bolos-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bolos/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/aluque/bolos
COMMENT=	Library to solve the Boltzmann equation
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
