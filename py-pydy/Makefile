# $NetBSD$

DISTNAME=	pydy-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pydy.org/
COMMENT=	Python tool kit for multi-body dynamics
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.1:../../math/py-sympy
# Theano optional dependencie
#DEPENDS+=	${PYPKGPREFIX}-Theano>=0.7.0:../../math/py-Theano


USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37

#py-cython optional dependencie
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
