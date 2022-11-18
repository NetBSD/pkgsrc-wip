# $NetBSD$

DISTNAME=	opt_einsum-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=o/opt_einsum/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dgasmith/opt_einsum
COMMENT=	Optimizing numpys einsum function
LICENSE=	mit

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
