# $NetBSD: Makefile,v 1.1.1.1 2005/03/29 04:59:45 sifu Exp $

DISTNAME=		TwistedWords-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-words-${TWISTED_VERSION}
CATEGORIES=             net python chat
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Words/0.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://www.twistedmatrix.com/projects/words/
COMMENT=		IM implementation for Twisted

DEPENDS+=		${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted
DEPENDS+=		${PYPKGPREFIX}-twisted-web>=0.1.0:../../wip/py-twisted-web
DEPENDS+=		${PYPKGPREFIX}-twisted-xish>=0.1.0:../../wip/py-twisted-xish

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
TWISTED_VERSION=	0.1.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
