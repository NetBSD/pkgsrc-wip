# $NetBSD$

DISTNAME=	metropack-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/m/metropack/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/eddiejessup/metropack
COMMENT=	Pack spheres in a finite space
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-spatious>=0.1.2:../../wip/py-spatious

WRKSRC=		${WRKDIR}/metropack-0.1.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
