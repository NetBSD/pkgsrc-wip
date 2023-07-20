# $NetBSD$

DISTNAME=	capturer-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/capturer/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://capturer.readthedocs.io/
COMMENT=	Easily capture stdout/stderr of the current process and subprocesses
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-humanfriendly>=8.0:../../wip/py-humanfriendly

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
