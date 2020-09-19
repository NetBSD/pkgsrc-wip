# $NetBSD$

DISTNAME=	ropemode-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/1d/f9/744263e13a8688afab4c61474a1d06cfc16dd454db6bc718801ce7b31726/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=       https://rope.sf.net/
COMMENT=        Ropemode, a helper for using rope refactoring library in IDEs
LICENSE=        gnu-gpl-v3

DEPENDS+=       ${PYPKGPREFIX}-rope-[0-9]*:../../devel/py-rope

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
