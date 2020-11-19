# $NetBSD$

DISTNAME=	ratelim-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ratelim/}

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/themiurgo/ratelim
COMMENT=	Makes it easy to respect rate limits
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-decorator>=0:../../devel/py-decorator

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
