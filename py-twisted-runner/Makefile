# $NetBSD: Makefile,v 1.4 2008/07/12 00:28:36 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

RUNNER_VERSION=	8.0.0
DISTNAME=	TwistedRunner-${RUNNER_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-runner-${RUNNER_VERSION}
CATEGORIES=	net python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Runner/8.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	Inetd replacement for Twisted

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=8.0.0:../../wip/py-twisted-core

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
