# $NetBSD: Makefile,v 1.4 2008/07/12 00:23:34 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

DISTNAME=	TwistedConch-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-conch-${TWISTED_VERSION}
CATEGORIES=	net security python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Conch/8.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/projects/conch
COMMENT=	SSHv2 implementation written in Python

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=8.1.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-amkCrypto>=1.9a6nb3:../../security/py-amkCrypto

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
