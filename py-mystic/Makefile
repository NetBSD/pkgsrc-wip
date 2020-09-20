# $NetBSD$

DISTNAME=	mystic-0.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/2a/b2/41d3503725a7fe223a8082b330dad5ebeeb352ca36f0d15a5b00d5bcdc45/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.org/project/mystic
COMMENT=	Constrained non-convex optimization and uncertainty quantification
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sympy>=0.6.7:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-dill>=0.3.2:../../wip/py-dill
DEPENDS+=	${PYPKGPREFIX}-klepto>=0.1.9:../../wip/py-klepto

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
