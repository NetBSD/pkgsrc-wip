# $NetBSD$

DISTNAME=	Bottleneck-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Bottleneck/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://berkeleyanalytics.com/bottleneck/
COMMENT=	Fast NumPy array functions written in Cython
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.9.1
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
