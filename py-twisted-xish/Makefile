# $NetBSD: Makefile,v 1.1.1.1 2005/03/29 04:58:05 sifu Exp $

DISTNAME=		TwistedXish-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-xish-${TWISTED_VERSION}
CATEGORIES=             textproc python
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Xish/0.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://www.twistedmatrix.com/projects/xish/
COMMENT=		Additional XML stuff for Twisted

DEPENDS+=		${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted
DEPENDS+=		${PYPKGPREFIX}-twisted-web>=0.1.0:../../wip/py-twisted-web

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
TWISTED_VERSION=	0.1.0

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
