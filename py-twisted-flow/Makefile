# $NetBSD: Makefile,v 1.1.1.1 2005/03/29 05:11:43 sifu Exp $

DISTNAME=		TwistedFlow-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-flow-${TWISTED_VERSION}
CATEGORIES=             devel python
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Flow/0.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=             sifu@0xx0.net
HOMEPAGE=		http://www.twistedmatrix.com/projects/flow
COMMENT=		Concurrency handling for Twisted

DEPENDS+=		${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted
DEPENDS+=		${PYPKGPREFIX}-twisted-web>=0.5.0:../../wip/py-twisted-web

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
TWISTED_VERSION=	0.1.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
