# $NetBSD: Makefile,v 1.2 2006/08/27 16:55:54 milosn Exp $

.include "../../wip/py-twisted-core/version.mk"

LORE_VERSION=	0.2.0
DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-lore-${LORE_VERSION}
CATEGORIES=	textproc python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	The Twisted documentation deneration system

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/TwistedLore-${LORE_VERSION}

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.4.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-web>=0.6.0:../../wip/py-twisted-web

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
