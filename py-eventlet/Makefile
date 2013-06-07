# $NetBSD: Makefile,v 1.6 2013/06/07 21:32:11 othyro Exp $
#

DISTNAME=	eventlet-0.9.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/e/eventlet/

MAINTAINER= 	kamel.derouiche@gmail.com
HOMEPAGE=	http://eventlet.net/
COMMENT=	High performance network library using coroutines
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
