# $NetBSD$

DISTNAME=	knnimpute-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=k/knnimpute/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/hammerlab/knnimpute
COMMENT=	K-Nearest Neighbor imputation
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
