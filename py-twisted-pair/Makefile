# $NetBSD: Makefile,v 1.1.1.1 2005/03/29 05:03:45 sifu Exp $

DISTNAME=		TwistedPair-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-pair-${TWISTED_VERSION}
CATEGORIES=             net python
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Pair/0.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://www.twistedmatrix.com/projects/pair/
COMMENT=		Low-level networking stuff for Twisted

DEPENDS+=		${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
TWISTED_VERSION=	0.1.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
