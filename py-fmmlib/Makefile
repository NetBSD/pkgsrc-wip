# $NetBSD$

DISTNAME=	pyfmmlib-2015.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfmmlib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/inducer/pyfmmlib
COMMENT=	Python wrappers for particle FMMs
#LICENSE=	gnu-gpl-v2 AND mit

USE_LANGUAGES=	c fortran

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
