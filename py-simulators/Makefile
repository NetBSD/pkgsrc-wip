# $NetBSD$

DISTNAME=	pysimulators-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysimulators/}
#LICENSE=	CeCILL-B

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pchanial.github.com/pysimulators
COMMENT=	Tools to build an instrument model

DEPENDS+=	${PYPKGPREFIX}-astropy>=1.1.1:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-operators>=0.11.1:../../wip/py-operators

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-astropy

USE_LANGUAGES=	c fortran

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
