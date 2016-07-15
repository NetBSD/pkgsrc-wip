# $NetBSD$

DISTNAME=	knnimpute-0.0.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/e0/be/c54045678e31c36c0d47d7c2ec2db3c3b13e74e94741c4c5a0031fc4f2a9/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/hammerlab/knnimpute
COMMENT=	K-Nearest Neighbor imputation
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
