# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:54 shattered Exp $
.include "../../wip/py-twisted-core/version.mk"

DISTNAME=		Twisted-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-core-${TWISTED_VERSION}
PKGREVISION=		2
CATEGORIES=		net python
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Twisted/2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Twisted reactor and other core stuff.

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/TwistedCore-${TWISTED_VERSION}

DEPENDS+=	${PYPKGPREFIX}-twisted-zopeinterface>=3.1.0c1:../../wip/py-twisted-zopeinterface
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

PYDISTUTILSPKG=		yes

CONFLICTS+=            ${PYPKGPREFIX}-twisted<2.4

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
