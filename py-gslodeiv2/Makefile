# $NetBSD$

DISTNAME=	pygslodeiv2-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygslodeiv2/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bjodah/
COMMENT=	Python binding for odeiv2 in GNU Scientific Library (GSL)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
