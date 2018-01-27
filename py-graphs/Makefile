# $NetBSD$

DISTNAME=	graphs-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=g/graphs/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/all-umass/graphs
COMMENT=	Library for graph-based machine learning
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy

USE_LANGUAGES=	c c++


.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"	
.include "../../mk/bsd.pkg.mk"
