# $NetBSD: Makefile,v 1.4 2008/05/22 15:38:47 tnn2 Exp $
.include "../../wip/py-twisted-core/version.mk"

ZI_VERSION=	3.3.0
DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-zopeinterface-${ZI_VERSION}
PKGREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	The zope.interface package for Twisted.

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/zope.interface-${ZI_VERSION}

DEPENDS+=	${PYPKGPREFIX}-xml>=0.8.4:../../textproc/py-xml

PYDISTUTILSPKG=		yes

CONFLICTS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
