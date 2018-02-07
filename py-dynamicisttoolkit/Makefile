# $NetBSD$

DISTNAME=	DynamicistToolKit-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/1e/ed/2be1322f723ef11f959581c7082100dd18b8b82107eca151a3730636290a/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/moorepants/DynamicistToolKit
COMMENT=	Various tools for theoretical and experimental dynamics
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
