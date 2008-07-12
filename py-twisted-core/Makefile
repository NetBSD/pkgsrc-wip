# $NetBSD: Makefile,v 1.6 2008/07/12 00:21:58 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

DISTNAME=		TwistedCore-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-core-${TWISTED_VERSION}
PKGREVISION=		0
CATEGORIES=		net python
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Core/8.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Twisted reactor and other core stuff

DEPENDS+=	${PYPKGPREFIX}-twisted-zopeinterface>=3.3.0:../../wip/py-twisted-zopeinterface
DEPENDS+=	${PYPKGPREFIX}-twisted-kqueue>=2.0:../../wip/py-twisted-kqueue
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

PYDISTUTILSPKG=		yes

CONFLICTS+=            ${PYPKGPREFIX}-twisted<2.4

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
