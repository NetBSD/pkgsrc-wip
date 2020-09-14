# $NetBSD$

VERSION=	0.26.0
DISTNAME=	poisson_approval-0.26.0
PKGNAME=	${PYPKGPREFIX}-poisson-approval-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/20/c1/4e996c171f7c7e06258f95b1671096f935a506589ed5ab1d881d6c2304ca/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/francois-durand/poisson_approval
COMMENT=	Poisson Approval studies the Poisson Game of Approval Voting
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	# TODO: pytest-runner>=0
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.4.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	# TODO: python-ternary>=0
DEPENDS+=	# TODO: shapely>=0
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
TEST_DEPENDS+=	# TODO: pytest>=3

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
