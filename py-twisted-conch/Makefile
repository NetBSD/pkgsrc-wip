# $NetBSD: Makefile,v 1.3 2007/02/04 19:22:35 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

CONCH_VERSION=	0.8.0
DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-conch-${CONCH_VERSION}
CATEGORIES=	net security python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/projects/conch
COMMENT=	SSHv2 implementation written in Python

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/TwistedConch-${CONCH_VERSION}


DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.5.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-amkCrypto>=1.9a6nb3:../../security/py-amkCrypto

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
