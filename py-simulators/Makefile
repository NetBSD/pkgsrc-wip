# $NetBSD: Makefile,v 1.2 2014/12/31 13:58:43 thomasklausner Exp $

DISTNAME=	pysimulators-0.8.dev26-g93d2e
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//S/-g93d2e//}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pysimulators/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pchanial.github.com/pysimulators
COMMENT=	Tools to build an instrument model
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-astropy>=0.3.1:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-operators>=0.11.1:../../wip/py-operators

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-astropy

USE_LANGUAGES=	c fortran

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
