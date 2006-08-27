# $NetBSD: Makefile,v 1.2 2006/08/27 16:59:20 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

NEWS_VERSION=	0.2.0
DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-news-${NEWS_VERSION}
CATEGORIES=	net python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	An NNTP-based news service

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/TwistedNews-${NEWS_VERSION}


DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.4.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-mail>=0.3.0:../../wip/py-twisted-mail

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
