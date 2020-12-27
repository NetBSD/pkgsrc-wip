# $NetBSD$

DISTNAME=	vispy-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vispy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://vispy.org
COMMENT=	Interactive visualization in Python
LICENSE=	modified-bsd

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
