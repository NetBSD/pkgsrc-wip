# $NetBSD$

DISTNAME=	numba-0.29.0.dev
GITHUB_PROJECT=	numba
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=numba/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://numba.pydata.org/
COMMENT=	NumPy aware dynamic Python compiler using LLVM
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
