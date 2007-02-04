# $NetBSD: Makefile,v 1.3 2007/02/04 19:23:56 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

WEB_VERSION=	0.7.0
DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-web-${WEB_VERSION}
CATEGORIES=	net python www
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com
COMMENT=	A Twisted web server

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/TwistedWeb-${WEB_VERSION}

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.5.0:../../wip/py-twisted-core

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
