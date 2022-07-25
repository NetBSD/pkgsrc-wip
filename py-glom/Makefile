# $NetBSD$

DISTNAME=	glom-22.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/glom/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mahmoud/glom
COMMENT=	Python's nested data operator (and CLI)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-attrs>=0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-boltons>=19.3.0:../../devel/py-boltons
DEPENDS+=	${PYPKGPREFIX}-face>=20.1.0:../../wip/py-face

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
