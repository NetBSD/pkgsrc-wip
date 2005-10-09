# $NetBSD: Makefile,v 1.19 2005/10/09 10:13:29 sifu Exp $

DISTNAME=		Twisted-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
CATEGORIES=		net python
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Twisted/2.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Event-driven networking framework for Python

DEPENDS+=               ${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

PYDISTUTILSPKG=		yes
TWISTED_VERSION=	2.1.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
