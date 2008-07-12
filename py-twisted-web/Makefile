# $NetBSD: Makefile,v 1.4 2008/07/12 00:24:31 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

DISTNAME=	TwistedWeb-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-web-${TWISTED_VERSION}
CATEGORIES=	net python www
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Web/8.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com
COMMENT=	A Twisted web server

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=8.1.0:../../wip/py-twisted-core

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
