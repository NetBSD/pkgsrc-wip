# $NetBSD$

DISTNAME=	numdifftools-0.9.39
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numdifftools/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pbrod/numdifftools
COMMENT=	Solves automatic numerical differentiation problems
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner>=5.2:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.8:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-statsmodels>=0.11.1:../../math/py-statsmodels
DEPENDS+=	${PYPKGPREFIX}-algopy>=0.5.7:../../wip/py-algopy

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
