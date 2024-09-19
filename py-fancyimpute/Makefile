# $NetBSD$

DISTNAME=	fancyimpute-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/b8/4d/f460fe747949d2b84f21cfaebe58fe1de8f4dcd6779d5fc58adb2f885417/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/hammerlab/fancyimpute
COMMENT=	Matrix completion and feature imputation algorithms
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-keras>=1.0.5:../../wip/py-keras

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
