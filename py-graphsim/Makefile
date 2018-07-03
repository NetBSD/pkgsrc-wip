# $NetBSD$

DISTNAME=	graphsim-0.2.6.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc math
MASTER_SITES=	${MASTER_SITE_PYPI:=g/graphsim/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/caesar0301/graphsim
COMMENT=	Graph similarity algorithms based on NetworkX
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.10:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-typedecorator>=0.0.4:../../wip/py-typedecorator

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.2.6.8

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
