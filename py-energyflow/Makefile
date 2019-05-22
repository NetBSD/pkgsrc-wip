# $NetBSD$

DISTNAME=	EnergyFlow-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/ea/ba/5db21316b0051804eec5d3410263bd710799dbab4b0bbc08c2ba029d5450/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://energyflow.network/
COMMENT=	Python package for the Energy Flow suite of particle physics tools
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSION_DEFAULT=	37

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
