# $NetBSD: Makefile,v 1.1.1.1 2010/01/28 10:26:14 jihbed Exp $
#

DISTNAME=	eventlet-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/e/eventlet/

MAINTAINER= kamel.derouiche@gmail.com
HOMEPAGE=	http://eventlet.net/
COMMENT=	Coroutine-based networking library
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.2:../../wip/py-greenlet

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
