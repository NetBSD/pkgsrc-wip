# $NetBSD: Makefile,v 1.15 2005/03/29 04:52:59 sifu Exp $

DISTNAME=		Twisted-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
CATEGORIES=		net python
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Twisted/2.0/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Event-driven networking framework for Python

DEPENDS+=               ${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../wip/py-ZopeInterface

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
TWISTED_VERSION=	2.0.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
