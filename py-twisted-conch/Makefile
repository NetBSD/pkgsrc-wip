# $NetBSD: Makefile,v 1.1.1.1 2005/03/29 05:14:22 sifu Exp $

DISTNAME=		TwistedConch-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-conch-${TWISTED_VERSION}
CATEGORIES=             net security python
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Conch/0.5/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://www.twistedmatrix.com/projects/conch
COMMENT=		SSHv2 implementation for Twisted

DEPENDS+=               ${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted
DEPENDS+=               ${PYPKGPREFIX}-amkCrypto>=1.9a6nb3:../../security/py-amkCrypto

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
TWISTED_VERSION=	0.5.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
