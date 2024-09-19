# $NetBSD$

DISTNAME=	idx2numpy-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/23/6b/abab4652eb249f432c62431907c8de32bdcedb5abdf869ff86653efff981/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ivanyu/idx2numpy
COMMENT=	Provides tools to convert files to and from IDX format
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
