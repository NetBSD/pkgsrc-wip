# $NetBSD: Makefile,v 1.4 2008/07/12 00:25:21 milosn Exp $

.include "../../wip/py-twisted-core/version.mk"

DISTNAME=	TwistedLore-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-lore-${TWISTED_VERSION}
CATEGORIES=	textproc python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Lore/8.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	The Twisted documentation generation system

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=8.1.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-web>=8.1.0:../../wip/py-twisted-web

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
