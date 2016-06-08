# $NetBSD$

DISTNAME=	Bottleneck-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Bottleneck/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://berkeleyanalytics.com/bottleneck/
COMMENT=	Fast, NumPy array functions written in Cython
LICENSE=	2-clause-bsd

#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
