# $NetBSD: Makefile,v 1.24 2009/03/22 14:40:40 milosn Exp $

TWISTED_VERSION=	8.2.0

DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
CATEGORIES =	net python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/8.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	Event-driven networking framework for Python

DEPENDS+=	${PYPKGPREFIX}-twisted-zopeinterface>=3.3.0:../../wip/py-twisted-zopeinterface
DEPENDS+=	${PYPKGPREFIX}-twisted-kqueue>=2.0:../../wip/py-twisted-kqueue
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-amkCrypto>=1.9a6nb3:../../security/py-amkCrypto

PYDISTUTILSPKG=		yes
_PYSETUPTOOLSINSTALLARGS+=	--old-and-unmanageable

CONFLICTS+=            ${PYPKGPREFIX}-twisted<2.4

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
