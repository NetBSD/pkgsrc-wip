# $NetBSD$

DISTNAME=	multivar_horner-2.1.0
PKGNAME=	${PYPKGPREFIX}-multivar-horner-2.1.0
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/23/4c/e7493a7fc77e3781b787a8a775240e90d9f62c636c5ed93d8491a33e16ff/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/MrMinimal64/multivar_horner
COMMENT=	Multivariate Horner scheme for evaluating multivariate polynomials
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-numba>=0.48:../../math/py-numba

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
