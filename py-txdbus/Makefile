# $NetBSD: Makefile,v 1.5 2014/06/01 12:49:47 thomasklausner Exp $

DISTNAME=	txdbus-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txdbus/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/cocagne/txdbus
COMMENT=	Python implementation of the DBus protocol for the Twisted
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted>=13.1.0:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not ported as of 1.0.8

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
