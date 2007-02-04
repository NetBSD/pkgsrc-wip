# $NetBSD: Makefile,v 1.3 2007/02/04 19:28:54 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

WORDS_VERSION=	0.5.0
DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-words-${WORDS_VERSION}
CATEGORIES=	net python chat
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	A Twisted chat service

WRKSRC=	${WRKDIR}/Twisted-${TWISTED_VERSION}/TwistedWords-${WORDS_VERSION}


DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.5.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-web>=0.7.0:../../wip/py-twisted-web

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
