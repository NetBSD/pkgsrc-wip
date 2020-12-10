# $NetBSD$

DISTNAME=	coverage-badge-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coverage-badge/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dbrgn/coverage-badge
COMMENT=	Generate coverage badges for Coverage.py
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5.4:../../devel/py-coverage

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
