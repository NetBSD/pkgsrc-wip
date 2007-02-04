# $NetBSD: Makefile,v 1.3 2007/02/04 19:25:09 milosn Exp $

.include "../../wip/py-twisted-core/version.mk"

LORE_VERSION=	0.3.0
DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-lore-${LORE_VERSION}
CATEGORIES=	textproc python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	The Twisted documentation generation system

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/TwistedLore-${LORE_VERSION}

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.5.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-web>=0.7.0:../../wip/py-twisted-web

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
