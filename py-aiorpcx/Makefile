# $NetBSD$

DISTNAME=	aiorpcX-0.18.2
PKGNAME=	${PYPKGPREFIX}-aiorpcx-0.18.2
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiorpcX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kyuupichan/aiorpcX
COMMENT=	Generic async RPC implementation, including JSON-RPC
LICENSE=	mit

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-websockets-[0-9]*:../../www/py-websockets

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
