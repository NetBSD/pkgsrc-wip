# $NetBSD: Makefile,v 1.3 2010/05/13 00:38:59 jihbed Exp $
#

DISTNAME=	eventlet-0.9.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/e/eventlet/

MAINTAINER= 	kamel.derouiche@gmail.com
HOMEPAGE=	http://eventlet.net/
COMMENT=	High performance network library using coroutines
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.2:../../wip/py-greenlet

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
