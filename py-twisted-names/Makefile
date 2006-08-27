# $NetBSD: Makefile,v 1.2 2006/08/27 16:58:27 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

NAMES_VERSION=	0.3.0
DISTNAME=       Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-names-${NAMES_VERSION}
CATEGORIES=	net python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.4/
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	DNS implementation for Twisted

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/TwistedNames-${NAMES_VERSION}

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.4.0:../../wip/py-twisted-core

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
