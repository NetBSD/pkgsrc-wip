# $NetBSD: Makefile,v 1.3 2007/02/04 19:29:52 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

RUNNER_VERSION=	0.2.0
DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-runner-${RUNNER_VERSION}
CATEGORIES=	net python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	Inetd replacement for Twisted

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/TwistedRunner-${RUNNER_VERSION}

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.5.0:../../wip/py-twisted-core

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
