# $NetBSD: Makefile,v 1.1.1.1 2005/03/29 05:01:08 sifu Exp $

DISTNAME=		TwistedWeb-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-web-${TWISTED_VERSION}
CATEGORIES=             net python www
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Web/0.5/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://www.twistedmatrix.com/projects/web/
COMMENT=		Webserver and webframework of Twisted

DEPENDS+=		${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
TWISTED_VERSION=	0.5.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
