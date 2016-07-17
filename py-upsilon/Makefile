# $NetBSD$

DISTNAME=	upsilon-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/10/05/99c8b1f10556c80b26e09dc88e86d84a9d957033e73c3ffa27258c2cefec/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/dwkim78/upsilon
COMMENT=	Automated Classification of Periodic Variable Stars
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.17:../../wip/py-scikit-learn

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.8.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
