# $NetBSD$

DISTNAME=	geometry-utils-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/05/f4/0ca9d716fd937996a61377c9094b390601355cc56a781c70dcac3e3f30db/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ihavenonickname/geometry-utils
COMMENT=	Functions for bidimensional and tridimensional arithmetic geometry
LICENSE=	mit

DEPENDS+=       ${PYPKGPREFIX}-pkginfo>=1.5.0.1:../../devel/py-pkginfo
DEPENDS+=       ${PYPKGPREFIX}-wheel>=0.35.1:../../devel/py-wheel
DEPENDS+=       ${PYPKGPREFIX}-twine>=1.13.0:../../net/py-twine
DEPENDS+=       ${PYPKGPREFIX}-sv-geometry>=0.1.3:../../wip/py-sv-geometry

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
