# $NetBSD: Makefile,v 1.4 2008/07/12 00:27:45 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

DISTNAME=	TwistedNews-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-news-${TWISTED_VERSION}
CATEGORIES=	net python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/News/8.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	An NNTP-based news service

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=8.1.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-mail>=8.1.0:../../wip/py-twisted-mail

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
