# $NetBSD$

DISTNAME=	autograd-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autograd/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/HIPS/autograd
COMMENT=	Efficiently computes derivatives of numpy code
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-future>=0.15.2:../../devel/py-future

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.12
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
