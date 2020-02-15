# $NetBSD$

DISTNAME=	cfgv-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cfgv/}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://github.com/asottile/cfgv
COMMENT=	Validate configuration and produce human readable error messages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
