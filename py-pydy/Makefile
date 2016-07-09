# $NetBSD: Makefile,v 1.1 2015/08/01 22:21:54 jihbed Exp $

DISTNAME=	pydy-0.3.0
 PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pydy.org
COMMENT=	Python tool kit for multi-body dynamics
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.4.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-theano>=0.7.0:../../wip/py-theano


USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE= 34 35

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
