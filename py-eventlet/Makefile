# $NetBSD: Makefile,v 1.4 2010/07/17 00:09:47 jihbed Exp $
#

DISTNAME=	eventlet-0.9.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/e/eventlet/

MAINTAINER= 	kamel.derouiche@gmail.com
HOMEPAGE=	http://eventlet.net/
COMMENT=	High performance network library using coroutines
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
