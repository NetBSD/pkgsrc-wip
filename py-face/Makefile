# $NetBSD$

DISTNAME=	face-20.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/face/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mahmoud/face
COMMENT=	Command-line application framework (and CLI parser)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-boltons>=20.0.0:../../devel/py-boltons

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
