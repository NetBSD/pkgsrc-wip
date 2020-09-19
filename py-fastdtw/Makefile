# $NetBSD$

DISTNAME=	fastdtw-0.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/99/43/30f2d8db076f216b15c10db663b46e22d1750b1ebacd7af6e62b83d6ab98/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/slaypni/fastdtw/
COMMENT=	Dynamic Time Warping (DTW) algorithm with an O(N)
LICENSE=	mit

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
