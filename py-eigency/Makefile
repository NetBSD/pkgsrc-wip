# $NetBSD$

DISTNAME=	eigency-1.75
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/55/a0/f6101aa64eb3840a2ca853dea2f8995e44a1a7633c5a70dce2b2672db019/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/wouterboomsma/eigency
COMMENT=	Cython interface between the numpy arrays and the Matrix/Array
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
