# $NetBSD: Makefile,v 1.1 2013/08/31 21:59:04 jihbed Exp $

DISTNAME=	txdbus-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://pypi.python.org/packages/source/t/txdbus/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/cocagne/txdbus
COMMENT=	Python implementation of the DBus protocol for the Twisted
LICENSE=	mit

DEPENDS+=       ${PYPKGPREFIX}-twisted>=13.1.0:../../net/py-twisted
DEPENDS+=	   ${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

FETCH_USING=    curl

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
