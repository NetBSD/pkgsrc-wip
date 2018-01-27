# $NetBSD$

DISTNAME=	trottersuzuki-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trottersuzuki/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://trotter-suzuki-mpi.github.io/
COMMENT=	Massively parallel implementation of the Trotter-Suzuki decomposition
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/trottersuzuki-1.4

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
#.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
