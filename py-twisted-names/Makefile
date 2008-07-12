# $NetBSD: Makefile,v 1.5 2008/07/12 00:26:11 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

DISTNAME=	TwistedNames-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-names-${TWISTED_VERSION}
CATEGORIES=	net python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Names/8.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	DNS implementation for Twisted

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=8.1.0:../../wip/py-twisted-core

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
